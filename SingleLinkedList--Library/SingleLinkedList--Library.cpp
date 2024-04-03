
#include<iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node* prev;
};

void InsertInBeginng(Node*& head, int value) {
	Node* new_Node = new Node();
	new_Node->value = value;
	new_Node->next = head;
	head = new_Node;
}

    

Node* Find(int value, Node * head) {

	while (head != NULL) {
		if (head->value == value) {
			return head;
		}
		head = head->next;
	}
	return NULL;
}

void InsterAfter(Node * prv_Node, int value) {
	if (prv_Node == NULL) {
		cout << "Node is NULL";
		return;
	}
	Node* new_Node = new Node();
	new_Node->value = value;
	new_Node->next = prv_Node->next;
	prv_Node->next = new_Node;
}

void InsertAtEnd(int value, Node * &head) {
	Node* last = new Node();
	last->value = value;
	last->next = NULL;
	if (head == NULL) {
		head = last;
		return;
	}
	Node* lastnode = head;
	while (lastnode->next != NULL) {
		lastnode = lastnode->next;
	}
	lastnode->next = last;


}

void PrintList(Node * head) {

	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
}

void DeleteNode(Node * &head, int value) {

	Node* Currently = head; Node* prev = head;
	if (head == NULL) {
		return;
	}
	if (Currently->value == value) {
		head = head->next;
		delete Currently;
	}
	while (Currently != NULL && Currently->value != value) {
		prev = Currently;
		Currently = Currently->next;
	}
	if (Currently == NULL) {
		return;
	}
	prev->next = Currently->next;
	delete Currently;


}

void DeleteFisrtNode(Node * &head) {
	Node* First = head;
	if (head == NULL) {
		return;
	}
	head = head->next;
	delete First;
}

void DeleteLastNode(Node * &head) {
	if (head == NULL) {
		return;
	}
	Node* last = head;
	Node* last1 = head;
	if (last->next == NULL) {
		head = NULL;
		delete last;
		return;
	}
	while (last->next != NULL) {
		last1 = last;
		last = last->next;
	}
	last1->next = NULL;
	delete last;

}

