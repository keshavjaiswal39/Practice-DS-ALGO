#include<bits/stdc++.h>
using namespace std;

bool minHeap=false;

bool compare(int a,int b)
{
	if(minHeap)
	{
		return a<b;
	}
	return a>b;
}

void print(vector<int> v)
{
	for(int x:v)
	{
		cout<<x<<" ";
	}
}

void Heapify(vector<int> &v,int idx)
{
	int left=2*idx;
	int right=2*idx+1;
	
	int last=v.size()-1;
	int min_idx=idx;
	
	if(left<=last and compare(v[left],v[idx]))
	{
		min_idx=left;
	}
	
	if(right<=last and compare(v[right],v[min_idx]))
	{
		min_idx=right;
	}
	
	if(min_idx!=idx)
	{
		swap(v[idx],v[min_idx]);
		Heapify(v,min_idx);
	}
	
}

void buidHeapOptimized(vector<int> &v)
{
	for(int i=(v.size()-1/2);i>=1;i--)
	{
		Heapify(v,i);
	}
}

int main()
{

	vector <int> v;
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		
		v.push_back(no);
	}
	
	print(v);
	
	cout<<endl;                                                      
	
	buidHeapOptimized(v);
	
	print(v);
	
	
	
	
}







