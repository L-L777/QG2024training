#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
using namespace std;
typedef struct node
{
	int date;
	node* lchild, * rchild;
}tree;
tree* dl[1000];
int head = 0, tail = 1;
void init(tree** t);
void initinsert(tree** t, int n);
void search(tree* t, int n);
void insert(tree** t, int n);
void shanchutwo(tree** t);
void shanchu(tree** t, int n);
void preorder(tree* t);
void inorder(tree* t);
void postorder(tree* t);
void rudui(tree* t);
void chudui(tree* t);
void cxorder(tree* t);
void menu();
