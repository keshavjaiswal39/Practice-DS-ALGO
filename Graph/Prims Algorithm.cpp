 /*
 
 PRIMS ALGORITHMS
 - Weighted Undirected Graph
 - Greedy Algorithm

 Terms
 ------
 MST Set = []
 Active Edge = edge from a vertex in the MST set to V
 MST Edge = an edge that has been included in MST so far
 
 Algorithm
 ----------
 
 1. Start from any Source vertex
 2. Start exploring all the active edges of that vertex
 3. Out of all active edges, pick the one with the smallest weight, lets say we picked some Y
 	--> Select in Y in MST
 	--> Add edges starting from Y in the active edge list
 
 */
 
 #include<bits/stdc++.h>
 using namespace std;
 
 class Graph{
 	// Adjacency List
 	vector<pair<int,int> > *l;
 	int V;
 	
 	public:
 		Graph(int n)
 		{
 			V = n;
 			l = new vector<pair<int,int> > [n];
		}
		
		void addEdge(int x, int y, int w)
		{
			l[x].push_back({y,w});
			l[y].push_back({x,w});
		}
		
		int prim_mst()
		{
			// most important stuffs
			// Init a min_heap
			priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
			
			// another array
			// visited array that denotes whether a node has been included in MST or not
			bool *visited = new bool[V]{0};
			int ans = 0;
			
			// begin
			Q.push({0,0});  //  weight, node
			while(!Q.empty())
			{
				// pick out the edge with minimum edge
				auto best = Q.top();
				Q.pop();
				
				int to = best.second;
				int weight = best.first;
				
				if(visited[to] == true)
				{
					// discard the edge, means it is not an active edge, so continue
					continue;
				}
				
				// otherwise take the current edge
				ans += weight;
				visited[to] = 1;
				
				// add the new edges in the queue
				for(auto x:l[to])
				{
					if(visited[x.first] == 0)
					{
						Q.push({x.second, x.first});
					}
				}
			}
			return ans;
		}
 };
 
 int main()
 {
 	
 }
 
 
 
 
 
