#include<bits/stdc++.h>
using namespace std;
int Rec(int x,int y,vector<vector<int>> &dp)
{
	if(x==0 || y==0) return 1;
	
	if(dp[x][y] != -1) return dp[x][y];
	
	return dp[x][y] = Rec(x-1,y,dp) + Rec(x-1,y-1,dp) + Rec(x,y-1,dp);
}
int NoofPaths(int x,int y)
{
	vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
	
	return Rec(x,y,dp);
}
signed main()
{
	int x = 4 , y = 5;  // Number of Paths from North - East Cell (x,y) to Sount - East Cell (0,0) by moving south or east or south east
    
    cout<< NoofPaths(x,y) <<endl;
    
	return 0;
}
