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

void deleteHead(node *&head)
{
	if(head == NULL)
	{
		return;
	}
	
	node *temp = head->next;
	delete head;
	head = temp;
}

void deleteMiddle(node *&head, int pos)
{
	if(head == NULL or pos==0)
	{
		deleteHead(head);
	}
	else
	{
		// take pos-1 jumps
		int jump = 1;
		node *temp = head;
		
		while(jump<=pos-1)
		{
			temp=temp->next;
			jump++;
		}
		
		node *n = temp->next;
		temp->next  = n->next;
		delete n; 
	}
}

void deleteTail(node *&head)
{
	if(head == NULL)
	{
		return;
	}
	
	node *prev = NULL;
	node *tail = head;
	
	while(tail->next!=NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	
	delete tail;
	prev->next = NULL;
	return;
}

void Display(node *head)
{
	while(head != NULL)
	{
		cout<<head->data<<" -> ";
		head = head->next;
	}
}

bool SearchInLinkedList(node *head, int key)
{
	node *temp = head;
	while(temp!=NULL)
	{
		if(temp->data == key)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool SearchInLinkedListRecursively(node *head, int key)
{
	if(head == NULL)
	{
		return false;
	}
	
	if(head->data == key)
	{
		return true;
	}
	
	else
	{
		return SearchInLinkedListRecursively(head->next, key);
	}
}

node *take_input()
{
	int d;
	cin>>d;
	node *head = NULL;
	
	while(d!=-1)
	{
		insertAtHead(head,d);
		cin>>d;
	}
	return head;
}

ostream& operator<<(ostream &os, node *&head)
{
	Display(head);
	return os;
}

istream& operator>>(istream &is, node *&head)
{
	head = take_input();
	return is;
}

void reverse(node *&head)
{
	node *current_node = head;
	node *prev_node = NULL;
	
	node *next_node;
	
	while(current_node!=NULL)
	{
		next_node = current_node->next;
		current_node->next = prev_node;
		prev_node = current_node;
		current_node = next_node; 
	}
	head = prev_node;
}

node * kthNode(node *head, int k)
{
	if(head == NULL or head->next == NULL)
	{
		return head;
	}
	
	node *fast = head;
	
	for(int i=0;i<k;i++)
	{
		fast = fast->next;
	}
	
	node *slow = head;
	
	while(fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	
	return slow;
}

node *merge(node *a, node *b)
{
	if(a == NULL)
	{
		return b;
	}
	
	if(b == NULL)
	{
		return a;
	}
	
	node *c;
	
	if(a->data < b->data)
	{
		c = a;
		c->next = merge(a->next,b);
	}
	
	else
	{
		c = b;
		c->next = merge(a,b->next);
	}
	
	return c;
}

int main()
{
	node *a, *b;
	
	cin>>a;
	cout<<a<<endl;
	
	cin>>b;
	cout<<b<<endl;
	
	node *root = merge(a,b);
	cout<<root;
	
//	node *head;
//	cin>>head;
//	
//	cout<<head<<endl;
//	
//	int k;
//	cin>>k;
//	
//	node *mid = kthNode(head, k);
//	
//	cout<<mid->data;
//	
//	node *head1;	
//	cin>>head1;
//	
//	cout<<head1;
//	cout<<endl;

//	reverse(head1);
//
//	cout<<head1;
	
//	insertAtHead(head,5);
//	insertAtHead(head,4);
//	insertAtHead(head,1);
//	insertAtHead(head,0);
//	Display(head);
//	cout<<endl;
//	
//	insertInMiddle(head,2,2);
//	insertInMiddle(head,3,3);
//	Display(head);
//	cout<<endl;
//	
//	insertAtTail(head,6);
//	insertAtTail(head,7);
//	insertAtTail(head,8);
//	Display(head);
//	cout<<endl;
//	
//	deleteHead(head);
//	Display(head);
//	cout<<endl;
//	
//	deleteMiddle(head,6);
//	Display(head);
//	cout<<endl;
//	
//	deleteTail(head);
//	Display(head);
//	cout<<endl;
//	
//	int key;
//	cin>>key;
	
//	if(SearchInLinkedList(head,key))
//	{
//		cout<<"Element found"<<endl;
//	}
//	else
//	{
//		cout<<"Element not found"<<endl;
//	}
	
//	if(SearchInLinkedListRecursively(head,key))
//	{
//		cout<<"Element found........."<<endl;
//	}
//	else
//	{
//		cout<<"Element not found........."<<endl;
//	}
}




