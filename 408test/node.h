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
	void init();
	void init(int);
	void sort(bool direction=true);
	void RunTest(void (*test)(SqList s,int length));
	void RunTest(void (*test)(int* s, int length));
	void output();
};

class LinkListWithHead {
public:
	int length;
	Node *head,*tail;
	void init();
	void init(int);
	void RunTest(void (*test)(LinkListWithHead s, int length));
	void RunTest(void (*test)(Node* s, int length));
	void output();
};

class LinkListWithoutHead {
public:
	int length;
	Node* head, * tail;
	void init();
	void init(int);
	void orderedInit(int);
	void RunTest(void (*test)(LinkListWithoutHead s, int length));
	void RunTest(void (*test)(Node* s, int length));
	void TestDelete(void (*test)(Node* s, int toDelete), int toDelete);
	void output();
};
