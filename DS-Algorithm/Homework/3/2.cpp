#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define Template template<class ElemType>

Template
struct Node{
    ElemType data;
    Node<ElemType> *next;
    Node();
	Node(ElemType item , Node<ElemType>*link=NULL); 
}; 

//Node ���캯�� 
Template
Node<ElemType>::Node(){
	next = NULL;
}
Template
Node<ElemType>::Node(ElemType item , Node<ElemType>*link){
	data = item;
	next = link;
}

//define ������                   
Template
class LinkList{
	protected:
		Node<ElemType>*head;
	    void init();
	public:
	    LinkList();
		virtual ~LinkList();
		void MakeList(int n);
		void PrintList();
		Node<ElemType>*Locate(int pos);  
		Node<ElemType>*max();         
		int number(ElemType &x);
		void create(ElemType *a, int n);
		void tidyup();  
};          
//���幹�캯��  �� ���������� 
Template 
void LinkList<ElemType>::init(){
	head = new Node<ElemType>;
}
Template 
LinkList<ElemType>::LinkList(){
	init();
}

Template 
void LinkList<ElemType>::MakeList(int n){
	init();
	int cnt = 0;
	Node<ElemType>*p = head;
	while(cnt < n){
        Node<ElemType>*q = new Node<ElemType>;
		p->next = q;
		cin>>q->data;
		p = q;
		cnt++;		
	}
}

//������������ 
Template
LinkList<ElemType>::~LinkList(){
	delete head;
}

//��ӡ������ 
Template 
void LinkList<ElemType>::PrintList(){
	Node<ElemType>*p = head;
	while((p=p->next) != NULL){
		cout<<p->data<<" ";
	}
	puts("");
}
         
//Locate         
Template             
Node<ElemType>*LinkList<ElemType>::Locate(int pos){
	if(pos <= 0)return NULL;
	Node<ElemType>*p = head;
	int k = 0;
	while(p != NULL && k<pos){
		p = p->next;
		k++;
	}
	if(p != NULL && k == pos){
		return p;
	}else {
		return NULL;
	}
} 

//
Template             
Node<ElemType>*LinkList<ElemType>::max(){
	if(head->next == NULL) return NULL;
	Node<ElemType>*pmax = head->next , *p = (head->next)->next; 
	while(p!=NULL){
		if(p->data > pmax->data)pmax = p;
		p = p->next;
	}
	return pmax;
}

//
Template             
int LinkList<ElemType>::number(ElemType &x){
     int n = 0;
     Node<ElemType>*p = head->next;
     while(p!=NULL){
     	if(p->data == x)n++;
     	p = p->next;
	 }
     return n;
}

//
Template             
void LinkList<ElemType>::create(ElemType *a, int n){
     Node<ElemType>*p = head;
	 for(int i=0 ;i < n; i++){
	 	p->next = new Node<ElemType>(a[i]);
	 	p = p->next;
	 }
	 p->next = NULL; 
}

//
Template             
void LinkList<ElemType>::tidyup(){
    Node<ElemType>*p = head->next , *tep;
    while(p!=NULL && p->next!=NULL)
	if(p->data == p->next->data){
    	tep = p->next;
    	p->next = tep->next;
    	delete tep;
	}
    else p = p->next;   
}

// main and test 
int main(){
	int str[5] = {3,4,5,6,7}, x,n,pos;//������֪���� 
	LinkList<int > a,b;
	cout<<"������Ҫ�������б�ĳ��� ���������Ԫ��: ";
	cin>>n;
	a.MakeList(n);
	cout<<"��ӡ�ղ����������";
	a.PrintList();
    cout<<"������Ҫ���ҵ�λ��pos��";
    cin>>pos; 
	cout<<"��λ��Ԫ�ص�ַ ֵ�� "<<a.Locate(pos)<<" "<<(a.Locate(pos)->data)<<endl;
	cout<<"����Ԫ�ص�ַ ֵ�� "<<a.max()<<" "<<(a.max()->data)<<endl;
	cout<<"������Ҫ���ҵ�Ԫ��x��ֵ��";
	cin>>x;
	cout<<"xԪ�صĸ����� "<<a.number(x)<<endl;
   
	b.create(str , 5);
	cout<<"create����������ԣ�" ;
	b.PrintList();
	
	a.tidyup();
	cout<<"tidyup����������ԣ�" ;
	a.PrintList();
	return 0;
}

