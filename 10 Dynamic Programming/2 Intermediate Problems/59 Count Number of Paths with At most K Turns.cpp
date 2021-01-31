#include<bits/stdc++.h>
using namespace std;
int totalWays(int i, int j, int k, bool isCol ,int n ,int m)
{
	if (k == -1 || i >= n || j >= m )  return 0;
	
	if (k == 0 && i == n - 1 && j == m - 1)  return 1;

	if (isCol)  return totalWays(i + 1, j, k, isCol, n, m) +  totalWays(i, j + 1, k - 1, !isCol, n, m);
	
	return totalWays(i, j + 1, k, isCol, n, m) + totalWays(i + 1, j, k - 1, !isCol, n, m);
}
int MaxTurns(int n,int m,int k)
{
	int ans = 0;
	
	for(int i = 1 ; i <= k ; i++)
	ans += totalWays( 1 , 0, i, true, n, m) + totalWays( 0, 1, i, false, n, m);
	
	return ans;
}
signed main()
{
	int n = 3 , m = 3 , k = 2;
	
	cout<< MaxTurns(n,m,k) <<endl;
    
	return 0;
}
