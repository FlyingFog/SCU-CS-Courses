#include "pch.h"
#include <iostream>

int main() {
	calculator Cal;
	cout << "***********��ӭʹ�ü򵥵ı��ʽ������************" << endl;
	cout << "                �밴����ʾ����   " << endl;
	cout << "              ��Ҫ�˳�������exit" << endl;
	cout << endl;
	try {
		 Cal.cal();
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
}
