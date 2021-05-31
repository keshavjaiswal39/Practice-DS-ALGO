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
	
	void Heapify(int idx)
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
			Heapify(min_idx);
		}
	}
	
	
	public:
		
		Heap(int default_size=10, bool type=true)
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
		
		int top()
		{
			return v[1];
		}
		
		void pop()
		{
			int last=v.size()-1;
			swap(v[1],v[last]);
			v.pop_back();
			
			Heapify(1);
		}
		
		bool isEmpty()
		{
			return v.size()==1;
		}
};

int main()
{
//	Heap h;

// Lets try for a max heap
	Heap h(10, false);
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		h.push(no);
	}
	
	while(!h.isEmpty())
	{
		cout<<h.top()<<" ";
		h.pop();
	}
	
	return 0;
	
}







