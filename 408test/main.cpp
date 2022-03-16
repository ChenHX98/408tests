#include<iostream>
#include<stdio.h>
#include"node.h"
using namespace std;

void test(SqList s, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (s.data[i] <= s.data[j]) {
				int t = s.data[i];
				s.data[i] = s.data[j];
				s.data[j] = t;
			}
		}
	}
}
int main() {
	cout << "hello world" << endl;
	LinkListWithHead s;
	//s.RunTest(test);
	s.output();
}
