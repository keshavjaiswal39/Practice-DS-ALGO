#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{
//	priority_queue<int> pq_max;
	priority_queue<int, vector<int>, greater<int> > pq_min;
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		
		pq_min.push(num);
	}
	

	while(!pq_min.empty())
	{
		cout<<pq_min.top()<<" ";
		pq_min.pop();
	}	
	
	
}




