#include<bits/stdc++.h>
using namespace std;
string Rec(int pos[27][27],int l,int r)
{
	    string s;
    
    int i = pos[l][r];
    
    s += '(';
    
    if(l > i-1)  s+= (char)('A' + i - 1 );
    
    else  s += Rec(pos,l,i-1);
        
    if(i+1 > r)  s += (char)('A' + i);
    
    else  s += Rec(pos,i+1,r);
        
    s += ')';
                    
    return s;
}
string MCMBracket(vector<int> &a,int n)
{	
	int dp[n-1][n-1];
	
	int pos[27][27];
	
	for(int i = n-2 ; i >= 1 ; i--)
	{
		for(int j = i ; j <= n-2 ; j++)
		{
			dp[i][j] = INT_MAX;
			
			for(int k = i ; k <= j ; k++)
			if(dp[i][j] > ((i > k-1) ? 0 : dp[i][k-1]) + ((k+1 > j) ? 0 : dp[k+1][j]) + a[i-1] * a[k] * a[j+1])
			{
				dp[i][j] = ((i > k-1) ? 0 : dp[i][k-1]) + ((k+1 > j) ? 0 : dp[k+1][j]) + a[i-1] * a[k] * a[j+1];
				
				pos[i][j] = k;
			}
		}
	}
	
	return Rec(pos,1,n-2);
}
signed main()
{
	vector<int> a = {40 , 20 , 30 , 10 , 30};
	int n = a.size();
	
	cout<< MCMBracket(a,n) <<endl;
    
	return 0;
}
