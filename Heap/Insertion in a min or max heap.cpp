#include<bits/stdc++.h>
using namespace std;

class Heap {
	
	vector<int> v;
	bool minHeap;
	
	bool compare(int a,int b)
	{
		if(minHeap)
		{
			return a<b;
		}
		return a>b;
	} 
	
	
	public:
		
		Heap(int default_size=10, bool type=false)
		{
			v.reserve(default_size);
			minHeap=type;
			v.push_back(-1);
		}
		
		void push(int data)
		{
			v.push_back(data);
			int idx=v.size()-1;
			int parent=idx/2;
			
			while(idx>1 and compare(v[idx], v[parent]))
			{
				swap(v[idx],v[parent]);
				idx=parent;
				parent=parent/2;
			}
		}
};

int main()
{
	Heap h;
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		h.push(no);
	}
	
	
}







