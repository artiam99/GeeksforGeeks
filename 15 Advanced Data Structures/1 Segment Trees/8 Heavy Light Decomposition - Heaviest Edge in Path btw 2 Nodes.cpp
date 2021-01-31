#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int parent , depth , size , chain , st_pos;
};
struct Edge
{
	int wt , deeper_end;
};
struct SegmentTree
{
	int *base_array , *tree;
	
	SegmentTree(int n)
	{
		base_array = new int[n];
		
		int p = ceil(log2(n)) , size = 2 * pow(2 , p) - 1;
		
		tree = new int[size];  memset(tree,-1,sizeof(int)*size);	
	}
};
void addEdge(int id , int u , int v , int w , Edge edge[] , vector<vector<int>> &tree)
{
	tree[u-1][v-1] = tree[v-1][u-1] = id - 1;
	
	edge[id-1].wt = w;
}
void DFS(int curr , int prev , int dep , int n , Node TreeNode[] , Edge edge[] , vector<vector<int>> &tree)
{
	TreeNode[curr].parent = prev;
	
	TreeNode[curr].depth = dep;
	
	TreeNode[curr].size = 1;
	
	for(int i = 0 ; i < n ; i++)
	if(i != curr && i != prev && tree[curr][i] != -1)
	{
		edge[tree[curr][i]].deeper_end = i;
		
		DFS(i , curr , dep + 1 , n , TreeNode , edge , tree);
		
		TreeNode[curr].size += TreeNode[i].size;
	}
}
void HLD(int curr , int id , int &edge_count , int &curr_chain , int n , int Chain_Heads[] , Node TreeNode[] , Edge edge[] , vector<vector<int>> &tree , SegmentTree &st)
{
	if(Chain_Heads[curr_chain] == -1)  Chain_Heads[curr_chain] = curr;
	
	TreeNode[curr].chain = curr_chain;
	
	TreeNode[curr].st_pos = edge_count;
	
	st.base_array[edge_count++] = edge[id].wt;
	
	int sp_chld = -1 , sp_chld_id;
	
	for(int i = 0 ; i < n ; i++)
	if(i != curr && i != TreeNode[curr].parent && tree[curr][i] != -1)
	{
		if(sp_chld == -1 || TreeNode[sp_chld].size < TreeNode[i].size)
		sp_chld = i , sp_chld_id = tree[curr][i];
	}
	
	if(sp_chld != -1)  HLD(sp_chld , sp_chld_id , edge_count , curr_chain , n , Chain_Heads , TreeNode , edge , tree , st);
	
	for(int i = 0 ; i < n ; i++)
	if(i != curr && i != TreeNode[curr].parent && tree[curr][i] != -1 && i != sp_chld)
	{
		curr_chain++;
		
		HLD(i , tree[curr][i] , edge_count , curr_chain , n , Chain_Heads , TreeNode , edge , tree , st);
	}
}
int RMQ(int l , int r , int ql , int qr , SegmentTree &st , int sti)
{
	if(l >= ql && r <= qr)  return st.tree[sti];
	
	if(l > qr || r < ql)  return INT_MIN;
	
	int m = l + (r - l) / 2;
	
	return max(RMQ(l , m , ql , qr , st , sti * 2 + 1) , RMQ(m + 1 , r , ql , qr , st , sti * 2 + 2));
}
void Update(int l , int r , SegmentTree &st , int sti , int x , int val)
{	
	if(l == r && l == x)
	{
		st.tree[sti] = val;
		
		return;
	}
	
	if(x < l || x > r)  return;
	
	int m = (r + l) / 2;
	
	Update(l , m , st , sti * 2 + 1 , x , val);
	
	Update(m + 1 , r , st , sti * 2 + 2 , x , val);
	
	st.tree[sti] = max(st.tree[sti * 2 + 1] , st.tree[sti * 2 + 2]);
}
void Construct_ST(int l , int r , SegmentTree &st , int sti)
{
	if(l == r)
	{
		st.tree[sti] = st.base_array[l];
		
		return;
	}
	
	int m = l + (r - l) / 2;
	
	Construct_ST(l , m , st , sti * 2 + 1);
	
	Construct_ST(m + 1 , r , st , sti * 2 + 2);
	
	st.tree[sti] = max(st.tree[sti * 2 + 1] , st.tree[sti * 2 + 2]);
}
int LCA(int u , int v , Node TreeNode[])
{	
	if(TreeNode[u].depth < TreeNode[v].depth)
	swap(u , v);
	
	while(TreeNode[u].depth > TreeNode[v].depth)
	u = TreeNode[u].parent;
	
	while(u != v)	
	u = TreeNode[u].parent , v = TreeNode[v].parent;
	
	return v;
}
int Crawl_Up(int u , int v , int edge_count , int Chain_Heads[] , Node TreeNode[] , SegmentTree &st)
{
	int chain_u , chain_v = TreeNode[v].chain , ans = 0;
	
	while(1)
	{
		chain_u = TreeNode[u].chain;
		
		if(chain_u == chain_v)
		{
			if(u != v)  ans = max(ans , RMQ(0 , edge_count - 1 , TreeNode[v].st_pos + 1 , TreeNode[u].st_pos , st , 0));
			
			break;
		}
		
		else
		{
			ans = max(ans , RMQ(0 , edge_count - 1 , TreeNode[Chain_Heads[chain_u]].st_pos , TreeNode[u].st_pos , st , 0));
			
			u = TreeNode[Chain_Heads[chain_u]].parent;
		}
	}
	
	return ans;
}
int MaxEdge(int u , int v , int edge_count , int Chain_Heads[] , Node TreeNode[] , SegmentTree &st)
{
	int lca = LCA(u , v , TreeNode);
	
	return max(Crawl_Up(u , lca , edge_count , Chain_Heads , TreeNode , st) , Crawl_Up(v , lca , edge_count , Chain_Heads , TreeNode , st));
}
void Change(int e , int val , int edge_count , Node TreeNode[] , Edge edge[] , SegmentTree &st)
{
	Update(0 , edge_count - 1 , st , 0 , TreeNode[edge[e].deeper_end].st_pos , val);
}
signed main()
{
	int n = 11;
	
	Node TreeNode[n];
	
	Edge edge[n];  edge[n-1].wt = 0;
		
	vector<vector<int>> tree(n,vector<int>(n,-1));
	
	SegmentTree st(n);
	
	addEdge(1, 1, 2, 13 , edge , tree);
    addEdge(2, 1, 3, 9 , edge , tree);
    addEdge(3, 1, 4, 23 , edge , tree);
    addEdge(4, 2, 5, 4 , edge , tree);
    addEdge(5, 2, 6, 25 , edge , tree);
    addEdge(6, 3, 7, 29 , edge , tree);
    addEdge(7, 6, 8, 5 , edge , tree);
    addEdge(8, 7, 9, 30 , edge , tree);
    addEdge(9, 8, 10, 1 , edge , tree);
    addEdge(10, 8, 11, 6 , edge , tree);
    
    int root = 0 , parent_of_root = -1 , depth_of_root = 0;
    
    DFS(root , parent_of_root , depth_of_root , n , TreeNode , edge , tree);
    
    int Chain_Heads[n];  memset(Chain_Heads , -1 , sizeof(int)*n);
    
    int edge_count = 0 , curr_chain = 0;
    
    HLD(root , n - 1 , edge_count , curr_chain , n , Chain_Heads , TreeNode , edge , tree , st);
    
    Construct_ST(0 , edge_count - 1 , st , 0);
    
    //.......................................................................................................................................
    
    int u = 11 , v = 9;
    cout << "Max Edge in Path between 11 to 9 is : " << MaxEdge(u-1 , v-1 , edge_count , Chain_Heads , TreeNode , st) << endl;
    
    int e = 8;
    Change(e-1 , 28 , edge_count , TreeNode , edge , st);
    
    cout << "Max Edge in Path between 11 to 9 is : " << MaxEdge(u-1 , v-1 , edge_count , Chain_Heads , TreeNode , st) << endl;
		
	return 0;
}
