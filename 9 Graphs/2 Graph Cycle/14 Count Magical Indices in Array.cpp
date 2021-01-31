#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
int CountMagicalindices(vector<int> &a,int n)
{
	int parent[n+1];
	memset(parent,-1,sizeof(parent));
	
	int vis[n+1];
	memset(vis,0,sizeof(vis));
	
	int cnt=0;
	
	for(int i=1;i<=n;i++)
	{
		int j=i;
		
		if(parent[j]==-1)
		{
			while(parent[j]==-1)
			{
				parent[j]=i;
				
				j=(j + a[j] )%n +1;
			}
		}
		
		if(parent[j]==i)
		{
			while(!vis[j])
			{
				vis[j]=true;
				cnt++;
				j=( j + a[j] )%n +1;
			}
		}
	}
	return cnt;
}
signed main()
{
	vector<int> a={0, 0, 0, 0, 2};// Considering 1 based indexing
	int n=a.size()-1;
	
	cout<<CountMagicalindices(a,n)<<endl;// i is child , j= ( i + a[i] ) %n +1; 
	
	return 0;
}
