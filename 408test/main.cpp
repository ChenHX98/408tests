#include<iostream>
#include<stdio.h>
#include"node.h"
#include"2.3.7.h"
#include"2.2.3.h"
using namespace std;

int main() {
	cout << "hello world" << endl;
	SqList a;
	a.init(9);
	a.sort();
	a.output();
	SqList b;
	b.init(9);
	b.sort();
	b.output();
	//2.2.3,11Ìâ
	/*SqList a;
	a.init();
	q10_swap(a.data, a.length, 5);
	a.output();*/
	
}
