#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
void multiply(vector<vector<int>> &A,vector<vector<int>> &B,vector<vector<int>> &C,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			C[i][j]+=A[i][k]*B[k][j];
		}
	}
}
int CountTriangles(vector<vector<int>> &adj,int n)
{
	vector<vector<int>> aux1(n,vector<int>(n,0)),aux2(n,vector<int>(n,0));
	
	multiply(adj,adj,aux1,n);
	multiply(adj,aux1,aux2,n);
	
	int trace=0;
	
	for(int i=0;i<n;i++)
	trace+=aux2[i][i];
	
	return trace/6;
}
signed main()
{
	vector<vector<int>> adj={ {0, 1, 1, 0},
	                          {1, 0, 1, 1},
	                          {1, 1, 0, 1},
	                          {0, 1, 1, 0} };
	                
	int n=4;
	
	cout<< CountTriangles(adj,n) <<endl;
	                
	return 0;
}
