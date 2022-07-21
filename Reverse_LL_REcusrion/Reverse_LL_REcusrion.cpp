// Reverse_LL_REcusrion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
using namespace std;

Node* reverseLL(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node* smallAns = reverseLL(head->next);

	Node* temp = smallAns;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = head;
	head->next = NULL;
	return smallAns;
}

Node* takeInput_Better() {
	int data;
	cin >> data;
	Node* head = NULL;
	Node* tail = NULL;
	while (data != -1) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
			// OR
			// tail = newNode;
		}

		cin >> data;
	}
	return head;
}


void print(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node* head = takeInput_Better();
	head = reverseLL(head);
	print(head);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
