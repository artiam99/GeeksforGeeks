#include<bits/stdc++.h>
using namespace std;
bool BPTMatchingUntill(int BPT[6][6],int u,vector<bool> &seen,vector<int> &match,int m,int n)
{
	for(int i=0;i<n;i++)
	{
		if(BPT[u][i] && !seen[i])
		{
			seen[i]=true;
			
			if(match[i] == -1 || BPTMatchingUntill(BPT,match[i],seen,match,m,n))
			{
				match[i]=u;
				
				return true;
			}
		}
	}
	return false;
}
int MaxBPTMatching(int BPT[6][6],int m,int n)
{
	vector<int> match(n,-1);
	
	int cnt=0;
	
	for(int i=0;i<m;i++)
	{
		vector<bool> seen(n);
		
		if(BPTMatchingUntill(BPT,i,seen,match,m,n))
		cnt++;
	}
	return cnt;
}
signed main()
{
	int BPT[6][6]={ {0, 1, 1, 0, 0, 0}, 
	                {1, 0, 0, 1, 0, 0}, 
	                {0, 0, 1, 0, 0, 0}, 
	                {0, 0, 1, 1, 0, 0}, 
	                {0, 0, 0, 0, 0, 0}, 
	                {0, 0, 0, 0, 0, 1} };
	
	int n=6,m=6;
	
	cout<< MaxBPTMatching(BPT,m,n) <<endl;
	
	return 0;
}
