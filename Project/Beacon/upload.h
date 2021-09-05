#pragma once
#include <Windows.h>
#include "data_deal.h"
#include "function.h"
unsigned __int64 __fastcall sub_18000CF64(__int64 a1, u_long a2);
unsigned __int64 __fastcall sub_18000CEA8(__int64 a1, const void* a2, int a3);
void* __fastcall sub_18000CF34(void* a1, unsigned int a2);
void __fastcall sub_18000DB74(unsigned int a1, unsigned int a2, unsigned int a3, __int64 a4);

__int64 __fastcall sub_180013E74(struc_1* a1)
{
    return a1->index2_size;
}
DWORD_PTR* __fastcall sub_180013D94(struc_1* a1)
{
    return a1->index2;
}


unsigned __int64 __fastcall sub_18000CEA8(__int64 a1, const void* a2, int a3)
{
    __int64 v3; // rsi
    unsigned __int64 result; // rax

    v3 = a3;
    result = (unsigned int)(*(_DWORD*)(a1 + 20) - *(_DWORD*)(a1 + 16));
    if (a3 < (int)result)
    {
        if (a3)
        {
            result = (unsigned __int64)memmove(*(void**)(a1 + 8), a2, a3);
            *(_QWORD*)(a1 + 8) += v3;
            *(_DWORD*)(a1 + 16) += v3;
        }
    }
    return result;
}

unsigned __int64 __fastcall sub_18000CF64(__int64 a1, u_long a2)
{
    u_long v4; // [rsp+38h] [rbp+10h] BYREF

    v4 = htonl(a2);
    return sub_18000CEA8(a1, &v4, 4);
}





void* __fastcall sub_18000CF34(void* a1, unsigned int a2)
{
    void* v4; // rax

    v4 = malloc((int)a2);
    return sub_100015F5(a1, a2, (struc_1*)v4);
}
__int64 __fastcall sub_18000D000(__int64 a1)
{
    return *(_QWORD*)a1;
}

void __fastcall sub_18000DB74(unsigned int a1, unsigned int a2, unsigned int a3, __int64 a4)
{
    __int64 v8; // r8
    struc_1* v9; // ebx
    __int64 v10; // rax
    char v11[40]; // [rsp+20h] [rbp-28h] BYREF

    struc_1* ptr_struc1 = (struc_1*)init_struc1_malloc_Memory(0x800);
    get_ptr_struc1_index2_OffsetN(ptr_struc1, a1);
    get_ptr_struc1_index2_OffsetN(ptr_struc1, a2);
    get_ptr_struc1_index2_OffsetN(ptr_struc1, a3);

    /*sub_18000CF34((void*)v11, 0x800u);
    sub_18000CF64((__int64)v11, a1);
    sub_18000CF64((__int64)v11, a2);
    sub_18000CF64((__int64)v11, a3);*/
    if (a4)
    {
        v8 = -1i64;
        do
            ++v8;
        while (*(_BYTE*)(v8 + a4));
        sub_18000CEA8((__int64)v11, (const void*)a4, v8);
    }
    v9 = (struc_1*)sub_180013E74((struc_1*)v11);
    v10 = sub_18000D000((__int64)v11);
    sub_100012CF(v9, v10, 0x1f);
    //sub_18000CDD8(v10, v9, 0x1Fu);
    //sub_18000CF10((__int64)v11);
    clean_it((void*)v11);
}


void __fastcall sub_18000DB60(__int64 a1, __int64 a2)
{
    sub_18000DB74(a1, a2, 0i64, 0i64);
}

void __fastcall upload(void* a1, int a2, const char* a3)
{
    void* v6; // rdi
    int v7; // eax
    void* v8; // rcx
    FILE* v9; // rsi
    size_t v10; // rbx
    const void* v11; // rax
    DWORD v12; // eax
    struc_1 v13; // [rsp+20h] [rbp-28h] BYREF

    v6 = malloc(0x400ui64);
    if (v6)
    {
        init_struc1((struc_1*)&v13, a1, a2);
        v7 = copy_struc_1_Nsize_src(v6, (struc_1*)&v13, 1024);
        v8 = v6;
        if (!v7)
        {
            free(v8);
            return;
        }
        v9 = fopen((const char*)v6, a3);
        if (NULL == v9)
        {
            free(v6);
            return; /* Òª·µ»Ø´íÎó´úÂë */
        }

        v10 = (int)sub_180013E74((struc_1*)&v13);
        v11 = (const void*)sub_180013D94((struc_1*)&v13);
        fwrite(v11, 1ui64, v10, v9);
        fclose(v9);
        v8 = v6;
        free(v6);
        //v12 = GetLastError();
        //sub_18000DB60(8i64, v12);
    }
}