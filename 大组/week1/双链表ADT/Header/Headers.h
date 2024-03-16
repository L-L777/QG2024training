#include<iostream>
using namespace std;
typedef struct node{
	string data;
	node *prev,*next;
}Link;
Link *head,*p,*tail;
int l=0;//记录链表长度 
void menu();//菜单 
void add();//增加数据 
void show();//显示链表数据 
void find();//查找节点 
void insert();//插入数据
void deleteData();//删除某个节点
void destroy();//销毁链表 
