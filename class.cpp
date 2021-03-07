#include <fstream>
#include "tools.h"
#include "class.h"

using namespace std;    //��׼�����ռ�  �������ô��ַ�ʽ  std::Ϊ��ȷ��ʽ

Customer* cust[30];   //Customer���ʵ�������� 
Room* room[30];       //Room���ʵ��������

int live; //��������

//��ȡroom_num
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
	cout << "���з�������" << endl;
	find_room();

	cout << "��������ѡ��ķ��䣺";
	short room_num;
	cin >> room_num;
	int flag = used(room_num);
	if (flag == 1)
	{
		cout << "�˷��䲻��ʹ��";
		getch();
		return;
	}
	else if (flag == -1)
	{
		cout << "�˷��䲻���ڣ�������ѡ��";
		getch();
		return;
	}
	else
	{
		cout << "��ѡ��ķ����ǣ�" << room_num << endl;
	}
	int index = room_index(room_num);
	short type = room[index]->room_type;

	cout << "��������������";
	string name;
	cin >> name;
	cout << "�������������֤��";
	string id;
	cin >> id;
	cout << "������������λ������0����ʾû�У�" << endl;
	string family1, family2;
	cin >> family1 >> family2;

	if (type == 1)
	{
		if (family1 != "0" && family2 != "0")
		{
			cout << "�����������࣬����ʧ��" << endl;
			getch();
			return;
		}
	}
	else if (type == 2)
	{
		if (family1 != "0" && family2 != "0")
		{
			cout << "�����������࣬����ʧ��" << endl;
			getch();
			return;
		}
	}
	else
	{
	}

	cout << "������Ҫ����������";
	short day;
	cin >> day;
	short pay = day * room[index]->price;
	cout << "��֧��" << pay << "Ԫ" << endl;
	short money, change;
	cout << "����";
	cin >> money;
	cout << "Ԫ" << endl;
	change = money - pay;
	if (change < 0)
	{
		cout << "���㣬���ֵ" << endl;
		getch();
		return;
	}
	cout << "����" << change << "Ԫ" << endl;
	short floor = room_num / 100;
	cust[live++] = new Customer(name, id, family1, family2, floor, room_num, day);
	cout << "�Ѷ����䣺" << live << endl;

	for (int i = 0; i < 30; i++)
	{
		if (room[i]->room_num == room_num)
		{
			room[i]->use = 1;
		}
	}

	cout << "�����ɹ�����ӭ��ס��ף��������죡" << endl;
	getch();
	
}

//ʹ�����
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
//��ʾ�˿�
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
			cout << "������" << cust[i]->name << endl;
			string f1, f2;
			f1 = cust[i]->family1;
			f2 = cust[i]->family2;
			cout << "����1��";
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