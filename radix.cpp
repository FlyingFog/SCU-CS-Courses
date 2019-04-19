#include<iostream>
#include<stack>
using namespace std;

class Number{
private:
	int num , radix;
	stack<int >s; 
public:
	Number(int n,int r){
		num = n;
		radix = r;
		while(s.size()) s.pop();
	}
	
	Number converto(int r){
		int n = num;
		while(n){
			int cur = n%r;
			s.push(cur);
			n/=r;
		}
	return *this;
	}
	
	void show(){
		while(s.size()){
			cout<<s.top();
			s.pop();
		}
	cout<<endl;
	}
};

int main() {
    int n, n1, n2;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2;
        Number no1(n1, 10);     //n1是10进制正整数
        Number no3 = no1.converto(n2);  //no3是n2进制的正整数
        no3.show();     //输出结果
    }
	return 0;
}

