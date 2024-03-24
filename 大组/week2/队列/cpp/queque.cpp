#include"queque.h"
void init(qq* p)
{
	p->head = (dl*)malloc(sizeof(dl));
	p->tail = p->head;
	p->l = 0;
	printf("队列初始化成功\n");
}
void rudui(qq* p)
{
	while (1)
	{
		printf("停止插入输入0，否则请输入任意一个数继续插入:");
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		printf("输入你想插入队列中的元素：");
		int e;
		scanf("%d", &e);
		dl* a = (dl*)malloc(sizeof(dl));
		a->date = e;
		a->next = NULL;
		p->tail->next = a;
		p->tail= a;
		p->l++;
	}
}
void chudui(qq* p)
{
	if (p->l == 0)
	{
		printf("该队列为空，无法出队\n");
		return;
	}
	dl* a;
	a = p->head->next;
	printf("此次出队元素为%d\n", a->date);
	p->head ->next= a->next;
	p->l--;
	free(a);
}
void chazhao(qq* p)
{
	printf("输入你想查找队列中第几个元素：");
	int b;
	scanf("%d", &b);
	if (b > p->l)
	{
		printf("该队列长度不够，没有您想查找的数据\n");
		return;
	}
	else
	{
		dl* a = (dl*)malloc(sizeof(dl));
		a = p->head;
		for (int i = 0; i < b; i++)
		{
			a = a->next;
		}
		printf("您想查找的元素：%d\n", a->date);
	}
}
void bianli(qq* p)
{
	if (p->l == 0)
	{
		printf("该队列为空，无法出队\n");
		return;
	}
	dl* a = (dl*)malloc(sizeof(dl));
	a = p->head;
	for (int i = 1; i <= p->l; i++)
	{
		a = a->next;
		printf("该队列中第%d个元素为：%d\n", i, a->date);
	}
}
void xiaohui(qq* p)
{
	p->tail = p->head;
	p->tail->next = NULL;
	p->l = 0;
	printf("销毁成功\n");
}
void menu()
{
	printf("=======================\n");
	printf("初始化队列请输入1\n");
	printf("入队列请输入2\n");
	printf("出队列请输入3\n");
	printf("查找队列元素请输入4\n");
	printf("遍历队列请输入5\n");
	printf("销毁队列请输入6\n");
	printf("退出请输入0\n");
	printf("=======================\n");
}
int main()
{
	qq p;
	init(&p);
	while (1)
	{
		int n;
		menu();
		scanf("%d",&n);
		switch (n)
		{
		case 1: init(&p); break;
		case 2: rudui(&p); break;
		case 3: chudui(&p); break;
		case 4: chazhao(&p); break;
		case 5: bianli(&p); break;
		case 6: xiaohui(&p); break;
		case 0: printf("退出操作"); return 0;
		}
	}
	return 0;
}
