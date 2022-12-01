#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void push(Node** head, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
}

int detectLoop(Node* list) {
	Node* slow_p = list;
	Node* fast_p = list;

	while (slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p) {
			return 1;
		}
	}

	return 0;
}


int main() {
	Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	/* Create a loop for testing */
	head->next->next->next->next = head;
	if (detectLoop(head))
		cout << "Loop Found";
	else
		cout << "No Loop";

	return 0;
}
