#include<bits/stdc++.h>
using namespace std;
int Get_Sum(vector<vector<int>> &BIT , int n , int i , int j)
{
	int sum = 0 ;
	
	if(i == 0)  return 0;
	
	for(; j > 0 ; j &= (j-1))
	sum += BIT[i][j];
	
	return sum;
}
void Update(vector<vector<int>> &BIT , int n , int i , int j , int diff)
{
	for(; j <= n ; j += (j & -j))
	BIT[i][j] += diff;
}
void Construct_BIT(vector<vector<int>> &a , int n , vector<vector<int>> &BIT)
{	
	for(int i = 1 ; i <= n ; i++)
	for(int j = 1 ; j <= n ; j++)
	{
		int v1 = Get_Sum(BIT , n , i , j);
		int v2 = Get_Sum(BIT , n , i-1 , j);
		int v3 = Get_Sum(BIT , n , i , j-1);
		int v4 = Get_Sum(BIT , n , i-1 , j-1);
		
		Update(BIT , n , i , j , a[i-1][j-1] - (v1 - v2 - v3 + v4));
	}
}
int Ans_Queries(vector<vector<int>> &BIT , int n , int x1 , int y1 , int x2 , int y2)
{
	x1++ , y1++ , x2++ , y2++;
	
	return Get_Sum(BIT , n , x2 , y2) - Get_Sum(BIT , n , x2 , y1-1) - Get_Sum(BIT , n , x1 - 1 , y2) + Get_Sum(BIT , n , x1-1 , y1-1);
}
signed main()
{
    vector<vector<int>> a = { {2, 4, 5, 1},
                     		  {4, 6, 3, 2},
                    		  {8, 7, 8, 3},
                    		  {9, 5, 1, 4} };
    int n = a.size();
    
    vector<vector<int>> BIT(n+1,vector<int>(n+1));
	
	Construct_BIT(a , n , BIT);
    
    cout << Ans_Queries(BIT , n , 1 , 1 , 3 , 2) << endl;
    
    cout << Ans_Queries(BIT , n , 2 , 3 , 3 , 3) << endl;
    
    cout << Ans_Queries(BIT , n , 1 , 1 , 1 , 1) << endl;
    
    return 0;
}
