#include"../Header/header.h"
void menu()//�˵� 
{
	cout << "=======================" << endl;
	cout << "��������������1" << endl;
	cout << "��ʾ��������������2" << endl;
	cout << "���ҽڵ�������3" << endl;
	cout << "��������������4" << endl;
	cout << "ɾ���ڵ�������5" << endl;
	cout << "��������������6" << endl;
	cout << "���������е�������7" << endl;
	cout << "������ż��ת������8" << endl;
	cout << "�ж������Ƿ�ɻ�������9" << endl;
	cout << "��ת����������10" << endl;
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
void middle()//�����е� 
{
	if(l==0){
		cout<<"������Ϊ��"<<endl;
		return; 
	}else if(l%2==1){//�������ڵ� 
		int n=l/2+1;
		p=head;
		for(int i=0;i<n;i++){
			p=p->next;
		}
		cout<<"�е��ǣ�"<<n<<endl;
		cout<<"�е�������ǣ�"<<p->data<<endl;
	}else{//ż�����ڵ� 
		int n=l/2;
		p=head;
		 for(int i=0;i<n;i++){
			p=p->next;
		}
		cout<<"Ŀǰ������ż�����ڵ�"<<endl;
		cout<<"��һ���е�Ϊ��"<<n<<" "<<"�����ǣ�"<<p->data<<endl;
		p=p->next;
		 cout<<"�ڶ����е�Ϊ��"<<n+1<<" "<<"�����ǣ�"<<p->data<<endl;
	} 
} 
void change()//��ż��ת
{
	if(l<2){
		cout<<"��������С��2���޷���ת"<<endl;
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
		cout<<"��ת�ɹ�"<<endl;
		cout<<"���Ϊ��";
		show();
	}
 } 
 void checkCycle()//�ж��Ƿ�ɻ�
 {
 	if (l==0) {
 		cout<<"��������Ϊ0"<<endl; 
        return ;
    }

    Link* slow = head;
    Link* fast = head;
int flag=1; //��� 
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout<<"��������ڻ�"<<endl; // ������ڻ�
            flag=0;//��Ϊ0 
            return;
        }
    }
    if(flag==1){
        	cout<<"���������ڻ�"<<endl;
	}
    
  } 
  void reverse()//��ת����
  {
  	if(l==0){
  		cout<<"������Ϊ��"<<endl;
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
    cout<<"��ת�ɹ�"<<endl; 
    show();
   } 
int main(){
	head=new node;
	tail=head;//�Զ���ʼ������ 
	int n;
	while(1){
	cout<<endl;
	cout<<"       ������"<<endl; 
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
	case 7: middle();  break;
	case 8: change();  break;
	case 9: checkCycle();  break;
	case 10: reverse();  break;
	case 0:  cout << "�˳��ɹ�����л����ʹ��";  return 0;
	}
	
	}
}
