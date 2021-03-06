#include<bits/stdc++.h>
using namespace std;

class Graph{
	list<int> *l;
	int V;
	
	public:
		Graph(int V)
		{
			this->V = V;
			l = new list<int> [V];
		}
		
		void addEdge(int x,int y)
		{
			l[x].push_back(y);
			l[x].push_back(y);
		}
		
		bool is_tree()
		{
			bool *visited = new bool[V];
			int *parent = new int[V];
			
			queue<int> q;
			
			// initially no node is visited
			for(int i=0;i<V;i++)
			{
				visited[i]=false;
				// update the parent array
				parent[i]=i;
			}
			
			int src = 0;
			
			q.push(src);
			visited[src] = true;
			
			// pop out one node and visit its neighbours
			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				
				for(int nbr:l[node])
				{
					if(visited[nbr] == true and parent[node] != nbr)
					{
						return false;
					}
					else if(!visited[nbr])
					{
						visited[nbr] = true;
						parent[nbr] = node;
						q.push(nbr);
					}
				}
			}
			
			return true;
		}
};

int main()
{
	Graph g(4);
	
	g.addEdge(0,1);
	g.addEdge(3,2);
	g.addEdge(1,2);
	g.addEdge(0,3);
	
	if(g.is_tree())
	{
		cout<<"Its a tree";
	}
	else
	{
		cout<<"Its not a tree";
	}
	
	return 0;
}




