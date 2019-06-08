#include<bits/stdc++.h>

#define pb(x) push_back(x)
#define f(i, x, y) for(int i = x; i < y; i++)
#define fstl(i,a)	for(auto i=a.begin();i!=a.end();++i)

using namespace std;

const int MAX = 1e4 + 5;
int parent[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

// Each node is the parent of itself
void initialize()
{
    for(int i = 0;i < MAX;++i)
        parent[i] = i;
}

// Returns the root of a node
int root(int i)
{
    while (parent[i] != i) 
        i = parent[i]; 
    return i; 
}

// Joins the 2 node-sets
void union1(int x, int y)
{
    int a = root(x); 
    int b = root(y); 
    parent[a] = b; 
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}