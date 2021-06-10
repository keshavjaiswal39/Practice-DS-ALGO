#include<bits/stdc++.h>
using namespace std;

int main()
{
	queue<char> q;
	int freq[27] = {0};
	
	char ch;
	cin>>ch;
	
	while(ch!='.')
	{
		// logic will go here
		// first insert in the queue and frquency table
		
		q.push(ch);
		freq[ch-'a']++;
		
		// query part
		while(!q.empty())
		{
			int idx = q.front() - 'a';
			
			if(freq[idx] > 1)
			{
				q.pop();
			}
			else
			{
				cout<<q.front()<<endl;
				break;
			}
		}
		
		// q is empty
		if(q.empty())
		{
			cout<<"-1"<<endl;
		}
			
		cin>>ch;
	}
 }



