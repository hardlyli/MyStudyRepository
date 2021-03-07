#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <cstring>

using namespace std;

class Customer
{
public:
	string name; //����
	string id; //���֤
	string family1;
	string family2;//����2
	short floor;   //¥��
	short room_num;//�����
	short day; //ʱ��
	Customer(string name = "0", string id = "0", string family1 = "0", string family2 = "0", short floor = "0", short room_num = "0", short day = "0")
	{
		this->name = name;
		this->id = id;
		this->family1 = family1;
		this->family2 = family2;
		this->floor = floor;
		this->room_num = room_num;
		this->day = day;
	}
};
class Room
{
public:
	short floor;//¥��
	short room_num;//�����
	short room_type;//��������
	short price;//�۸�
	short use;//�Ƿ�ʹ��
	Room(short floor = 0, short room_num = 0, short room_type = 0, short price = 0, short use = 0)
	{
		this->floor = 0;
		this->price = 0;
		this->room_num = 0;
		this->room_type = 0;
		this->use = 0;
	}
	short get_room_num(void);
};

class Manage
{
public:
	void menu(void);//�˵�
	void find_room(void);//ʣ�෿��
	void get_room(void);//����
	void renew_room(void);//����
	void cancel_room(void);//�˷�
	int room_index(short room_num); //�����±�
	int cust_index(short room_num); //�˿��±�
	int used(short room_num);  //����ʹ�����
	void show_cust(void); //��ʾ��ס�˿�
	int room_price(short room_num); //����۸�
	void c_init(void); //�˿ͳ�ʼ��
	void r_init(void); //�����ʼ��
	void save_data(void); //��������
};

#endif //CLASS_H



