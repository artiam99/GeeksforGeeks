#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int n,int M,int l,int m,vector<int> &dp,vector<int> &end)
{
    if(l == n)  return 0;
    
    if(dp[l] != -1)  return dp[l];
    
    dp[l] = INT_MAX;
    
    for(int i = l ; a[i] <= m ; i++)
    {
        int x = Rec(a , n , M , i+1 , M+a[i]+2 , dp , end) + ((i+1 == n) ? 0 : pow(m - a[i],2) );
        
        if(dp[l] > x)
        {
            dp[l] = x;
            
            end[l] = i+1;
        }
    }
    return dp[l];
}
void Lines_with_Min_Cost(vector<int> &a,int n,int m)
{
	a[0]--;
    for(int i = 1 ; i < n ; i++)
    a[i] += a[i-1] + 1;
    
    vector<int> dp(n,-1) , end(n);
    
    Rec(a , n , m-1 , 0 , m-1 , dp , end);
    
    int i = 0;
    while(i < n)
    {
        cout<< i+1 << " " << end[i] << " ";
        
        i = end[i];
    }
    
    cout<<endl;
}
signed main()
{
	vector<int> a = {3, 2, 2, 5};
	int n = a.size();
	
	int m = 6;
	
	Lines_with_Min_Cost(a,n,m);
    
	return 0;
}
