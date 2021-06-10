#include<bits/stdc++.h>
using namespace std;

void stockSpan(int price[], int n, int span[])
{
	stack<int> s; // indices of the days
	s.push(0);
	
	span[0]=1;
	
	// loop for the rest of the days
	for(int i=1;i<=n-1;i++)
	{
		// find out top most element that is higher than the current price
		int currentPrice = price[i];
		
		while(!s.empty() and price[s.top()]<=currentPrice)
		{
			s.pop();
		}
		
		if(!s.empty())
		{
			int prev_highest = s.top();
			span[i] = i - prev_highest;
		}
		else
		{
			span[i] = i+1;
		}
		
		// push the element in the stack
		s.push(i);
	}
}


int main()
{
	int prices[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(prices)/sizeof(int);
	int span[1000000]={0}; 
	
	stockSpan(prices,n,span);
	
	for(int i=0;i<n;i++)
	{
		cout<<span[i]<<" ";
	}
}


