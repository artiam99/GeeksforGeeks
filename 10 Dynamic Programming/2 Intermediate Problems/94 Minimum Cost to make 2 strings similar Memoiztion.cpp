#include<bits/stdc++.h>
using namespace std;
int Rec(string &x,string &y,int i,int j,int &cx,int &cy,vector<vector<int>> &dp)
{
    if(i == x.length())  return (y.length()-j)*cy;

    if(j == y.length())  return (x.length()-i)*cx;
    
    if(dp[i][j]!=-1)  return dp[i][j];
    
    if(x[i] == y[j])
    return dp[i][j] = min( Rec(x,y,i+1,j+1,cx,cy,dp) , min( Rec(x,y,i+1,j,cx,cy,dp) + cx , Rec(x,y,i,j+1,cx,cy,dp) + cy ) );
    
	return dp[i][j] = min( Rec(x,y,i+1,j+1,cx,cy,dp) + cx + cy , min(Rec(x,y,i+1,j,cx,cy,dp) + cx , Rec(x,y,i,j+1,cx,cy,dp) + cy ) );
}
int MinCost(string x, string y, int cx, int cy)
{
    vector<vector<int>> dp(x.length(),vector<int>(y.length(),-1));
    
	return Rec(x,y,0,0,cx,cy,dp);
}
signed main()
{
	string x = "acbd";
	string y = "abcd";
	
	int cx = 10;
	int cy = 20;
	
	cout<< MinCost(x,y,cx,cy) <<endl;
	
	return 0;
}
