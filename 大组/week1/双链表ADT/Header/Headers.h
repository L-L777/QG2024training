#include<iostream>
using namespace std;
typedef struct node{
	string data;
	node *prev,*next;
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
