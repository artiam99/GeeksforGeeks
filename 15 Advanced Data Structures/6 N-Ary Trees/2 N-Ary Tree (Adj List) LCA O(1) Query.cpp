// C++ program to demonstrate LCA of n-ary tree
// in constant time.
#include "bits/stdc++.h"
using namespace std;

#define sz 101

vector<int> adj[sz];
vector<int> euler;
vector<int> depthArr;

int FAI[sz];
int level[sz];
int ptr;
int dp[sz][18];
int logn[sz];
int p2[20];

void buildSparseTable(int n)
{
	memset(dp,-1,sizeof(dp));

	for (int i=1; i<n; i++)
	dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i;

	for (int l=1; l<15; l++)
	for (int i=0; i<n; i++)
	{
		if (dp[i][l-1] != -1 && dp[i+p2[l-1]][l-1] != -1)
		dp[i][l] = (depthArr[dp[i][l-1]] > depthArr[dp[i+p2[l-1]][l-1]]) ? dp[i+p2[l-1]][l-1] : dp[i][l-1];
		
		else break;
	}
}

int query(int l , int r)
{
	int d = r-l;
	
	int dx = logn[d];
	
	if(l == r) return l;
	
	if (depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]])
	return dp[r-p2[dx]][dx];
	
	return dp[l][dx];
}

void preprocess()
{
	p2[0] = 1;
	
	for (int i = 1 ; i < 18 ; i++)
		p2[i] = p2[i-1] * 2;

	int val = 1 , ptr = 0;
	
	for (int i=1; i<sz; i++)
	{
		logn[i] = ptr-1;
		
		if (val==i)
		{
			val*=2;
			
			logn[i] = ptr;
			
			ptr++;
		}
	}
}

void dfs(int cur , int prev , int dep)
{
	if (FAI[cur]==-1)
	FAI[cur] = ptr;

	level[cur] = dep;

	euler.push_back(cur);

	ptr++;

	for (auto x : adj[cur])
	{
		if (x != prev)
		{
			dfs(x , cur , dep+1);

			euler.push_back(cur);

			ptr++;
		}
	}
}

void makeArr()
{
	for (auto x : euler)
	depthArr.push_back(level[x]);
}

int LCA(int u,int v)
{
	if (u == v)
	return u;

	if (FAI[u] > FAI[v])
	swap(u,v);
	
	return euler[query(FAI[u] , FAI[v])];
}

void addEdge(int u , int v)
{
	adj[u].push_back(v);
	
	adj[v].push_back(u);
}

int main(int argc , char const *argv[])
{
	int numberOfNodes = 8;
	
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(2,5);
	addEdge(2,6);
	addEdge(3,7);
	addEdge(3,8);

	preprocess();

	ptr = 0;
	
	memset(FAI,-1,sizeof(FAI));
	
	dfs(1,0,0);

	makeArr();

	buildSparseTable(depthArr.size());
	
	cout << "LCA(6,7) : " << LCA(6,7) << "\n";
	cout << "LCA(6,4) : " << LCA(6,4) << "\n";

	return 0;
}

