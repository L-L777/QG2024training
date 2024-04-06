#include"header.h"

void init(tree** t)
{
	*t = (tree*)malloc(sizeof(tree));
	(*t) = NULL;
}
void initinsert(tree** t, int n)
{
	if ((*t) == NULL)
	{
		*t = (tree*)malloc(sizeof(tree));
		(*t)->date = n;
		(*t)->lchild = NULL;
		(*t)->rchild = NULL;
	}
	else if (n > (*t)->date)
	{
		initinsert(&(*t)->rchild, n);
	}
	else if (n < (*t)->date)
	{
		initinsert(&(*t)->lchild, n);
	}
	else printf("����������ݳ����ظ������ݹ���\n");
}
void search(tree* t, int n)
{
	if (t == NULL)
	{
		printf("δ�������ҵ�������\n");
		return;
	}
	if (t->date == n)
	{
		printf("�����д��ڸ�����\n");
		return;
	}
	else if (n > t->date)
	{
		search(t->rchild, n);
	}
	else if (n < t->date)
	{
		search(t->lchild, n);
	}
}
void insert(tree** t, int n)
{
	if ((*t) == NULL)
	{
		(*t) = (tree*)malloc(sizeof(tree));
		(*t)->date = n;
		(*t)->lchild = NULL;
		(*t)->rchild = NULL;
		printf("����ɹ���\n");
	}
	else if (n > (*t)->date)
	{
		insert(&(*t)->rchild, n);
	}
	else if (n < (*t)->date)
	{
		insert(&(*t)->lchild, n);
	}
	else printf("������������ظ�������ʧ��\n");
}
void shanchutwo(tree** t)
{
	tree* q, * s;
	if ((*t)->rchild == NULL)
	{
		q = *t; *t = (*t)->lchild; free(q);
	}
	else if ((*t)->lchild == NULL)
	{
		q = *t; *t = (*t)->rchild; free(q);
	}
	else
	{
		q = (*t);
		s = (*t)->lchild;
		while (s->rchild)
		{
			q = s; s = s->rchild;
		}
		(*t)->date = s->date;
		if (q != (*t))
		{
			q->rchild = s->lchild;
		}
		else
		{
			q->lchild = s->lchild;
		}
		free(s);
	}
}
void shanchu(tree** t, int n)
{
	if (!*t)
	{
		printf("δ���ҵ�����ɾ��������\n");
		return;
	}
	if (n > (*t)->date)
	{
		shanchu(&(*t)->rchild, n);
	}
	else if (n < (*t)->date)
	{
		shanchu(&(*t)->lchild, n);
	}
	else {

		shanchutwo(t);
		printf("ɾ���ɹ�\n");
	}
}
void preorder(tree* t)
{
	if (t)
	{
		printf("%d ", t->date);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
void inorder(tree* t)
{
	if (t)
	{
		inorder(t->lchild);
		printf("%d ", t->date);
		inorder(t->rchild);
	}
}
void postorder(tree* t)
{
	if (t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%d ", t->date);
	}
}
void rudui(tree* t)
{
	dl[tail] = t;
	tail++;
}
void chudui(tree* t)
{
	printf("%d ", dl[head]->date);
	head++;
}
void cxorder(tree* t)
{
	head = 0, tail = 1;
	dl[head] = (tree*)malloc(sizeof(tree));
	dl[head] = t;
	while (head < tail)
	{
		if (dl[head]->lchild != NULL)
		{
			rudui(dl[head]->lchild);
		}
		if (dl[head]->rchild != NULL)
		{
			rudui(dl[head]->rchild);
		}
		chudui(dl[head]);
	}
}
void menu()
{
	printf("========================\n");
	printf("��ʼ����������1\n");
	printf("�������е�����������2\n");
	printf("��������������3\n");
	printf("ɾ������������4\n");
	printf("ǰ�����������5\n");
	printf("�������������6\n");
	printf("�������������7\n");
	printf("�������������8\n");
	printf("�˳�����������0\n");
	printf("========================\n");
}

int main()
{
	char m;
	int n;
	tree* t;
	init(&t);
	while (1)
	{
		menu();
		cin>>m;
		switch (m)
		{
		case '1': printf("������һ�����ݣ���ʼ����(�������0��������):");
			      do
		          {
			              scanf("%d", &n);
			               if (n == 0)
				           break;
			               initinsert(&t, n);
		           } while (n != 0);
				   printf("��ʼ���ɹ�\n");
				   break;
		case '2': printf("����������Ҫ���ҵ����ݣ�"); scanf("%d", &n); search(t, n); break;
		case '3':  printf("����������Ҫ��������ݣ�"); scanf("%d", &n); insert(&t, n); break;
		case '4': printf("����������Ҫɾ�������ݣ�"); scanf("%d", &n); shanchu(&t, n); break;
		case '5': printf("ǰ�����Ϊ��"); preorder(t); printf("\n"); break;
		case '6': printf("�������Ϊ��"); inorder(t); printf("\n"); break;
		case '7': printf("�������Ϊ��"); postorder(t); printf("\n"); break;
		case '8': printf("�������Ϊ��"); cxorder(t); printf("\n"); break;
		case '0':printf("�˳�����"); return 0;
		}
	}
}
