#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		
		node(int d)
		{
			data = d;
			next = NULL;
		}
};

int length(node *head)
{
	int cnt = 0;
	while(head!=NULL)
	{
		cnt++;
		head = head->next;
	}
	return cnt;
}

void insertAtHead(node *& head, int data)
{
	if(head == NULL)
	{
		head = new node(data);
		return;
	}
	
	node * temp = new node(data);
	temp->next = head;
	head = temp;
}

void insertAtTail(node *& head, int data)
{
	if(head == NULL)
	{
		insertAtHead(head,data);
		return;
	}
	
	node *temp = head;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	temp->next = new node(data);
	return;
}

void insertInMiddle(node *& head, int data, int pos)
{
	if(head == NULL)
	{
		insertAtHead(head, data);
		return;
	}
	else if(pos>length(head))
	{
		insertAtTail(head, data);
		return;
	}
	
	else
	{
		// first take pos-1 jumps and keep a temp pointer in that node
		int jump = 1;
		node *temp = head;
		
		while(jump<=pos-1)
		{
			temp = temp->next;
			jump++;
		}
		
		node * n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
}

void Display(node *head)
{
	while(head != NULL)
	{
		cout<<head->data<<" -> ";
		head = head->next;
	}
}


int main()
{
	node *head = NULL;
	
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,1);
	insertAtHead(head,0);
	Display(head);
	cout<<endl;
	
	insertInMiddle(head,2,2);
	insertInMiddle(head,3,3);
	Display(head);
	cout<<endl;
	
	insertAtTail(head,6);
	insertAtTail(head,7);
	insertAtTail(head,8);
	Display(head);
	cout<<endl;
}




