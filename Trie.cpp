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

using namespace std;


struct TrieNode
{
	int is_prefix;								// Count of how many strings end at this node, 0 if no string ends here
	unordered_map<char,TrieNode*> child;		// to store the children of the current node
};

struct TrieNode* NewTrieNode()
{
	struct TrieNode* node = new TrieNode();		// Create new node dynamically
	node->is_prefix = 0;						// Assign is_prefix = 0, initially

	return node;
}

void insert(struct TrieNode *root, string s)
{
	struct TrieNode *current = root;			// Pointer to root
	f(i,0,s.length())							// Loop till string's length
	{
		char ch = s[i];		
		struct TrieNode *node = current->child[ch];		// 'node' points to the child corresponding to the character 'ch' in the current node 
		//cout<<ch<<" "<<node<<endl;					// If current has no child as 'ch', node is assigned NULL
		if(!node)										// current does not has a child 'ch', so node is assigned NULL
		{
			node = new TrieNode();						// Create a new node which will act as child node
			current->child[ch] = node;					// current node now has a child correspoding to 'ch' and points to the above created node
		}
		current = node;									// Child node is now the current node, to continue traversing further
	}
	current->is_prefix++;								// The last node has its is_prefix incremented indicating a string ENDS here
}

bool search(struct TrieNode *root, string s)			
{
	struct TrieNode* current = root;			
	f(i,0,s.length())
	{
		char ch = s[i];
		if(!current->child[ch])							// If the current node DOES NOT has a child pointer corresponding to 'ch' 
			return false;								// return false

		current = current->child[ch];					// If the current node has a child 'ch', make current node as child and traverse further
	}

	return (current->is_prefix > 0);					// We reach the end of string here, if this node has is_prefix>0, it means that a string ends
}														// here. If is_prefix is 0, it means that 's' is just a substring and we return false

/*
1. 'level' corresponds to the current index of the string, initially level = 0 is passed to the function
2. recursively pass root's child node corresponding to 'ch' to the function
3. If a node is removed and its parent has no children AND its predix count = 0 (no other string ends here); then it is safe to remove
	this parent node as well

BASE CONDITIONS:

4. if the root at any point is null, happens when
a) 	 original root is null
b)   parent node does not has a child 'ch', so it passed NULL to the recursive function
	 Ex: If only a path 'ADE' exists, and we delete 'AB'; then node 'A' will not have a child 'B'; so it will pass NULL and return from the recusion 
5. If level has reached the end of the string(string's length)
a)  It is obvious that TRIE has a path 's', so decrement the last nodes is_prefix, because now this string is removed
	EX: Let a TRIE contain ABCD twice, so D will have is_prefix = 2; meaning that this node is the terminating node for 2 strings
		Now ehen we remove ABCD, there should exist only 1 ocurrance of ABCD in the TRIE, so is_prefix of D is now decremented to 1
b)  If the last node has no children; ONLY THEN delete the last node and return NULL; otherwise the last node may have other children and we
	dont delete that node as it would change the structure of TRIE, we only decrease the is_prefix count

*/
struct TrieNode* remove(struct TrieNode* root, int level, string s) 
{
	if(!root)												// STEP 4							
		return NULL;
	
	if(level==s.length())									// Checks if we reached the end of the string
	{
		root->is_prefix--;									// STEP 5 a)
		if(root->child.size()==0)							// STEP 5 b)
		{
			delete (root);
			return NULL;
		}
	}

	char ch = s[level];										// STEP 1
	root->child[ch] = remove(root->child[ch],level+1,s);	// STEP 2

	if(root->child.size()==0 && !root->is_prefix)			// STEP 3; current node has no child and no string ends here
	{
		delete (root);
		return NULL;
	}
	return root;											// if root has some child or it is a prefix; we return root to the previous called func 
}

int main()
{
	struct TrieNode *root = NewTrieNode();
	insert(root,"pqrs");
	insert(root,"pqst");
	insert(root,"psst");
	insert(root,"pqrs");
	
	remove(root,0,"pqs");
	cout<<search(root,"pqst");
	
}
