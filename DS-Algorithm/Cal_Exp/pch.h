
#ifndef PCH_H
#define PCH_H

#include<iostream>
#include<string>
#include<cstdlib>
#include<stack>
using namespace std;

// TODO: ���Ҫ�ڴ˴�Ԥ����ı�ͷ
class calculator {
private:
	string expression;
	stack<double >opnd;  //������
	stack<char>optr;     //������
public:
	calculator();
	~calculator();
	bool read();
	void clear();
	int judgePri(char a, char b);
	double calTwoNum(double a, char c, double b);
	void cal();
};


#endif //PCH_H