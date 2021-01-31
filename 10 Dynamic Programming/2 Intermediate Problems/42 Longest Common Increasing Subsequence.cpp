#include<bits/stdc++.h>
using namespace std;
int LCIS(vector<int> &a1,int n1,vector<int> &a2,int n2)
{
	vector<int> dp(n2);
	
	for(int i=0 ; i < n1 ; i++)
	{
		int curr = 0;
		
		for(int j=0 ; j < n2 ; j++)
		{
			if(a1[i] == a2[j])
			dp[j] = max(dp[j] , curr + 1);
			
			else if(a1[i] > a2[j])
			curr = max(curr , dp[j]);
		}
	}
	
	return *max_element(dp.begin(),dp.end());
}
signed main()
{
	vector<int> a1 = {5, 3, 8, 9, 10, 2, 1};
	int n1 = a1.size();
	
	vector<int> a2 = {3, 4, 9, 1};
	int n2 = a2.size();
	
	cout<< LCIS(a1,n1,a2,n2) <<endl;
    
	return 0;
}
