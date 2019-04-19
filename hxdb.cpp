#include<iostream>
using namespace std;

class HanXin{
private:
	int n,n3,n5,n7;
public:
	HanXin(){
		n=0;
	}
	void line3(int n){
		n3 = n;
	}
	void line5(int n){
		n5 = n;
	}
	void line7(int n){
		n7 = n;
	}
	void showMany(){
		int i;
		for(i=10 ;i<=100 ; i++){
			if(i%3==n3 && i%5==n5 && i%7==n7){
				n = i;
				break;
			}
		}
		if(n==0)cout<<"Impossible"<<endl;
		else cout<<n<<endl;
	}
};

int main() {
    int n, n1, n2,n3;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2 >> n3;
        HanXin hx;  //韩信
        hx.line3(n1);  //3人一排
        hx.line5(n2);   //5人一排
        hx.line7(n3);   //7人一排
        hx.showMany();
    }
	return 0;
}

