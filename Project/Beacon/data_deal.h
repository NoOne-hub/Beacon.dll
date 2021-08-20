#pragma once
#include <Windows.h>
#include "global.h"
#include "data_struct.h"
void push_dowrd_struc3(u_long hostlong, struc_3* a2);
void  push_short_struc3(struc_3* a1, int hostshort);
void push_byte_struc3(struc_3* a1, char Src);
void* clear_struc1_index(struc_1* a1);
void free_struc1(struc_1* a1);
DWORD_PTR sub_10001C90(struc_3* a1);
int random_dword_4();
int call_random_dword_4();
int ret_0();
int random_byte_N(BYTE* pbBuffer, DWORD dwLen);
DWORD rng_win32(BYTE* pbBuffer, DWORD dwLen);
DWORD_PTR sub_10009F44(DWORD_PTR* a1, int a2);
char* get_str(int a1);
WORD get_short(int a1);
DWORD get_DWORD(int a1);
size_t copy_struc_1_Nsize_src(void* a1, struc_1* a2, int a3);
void free_struc2_in_struc1(struc_2* a1);
unsigned int get_str_config_len(int a1);
DWORD_PTR ret_struc3_off_add4(struc_3* a1);
void* sub_100015F5(void* a1, size_t Size, struc_1* a3);
void* __cdecl init_struc1_size(struc_1* a1, size_t Size);
void* __cdecl copy_N_struc1_index2(struc_1* a1, void* Src, size_t Size);
void* __cdecl copy_size4_struc1_index2(struc_1* a1, u_long hostlong);
int ret_struc1_index2_size(struc_1* a1);
DWORD_PTR* ret_struc1_index1(struc_1* a1);
DWORD_PTR* ret_struc1_index2(struc_1* a1);
void free_struc_1(struc_1* a1);
int get_short_struc1_index2(struc_1* a1);
struc_1* init_struc1(struc_1* struc, void* Memory_addr, int Memory_size);
DWORD get_int_struc1_index2(struc_1* a1);
void* get_ptr_struc1_index2_OffsetN(struc_1* struc, int size);
void* init_struc1_malloc_Memory(size_t v3_Size);
void init_struc3(struc_3* struc3, DWORD* index_addr, int index_size);

void push_N_struc3(size_t Size, struc_3* struc3, void* src);



void push_dowrd_struc3(u_long hostlong, struc_3* a2)
{
	hostlong = htonl(hostlong);
	push_N_struc3(4, a2, &hostlong);
}

void  push_short_struc3(struc_3* a1, int hostshort)
{
	hostshort = htons(hostshort);
	push_N_struc3(2, a1, &hostshort);
}

void push_byte_struc3(struc_3* a1, char Src)
{
	push_N_struc3(1, a1, &Src);
}

void* clear_struc1_index(struc_1* a1)
{
	return memset((a1->index1), 0, a1->index1_size);
}

void free_struc1(struc_1* a1)
{
	clear_struc1_index(a1);
	free(a1->index1);
	free(a1);
}
DWORD_PTR sub_10001C90(struc_3* a1)
{
	*a1->index = htonl(48879);
	return a1->index_offset;
}

int random_dword_4()
{
	BYTE pbBuffer[4];
	random_byte_N(pbBuffer, 4);
	return *(DWORD*)pbBuffer;
}
int call_random_dword_4()
{
	return random_dword_4() & 0x7FFFFFFE;
}

int ret_0()
{
	return 0;
}
int random_byte_N(BYTE* pbBuffer, DWORD dwLen)
{
	int result;

	result = rng_win32(pbBuffer, dwLen);
	if (!result)
		//�����ٵ���һ���Զ���ʵ�ֵ�win apiʧ��ʱ
		//result = sub_1000B09D(dwLen, pbBuffer);
		return result;
}
DWORD rng_win32(BYTE* pbBuffer, DWORD dwLen)
{
	DWORD result;
	HCRYPTPROV phProv;

	phProv = 0;
	if (!CryptAcquireContextA(&phProv, 0, "Microsoft Base Cryptographic Provider v1.0", 1, 0xF0000020)
		&& (result = CryptAcquireContextA(&phProv, 0, "Microsoft Base Cryptographic Provider v1.0", 1, 0xF0000028)) == 0)
	{
		return result;
	}
	result = dwLen;
	if (!CryptGenRandom(phProv, dwLen, pbBuffer)) {
		result = 0;
	}
	CryptReleaseContext(phProv, 0);
	return result;
}

DWORD_PTR sub_10009F44(DWORD_PTR* a1, int a2)
{
	//change
#ifdef _M_X64
	* a1 = *(DWORD_PTR*)(CsC2Config + 16 * a2 + sizeof(size_t));
	return *(DWORD_PTR*)(CsC2Config + 16 * a2);
#else
	*a1 = *(DWORD_PTR*)(CsC2Config + 8 * a2 + sizeof(size_t));
	return *(DWORD_PTR*)(CsC2Config + 8 * a2);
#endif

}
char* get_str(int a1)
{
	int data_type;
	char* result;
	DWORD_PTR data = NULL;
	data_type = sub_10009F44(&data, a1);
	if ((WORD)data_type == 3)
		result = (char*)data;
	else
		result = 0;
	return result;
 }

WORD get_short(int a1)
{
	int data_type;
	WORD result;
	DWORD_PTR data = NULL;
	data_type = sub_10009F44(&data, a1);
	if ((WORD)data_type == 1)
		result = data;
	else
		result = 0;
	return result;
}

DWORD get_DWORD(int a1)
{
	int data_type;
	//change
	//int result
	size_t result;
	DWORD_PTR data = NULL;
	data_type = sub_10009F44(&data, a1);
	if ((WORD)data_type == 2)
		result = data;
	else
		result = 0;
	return result;
}



size_t copy_struc_1_Nsize_src(void* a1, struc_1* a2, int a3)
{
	int v3;
	size_t v4;
	void* v5;

	v3 = get_int_struc1_index2(a2);
	v4 = v3;
	if (!v3)
		return 0;
	if (v3 + 1 >= a3)
		return 0;
	v5 = get_ptr_struc1_index2_OffsetN(a2, v3);
	if (!v5)
		return 0;
	memcpy(a1, v5, v4);
	*((BYTE*)a1 + v4) = 0;
	return v4 + 1;
}

void free_struc2_in_struc1(struc_2* a1)
{
	free_struc1(a1->p_struc_1);
}

unsigned int get_str_config_len(int a1)
{
	return strlen(get_str(a1));
}
DWORD_PTR ret_struc3_off_add4(struc_3* a1)
{
	return a1->index_offset + 4;
}

void* sub_100015F5(void* a1, size_t Size, struc_1* a3)
{
	a3->index2_size = 0;
	a3->index1 = (DWORD_PTR*)a1;
	a3->index2 = (DWORD_PTR*)a1;
	a3->index1_size = Size;
	return memset(a1, 0, Size);
}

void* __cdecl init_struc1_size(struc_1* a1, size_t Size)
{
	void* v2;

	v2 = malloc(Size);
	return sub_100015F5(v2, Size, a1);
}

void* __cdecl copy_N_struc1_index2(struc_1* a1, void* Src, size_t Size)
{
	void* result;

	result = (void*)(a1->index1_size - a1->index2_size);
	if ((int)Size >= (int)result)
		return result;
	if (!Size)
		return result;
	result = memcpy(a1->index2, Src, Size);
	a1->index2 = (DWORD_PTR*)((char*)a1->index2 + Size);
	a1->index2_size += Size;
	return result;
}

void* __cdecl copy_size4_struc1_index2(struc_1* a1, u_long hostlong)
{
	hostlong = htonl(hostlong);
	return copy_N_struc1_index2(a1, &hostlong, 4u);
}

int ret_struc1_index2_size(struc_1* a1)
{
	return a1->index2_size;
}

DWORD_PTR* ret_struc1_index1(struc_1* a1)
{
	return a1->index1;
}

DWORD_PTR* ret_struc1_index2(struc_1* a1)
{
	return a1->index2;
}

void free_struc_1(struc_1* a1)
{
	memset(a1->index1, 0, a1->index1_size);
	free(a1->index1);
}

int get_short_struc1_index2(struc_1* a1)
{
	WORD result;

	if (a1->index2_size < sizeof(WORD))
		return 0;
	result = ntohs(*(WORD*)(a1->index2));
	//change
#ifdef _M_X64
	a1->index2 = (DWORD_PTR*)((size_t)(a1->index2) + sizeof(WORD));
	a1->index2_size -= sizeof(WORD);
#else
	a1->index2 = (DWORD_PTR*)((char*)(a1->index2) + sizeof(WORD));
	a1->index2_size -= sizeof(WORD);
#endif
	return result;
}
struc_1* init_struc1(struc_1* struc, void* Memory_addr, int Memory_size)
{
	struc_1* result;

	result = struc;
	struc->index1 = (DWORD_PTR*)Memory_addr;
	struc->index2 = (DWORD_PTR*)Memory_addr;
	struc->index2_size = Memory_size;
	struc->index1_size = Memory_size;
	return result;
}

DWORD get_int_struc1_index2(struc_1* a1)
{
	DWORD result;

	if (a1->index2_size < sizeof(int))
		return 0;
	result = ntohl(*a1->index2);
	//change
#ifdef _M_X64
	a1->index2 = (DWORD_PTR*)((size_t)(a1->index2) + 4);
	a1->index2_size -= sizeof(int);
#else
	++a1->index2;
	a1->index2_size -= sizeof(int);
#endif
	return result;
}

void* get_ptr_struc1_index2_OffsetN(struc_1* struc, int size)
{
	int v2;
	void* result;

	v2 = struc->index2_size;
	result = struc->index2;
	if (v2 < size)
		return 0;
	struc->index2 = (DWORD_PTR*)((char*)result + size);
	struc->index2_size = v2 - size;
	return result;
}

void* init_struc1_malloc_Memory(size_t v3_Size)
{
	void* result;
	void* struc1;
	void* v3;

	result = malloc(sizeof(struc_1));               // ����16���ֽڵ����ṹ��
	struc1 = result;
	if (!result)
		return result;
	result = (char*)malloc(v3_Size);
	v3 = result;
	if (!result)
		return result;
	memset(result, 0, v3_Size);
	init_struc1((struc_1*)struc1, v3, v3_Size);
	return struc1;
}

void init_struc3(struc_3* struc3, DWORD* index_addr, int index_size)
{
	DWORD v3;
	u_long v4;

	v3 = htonl(hostlong);
	v4 = htonl(0);
	++hostlong;
	*index_addr = v3;
	struc3->index = index_addr;
	struc3->size = index_size;
	index_addr[1] = v4;
	struc3->index_offset = 8;
}

void push_N_struc3(size_t Size, struc_3* struc3, void* src)
{
	DWORD_PTR v3;
	DWORD_PTR index_new_size;

	v3 = struc3->index_offset;
	index_new_size = v3 + Size;
	if ((signed int)(v3 + Size) <= struc3->size)
	{
		memcpy((char*)struc3->index + v3, src, Size);
		struc3->index_offset = index_new_size;
		struc3->index[1] = ntohl(index_new_size - 8);
	}
}
