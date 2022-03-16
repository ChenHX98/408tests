#include"node.h"
using namespace std;
SqList::SqList() {
	new (this)SqList(10);
}

SqList::SqList(int c) {
	default_random_engine e;
	this->length = c;
	this->data = new int[c];
	for (int i = 0; i < c; i++) {
		int data = e() % (c*3);
		bool repeat = false;
		for (int j = 0; j < i; j++) {
			if (this->data[j] == data)
				repeat = true;
		}
		if (repeat) {
			i--;
		}
		else {
			this->data[i] = data;
		}
	}
	for (int i = 0; i < c; i++) {
		cout << this->data[i] << "\t";
	}
	cout << endl;
}

void SqList::RunTest(void (*test)(SqList s, int length)) {
	test(*this, this->length);
}
void SqList::RunTest(void (*test)(int* s, int length)) {
	test(this->data, this->length);
}

void SqList::output() {
	for (int i = 0; i < length; i++) {
		cout << this->data[i] << "\t";
	}
	cout << endl;
}

LinkListWithHead::LinkListWithHead() {
	new (this)LinkListWithHead(10);
}
LinkListWithHead::LinkListWithHead(int c) {
	//cout << "!!!!!";
	this->head = new Node;
	this->head->next = nullptr;
	this->head->pre = nullptr;
	this->tail = this->head;
	default_random_engine e;
	for (int i = 0; i < c; i++) {
		int data = e() % (c * 3);
		bool repeat = false;
		for (Node* j = this->head->next; j != nullptr; j = j->next) {
			if (j->data == data) {
				repeat = true;
				break;
			}
						
		}
		if (repeat) {
			i--;
		}
		else {
			Node* p = new Node;
			p->data = data;
			p->next = nullptr;
			p->pre = this->tail;
			p->pre->next = p;
			this->tail = this->tail->next;
		}
	}
}
void LinkListWithHead::output() {
	Node* now = this->head;
	while (now->next != nullptr) {
		cout << now->next->data << "\t";
		now = now->next;
	}
	cout << endl;
}

void LinkListWithHead::RunTest(void (*test)(LinkListWithHead s, int length)) {
	test(*this, this->length);
}
void LinkListWithHead::RunTest(void (*test)(Node* s, int length)) {
	test(this->head, this->length);
}