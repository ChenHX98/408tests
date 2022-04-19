#pragma once
void q1(Node* p, int deletenumber) {
	if (p == nullptr) {
		return;
	}
	else {
		q1(p->next, deletenumber);
		if (p->data == deletenumber) {
			Node* q = p->next;
			p->data = q->data;
			p->next = q->next;
			delete q;
		}
	}
	
	//这个算法第一个数删不掉
	/*if (p == nullptr) {
		return;
	}
	else if (p->next == nullptr) {
		return;
	}
	else {
		q1(p->next, deletenumber);
		if (p->next->data == deletenumber) {
			Node* q = p->next;
			p->next = p->next->next;
			delete q;
		}
	}*/
	
}