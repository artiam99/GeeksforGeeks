#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	
	vector<int> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<int>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
}
void removepoints(int m,int n,int r,int i,int j,vector<vector<bool>> &vis)
{
	int ru=i-r,rd=i+r,cl=j-r,cr=j+r;
	
	for(int p=ru;p<=rd;p++)
	{
		for(int q=cl;q<=cr;q++)
		{
			if(sqrt(pow(p-i,2)+pow(q-j,2))<=r && p>=0 && p<m && q>=0 && q<n)
			vis[p][q]=true;
		}
	}
}
void DFT(int x,int y,vector<vector<bool>> &vis,int m,int n,bool &b)
{
	if(b)
	return;
	
	if(x==m && y==n)
	{
		b=true;
		return;
	}
	
	vis[x][y]=true;
	
	if(x-1>=0 && !vis[x-1][y])
	DFT(x-1,y,vis,m,n,b);
	
	if(x+1<=m && !vis[x+1][y])
	DFT(x+1,y,vis,m,n,b);
	
	if(y-1>=0 && !vis[x][y-1])
	DFT(x,y-1,vis,m,n,b);
	
	if(y+1<=n && !vis[x][y+1])
	DFT(x,y+1,vis,m,n,b);
}
bool check(int m,int n,int r,vector<pair<int,int>> &p)
{
	vector<vector<bool>> vis(m,vector<bool>(n,false));
	
	for(int i=0;i<p.size();i++)
	removepoints(m,n,r,p[i].first,p[i].second,vis);
	
	bool b=false;
	
	if(!vis[0][0])
	DFT(0,0,vis,m-1,n-1,b);
	
	return b;
}
signed main()
{
	int m = 5, n = 5, r = 1;
	
	vector<pair<int,int>> p= {{0, 2},{2, 2}};
	
	if(check(m,n,r,p))
	cout<<"Possible"<<endl;
	else
	cout<<"Impossible"<<endl;
	
	return 0;
}
