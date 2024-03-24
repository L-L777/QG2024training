#include<stdio.h>
#include<stdlib.h>
typedef struct node1
{
	int date;
	node1* next;
}dl;
typedef struct node2
{
	int l;
	dl* head, * tail;
}qq;
void init(qq *P);
void rudui(qq *p);
void chudui(qq *p);
void chazhao(qq *p);
void bianli(qq *p);
void xiaohui(qq *p);
void menu();
