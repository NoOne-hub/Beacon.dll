#pragma once
#include <Windows.h>
typedef struct struc_1
{
	DWORD_PTR* index1;
	DWORD_PTR* index2;
	int index2_size;
	int index1_size;
}struc_1;

typedef struct struc_2
{
	DWORD_PTR* lpszHeaders;
	DWORD_PTR* field_1;
	DWORD_PTR* http_get_url;
	DWORD_PTR* lpOptional;
	DWORD_PTR dwOptionalLength;
	DWORD_PTR encrypt_Metadata_size;
	DWORD_PTR* encrypt_Metadata;
	DWORD_PTR* Encoding_encrypt_Metadata;
	struc_1* p_struc_1;
}struc_2;

typedef struct struc_3
{
	DWORD* index;
	DWORD index_offset;
	int size;
}struc_3;

typedef struct rotationstruc
{
	DWORD Rotation67; //67
	DWORD Rotation68; //68
	DWORD Rotation70; //70
	DWORD Rotation69; //69
}rotationstruc;

typedef struct TaskdataStruc
{
	int Task_id;
	int Task_data_len;
	char Task_data[];
}TaskdataStruc;
