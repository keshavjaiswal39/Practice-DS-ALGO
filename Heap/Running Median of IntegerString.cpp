#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{
	
	priority_queue<int> left;  // max heap
	priority_queue<int, vector<int>, greater<int> > right; // min heap
	
	int d;
	cin>>d;
	left.push(d);
	
	float med=d;
	cout<<"Med "<<med<<endl;
	
	cin>>d;
	
	while(d!=-1)
	{
		
		// case 1
		// if the left heap has more element than right heap
		if(left.size()>right.size())
		{
			// two cases, either the number to be placed in left heap or the right heap
			if(d<med)
			{
				right.push(left.top());
				left.pop();
				left.push(d);
			}
			else
			{
				right.push(d);
			}
			
			med=(left.top()+right.top())/2.0;
		}
		
		// case 2
		// if both the heap has the same number of element
		else if(left.size()==right.size())
		{
			// two cases, either the number to be placed in left heap or the right heap
			if(d<med)
			{
				left.push(d);
				med=left.top();
			}
			else
			{
				right.push(d);
				med=right.top();
			}
		}
		
		// case 3
		// if the right heap is greater than the left heap
		else
		{
			// two cases, either the number to be placed in left heap or the right heap
			if(d<med)
			{
				left.push(d);
			}
			else
			{
				left.push(right.top());
				right.pop();
				right.push(d);
			}
			
			med=(left.top()+right.top())/2.0;
		}
		
		cout<<"Med "<<med<<endl;
		
		cin>>d;		
	}
		
	return 0;
}
