#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head, * tail;

// 첫번째 노드 추가
void addFrontNode(int n) {
	Node* temp = new Node;
	temp->data = n;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}

}
// 마지막 노드 추가
void addNode(int n) {
	Node* temp = new Node;
	temp->data = n;
	temp->next = NULL;
	
	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}


}
//노드 삽입
void insertNode(Node* prevNode, int n) {
	Node* temp = new Node;
	temp->data = n;

	temp->next = prevNode->next;
	prevNode->next = temp;

}
//node 삭제
void deleteNode(int val) {
	if (head == NULL) {
		cout << "Empty list" << "\n";
		return;
	}

	// 삭제노드가 head 인 경우
	if (head->data == val) {
		Node* temp = head;
		head = temp->next;
		delete temp;
		return;
	}

	//탐색
	Node* temp = head;
	while (temp->next && temp->next->data != val) {
		temp = temp->next;
	}

	if (!temp->next) {
		cout << "Node not found" << "\n";
		return;
	}

	Node* deleteNode = temp->next;
	temp->next = temp->next->next;
	delete deleteNode;

}

void Print(Node* head) {
	if (head == NULL) {
		cout << "\n";
	}
	else {
		cout << head->data << " ";
		Print(head->next);
	}
}


int main() {
	addNode(4);
	addNode(5);
	addNode(6);

	addFrontNode(1);

	deleteNode(4);

	Print(head);
	


	return 0;
}