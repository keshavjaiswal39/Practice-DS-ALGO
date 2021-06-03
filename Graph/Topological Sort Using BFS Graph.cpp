#include<bits/stdc++.h>
using namespace std;

class Graph
{
	list<int> *l;
	int V;
	
	public:
		Graph(int V)
		{
			this->V=V;
			l = new list<int>[V];
		}
		
		void addEdges(int x, int y)
		{
			l[x].push_back(y);
		}
		
		void topological_sort()
		{
			// indegree
			int *indegree = new int[V];
			
			for(int i=0;i<V;i++)
			{
				indegree[i]=0;
			}
			
			// update indegree by traversing edges x->y 
			// indegree[y]++
			
			for(int i=0;i<V;i++)
			{

				for(auto y:l[i])
				{
					indegree[y]++;
				}
			}
			
			queue<int> q;
			
			// bfs
			// 1. first step: find the node with 0 indegree
			for(int i=0;i<V;i++)
			{
				if(indegree[i]==0)
				{
					q.push(i);
				}
			}
			
			// 2. Start removing element from the queue
			while(!q.empty())
			{
				int node = q.front();
				cout<<node<<" ";
				q.pop();
				
				// iterate over the nbr of that node and reduce their indegree by 1
				for(auto nbr:l[node])
				{
					indegree[nbr]--;
					
					if(indegree[nbr]==0)
					{
						q.push(nbr);
					}
				}
			}
		}
};



int main()
{
	Graph g(6);
	
	g.addEdges(0,2);
	g.addEdges(1,2);
	g.addEdges(1,4);
	g.addEdges(2,3);
	g.addEdges(2,5);
	g.addEdges(1,4);
	g.addEdges(4,5);
	
	g.topological_sort();
	
}




