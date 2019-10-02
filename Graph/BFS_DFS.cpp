#include<bits/stdc++.h>

#define pb(x) push_back(x)
#define f(i, x, y) for(int i = x; i < y; i++)
#define fstl(i,a)	for(auto i=a.begin();i!=a.end();++i)

using namespace std;

const int nodes = 7;
vector<int> g[nodes];	//No. of Nodes
vector<int> visit;
vector<int> level;


int bfs(int root)
{
	queue<int> q;
	
	q.push(root);
	visit[root]=1;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		cout<<cur<<" ";

		fstl(i,g[cur])
		{
			if(!visit[*i])
			{
				visit[*i]=1;
				q.push(*i);
			}
		}
	}
}

int dfs(int root)
{
	visit[root]=1;
	
	cout<<root<<" ";

	fstl(i,g[root])
		if(!visit[*i])
			dfs(*i);	
}

int main()
{
	int edges;
	cin>>edges;
    visit.assign(nodes+1,0);
    
    int a,b;
	f(i,0,edges)
	{
		cin>>a>>b;
		g[a].pb(b);		//directed graph
		g[b].pb(a);		//undirected graph additional line
	}
	int root = 1;
	
	dfs(root);
}


