#include <bits/stdc++.h>
using namespace std;
pair<int,int> DFS(vector<pair<int,int>> adj[],int u,int w)
{
    pair<int,int> p = {u,w};
    
    for(auto i:adj[u])
    p = DFS(adj,i.first,i.second);
    
    p.second = min(p.second , w);
    
    return p;
}
void WaterConnection(int n,vector<tuple<int,int,int>> &a,int p)
{
	vector<pair<int,int>> adj[n];
	    
    for(int i = 0 ; i < p ; i++)
    {
        int u = get<0>(a[i])-1 , v = get<1>(a[i])-1 , w = get<2>(a[i]);
        adj[u].push_back({v,w});
    }
    
    int indegree[n]; memset(indegree,0,sizeof(indegree));
    
    for(int i = 0 ; i < n ; i++)
    {
        for(auto j:adj[i])
        indegree[j.first]++;
    }
    
    int cnt = 0;
    
    for(int i = 0 ; i < n ; i++)
    if(!indegree[i] && adj[i].size() != 0)  cnt++;
    
    cout<< cnt << endl;
    
    for(int i = 0 ; i < n ; i++)
    if(!indegree[i] && adj[i].size() != 0)
    {
        pair<int,int> p = DFS(adj,i,INT_MAX);
    
        cout<< i+1 << " " << p.first+1 << " " << p.second << endl;
        
    }
}
int main()
{
	int n = 10;
	
	vector<tuple<int,int,int>> a = {make_tuple(1,7,40) , make_tuple(7,3,5) , make_tuple(3,5,78) ,
								    make_tuple(5,1,33) , make_tuple(9,2,52) , make_tuple(2,6,70) , make_tuple(6,4,47) , make_tuple(4,10,46)};
	int p = a.size();
	
	WaterConnection(n,a,p);
	
	return 0;
}
