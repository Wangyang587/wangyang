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
void add(Equipment& p) //¼���豸��Ϣ����//
{
	equipment* p1 = new equipment;
	cout << "�������豸�ı�ţ����ƣ����࣬�������̣�����ʱ�䣬������" << endl;
	cin >> p1->ID >> p1->name >> p1->fl >> p1->cs >> p1->time >> p1->num;
	p1->next = p->next;
	p->next = p1;
	cout << endl;
}
void tj(Equipment& p) //����ͳ���豸��������//
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
		cout << as[j] << "����Ϊ��" << num << endl;
		cout << endl;
	}
}
void IDFound(Equipment& p) //����Ų�ѯ�豸��Ϣ//
{
	int as;
	cout << "������Ҫ��ѯ�ı�ţ�" << endl;
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
void nameFound(Equipment& p) //�����Ʋ�ѯ�豸��Ϣ//
{
	string as;
	cout << "������Ҫ��ѯ�����ƣ�" << endl;
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
void flFound(Equipment& p)//�������ѯ�豸��Ϣ//
{
	string as;
	cout << "������Ҫ��ѯ�ķ��ࣺ" << endl;
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
void print(Equipment& head)//�������//
{
	if (b == 0) {
		cout << "****************************************" << endl;
		cout << "1.�豸��Ϣ¼��" << endl;
		cout << "2.����ͳ��ʵ���豸����" << endl;
		cout << "3.���豸��Ų�ѯʵ���豸��Ϣ" << endl;
		cout << "4.���豸���Ʋ�ѯʵ���豸��Ϣ" << endl;
		cout << "5.�����������ѯʵ���豸��Ϣ" << endl;
		cout << "6.��������" << endl;
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
	cout << "ʵ���豸����ϵͳ" << endl;
	print(head);
	return 0;
}