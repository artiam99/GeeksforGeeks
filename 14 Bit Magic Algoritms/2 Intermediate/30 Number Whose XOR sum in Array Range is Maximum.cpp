#include<bits/stdc++.h> 
using namespace std;
void PreProcess(vector<int> &a,int n,int one[][32])
{	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < 32 ; j++)
	{
		if(i == 0)  one[i][j] = 0;
		
		else  one[i][j] = one[i-1][j];
		
		if(a[i] & (1 << j))  one[i][j]++;
	}
}
void AnsQueries(vector<int> &a,int n,vector<pair<int,int>> &Q,int q)
{
	int one[n][32];	 PreProcess(a,n,one);
	
	for(int i = 0 ; i < q ; i++)
	{
		int ans = (~0 ^ INT_MIN);
		
		int l = Q[i].first - 1 , r = Q[i].second - 1;
		
		int tot_bits = r - l + 1;
		
		for(int j = 0 ; j < 32 ; j++)
		{
			int ones = one[r][j] - ((l == 0) ? 0 : one[l-1][j]);
			
			if(ones >= tot_bits - ones)  ans ^= (1 << j);  // Number of ones should be greater than or equal to number of zeros
		}
		
		cout << ans << endl;
	}
}
int main() 
{
	vector<int> a = {20, 11, 18, 2, 13};
	int n = a.size();
	
	vector<pair<int,int>> Q = {{1 , 3} , {3 , 5} , {2 , 4}};
	int q = Q.size();
	
	AnsQueries(a,n,Q,q);
	
	return 0;
}

