#include <bits/stdc++.h> 
#include <inttypes.h> 
using namespace std; 

class Node { 
	public: 
    	int data; 
    	Node* link; 
}; 

Node* XOR (Node *a, Node *b) { 
	return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
} 

void insertBeginning(Node **head_ref, int data) { 
	Node *new_node = new Node(); 
	new_node->data = data; 

	new_node->link = *head_ref; 

	if (*head_ref != NULL) 
	{ 
		(*head_ref)->link = XOR(new_node, (*head_ref)->link); 
	} 

	*head_ref = new_node; 
} 

void insertEnd(Node **head_ref, int data) {
    Node *new_node = new Node(); 
	new_node->data = data;
    Node *curr = *head_ref;
    Node *prev = NULL;
    Node *next;
    while(curr != NULL){
        next = XOR (prev, curr->link); 
        prev = curr;
        curr = next;
    }
    new_node->link = XOR(curr, NULL);
    curr->link = XOR(new_node, prev);
}

void printList (Node *head) { 
	Node *curr = head; 
	Node *prev = NULL; 
	Node *next; 

	cout << "The nodes of the Linked List are: \n"; 

	while (curr != NULL) { 
		cout<<curr->data<<" "; 

		next = XOR (prev, curr->link); 

		prev = curr; 
		curr = next; 
	} 
} 

int main () { 
	Node *head = NULL;
	int d = 0;
	int w = 0;
	while(true) {
    	cout << "Enter the number and -1 to stop: ";
    	cin >> d;
    	cout<< "Enter 1 to insert at the beginning and 2 at the end: "
    	cin >> w;
    	if (d == -1)  
    	    break;
    	if (w == 1)
    	    insertBeginning(&head, d); 
    	if (w == 2)
    	    insertEnd(&head, d); 
	}

	printList (head); 

	return (0); 
} 