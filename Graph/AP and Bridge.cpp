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

const int nodes = 10 + 1;
vector<int> g[nodes];	//No. of Nodes
int visit[nodes];
vector<key> bridge;
vector<int> ap;
vector<int> parent;
int disc[nodes];
int low[nodes];

int time_ = 0;
int AP_Bridge(int at, int parr)
{
	visit[at] = 1;
	disc[at] = low[at] = ++time_;
	int child = 0;

	for(auto i:g[at])	
	{
		if(i==parr)	continue;	// If adjacent node is parent, go for the next
		if(!visit[i])			// If adjacent node not visited
		{
			++child;			
			parent[i] = at;
			AP_Bridge(i,at);				// DFS runs
			low[at] = min(low[at],low[i]);	// After DFS, the adjacent node's low-link value has been computed, update the current node's low-link value with its adjacent
			if((parr==-1 && child>1))		ap.pb(at);		//If root node and having 2 or more children -> AP
			if(disc[at]<=low[i] && parent[at]!=-1)	ap.pb(at);	// If current nodes is discovered before or at the same instance of low-link value 
																// of adjacent node and the current node is not the root -> AP
			if(disc[at]<low[i])		bridge.pb(mp(at,i));	// If discovery time of current node is less than adjacent node's low link val -> BRIDGE
		}
		else
			low[at] = min(low[at],disc[i]);		// For an already visited node, update current node's low-link with discovery time of the adjacent
	}
}

int main()
{
	fastread;
	int m,n;
	cin>>n>>m;

	int a,b;
	f(i,0,m)
	{
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}

	parent.assign(nodes,-1);

	f(i,0,nodes)
	{
		if(!visit[i])
		AP_Bridge(i,-1);
	}
	
	// Printing Stuffs
	cout<<ap.size()<<endl;
	sort(ap.begin(), ap.end());
	fstl(i,ap)
	cout<<*i<<" ";
	cout<<endl;
	
	sort(bridge.begin(), bridge.end());
	cout<<bridge.size()<<endl;
	fstl2(i,bridge)
	cout<<bridge[i].ff<<" "<<bridge[i].ss<<endl;
	
}
