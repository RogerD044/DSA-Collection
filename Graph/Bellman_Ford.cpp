/*

1. Run a loop N-1 times; where N is number of vertices
2. For every iteration, go thrught all the edges, i.e, run a loop for all vertices and in every iteration go through its adjacency list  
3. If adjacent Vertex's distance required updation; Update it

BY NOW, WE HAVE ARRIVE AT THE SHORTEST DISTACNCE FROM ROOT TO ALL NODES(which is stored in dist[] array)

4. Go through all the edges, ONE more time.
5. If there is condition for Relaxation/Updation, It means a NEGATIVE CYCLE IS PRESENT

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

const int nodes = 10000 + 1;
vector<key> g[nodes];	//No. of Nodes
vector<int> visit;
int dist[nodes];
int inf = 1e9; 

int Bellman_Ford(int n, int source)			// n = number of vertices/nodes as input
{
	f(i,0,nodes)
		dist[i] = inf;						// initializing all nodes to distance infinty

	dist[source] = 0;						// Source node is at dist 0

	f(i,0,n-1)								// 1. Running loop (n-1) times
	{
		f(j,1,n+1)							// 2. Taking all vertices numbered from 1-n(both inclusive)
		{
			fstl2(to,g[j])					// Loop through all the adjacent vertices of the current vertex(chosen in step 2) 
			{
				if(g[j][to].ff + dist[j] < dist[g[j][to].ss])	// 3. adjcent vertex's WEIGHT + current vertex's DISTANCE < adjacent vertex's DISTANCE
					dist[g[j][to].ss] = g[j][to].ff + dist[j];	// update DISTANCE of adjacent vertex
			}
		}
	}

	f(j,1,n+1)								// 4. Loop through all the vertices 1 more time
		{
			fstl2(to,g[j])					// Every adjacent vertices of the current vertex
			{
				if(g[j][to].ff + dist[j] < dist[g[j][to].ss])	// If any of the adjacent vertex distance needs to be changed
				{
					cout<<"Graph Contains Negative Cycle"<<endl;	// Negative Weight Cycle is Present
					return 0;										// Need not check further
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

	Bellman_Ford(n,1);

	f(i,2,n+1)
	cout<<dist[i]<<" ";
}
