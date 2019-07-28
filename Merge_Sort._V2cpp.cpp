// C++ code for linked list merged sort 
#include <bits/stdc++.h>
using namespace std; 

/* Link list node */
class Node { 
public: 
	int data; 
	Node* next; 
}; 

Node* Split(Node* head)
{
	Node* slow;
	Node* fast;
	slow = head;
	fast = head;
	while(fast->next && fast->next->next)
	{
		fast=fast->next->next;
		slow = slow->next;
	}
	Node *temp = slow->next;
	slow->next = NULL;
	return temp;
}

Node* Merge(Node* h1, Node* h2)
{
	if(h1==NULL)	return h2;
	else if(h2==NULL)	return h1;
	
	Node* res = NULL;
	if(h1->data <= h2->data)
	{
		res=h1;		res->next = Merge(h1->next,h2);	
	}
	else
	{
		res=h2;		res->next = Merge(h1,h2->next);	
	}
	return res;
}


void MergeSort(Node* head)
{
	if(head==NULL || head->next==NULL)		return;
	
	Node* pt = Split(head);
	
	head = MergeSort(head);		// After complete merging(sorted) of the 1st part, it now returns the head pointer to the sorted 1st half of the list
	pt = MergeSort(pt);			// After complete merging(sorted) of the 2nd part, it now returns the head pointer to the sorted 2nd half of the list

	// The 2 halfs are merged using the pointers pointing to the 2 sorted lists 
	return Merge(head,pt);		// Returns the pointer to the head of the list after sorting 
}

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data) 
{ 
	Node* new_node = new Node(); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Drier program to test above functions*/
int main() 
{ 
	Node* a = NULL; 
	//Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15); 
	push(&a, 10); 
	push(&a, 5); 
	push(&a, 20); 
	push(&a, 3); 
	push(&a, 2); 
	//push(&a, 11); 
	//push(&a, 4); 
	
	MergeSort(a); 

	cout << "Sorted Linked List is: \n"; 
	printList(a); 

	return 0; 
} 

// This is code is contributed by rathbhupendra 
