#include<bits/stdc++.h>
using namespace std;
int Rec(vector<vector<char>> &a,int n,int m,int x1,int y1,int x2,int y2,int dp[11][11][11][11])
{
    if(a[x1][y1] != a[x2][y2])  return 0;
    
    if((x1 == x2 && y1 == y2) || (x1+1 == x2 && y1 == y2) || (x1 == x2 && y1+1 == y2))  return 1;
    
    if(dp[x1][y1][x2][y2] != -1)  return dp[x1][y1][x2][y2];
    
    return dp[x1][y1][x2][y2] =
           
           ((x1 < n-1) ? (( (x2 > 0) ? Rec(a , n , m , x1+1 , y1 , x2-1 , y2 , dp) : 0 ) +
            
                         ( (y2 > 0) ? Rec(a , n , m , x1+1 , y1 , x2 , y2-1 , dp) : 0 )) : 0 ) +
           
           ((y1 < m-1) ? (( (x2 > 0) ? Rec(a , n , m , x1 , y1+1 , x2-1 , y2 , dp) : 0 ) +
            
                         ( (y2 > 0) ? Rec( a , n , m , x1 , y1+1 , x2 , y2-1 , dp) : 0 )) : 0);
}
int PalindromicPaths(vector<vector<char>> &a,int R,int C)
{
	int dp[11][11][11][11];  memset(dp,-1,sizeof(dp));
	    
	return  Rec(a , R , C , 0 , 0 , R-1 , C-1 , dp);
}
signed main()
{
	vector<vector<char>> a = { {'a', 'a', 'a', 'b'}, 
					           {'b', 'a', 'a', 'a'}, 
					           {'a', 'b', 'b', 'a'} };
	int R = a.size();
	int C = a[0].size(); 
	
	cout<< PalindromicPaths(a,R,C) <<endl;
    
	return 0;
}
