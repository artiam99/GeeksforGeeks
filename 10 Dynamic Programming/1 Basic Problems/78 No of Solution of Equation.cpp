#include<bits/stdc++.h>
using namespace std;
int NoofSolution(vector<int> &coeff,int n,int rhs)
{	
	vector<int> dp(rhs+1);
	dp[0]=1;
	
	for(int i=0;i<n;i++)
	for(int j=coeff[i];j<=rhs;j++)
	dp[j]+=dp[j-coeff[i]];
	
	return dp[rhs];
}
signed main()
{
	vector<int> coeff = {2,2,5};  // 2 x + 2 y + 5 z = 4  ... Positive Coefficient and Positive Solutions
	int n=coeff.size();
	
	int rhs=4;
	
	cout<< NoofSolution(coeff,n,rhs) <<endl;
	
	return 0;
}
