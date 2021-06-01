#include<bits/stdc++.h>
#include<queue>
using namespace std;

int join_ropes(int rope[],int n)
{
	priority_queue<int, vector<int>, greater<int> > pq(rope,rope+n);
	
	int cost=0;
	
	while(pq.size() > 1)
	{
		int A=pq.top();
		pq.pop();
		
		int B=pq.top();
		pq.pop();
		
		int new_cost=A+B;
		cost+=new_cost;
		pq.push(new_cost);
	}
	
	return cost;	
}

int main()
{
	int rope[]={4,3,2,6};
	
	cout<<join_ropes(rope,4);
	
}




