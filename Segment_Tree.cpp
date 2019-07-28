#include<bits/stdc++.h>
#define f(i, x, y) for(int i = x; i < y; i++)
#define fstl(i,a)	for(auto i=a.begin();i!=a.end();++i)
#define fstl2(i,a)	for(auto i=0;i<a.size();++i)

using namespace std;

vector<int> tree;

void SumTree(int ar[],int start,int end,int node)
{
    if(start==end)
	{	tree[node] = ar[start];     return;     }

	int mid = (start+end)/2;
	SumTree(ar,start,mid,2*node + 1);
	SumTree(ar,mid+1,end,2*node + 2);

	tree[node] = tree[2*node + 1] + tree[2*node + 2];
}

void UpdateSumTree(int ar[], int index, int val, int start, int end, int node)
{
	if(start == end)
	{	ar[index] = val;		tree[node] = val;	    }
	else
	{
		int mid = (start+end)/2;
		if(start<=index && index<=mid)		// if INDEX lies b/w start and mid --> LEFT Child
			UpdateSumTree(ar,index,val,start,mid,2*node + 1);
		else
			UpdateSumTree(ar,index,val,mid + 1,end,2*node + 2);	
	
		tree[node] = tree[2*node + 1] + tree[2*node + 2];	
	}
}

int SumQuery(int qstart, int qend, int start, int end, int node)
{
	if(qstart<=start && end<=qend)		// Totoal Overlap
		return tree[node];
	if(qend< start || qstart>end)		// No Overlap
		return 0;
	int mid = (start+end)/2;
	return SumQuery(qstart,qend,start,mid,2*node + 1) +	SumQuery(qstart,qend,mid+1,end,2*node + 2);
}

int main()
{
	int ar[] = {1, 3, 5, 7, 9, 11};  
    int n = sizeof(ar)/sizeof(ar[0]);
    // TreeSize = 2*(NearestPower of 2 >= n) - 1;
    //Height of segment tree  
    int x = (int)(ceil(log2(n)));  
    //Maximum size of segment tree  
    int max_size = 2*(int)pow(2, x) - 1;  
    tree.assign(max_size,NULL);
    
    SumTree(ar,0,n-1,0);
    UpdateSumTree(ar,1,4,0,n-1,0);
    for(auto i: ar)     cout<<i<<",";       cout<<endl;
    for(auto i: tree)   cout<<i<<",";       cout<<endl;
    
    cout<<SumQuery(0,3,0,n-1,0);
}