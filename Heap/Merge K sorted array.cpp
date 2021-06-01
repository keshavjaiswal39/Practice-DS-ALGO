#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

typedef pair <int, pair<int,int> > node;

vector<int> mergeKSortedArray(vector<vector<int> > arr)
{
	vector<int> result;
	priority_queue <node, vector<node>, greater<node> > pq;
	
	for(int i=0;i<arr.size();i++)
	{
		pq.push({arr[i][0],{i,0}});
	}
	
	while(!pq.empty())
	{
		node current = pq.top();
		pq.pop();
		
		int element = current.first;
		int row=current.second.first;
		int col=current.second.second;
		
		result.push_back(element);
		
		if(col<arr[row].size()-1)
		{
			pq.push({arr[row][col+1],{row,col+1}});
		}
	}

	return result;	
}


int main()
{
	vector<vector<int> > arr{{1,4,7,10},
					{2,5,8,11},
					{3,6,9,12}};
	
	vector<int> output=mergeKSortedArray(arr);
	
	for(auto x:output)
	{
		cout<<x<<" ";
	}
	
	return 0;	
}




