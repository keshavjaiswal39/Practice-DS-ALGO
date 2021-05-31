#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v)
{
	for(int x:v)
	{
		cout<<x<<" ";
	}
}

void buidHeap(vector<int> &v)
{
	for(int i=2;i<v.size();i++)
	{
		int idx=i;
		int parent=i/2;
		
		while(idx>1 and v[idx]>v[parent])
		{
			swap(v[idx],v[parent]);
			idx=parent;
			parent=parent/2;
		}
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
	
	buidHeap(v);
	
	print(v);
	
	
	
	
}







