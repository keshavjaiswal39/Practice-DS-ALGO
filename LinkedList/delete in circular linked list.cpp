#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		
		node(int data)
		{
			this->data = data;
			next = NULL;
		}
};

void insert(node *&head, int data)
{
	node *n = new node(data);
	node *temp = head;
	
	n->next = head;
	if(temp != NULL)
	{
		while(temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = n;
	}
	else
	{
		n->next = n;
	}
	
	head = n;
}

void Display(node *head)
{
	node *temp = head;
	
	while(temp->next != head)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
	return;
}

node *getnode(node *head, int data)
{
	node *temp = head;
	
	// for all the node except the last node
	while(temp->next != head)
	{
		if(temp->data == data)
			return temp;
		temp = temp->next;
	}
	
	// out of the loop, last node
	if(temp->data == data)
	{
		return temp;
	}
	
	return NULL;
}

void deleteNode(node *&head, int data)
{
	node *del = getnode(head, data);
	
	if(del == NULL)
	{
		return;
	}
	
	// otherwise
	if(head == del)
	{
		head = head->next;
	}
	
	
	
	
	node *temp = head;
	
	// stop one step behind the node to be deleted
	while(temp->next != del)
	{
		temp = temp->next;
	}
	
	temp->next = del->next;
	
	delete del;
}

int main()
{
	node *head = NULL;
	
	insert(head, 10);
	insert(head, 20);
	insert(head, 30);
	insert(head, 40);
	insert(head, 50);
	
	Display(head);
	cout<<endl;
	
	deleteNode(head, 50);
	Display(head);
	
}
