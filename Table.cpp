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
  Table tb;         //新建一张表 
  tb.show();        //show 表 
  tb.addRow();      //加入一行 
  tb.show();        //show 表 
  tb.addColumn();   //加入一列 
  tb.show();        //show 
  Table tb1(5,5);   //新建一张5*5的表 
  tb1.show();       
  tb1.set(1,1,30);  //（1,1）->30 
  tb1.set(2,2,"hello");  //
  tb1.show();       //show 
  tb1.delRow(1);    //删除第一行 
  tb1.show();       //show 
  tb1.delColumn(1); //删除第一列 
  tb1.show();
  return 0;
}
