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
/*
	for (; x <= N; x += (x & -x))
	{
	____for (; y <= N; y += (y & -y)) ________// here y becomes > N for the initial value of x ...
	____BIT[x][y] += val; _________________//So next iterations for the outer loop are useless
	}
	
	for(;y <= N ; y += (y & -y))
	BIT[x][y] += val;
	
	is enough and that's why Complexity for each Getsum and Update are O(logM)\
	Overall Complexity is O((NM + Q) LogM)
	
	if You're Confused about AUX it's useless. it's just rotating the whole matrix clock wise once.
	Because In the question Matrix's (0,0) index is at the bottom left corner (makes no sense though)
	
	Here is a Clean Code : https://ide.geeksforgeeks.o...
	Practice : https://leetcode.com/proble...
	
	Eg.
	
	Mat
	
	2348
	5679
	8908
	
	Initial BIT
	
	00000
	00000
	00000
	00000
	00000
	
	..............................................................................................................
	
	for - Mat[0][0] 2 will be added to first row as 1 dimensional BIT
	
	00000
	02202
	00000
	00000
	00000
	
	Now if we add (say) Mat[1][0]
	
	getsum[1+1][1+1] = 0 , getsum[0+1][1+1] = 2 , getsum[1+1][0+1] = 0 , getsum[0+1][0+1] = 0
	
	getsum[1+1][1+1] - getsum[0+1][1+1] - getsum[1+1][0+1] + getsum[0+1][0+1]) = -2;
	
	diff = Mat[1][0] - (getsum[1+1][1+1] - getsum[0+1][1+1] - getsum[1+1][0+1] + getsum[0+1][0+1])
	= 5 + 2 = 7;
	
	so this 7 will be added to second row as 1 dimensional BIT
	(extra 2 for Mat[0][0] from getsum[0+1][1+1])
	
	00000
	02202
	07707
	00000
	00000
	
	Note that : This Method doesn't support Update Queries (As it's taking values form previous rows and columns , Insertion should be in order)
	
	For Update Queries use a Regular 2D Binary index tree
	
	void Update(int* BIT , int x , int y , int diff)
	{
	____for(int i = x ; i <= N ; i += (i & -i))
	____for(int j = y ; j <= M ; j+= (j & -j))
	____BIT[i][j] += diff;
	}
	
	int Get_Sum(int* BIT , int x , int y)
	{
	____int sum = 0;
	____for(int i = x ; i > 0 ; i -= (i & -i))
	____for(int j = y ; j > 0 ; j -= (j & -j))
	____sum += BIT[i][j];
	____return sum;
	}
	
	This will work But Time Complexity Will Be => O((NM + Q)(LongN * LongM))
*/
