#include"../Header/Headers.h"
void menu()//�˵� 
{
	cout << "=======================" << endl;
	cout << "��������������1" << endl;
	cout << "��ʾ��������������2" << endl;
	cout << "���ҽڵ�������3" << endl;
	cout << "��������������4" << endl;
	cout << "ɾ���ڵ�������5" << endl;
	cout << "��������������6" << endl;
	cout << "�����밴0�������ַ������ֳ��⣩" << endl;
	cout << "=======================" << endl;
}
void add()//�������� 
{
	cout<<"���������ӵ�����:" ; 
	string x;
	cin>>x;
	p=new node;//�����½ڵ� 
	p->data=x;
	l++;
	p->next=NULL; 
	p->prev=tail;
	tail->next=p;
	tail=p;
} 
void show()//��ʾ�������� 
{
	if(l==0){
		cout<<"������Ϊ��"<<endl;
		return;
	}//�ж��Ƿ�������� 
	p=head->next;
	for(int i=0;i<l;i++){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
} 
void find()//���ҽڵ� 
{
	cout<<"��Ҫ���ҵڼ��ڵ㣺";
	int x;
	cin>>x;
	if(x>l){
		cout<<"��Ǹ����������û�иýڵ�"<<endl;
		return; //�ж��Ƿ���ڸýڵ� 
	}else{
		p=head;
		for(int i=0;i<x;i++){
			p=p->next; 
		}
		cout<<p->data<<endl;
	}
}
void insert()//��������
{
	int n;
	cout<<"��Ҫ�嵽�ڼ��ڵ�֮��" ;
cin>>n;
	if(n>l){
		cout<<"��Ǹ��������Ŀǰû�иýڵ�"<<endl;
		return;//�ж��Ƿ���ڸýڵ� 
	}else{
		string x;
		cout<<"��������Ҫ��������ݣ�";
		cin>>x;
		p=head;
		for(int i=0;i<n;i++){
			p=p->next;
		}
		Link *s;
		s=new node;
		s->data=x;
		s->next=p->next;
		s->prev=p;
		p->next=s;
		l++;
	}
 } 
 void deleteData()//ɾ��ĳ���ڵ�
 {
 	int n;
 		cout<<"��������Ҫɾ���Ľڵ㣺" ;
	cin>>n;
	if(n>l){
		cout<<"��Ǹ��������Ŀǰû�иýڵ�"<<endl;
		return;//�ж��Ƿ���ڸýڵ� 
	}
	else{
		p=head;
		for(int i=0;i<n-1;i++){
			p=p->next;
		}
		Link *s;
		s=p->next;
		s->prev=p->prev;
		p->next=s->next;
		l--;
	} 
	cout<<endl;
  } 
void destroy()//�������� 
{
	head->next=NULL;
	head=new node;
	tail=head; 
	l=0; 
	cout<<"���ٳɹ�"<<endl;
}
int main(){
	head=new node;
	tail=head;//�Զ���ʼ������ 
	int n;
	while(1){
	cout<<endl;
	cout<<"       ˫����"<<endl; 
		menu();
		cout<<"������������Ĳ�����"<<endl;
		cin >> n;
		system("cls");
	switch (n)
	{
	case 1: add();  break;
	case 2: show();  break;
	case 3: find();  break;
	case 4: insert();  break;
	case 5: deleteData();  break;
	case 6: destroy();  break;
	case 0:  cout << "�˳��ɹ�����л����ʹ��";  return 0;
	}
	
	}
}
