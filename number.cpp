#include <iostream>
using namespace std;


const char Num[7][70]={{"*****      *  *****  *****  *   *  *****  *****  *****  *****  *****"},
{"*   *      *      *      *  *   *  *      *          *  *   *  *   *"},
{"*   *      *      *      *  *   *  *      *          *  *   *  *   *"},
{"*   *      *  *****  *****  *****  *****  *****      *  *****  *****"},
{"*   *      *  *          *      *      *  *   *      *  *   *      *"},
{"*   *      *  *          *      *      *  *   *      *  *   *      *"},
{"*****      *  *****  *****      *  *****  *****      *  *****  *****"}};


class DotArray{   //点阵对象
    const int maxcol, maxrow;
public:
	DotArray(int n,int m):maxcol(n),maxrow(m){}
    virtual void showrow(int i) const{};
};

class DA : public DotArray {   //0的点阵
	int num;
	int st,ed;
	int cur;
public:
	DA(int n):DotArray(5,7),num(n),cur(0){
		st=n*7; 
		ed=st+4;
	}
    virtual void showrow(int i) const;
};

void DA::showrow(int cur) const{
	for(int i=st ;i<=ed ;i++)
	std::cout<<Num[cur][i]; 
}

//其它数字点阵类自己补充

///////////////////////////////////////

class DAPrinter {
private:
    const int num;
    DotArray *das[4]; //最多4个点阵对象
	int tot;
public:
	DAPrinter(int n):num(n),tot(0){};
    void split();
    void print();
    void reset();
};

void DAPrinter::split(){
	int tem = num;
	while(tem){
		das[tot++] = new DA(tem%10);
		tem/=10;
	}
}

void DAPrinter::print(){
	cout<<num<<":"<<endl;
	for(int j=0 ;j<7 ;j++){
	  	for(int i=tot-1; i>=0 ;i--){
			das[i]->showrow(j);
			cout<<"  ";
		}
	cout<<endl;
	}
}
void DAPrinter::reset(){
	tot = 0;
}

int main() {
	/*
	for(int i=0 ;i<=7 ;i++){
		std::cout<<num[i]<<std::endl;
	}
	*/
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        int n1;
		std::cin >> n1;
        DAPrinter p(n1);
		p.split();
        p.print();
    }
    return 0;
}


