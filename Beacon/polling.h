#pragma once
#include "data_struct.h"
#include <time.h>
#include "global.h"

int sub_1000A498(rotationstruc* a1, char* Source, int a3)
{
	char* i;
	int v5;
	int v6;
	int v7;
	int result;
	__time64_t v9;
	int v10;

	v10 = 0;
	v9 = _time64(0);
	if (dword_10037E7C)
	{
		v6 = dword_10032018;
		v7 = dword_10032014;
	}
	else
	{
		dword_10037E7C = (char*)malloc(strlen(Source) + 1);
		strncpy(dword_10037E7C, Source, strlen(Source) + 1);
		dword_100375E8 = 0;
		for (i = strtok(dword_10037E7C, ","); i; i = strtok(0, ","))
		{
			v5 = dword_100375E8++;
			dword_100372B0[v5] = (int)i;
		}
		dword_100375D4 = 0;
		qword_100375E0 = _time64(0);
		v6 = a1->Rotation69;
		dword_10032010 = a1->Rotation68;
		v7 = a1->Rotation70;
		qword_100375D8 = 0i64;
		dword_10032018 = v6;
		dword_10032014 = v7;
	}
	if (a3)
	{
		if (v6 > -1 && ++dword_10037E84 > v6)
			v10 = 1;
		if (v7 > -1)
		{
			if (qword_100375D8)
			{
				if (v9 > qword_100375D8 + v7)
					v10 = 1;
			}
			else
			{
				qword_100375D8 = _time64(0);
			}
		}
	}
	else if (!dword_10037E80)
	{
		qword_100375D8 = 0i64;
		dword_10037E84 = 0;
	}
	if (dword_10032010 <= -1)
		goto LABEL_23;
	if (!v10)
	{
		if (dword_10037E80)
			goto LABEL_29;
		if (v9 <= qword_100375E0 + dword_10032010)
		{
		LABEL_28:
			result = dword_100372B0[dword_100375D4];
			dword_10037E80 = 1;
			return result;
		}
		v10 = 1;
	LABEL_23:
		if (!v10)
			goto LABEL_27;
	}
	dword_100375D4 += 2;
	dword_10037E84 = 0;
	dword_10037E80 = 0;
	qword_100375D8 = 0i64;
	if (dword_100375D4 >= dword_100375E8)
		dword_100375D4 = 0;
	qword_100375E0 = _time64(0);
LABEL_27:
	if (!dword_10037E80)
		goto LABEL_28;
LABEL_29:
	result = dword_100372B0[dword_100375D4 + 1];
	dword_10037E80 = 0;
	return result;
}


int sub_1000A3AB(int a1)
{
	return rand() % (a1 + 1);
}
int sub_1000A3BE(int a1)
{
	return a1 - a1 % 2;
}

int random_strategy(char* Source)
{
	char* i;
	int v2;
	int v3;
	int v4;
	int v5;

	if (buff)
	{
		v3 = dword_100375D0;
	}
	else
	{
		buff = (char*)malloc(strlen(Source) + 1);
		strncpy(buff, Source, strlen(Source) + 1);
		dword_10035EDC = 0;
		for (i = strtok(buff, ","); i; i = strtok(0, ","))
		{
			v2 = dword_10035EDC++;
			dword_10036F90[v2] = (int)i;
		}
		v3 = -1;
		dword_100375D0 = -1;
	}
	if (v3 < 0 || v3 >= dword_10035EDC)
	{
		v5 = sub_1000A3AB(dword_10035EDC - 1);
		v4 = sub_1000A3BE(v5);
		dword_100375D0 = v4;
	}
	else
	{
		v4 = v3 + 1;
		dword_100375D0 = -1;
	}
	return dword_10036F90[v4];
}



char* no_rotation(char* Source)
{
	char* result;

	if (Global_strbuf)
	{
		result = strtok(0, ",");
		if (result)
			return result;
		free(Global_strbuf);
	}
	Global_strbuf = (char*)malloc(strlen(Source) + 1);
	strncpy(Global_strbuf, Source, strlen(Source) + 1);
	return strtok(Global_strbuf, ",");
}

char* beacon_Rotation_Strategy(rotationstruc* a1, char* Source, int number)
{
	//round-robin=0
	//random=1
	if (a1->Rotation67 == 1) {//随机选取
		return (char*)random_strategy(Source);
	}
	if (a1->Rotation67 == 2) {//rotate或failover都是2 轮询策略
		return (char*)sub_1000A498(a1, Source, number);
	}
	return no_rotation(Source);//无轮询
}

void init_rotation(rotationstruc* result, int get_67, int get_68, int get_70, int get_69)
{
	result->Rotation67 = get_67;
	result->Rotation68 = get_68;
	result->Rotation70 = get_70;
	result->Rotation69 = get_69;
}