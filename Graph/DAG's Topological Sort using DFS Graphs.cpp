#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Graph{
	map<T,list<T> > l;
	
	public:
		void addEdges(T x, T y)
		{
			l[x].push_back(y);
		}
		
		void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering)
		{
			visited[src]=true;
			
			for(auto nbr:l[src])
			{
				if(!visited[nbr])
				{
					dfs_helper(nbr, visited, ordering); 
				}
			}
			
			ordering.push_front(src);
			
			return;
		}
		
		void dfs()
		{
			map<T,bool> visited;
			list<T> ordering;
			
			for(auto p:l)
			{
				T node = p.first;
				visited[node]=false;
			}
			
			for(auto p:l)
			{
				T node = p.first;
				if(!visited[node])
				{
					dfs_helper(node, visited, ordering);
				}
			}
			
			for(auto p:ordering)
			{
				cout<<p<<" ";
			}
		}
};

int main()
{
	Graph<string> g;
	
	g.addEdges("Python","DataProcessing");
	g.addEdges("Python","PyTorch");
	g.addEdges("Python","ML");
	g.addEdges("DataProcessing","ML");
	g.addEdges("PyTorch","DL");
	g.addEdges("ML","DL");
	g.addEdges("DL","FaceRecogn");
	g.addEdges("DataSet","FaceRecogn");
	
	g.dfs();
		
}
