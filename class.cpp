#include <fstream>
#include "tools.h"
#include "class.h"

using namespace std;    //标准命名空间  不建议用此种方式  std::为正确方式

Customer* cust[30];   //Customer类的实例化对象 
Room* room[30];       //Room类的实例化对象

int live; //被订房数

//获取room_num
short Room::get_room_num(void)
{
	return room_num;
}

int Manage::room_index(short room_num)
{
	short num = room_num;
	for (int i = 0; i < 30; i++)
	{
		if (num == room[i]->get_room_num())
		{
			return i;
		}
	}
	return -1;
}
void Manage::find_room(void)
{
	for (int i = 0; i < 30; i++)
	{
		if (i == 10 || i == 20)
		{
			cout << endl;
		}
		if (room[i]->use != 0)
		{
			continue;
		}
		cout << room[i]->room_num << " ";
	}
	cout << endl;
}

void Manage::get_room(void)
{
	cout << "现有房间如下" << endl;
	find_room();

	cout << "请输入您选择的房间：";
	short room_num;
	cin >> room_num;
	int flag = used(room_num);
	if (flag == 1)
	{
		cout << "此房间不能使用";
		getch();
		return;
	}
	else if (flag == -1)
	{
		cout << "此房间不存在，请重新选择";
		getch();
		return;
	}
	else
	{
		cout << "您选择的房间是：" << room_num << endl;
	}
	int index = room_index(room_num);
	short type = room[index]->room_type;

	cout << "请输入您的姓名";
	string name;
	cin >> name;
	cout << "请输入您的身份证：";
	string id;
	cin >> id;
	cout << "请输入您的两位家属（0，表示没有）" << endl;
	string family1, family2;
	cin >> family1 >> family2;

	if (type == 1)
	{
		if (family1 != "0" && family2 != "0")
		{
			cout << "开房人数过多，开房失败" << endl;
			getch();
			return;
		}
	}
	else if (type == 2)
	{
		if (family1 != "0" && family2 != "0")
		{
			cout << "开房人数过多，开房失败" << endl;
			getch();
			return;
		}
	}
	else
	{
	}

	cout << "请输入要订的天数：";
	short day;
	cin >> day;
	short pay = day * room[index]->price;
	cout << "请支付" << pay << "元" << endl;
	short money, change;
	cout << "收您";
	cin >> money;
	cout << "元" << endl;
	change = money - pay;
	if (change < 0)
	{
		cout << "余额不足，请充值" << endl;
		getch();
		return;
	}
	cout << "找您" << change << "元" << endl;
	short floor = room_num / 100;
	cust[live++] = new Customer(name, id, family1, family2, floor, room_num, day);
	cout << "已订房间：" << live << endl;

	for (int i = 0; i < 30; i++)
	{
		if (room[i]->room_num == room_num)
		{
			room[i]->use = 1;
		}
	}

	cout << "开房成功，欢迎入住，祝您生活愉快！" << endl;
	getch();
	
}

//使用情况
int Manage::used(short room_num)
{
	short num = room_num;
	for (int i = 0; i < 30; i++)
	{
		if (num == room[i]->room_num)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return -1;
}
//显示顾客
void Manage::show_cust(void)
{
	for (int i = 0; i < 30; i++)
	{
		if (cust[i]->name == "0")
		{
			break;
		}
		else
		{
			cout << "姓名：" << cust[i]->name << endl;
			string f1, f2;
			f1 = cust[i]->family1;
			f2 = cust[i]->family2;
			cout << "家属1：";
			if (f1 == "0")
			{
				cout << " " << endl;
			}
			else
			{
				cout << f1 << endl;
			}
			if (f2 == "0")
			{
				cout << " " << endl;
			}
			else
			{
				cout << f2 << endl;
			}
		}
	}
}