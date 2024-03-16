#include"../Header/header.h"
void menu()//菜单 
{
	cout << "=======================" << endl;
	cout << "增加数据请输入1" << endl;
	cout << "显示链表数据请输入2" << endl;
	cout << "查找节点请输入3" << endl;
	cout << "插入数据请输入4" << endl;
	cout << "删除节点请输入5" << endl;
	cout << "销毁链表请输入6" << endl;
	cout << "查找链表中点请输入7" << endl;
	cout << "链表奇偶反转请输入8" << endl;
	cout << "判断链表是否成环请输入9" << endl;
	cout << "反转链表请输入10" << endl;
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
void middle()//查找中点 
{
	if(l==0){
		cout<<"该链表为空"<<endl;
		return; 
	}else if(l%2==1){//奇数个节点 
		int n=l/2+1;
		p=head;
		for(int i=0;i<n;i++){
			p=p->next;
		}
		cout<<"中点是："<<n<<endl;
		cout<<"中点的数据是："<<p->data<<endl;
	}else{//偶数个节点 
		int n=l/2;
		p=head;
		 for(int i=0;i<n;i++){
			p=p->next;
		}
		cout<<"目前链表有偶数个节点"<<endl;
		cout<<"第一个中点为："<<n<<" "<<"数据是："<<p->data<<endl;
		p=p->next;
		 cout<<"第二个中点为："<<n+1<<" "<<"数据是："<<p->data<<endl;
	} 
} 
void change()//奇偶反转
{
	if(l<2){
		cout<<"该链表长度小于2，无法反转"<<endl;
		return; 
	}
	else{
		int n=l/2;
		p=head;
		for(int i=0;i<n;i++){
			p=p->next;
			string t;
			t=p->data;
			Link *s;
			s=p->next;
			p->data=s->data;
			p=p->next;
			p->data=t;
		}
		cout<<"反转成功"<<endl;
		cout<<"结果为：";
		show();
	}
 } 
 void checkCycle()//判断是否成环
 {
 	if (l==0) {
 		cout<<"该链表长度为0"<<endl; 
        return ;
    }

    Link* slow = head;
    Link* fast = head;
int flag=1; //标记 
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout<<"该链表存在环"<<endl; // 链表存在环
            flag=0;//改为0 
            return;
        }
    }
    if(flag==1){
        	cout<<"该链表不存在环"<<endl;
	}
    
  } 
  void reverse()//反转链表
  {
  	if(l==0){
  		cout<<"该链表为空"<<endl;
  		return;
	  }
  	Link* prev = NULL;
    Link* s = head;

    while (s != NULL) {
        Link* temp = s->next;
        s->next = prev;
        prev = s;
        s = temp;
    }
    head->next=prev;
    cout<<"反转成功"<<endl; 
    show();
   } 
int main(){
	head=new node;
	tail=head;//自动初始化链表 
	int n;
	while(1){
	cout<<endl;
	cout<<"       单链表"<<endl; 
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
	case 7: middle();  break;
	case 8: change();  break;
	case 9: checkCycle();  break;
	case 10: reverse();  break;
	case 0:  cout << "退出成功，感谢您的使用";  return 0;
	}
	
	}
}
