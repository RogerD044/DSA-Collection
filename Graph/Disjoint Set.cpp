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

void initialize(int arr[], int n)
{
	f(i,0,n)
	arr[i] = i;
}

// APPROACH 1. //////////////////////////////////////////////////////////

bool find( int Arr[ ], int A, int B)                           
{
	if(Arr[ A ] == Arr[ B ])
	return true;
	else
	return false;   
}
void union(int Arr[ ], int N, int A, int B)		// B -> Parent(A)
{
    int TEMP = Arr[ A ];
	for(int i = 0; i < N;i++)
    {
    	if(Arr[ i ] == TEMP)	// Changing all the nodes having root as A to B by searching linearly for all the nodes 
    	Arr[ i ] = Arr[ B ]; 
    }
}
//TIME CPLX = O(N^2)

// APPROACH 2. //////////////////////////////////////////////////////////

//finding root of an element
int root(int Arr[ ],int i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root
    {
     i = Arr[ i ];
    }
    return i;
}


/*modified union function where we connect the elements by changing the root of one of the elements*/

int union(int Arr[ ] ,int A ,int B)
{
    int root_A = root(Arr, A);       
    int root_B = root(Arr, B);  
    Arr[ root_A ] = root_B ;       //setting parent of root(A) as root(B)
}
bool find(int A,int B)
{
    if( root(A)==root(B) )       //if A and B have the same root, it means that they are connected.
    return true;
    else
    return false;
}

// TIME CPLX - O(N)

/*
The above method does not considers the size of the subset,
which may result in unbalanced trees resulting in more time for Union
*/

// APPROACH 3. //////////////////////////////////////////////////////////
/*modified initialize function:
We use a size[] array to account for the size of each subset, initializing it with 1
*/
void initialize( int Arr[ ], int N)
{
    for(int i = 0;i<N;i++)
    {
	Arr[ i ] = i ;
	size[ i ] = 1;
	}
}

// For 2 subsets, the one with more number of elements is kept as the root, and the subset
// with less number of elements in changed to traverse in least time 
void weighted-union(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B ])	// if size of A is smaller, change root of A
    {
		Arr[ root_A ] = Arr[root_B];
		size[root_B] += size[root_A];	// Increase size of B
	}
    else
    {
		Arr[ root_B ] = Arr[root_A];
		size[root_A] += size[root_B];
	}
}

// UNION WITH PATH COMPRESSION /////////////////////////////////////////
int root (int Arr[ ] ,int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ; // Instead of pointing to the parent, we are pointing to the grandparent
		i = Arr[ i ]; 
    }
	return i;
}
