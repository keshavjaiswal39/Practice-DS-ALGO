#include<bits/stdc++.h>
using namespace std;

class Graph{
	map<string, list<pair<string, int> > > p;
	
	public:
		Graph()
		{
			
		}
		
		void addEdges(string x, string y, bool bidir, int wt)
		{
			p[x].push_back(make_pair(y,wt));
			
			if(bidir)
			{
				p[y].push_back(make_pair(x,wt));
			}
		}
		
		void printAdjacencyList()
		{
			for(auto l:p)
			{
				string city = l.first;
				list<pair<string,int> > nbr = l.second;
				
				cout<<city<<" -> ";
				
				for(auto x:nbr)
				{
					string dest = x.first;
					int data = x.second;
					
					cout<<dest<<" "<<data<<", ";
				}
				cout<<endl;
			}
		}
};

int main()
{
	Graph g;
	g.addEdges("A","B",true,20);
	g.addEdges("B","D",true,40);
	g.addEdges("A","C",true,10);
	g.addEdges("C","D",true,40); 
	g.addEdges("A","D",false,50);
	
	
	g.printAdjacencyList();
}
