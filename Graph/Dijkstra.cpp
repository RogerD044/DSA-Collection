/*

Algorithm Steps:

- Set all vertices distances = infinity except for the source vertex, set the source distance = 0.
- Push the source vertex in a min-priority queue in the form (distance , vertex), as the comparison in the min-priority queue will be according
	 to vertices distances.
- Pop the vertex with the minimum distance from the priority queue (at first the popped vertex = source).
- Update the distances of the connected vertices to the popped vertex in case of "current vertex distance + edge weight < next vertex distance",
	 then push the vertex with the new distance to the priority queue.
- If the popped vertex is visited before, just continue without using it.
- Apply the same algorithm again until the priority queue is empty. 

*/


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
vector<key> g[nodes];			// Its a vector array of PAIRs, to keep a record of (dist,to_edge) from any particular edge
vector<int> visit;
int dist[nodes];
int inf = 1e9; 					// Initialize the dist array with a large value

int dijkstra(int source)
{
	f(i,0,nodes)
		dist[i] = inf;

	dist[source] = 0;			// Put distance of source = 0
	multiset<key> pq;
	key cur;
	int edge,wei,new_dist;
		
	// Insert Pairs as (DIST, EDGE)
	pq.insert(mp(0,source));

	while(pq.size())
	{
		cur = *pq.begin();
		pq.erase(pq.begin());

		edge = cur.ss;	wei = dist[edge];
		if(visit[edge])		continue;			// If an edge is explored, do not visit it again
		visit[edge] = 1;
		fstl2(i,g[edge])
		{
			new_dist = wei + g[edge][i].ff;
			if(new_dist< dist[g[edge][i].ss])
			{	
				pq.insert(mp(new_dist,g[edge][i].ss));
				dist[g[edge][i].ss] = new_dist;
			}
		}
	}
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
	}

	dijkstra(1);								// Assuming source node is 1

	f(i,2,n+1)					
	cout<<dist[i]<<" ";
}
