#include<bits/stdc++.h>
using namespace std;
int Rec(int p,int q,int r,char x,int dp[10][10][10][3])
{
    if(p==0 && q==0 && r==0) return 1;
    
    if((x=='p' || x=='q' || x=='r') && dp[p][q][r][x-'p'] != -1)  return dp[p][q][r][x-'p'];
    
    int ans= ((p > 0 && x != 'p') ? Rec(p-1 , q , r , 'p' , dp) : 0) +
             ((q > 0 && x != 'q') ? Rec(p , q-1 , r , 'q' , dp) : 0) + 
             ((r > 0 && x != 'r') ? Rec(p , q , r-1 , 'r' , dp) : 0);
   
   if(x=='p' || x=='q' || x=='r')  dp[p][q][r][x-'p'] = ans;
   
   return ans;
}
int Arrange(int P,int Q,int R)
{
	int dp[10][10][10][3];  memset(dp,-1,sizeof(dp));
	    
	return Rec(P,Q,R,'m',dp);
}
signed main()
{
	int P = 2 , Q = 2 , R = 2;
	
	cout<< Arrange(P,Q,R) <<endl;
	
	return 0;
}
