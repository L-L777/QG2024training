#include<iostream>

#define HEADER_H
using namespace std;
typedef struct node{
	string data;
	struct node *next;
}Link;
Link *head,*p,*tail;
int l=0;//��¼������ 
void menu();//�˵� 
void add();//�������� 
void show();//��ʾ�������� 
void find();//���ҽڵ� 
void insert();//��������
void deleteData();//ɾ��ĳ���ڵ�
void destroy();//�������� 
void middle();//�����е� 
void change();//��ż��ת
void checkCycle();//�ж��Ƿ�ɻ�
void reverse();//��ת����
