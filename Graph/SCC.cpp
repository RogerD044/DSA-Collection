#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define ppb() pop_back()
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f(i, x, y) for(int i = x; i < y; i++)
#define fstl(i,a)	for(auto i=a.begin();i!=a.end();++i)
#define fstl2(i,a)	for(auto i=0;i<a.size();++i)
#define ll long long
#define llu unsigned long long int
#define key pair<int, int>
#define mp(x,y) make_pair(x,y)
#define keyd pair<double, double>
#define ff first
#define ss second
int mod = 1e9+7;

using namespace std;

const int nodes = 15 + 1;
vector<int> g[nodes];
vector<int> gr[nodes];
int visit[nodes];
vector<int> s;

void DFS_frwd(int node)
{
	visit[node] = 1;
	fstl(i,g[node])
	{
		if(!visit[*i])
			DFS_frwd(*i);
	}
	s.pb(node);				//Push node only when it is fully explored
}

void DFS_rev(int node)
{
	visit[node] = 1;
	cout<<node<<" ";		// Printing the nodes in 1 strongly connected component
	fstl(i,gr[node])
	{
		if(!visit[*i])
			DFS_rev(*i);
	}
}

void SCC()
{
	// 1. FORWARD DFS
	f(i,0,nodes)
		if(!visit[i] && g[i].size()!=0)		//DFS only when node is unvisited and it is connected(not considering isolated single nodes)
		DFS_frwd(i);
	
	// 2. REVERSING THE GRAPH
	f(i,0,nodes)
	{
		fstl(n,g[i])
		gr[*n].pb(i);

		visit[i] = 0;						// Reinitializing the visit array
	}

	// 3. DFS on the reverse graph untill the stack is empty
	while(!s.empty())
	{
		int t = s.back();	s.ppb();
		if(!visit[t])
		{
			DFS_rev(t);
			cout<<endl;						// Change line after printing 1 SCC
		}
	}
}

int main()
{
	fastread;
	int n,m;
	cin>>n>>m;
	int a,b;
	f(i,0,nodes)
	{
		cin>>a>>b;
		g[a].pb(b);							// Directed Graph
	}
	SCC();
}
