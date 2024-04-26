#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int b = 0;
typedef struct equipment {
	int ID;
	string name;
	string fl;
	string cs;
	string time;
	int num;
	equipment* next;
}equipment, * Equipment;
void add(Equipment& p) //录入设备信息函数//
{
	equipment* p1 = new equipment;
	cout << "请输入设备的编号，名称，分类，生产厂商，购入时间，数量：" << endl;
	cin >> p1->ID >> p1->name >> p1->fl >> p1->cs >> p1->time >> p1->num;
	p1->next = p->next;
	p->next = p1;
	cout << endl;
}
void tj(Equipment& p) //分类统计设备数量函数//
{
	string* as = new string[100];
	int num = 0;
	int i = 0;
	equipment* p1 = p->next;
	while (p1 != NULL) {
		for (int j = 0; j < i; j++) {
			if (p1->fl == as[j]) {
				num = 1;
				break;
			}
		}
		if (num == 0) {
			as[i] = p1->fl;
			i++;
		}
		p1 = p1->next;
		num = 0;
	}
	for (int j = 0; j < i; j++) {
		p1 = p->next;
		num = 0;
		while (p1 != NULL) {
			if (p1->fl == as[j]) {
				num = num + p1->num;
			}
			p1 = p1->next;
		}
		cout << as[j] << "数量为：" << num << endl;
		cout << endl;
	}
}
void IDFound(Equipment& p) //按编号查询设备信息//
{
	int as;
	cout << "输入你要查询的编号：" << endl;
	cin >> as;
	equipment* p1 = p->next;
	while (p1 != NULL) {
		if (p1->ID == as) {
			cout << p1->ID << ' ' << p1->name << ' '
				<< p1->fl << ' ' << p1->cs << ' ' << p1->time << ' ' << p1->num << ' ';
			cout << endl;
		}
		p1 = p1->next;
	}
	cout << endl;
}
void nameFound(Equipment& p) //按名称查询设备信息//
{
	string as;
	cout << "输入你要查询的名称：" << endl;
	cin >> as;
	equipment* p1 = p->next;
	while (p1 != NULL) {
		if (p1->name == as) {
			cout << p1->ID << ' ' << p1->name << ' '
				<< p1->fl << ' ' << p1->cs << ' ' << p1->time << ' ' << p1->num << ' ';
			cout << endl;
		}
		p1 = p1->next;
	}
	cout << endl;
}
void flFound(Equipment& p)//按分类查询设备信息//
{
	string as;
	cout << "输入你要查询的分类：" << endl;
	cin >> as;
	equipment* p1 = p->next;
	while (p1 != NULL) {
		if (p1->fl == as) {
			cout << p1->ID << ' ' << p1->name << ' '
				<< p1->fl << ' ' << p1->cs << ' ' << p1->time << ' ' << p1->num << ' ';
			cout << endl;
		}
		p1 = p1->next;
	}
	cout << endl;
}
void print(Equipment& head)//输出函数//
{
	if (b == 0) {
		cout << "****************************************" << endl;
		cout << "1.设备信息录入" << endl;
		cout << "2.分类统计实验设备数量" << endl;
		cout << "3.按设备编号查询实验设备信息" << endl;
		cout << "4.按设备名称查询实验设备信息" << endl;
		cout << "5.按所属分类查询实验设备信息" << endl;
		cout << "6.结束程序" << endl;
		cout << "****************************************" << endl;
	}
	int a = 0;
	while (1) {

		cin >> a;
		if (a == 1) {
			add(head);
		}
		else if (a == 2) {
			tj(head);
		}
		else if (a == 3) {
			IDFound(head);
		}
		else if (a == 4) {
			nameFound(head);
		}
		else if (a == 5) {
			flFound(head);
		}
		else if (a == 6) {
			return;
		}
		b = 1;
		print(head);

	}
}
int main()
{
	equipment* head = new equipment;
	head->next = NULL;
	cout << "实验设备管理系统" << endl;
	print(head);
	return 0;
}