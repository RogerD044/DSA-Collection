#include<bits/stdc++.h>

#define pb(x) push_back(x)
#define f(i, x, y) for(int i = x; i < y; i++)
#define fstl(i,a)	for(auto i=a.begin();i!=a.end();++i)

using namespace std;

const int nodes = 10 + 1;
vector<int> g[nodes];	//No. of Nodes
vector<int> visit;
vector<int> s;

int dfs(int root)
{
	visit[root]=1;
	fstl(i,g[root])
	{
		if(!visit[*i])
			dfs(*i);
	}
	
	s.pb(root);
}

int top_sort(int nodes)
{
	// Perform for all nodes, if the root node is not known
	f(i,1,nodes+1)
	{
		if(!visit[i])
			dfs(i);
	}

	// Stored in the form of stack, so printing in reverse manner
	for(auto i=s.rbegin();i!=s.rend();++i)
		cout<<*i<<" ";
}

int main()
{
	int n,m;
	cin>>n>>m;

	//Assigning all the nodes as unvisited
	visit.assign(nodes,0);

	int a,b;
	f(i,0,m)
	{
		cin>>a>>b;
		g[a].pb(b);
	}

	top_sort(n);
}