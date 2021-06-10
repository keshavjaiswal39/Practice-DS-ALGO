#include<iostream>
#include<list>
using namespace std;

// Cycle detection in a undirected graph using DSU

class Graph
{
	int V;
	list<pair<int,int> > l;
	
	public:
		Graph(int V)
		{
			this->V=V;
		}
		
		int addEdges(int u,int v)
		{
			l.push_back(make_pair(u,v));
		}
		
		// Find
		int findSet(int i,int parent[])
		{
			// base case
			if(parent[i]==-1)
			{
				return i;
			}
			
			// Path compression optimisation
			return parent[i]=findSet(parent[i],parent);
		}
		
		// Union
		void unionSet(int x,int y,int parent[],int rank[])
		{
			int s1=findSet(x,parent);
			int s2=findSet(y,parent);
			
			// Union by rank Optimisation
			if(s1!=s2)
			{
				if(rank[s1]<rank[s2])
				{
					parent[s1]=s2;
					rank[s2]+=rank[s1];
				}
				else
				{
					parent[s2]=s1;
					rank[s1]+=rank[s2];
				}
			}		
		}
		
		// Code Logic
		int pairing()
		{
			// Init the DSU Logic
			int *parent=new int[V];
			int *rank=new int[V];
			
			for(int i=0;i<V;i++)
			{
				parent[i]=-1;
				rank[i]=1;
			}
			
			// Code Logic
			
			for(auto edge:l)
			{
				int i=edge.first;
				int j=edge.second;
				
				int s1=findSet(i,parent);
				int s2=findSet(j,parent);
				
				unionSet(s1,s2,parent,rank);
			}
			
			// Go to all the nodes
			
			int ans=0;
			
			for(int i=0;i<V;i++)
			{
				ans+=V-rank[findSet(i,parent)];
			}
			delete [] parent;
			delete [] rank;
			
			return ans/2;
			
		}
		
};


int main()
{
	
	int n,m;
	cin>>n>>m;
	
	Graph g(n);
	
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		g.addEdges(x,y);
	}
	
	cout<<g.pairing()<<endl;
	
	return 0;
}













