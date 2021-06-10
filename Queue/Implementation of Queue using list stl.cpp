#include<bits/stdc++.h>
using namespace std;

class Queue{
	list<int> l;
	int cs;
	
	public:
	
	Queue()
	{
		cs = 0; 
	}
	
	bool isEmpty()
	{
		return cs == 0;
	}
	
	void push(int data)
	{
		l.push_back(data);
		cs++;
	}
	
	void pop()
	{
		cs--;
		l.pop_front();
	}
	
	int front()
	{
		return l.front();
	}
};

int main()
{
	Queue q;
	
	for(int i=1;i<=10;i++)
	{
		q.push(i);
	}
	
	while(!q.isEmpty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	
}



