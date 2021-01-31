#include<bits/stdc++.h>
using namespace std;

#define N 100010

vector<int> tree[N];
vector<int> centroidTree[N];
bool centroidMarked[N];
int subtree_size[N];

void addEdge(int u, int v)
{
	tree[u].push_back(v);

	tree[v].push_back(u);
}

void DFS(int u, int p)
{
	subtree_size[u] = 1;
	
	for (auto v : tree[u])
	if (v != p && !centroidMarked[v])
	{
		DFS(v , u);
		
		subtree_size[u] += subtree_size[v];
	}
}

int getCentroid(int u, int p, int n)
{
	bool is_centroid = true;
	
	int heaviest_child = 0;
	
	vector<int>::iterator it;
	
	for (auto v:tree[u])
	{
		if ((v!=p) && !centroidMarked[v])
		{
			if (subtree_size[v] > n/2)
			is_centroid = false;
			
			if (heaviest_child == 0 || subtree_size[v] > subtree_size[heaviest_child])
			heaviest_child = v;
		}
	}
	
	if (is_centroid && n-subtree_size[u] <= n/2)
	return u;
	
	return getCentroid(heaviest_child , u , n);
}

int getCentroid(int u)
{
	DFS(u, -1);

	int centroid = getCentroid(u,-1,subtree_size[u]);

	centroidMarked[centroid] = true;

	return centroid;
}

int decomposeTree(int u)
{
	int cend_tree = getCentroid(u);
	
	printf("%d ", cend_tree);
	
	for (auto v:tree[cend_tree])
	{
		if (!centroidMarked[v])
		{
			int cend_subtree = decomposeTree(v);
			
			centroidTree[cend_tree].push_back(cend_subtree);
			
			centroidTree[cend_subtree].push_back(cend_tree);
		}
	}
	
	return cend_tree;
}

int main()
{
	/*  O(N LogN) Algo
	
		Used in Queris over Trees
		
		Properties of centroid tree :
										Height = LogN as Subtree size is less than equal to N/2 ... N/2 => N/4 ... 1   So LogN
										
										LCA of U and V in Centroid Tree Must lie in the path from u to v ... Finding LCA in Centroid Tree takes N LogN
	*/
	
	int n = 16;
	
	addEdge(1, 4);
	addEdge(2, 4);
	addEdge(3, 4);
	addEdge(4, 5);
	addEdge(5, 6);
	addEdge(6, 7);
	addEdge(7, 8);
	addEdge(7, 9);
	addEdge(6, 10);
	addEdge(10, 11);
	addEdge(11, 12);
	addEdge(11, 13);
	addEdge(12, 14);
	addEdge(13, 15);
	addEdge(13, 16);
	
	decomposeTree(1);
	
	return 0;
}
