#include<bits/stdc++.h>
using namespace std;
#define int long long
void Construct(vector<int> &deg,int n)
{
	vector<vector<bool>> mat(n,vector<bool>(n,0));
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		if(deg[i] && deg[j])
		{
			deg[i]--;
			deg[j]--;
			mat[i][j]=mat[j][i]=true;
		}
	}
	
	for(auto i:mat)
	{
		for(auto j:i)
		cout<<j<<" ";
		cout<<endl;
	}
}
signed main()
{
	vector<int> deg={2,2,1,1};
	int n=deg.size();
	
	Construct(deg,n);
	
	return 0;
}
