#pragma once
#include<random>
#include<iostream>
struct Node {
	int data;
	Node* next;
	Node* pre;
};

class SqList {	
public:
	int length;
	int* data;
	SqList();
	SqList(int);
	void RunTest(void (*test)(SqList s,int length));
	void RunTest(void (*test)(int* s, int length));
	void output();
};

class LinkListWithHead {
public:
	int length;
	Node *head,*tail;
	LinkListWithHead();
	LinkListWithHead(int);
	void RunTest(void (*test)(LinkListWithHead s, int length));
	void RunTest(void (*test)(Node* s, int length));
	void output();
};

