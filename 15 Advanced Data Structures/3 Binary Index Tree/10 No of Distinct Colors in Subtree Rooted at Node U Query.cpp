#include <bits/stdc++.h> 
using namespace std;
void addEdge(vector<int> adj[] , int u , int v)
{
	u--; v--;
	
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int Get_Distinct(int BIT[] , int ind)
{
	int sum = 0;
	
	for(; ind > 0 ; ind -= (ind & -ind))
	sum += BIT[ind];
	
	return sum;
}
void Update(int BIT[] , int n , int ind , int val)
{
	for(; ind <= n ; ind += (ind & -ind))
	BIT[ind] += val;
}
void DFS(int u , vector<int> adj[] , int n , int &timer , int color[] , bool vis[] , int vis_time[] , int Query[] , int BIT[] , int last_vis_color[])
{
	vis[u] = true;
	
	vis_time[u] = ++timer;
	
	if(last_vis_color[color[u]])
	Update(BIT , n , last_vis_color[color[u]] , -1);
	
	last_vis_color[color[u]] = timer;
	
	Update(BIT , n , timer , 1);
	
	for(auto i : adj[u])
	if(!vis[i])
	DFS(i , adj , n , timer , color , vis , vis_time , Query , BIT , last_vis_color);
	
	Query[u] = Get_Distinct(BIT , ++timer) - Get_Distinct(BIT , vis_time[u]);
}
void Answer_Query(int n , int color[] , vector<int> adj[] , int Q[] , int q)  // Number of Distinct elements in flat tree for node u in range [vis_time[u] - dep_time[u]]
{
	int timer = 0;
	
	int vis_time[n];
	
	int Query[n];
	
	int last_vis_color[n];  memset(last_vis_color , 0 , sizeof(last_vis_color));
	
	bool vis[n];  memset(vis , 0 , sizeof(vis));
	
	int BIT[2*n+1];  memset(BIT , 0 , sizeof(BIT));
	
	DFS(0 , adj , 2*n , timer , color , vis , vis_time , Query , BIT , last_vis_color);
	
	for(int i = 0 ; i < q ; i++)
	cout << Query[Q[i]-1] << endl;
}
signed main()
{
	int n = 11;
    int color[] = {0, 2, 3, 3, 4, 1, 3, 4, 3, 2, 1, 1};
    
    vector<int> adj[n];
    
    addEdge(adj , 1, 2);
    addEdge(adj , 1, 3);
    addEdge(adj , 2, 4);
    addEdge(adj , 2, 5);
    addEdge(adj , 2, 6);
    addEdge(adj , 3, 7);
    addEdge(adj , 3, 8);
    addEdge(adj , 7, 9);
    addEdge(adj , 7, 10);
    addEdge(adj , 7, 11);

    int Q[] = {3, 2, 7};
    int q = 3;
    
    Answer_Query(n , color , adj , Q , q);
	
	return 0; 
}
