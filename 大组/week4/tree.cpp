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
	else printf("您输入的数据出现重复，数据过滤\n");
}
void search(tree* t, int n)
{
	if (t == NULL)
	{
		printf("未在树中找到此数据\n");
		return;
	}
	if (t->date == n)
	{
		printf("该树中存在该数据\n");
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
		printf("插入成功！\n");
	}
	else if (n > (*t)->date)
	{
		insert(&(*t)->rchild, n);
	}
	else if (n < (*t)->date)
	{
		insert(&(*t)->lchild, n);
	}
	else printf("您插入的数据重复，插入失败\n");
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
		printf("未能找到您想删除的数据\n");
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
		printf("删除成功\n");
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
	printf("初始化树请输入1\n");
	printf("查找树中的数据请输入2\n");
	printf("插入数据请输入3\n");
	printf("删除数据请输入4\n");
	printf("前序遍历请输入5\n");
	printf("中序遍历请输入6\n");
	printf("后序遍历请输入7\n");
	printf("层序遍历请输入8\n");
	printf("退出操作请输入0\n");
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
		case '1': printf("请输入一窜数据，初始化树(最后输入0结束操作):");
			      do
		          {
			              scanf("%d", &n);
			               if (n == 0)
				           break;
			               initinsert(&t, n);
		           } while (n != 0);
				   printf("初始化成功\n");
				   break;
		case '2': printf("请输入您想要查找的数据："); scanf("%d", &n); search(t, n); break;
		case '3':  printf("请输入您想要插入的数据："); scanf("%d", &n); insert(&t, n); break;
		case '4': printf("请输入您想要删除的数据："); scanf("%d", &n); shanchu(&t, n); break;
		case '5': printf("前序遍历为："); preorder(t); printf("\n"); break;
		case '6': printf("中序遍历为："); inorder(t); printf("\n"); break;
		case '7': printf("后序遍历为："); postorder(t); printf("\n"); break;
		case '8': printf("层序遍历为："); cxorder(t); printf("\n"); break;
		case '0':printf("退出操作"); return 0;
		}
	}
}
