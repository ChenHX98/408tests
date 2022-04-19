#include"node.h"
using namespace std;
void SqList::init() {
	this->init(10);
}

void SqList::init(int c) {
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

void SqList::sort(bool direction) {
	if (direction) {
		for (int i = 0; i < this->length; i++) {
			for (int j = i; j < this->length; j++) {
				if (this->data[i] > this->data[j]) {
					int d = this->data[i];
					this->data[i] = this->data[j];
					this->data[j] = d;
				}
			}

		}
	}
	else {
		for (int i = 0; i < this->length; i++) {
			for (int j = i; j < this->length; j++) {
				if (this->data[i] < this->data[j]) {
					int d = this->data[i];
					this->data[i] = this->data[j];
					this->data[j] = d;
				}
			}

		}
	}

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


void LinkListWithHead::init() {
	this->init(10);
}

void LinkListWithHead::init(int c) {
	//cout << "!!!!!";
	this->head = new Node;
	this->head->next = nullptr;
	this->head->pre = nullptr;
	this->tail = this->head;
	this->length = c;
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

void LinkListWithoutHead::init() {
	this->init(10);
}
void LinkListWithoutHead::init(int c) {
	//cout << "!!!!!";
	this->head = nullptr;
	this->tail = this->head;
	this->length = c;
	default_random_engine e;
	for (int i = 0; i < c; i++) {
		int data = e() % (c * 3);
		bool repeat = false;
		for (Node* j = this->head; j != nullptr; j = j->next) {
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
			p->pre = nullptr;
			if (head==nullptr) {
				head = tail = p;
			}
			else {
				tail->next = p;
				p->pre = tail;
				tail = p;
			}
			
		}
	}
}

void LinkListWithoutHead::orderedInit(int c) {
	this->head = nullptr;
	this->tail = this->head;
	this->length = c;
	for (int i = 0; i < c; i++) {
		Node* p = new Node;
		p->data = i;
		p->next = nullptr;
		p->pre = nullptr;
		if (head == nullptr) {
			head = tail = p;
		}
		else {
			tail->next = p;
			p->pre = tail;
			tail = p;
		}
	}
	
}
void LinkListWithoutHead::output() {
	Node* now = this->head;
	while (now != nullptr) {
		cout << now->data << "\t";
		now = now->next;
	}
	cout << endl;
}

void LinkListWithoutHead::RunTest(void (*test)(LinkListWithoutHead s, int length)) {
	test(*this, this->length);
}

void LinkListWithoutHead::RunTest(void (*test)(Node* s, int length)) {
	test(this->head, this->length);
}

void LinkListWithoutHead::TestDelete(void (*test)(Node* s, int toDelete), int toDelete) {
	test(this->head, toDelete);
}