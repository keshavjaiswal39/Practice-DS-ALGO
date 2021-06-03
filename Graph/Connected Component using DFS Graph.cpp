#include<iostream>
#include<map>
#include<list>

using namespace std;

class Graph{
	map<int,list<int> > l;
	
	public:
		Graph()
		{
			
		}
		
		void addEdges(int x, int y)
		{
			l[x].push_back(y);
			l[y].push_back(x);
		}
		
		void dfs_helper(int src, map<int, bool> &visited)
		{
			cout<<src<<" ";
			visited[src]=true;
			
			for(auto nbr:l[src])
			{
				if(!visited[nbr])
				{
					dfs_helper(nbr,visited);
				}
			}
		}
		
		void dfs()
		{
			map<int, bool> visited;
			
			for(auto p:l)
			{
				int node = p.first;
				visited[node]=false;
			}
			
			// Iterate over all the vertices and initiate a dfs call if a vertex is not visited
	
			int cnt = 0;
			
			for(auto x:l)
			{
				int node = x.first;
				
				if(!visited[node])
				{
					cout<<"Component "<<cnt<<"--> ";
					dfs_helper(node, visited);
					cnt++;
					cout<<endl;
				}
			}
		}
};

int main()
{
	Graph g;
	
	g.addEdges(0,1);
	g.addEdges(0,3);
	g.addEdges(1,2);
	g.addEdges(2,3);
	g.addEdges(0,3);
	g.addEdges(0,4);
	
	g.addEdges(5,6);
	g.addEdges(6,7);

	g.addEdges(8,8);
		
	g.dfs();

	return 0;	
}













