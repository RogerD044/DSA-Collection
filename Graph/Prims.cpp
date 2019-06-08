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

const int nodes = 10000 + 1;	//No. of Nodes
vector<key> g[nodes];			// Its a vector array of PAIRs, to keep a record of (weight,to_edge) from any particular edge
vector<int> visit;				// Keep track of a visited vertex

int Prims(int source)
{
	multiset<key> pq;
	pq.insert(mp(0,source));	// Insert The source in Priority Queue

	int cost = 0,weight,to_edge;
	key p;
	while(!pq.empty())			// Till Queue is not empty
	{
		p = *pq.begin();		// Extracts the top of the queue(MINIMUM WEIGHT)
		pq.erase(pq.begin());	// Delete the topmost element

		weight = p.ff;			// weight
		to_edge = p.ss;			// Minimum weight Destination Vertex

		if(visit[to_edge])		// If the destination vertex is already visited, it means a cycle can be formed
			continue;			

		visit[to_edge] = 1;		// Mark the visited vertex
		cost+=weight;			// update cost

		fstl2(i,g[to_edge])		// For all the adjacenet vertices of this MINIMUM vertex
		{
			if(!visit[g[to_edge][i].ss])	// If adjacent vertex is not marked
				pq.insert(g[to_edge][i]);	// Add it to the list
		}
	}
	
	cout<<cost;					// Print the cost
}

int main()
{
	int n,m;
	cin>>n>>m;

	//Assigning all the nodes as unvisited
	visit.assign(nodes,0);

	int a,b,w;
	f(i,0,m)
	{
		cin>>a>>b>>w;
		g[a].pb(mp(w,b));
		g[b].pb(mp(w,a));
	}
	
	Prims(1);

}
