#include<iostream>
#include<list>
#include<cstring>
#include<unordered_map>

using namespace std;

class Graph{
	unordered_map<string, list<pair<string,int> > > l;
	
	public:
		Graph()
		{
				
		}
		
		void addEdge(string x, string y,bool bidir, int dist)
		{
			l[x].push_back(make_pair(y,dist));
			
			if(bidir)
			{
				l[y].push_back(make_pair(x,dist));
			}
		}
		
		void printAdjList()
		{
			for(auto p:l)
			{
				string city = p.first;
				list<pair<string, int> > nbrs = p.second;
				
				cout<<city<<" -> ";
				
				for(auto x:nbrs)
				{
					string dest = x.first;
					int dist = x.second;
					
					cout<<dest<<" "<<dist<<", ";
				}  
				cout<<endl;
			}
		}
};

int main()
{
	Graph g;
	
	g.addEdge("A","B",true,20);
	g.addEdge("B","D",true,40);
	g.addEdge("A","C",true,10);
	g.addEdge("C","D",true,40);
	g.addEdge("A","D",false,50);

	g.printAdjList();
}
