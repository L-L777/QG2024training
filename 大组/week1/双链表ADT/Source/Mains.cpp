#include"../Header/Headers.h"
void menu()//菜单 
{
	cout << "=======================" << endl;
	cout << "增加数据请输入1" << endl;
	cout << "显示链表数据请输入2" << endl;
	cout << "查找节点请输入3" << endl;
	cout << "插入数据请输入4" << endl;
	cout << "删除节点请输入5" << endl;
	cout << "销毁链表请输入6" << endl;
	cout << "结束请按0或其他字符（数字除外）" << endl;
	cout << "=======================" << endl;
}
void add()//增加数据 
{
	cout<<"请输入增加的数据:" ; 
	string x;
	cin>>x;
	p=new node;//创建新节点 
	p->data=x;
	l++;
	p->next=NULL; 
	p->prev=tail;
	tail->next=p;
	tail=p;
} 
void show()//显示链表数据 
{
	if(l==0){
		cout<<"该链表为空"<<endl;
		return;
	}//判断是否存在链表 
	p=head->next;
	for(int i=0;i<l;i++){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
} 
void find()//查找节点 
{
	cout<<"您要查找第几节点：";
	int x;
	cin>>x;
	if(x>l){
		cout<<"抱歉，该链表中没有该节点"<<endl;
		return; //判断是否存在该节点 
	}else{
		p=head;
		for(int i=0;i<x;i++){
			p=p->next; 
		}
		cout<<p->data<<endl;
	}
}
void insert()//插入数据
{
	int n;
	cout<<"您要插到第几节点之后：" ;
cin>>n;
	if(n>l){
		cout<<"抱歉，该链表目前没有该节点"<<endl;
		return;//判断是否存在该节点 
	}else{
		string x;
		cout<<"请输入您要插入的数据：";
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
 void deleteData()//删除某个节点
 {
 	int n;
 		cout<<"请输入您要删除的节点：" ;
	cin>>n;
	if(n>l){
		cout<<"抱歉，该链表目前没有该节点"<<endl;
		return;//判断是否存在该节点 
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
void destroy()//销毁链表 
{
	head->next=NULL;
	head=new node;
	tail=head; 
	l=0; 
	cout<<"销毁成功"<<endl;
}
int main(){
	head=new node;
	tail=head;//自动初始化链表 
	int n;
	while(1){
	cout<<endl;
	cout<<"       双链表"<<endl; 
		menu();
		cout<<"请输入您所需的操作："<<endl;
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
	case 0:  cout << "退出成功，感谢您的使用";  return 0;
	}
	
	}
}
