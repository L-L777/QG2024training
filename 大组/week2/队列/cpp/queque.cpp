#include"queque.h"
void init(qq* p)
{
	p->head = (dl*)malloc(sizeof(dl));
	p->tail = p->head;
	p->l = 0;
	printf("���г�ʼ���ɹ�\n");
}
void rudui(qq* p)
{
	while (1)
	{
		printf("ֹͣ��������0����������������һ������������:");
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		printf("���������������е�Ԫ�أ�");
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
		printf("�ö���Ϊ�գ��޷�����\n");
		return;
	}
	dl* a;
	a = p->head->next;
	printf("�˴γ���Ԫ��Ϊ%d\n", a->date);
	p->head ->next= a->next;
	p->l--;
	free(a);
}
void chazhao(qq* p)
{
	printf("����������Ҷ����еڼ���Ԫ�أ�");
	int b;
	scanf("%d", &b);
	if (b > p->l)
	{
		printf("�ö��г��Ȳ�����û��������ҵ�����\n");
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
		printf("������ҵ�Ԫ�أ�%d\n", a->date);
	}
}
void bianli(qq* p)
{
	if (p->l == 0)
	{
		printf("�ö���Ϊ�գ��޷�����\n");
		return;
	}
	dl* a = (dl*)malloc(sizeof(dl));
	a = p->head;
	for (int i = 1; i <= p->l; i++)
	{
		a = a->next;
		printf("�ö����е�%d��Ԫ��Ϊ��%d\n", i, a->date);
	}
}
void xiaohui(qq* p)
{
	p->tail = p->head;
	p->tail->next = NULL;
	p->l = 0;
	printf("���ٳɹ�\n");
}
void menu()
{
	printf("=======================\n");
	printf("��ʼ������������1\n");
	printf("�����������2\n");
	printf("������������3\n");
	printf("���Ҷ���Ԫ��������4\n");
	printf("��������������5\n");
	printf("���ٶ���������6\n");
	printf("�˳�������0\n");
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
		case 0: printf("�˳�����"); return 0;
		}
	}
	return 0;
}
