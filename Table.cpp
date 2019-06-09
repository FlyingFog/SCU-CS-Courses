#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class Cell{
public:
  Cell(char con[]);
  ~Cell();
  void show();
private:
  string content;
}

Cell::Cell(char con[]){
	content = con;
}

void Cell::show(){
	cout<<content<<endl;
}

class Table {
public: 
  Table();
  Table(int r,int c);
  void show();
  int addRow();
  void delRow(int n);
  int addColumn();
  void delColumn(int n);
private:
  Cell cells;
};


int main() {
  Table tb;         //�½�һ�ű� 
  tb.show();        //show �� 
  tb.addRow();      //����һ�� 
  tb.show();        //show �� 
  tb.addColumn();   //����һ�� 
  tb.show();        //show 
  Table tb1(5,5);   //�½�һ��5*5�ı� 
  tb1.show();       
  tb1.set(1,1,30);  //��1,1��->30 
  tb1.set(2,2,"hello");  //
  tb1.show();       //show 
  tb1.delRow(1);    //ɾ����һ�� 
  tb1.show();       //show 
  tb1.delColumn(1); //ɾ����һ�� 
  tb1.show();
  return 0;
}
