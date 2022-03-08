#include<iostream>
using namespace std;

class Number{
private:
	int num;
public:
	Number(int n){
		this->num = n;
	}
	Number maxDivisor(Number no){
		int a = num, b = no.num, t;
		
		while(b){
			t = b;
			b = a%b;
			a = t;
		}
	return Number(a);
	}
	void show(){
		cout<<num<<endl;
	}
};


int main() {
    int n, n1, n2;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2;
        Number no1(n1), no2(n2);
        Number no3 = no1.maxDivisor(no2);  //最大公约数
        no3.show();
    }
	return 0;
}

