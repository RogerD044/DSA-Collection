#include<bits/stdc++.h>
using namespace std;

/*
Current Node = i
Parent Node = i/2
Left Child = 2*i
Right CHild = 2*i + 1

We start indexing from 1 instead of 0
*/

#define Parent(i)	i/2
#define Left(i)		2*i
#define Right(i)	2*i+1

const int size = 10000 + 1;
int heap[size], heap_size = 0;

void Insert(int key)
{
	++heap_size;					// increase heap size
	int i = heap_size;				// i points to the last position of the heap which is empty
	heap[i] = key;					// key is added to the last position in array

	while(i!=1 && heap[Parent(i)]>heap[i])	// runs till we have not reached root node or the current node is smaller than its parent
	{
		swap(heap[Parent(i)], heap[i]);		//swap current node with its parent
		i = Parent(i);						// current position = position of parent
	}
}

void decrease(int pos, int key)
{
	heap[pos] = key;						// we decrease value at position to new value 
	int i = pos;
	while(i!=1 && heap[Parent(i)]>heap[i])	// move from bottom to top to check min heap condition SAME AS IN INSERT
	{
		swap(heap[Parent(i)], heap[i]);
		i = Parent(i);
	}
	
}

void MinHeapify(int pos)					
{
	// We swap the current position value with the smallest between its 2 children node's, and recur further

	int smallest = pos;						
	if(Left(pos)<=heap_size && heap[Left(pos)]<heap[smallest])		// If left child is smallest
		smallest = Left(pos);
	if(Right(pos)<=heap_size && heap[Right(pos)]<heap[smallest])	// If right is smallest
		smallest = Right(pos);

	if(smallest!=pos)												// If 1 among the children were smallest, we recur through the children
	{
		swap(heap[pos],heap[smallest]);
		MinHeapify(smallest);
	}
}

int extractMin()
{
	if(heap_size==1)
	{		--heap_size;		return heap[1];		}

	int root = heap[1];							// Root node is extracted
	heap[1] = heap[heap_size];					// The last node value takes the place of root 
	--heap_size;								// heap size is decreased by 1
	MinHeapify(1);								// heapify is called to form heap from node 1(root)
}

void deleteKey(int pos)
{
	decrease(pos, INT_MIN);						// First mark that key as minimum, so that it becomes the root
	extractMin();								// Then extract the minimum
}


void build_MinHeap()							// Builds min_heap from an arbitrary array
{
	// heap from (heap_size/2+1) forms the leaf nodes, as these are leaf nodes they already satisfy min_heap condition
	for(int i = heap_size/2; i>=1; --i)		// We start heapifying from the last parent which is heapsize/2 			
		MinHeapify(i);		
}

void Heap_Sort()				// For min heap----> Descending order
{
	build_MinHeap();			// Build min heap

	int n = heap_size;			// store heapsize
	for(int i = n; i>=2; --i)	// start from back till 1 element is left
	{
		swap(heap[1],heap[i]);	// minimum element(ROOT) is swapped with the last element of heap
		--heap_size;			// size is decreased
		MinHeapify(1);			//	heapifying from root till the new reduced size
	}
	heap_size = n;				// heap size is retained, so now the heap array is in descending order starting from 1 till heapsize
}

int main()
{
	Insert(1);
	Insert(6);
	Insert(8);
	Insert(9);
	Insert(7);
	Insert(3);
	Insert(2);
	deleteKey(5);
	
	Heap_Sort();
	for(int i=1;i<=heap_size;++i)
	cout<<heap[i]<<" ";

}