#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> a[],int n,int C,int cap_type,int mask,vector<vector<int>> &dp)
{
	if(mask == ((1 << n) - 1))  return 1;
	
	if(cap_type > C)  return 0;
	
	if(dp[cap_type][mask] != -1)  return dp[cap_type][mask];
	
	int ways = Rec(a , n , C , cap_type + 1 , mask , dp);
	
	for(int i = 0 ; i < n ; i++)
	if(!(mask & (1 << i)))
	{		
		for(int j = 0 ; j < a[i].size() ; j++)
		if(a[i][j] == cap_type)
		{
			ways += Rec(a , n , C , cap_type + 1 , mask | (1 << i) , dp);
			
			break;
		}
	}
	return dp[cap_type][mask] = ways;
}
int Count_Ways(int C,int n,vector<int> a[])
{
	vector<vector<int>> dp(C+1,vector<int>((1 << n),-1));
	
	return Rec(a , n , C , 1 , 0 , dp);
}
signed main()
{
	int C = 100;  // 1 to 100 unique types of caps are there
	
	int n = 3;  // 1 <= n <= 10 .. n people is there
	
	vector<int> a[] = { {5, 100, 1},
						{2},
						{5, 100} };
	
	cout << Count_Ways(C,n,a) << endl;
	
	return 0;
}
