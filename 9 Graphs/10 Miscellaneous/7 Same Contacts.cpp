#include<bits/stdc++.h>
using namespace std;
#define int long long
struct contact
{
	string field1,field2,field3;
};
void BuildGraph(contact arr[],int n,vector<vector<bool>> &adj)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		if(arr[i].field1==arr[j].field1||
		   arr[i].field1==arr[j].field2||
		   arr[i].field1==arr[j].field3||
		   arr[i].field2==arr[j].field1||
		   arr[i].field2==arr[j].field2||
		   arr[i].field2==arr[j].field3||
		   arr[i].field3==arr[j].field1||
		   arr[i].field3==arr[j].field2||
		   arr[i].field3==arr[j].field3)
		   		adj[i][j]=adj[j][i]=true;
	}
}
void DFS(vector<vector<bool>> &adj,int n,int u,vector<bool> &vis)
{
	vis[u]=true;
	cout<<u<<" ";
	
	for(int i=0;i<n;i++)
	if(adj[u][i] && !vis[i])
	DFS(adj,n,i,vis);
}
void FindSameContacts(contact arr[],int n)
{
	vector<vector<bool>> adj(n,vector<bool>(n,false)); 
	
	BuildGraph(arr,n,adj);
	
	vector<bool> vis(n);
	
	for(int i=0;i<n;i++)
	if(!vis[i])
	{
		DFS(adj,n,i,vis);
		cout<<endl;
	}
}
signed main()
{
	contact arr[] = {{"Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"},
                     {"Lucky", "lucky@gmail.com", "+1234567"},
                     {"gaurav123", "+5412312", "gaurav123@skype.com"},
                     {"gaurav1993", "+5412312", "gaurav@gfgQA.com"},
                     {"raja", "+2231210", "raja@gfg.com"},
                     {"bahubali", "+878312", "raja"}
                    };
	int n=6;
	
	FindSameContacts(arr,n);
	
	return 0;
}
