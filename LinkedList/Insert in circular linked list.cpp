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
	return;
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
	
}
