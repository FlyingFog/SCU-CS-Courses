#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#include<string>
using namespace std;

class Cell{
public:
  Cell(){
  	content = "";
  }	
  Cell(char con[]){
  	content = con;
  }
  ~Cell(){
  };
  void show();
private:
  string content;
};

void Cell::show(){ 
	cout<< setw(10) <<content<<"  |";
}

class Table{
public: 
  Table(){
  	r = c = 0;
  }
  Table(int rr,int cc){
    r = rr;
    c = cc;
  };
  ~Table(){
  };
  void show();
  void set(int r , int c ,int con);
  void set(int r , int c ,char con[]);
  int addRow();
  void delRow(int n);
  int addColumn();
  void delColumn(int n);
private:
  int r,c;
  Cell cells[100][100];
};

void Table::show(){
	for(int i=1 ;i<=r ;i++){
	cout<<i<<" |";   
	   for(int j=1 ;j<=c ;j++){
	   	cells[i][j].show();
	   }
	cout<<endl;
	}
	cout<<"-----end show------"<<endl;
}

void Table::set(int r , int c ,char con[]){
	cells[r][c] = con;
}

void Table::set(int r , int c ,int con){
	char t[255];
    sprintf(t, "%d", con);
	set(r,c,t);
}

int Table::addRow(){
	return r = r + 1;
}
void Table::delRow(int n){
	for(int i=n ;i<=r-1 ;i++)
		for(int j=1 ;j<=c ;j++)
		cells[i][j] = cells[i+1][j];
	r--;
}

int Table::addColumn(){
	return c = c + 1;
}

void Table::delColumn(int n){
	for(int i=n ;i<=c-1 ;i++)
		for(int j=1 ;j<=r ;j++)
		cells[j][i] = cells[j][i+1];
	c--;
}


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
