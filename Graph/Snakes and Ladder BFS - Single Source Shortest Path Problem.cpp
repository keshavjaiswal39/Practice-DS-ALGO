#include<bits/stdc++.h>
using namespace std;

class Graph{
	map<int, list<int> > l;
	
	public:
		
		void addEdge(int x, int y)
		{
			l[x].push_back(y);
		}
		
		void bfs(int src, int dest)
		{
			map<int, int> dist;
			queue<int> q;
			
			// all the nodes will have int_max
			for(auto node_pair:l)
			{
				int node = node_pair.first;
				dist[node]=INT_MAX;
			}
			
			q.push(src);
			dist[src]=0;
			
			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				
				for(int nbr:l[node])
				{
					if(dist[nbr] == INT_MAX)
					{
						q.push(nbr);
						
						// mark that node as visited
						dist[nbr] = dist[node] + 1;
					}
				}
			}
			
			for(auto node_pair:l)
			{
				cout<<node_pair.first<<" and dist "<< dist[node_pair.first]<<endl;
			}
			
			cout << dist[dest];
		}	
};


int main()
{
	// Input
	
	int board[50]={0};
	
	// Snakes or Ladder (Jump)
	
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=10;
	board[32]=-2;
	board[34]=-22;
	
	// Add Edges to the Graph
	
	Graph g;
	
	for(int i=0;i<=36;i++)
	{
		for(int dice=1;dice<=6;dice++)
		{
			int j = i + dice;
			j += board[j];
			
			if(j<=36)
			{
				g.addEdge(i,j);
			}
		}
	}
	
	g.addEdge(36,36);
	
	g.bfs(0,36);
	
	return 0;
}




