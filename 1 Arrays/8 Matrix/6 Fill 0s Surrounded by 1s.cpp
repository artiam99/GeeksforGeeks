#include<bits/stdc++.h>
using namespace std;

void Going_Out(int x , int y , int r , int c , vector<vector<bool>> &a , vector<vector<bool>> &vis , bool &flag)
{	
    if(x == 0 || x == r-1 || y == 0 || y == c-1)
    flag = true;
    
    vis[x][y] = true;
    
    if(x > 0 && !a[x-1][y] && !vis[x-1][y])  Going_Out(x-1 , y , r , c , a , vis , flag);
    if(x < r-1 && !a[x+1][y] && !vis[x+1][y])  Going_Out(x+1 , y , r , c , a , vis , flag);
    if(y > 0 && !a[x][y-1] && !vis[x][y-1])  Going_Out(x , y-1 , r , c , a , vis , flag);
    if(y < c-1 && !a[x][y+1] && !vis[x][y+1])  Going_Out(x , y+1 , r , c , a , vis , flag);
}

void Fill(int x , int y , int r , int c , vector<vector<bool>> &a)
{   
    a[x][y] = true;
    
    if(x > 0 && !a[x-1][y])  Fill(x-1 , y , r , c , a);
    
    if(x < r-1 && !a[x+1][y])  Fill(x+1 , y , r , c , a);
    
    if(y > 0 && !a[x][y-1])  Fill(x , y-1 , r , c , a);

    if(y < c-1 && !a[x][y+1])  Fill(x , y+1 , r , c , a);
}

int Fill_0s(vector<vector<bool>> &a , int r , int c)
{
	vector<vector<bool>> vis(r,vector<bool>(c,false));
	    
    for(int i = 0 ; i < r ; i++)
    for(int j = 0 ; j < c ; j++)
    if(!a[i][j] && !vis[i][j])
    {
        bool flag = false;
        
        Going_Out(i , j , r , c , a , vis , flag);
        
        if(!flag)
        Fill(i , j , r , c , a);
    }
    
    for(auto i : a)
    {
        for(auto j : i)
        cout << j << " ";
        cout << endl;
    }
}

signed main()
{
	vector<vector<bool>> a = { {1 , 0 , 1 , 1 , 1 , 1},
		                       {1 , 0 , 1 , 1 , 0 , 1},
		                       {1 , 1 , 1 , 0 , 0 , 1},
		                       {0 , 1 , 1 , 1 , 1 , 1},
		                       {1 , 1 , 1 , 0 , 1 , 0},
		                       {0 , 0 , 1 , 0 , 0 , 0} };
    int r = a.size();
    int c = a[0].size();
    
    Fill_0s(a , r , c);
    
	return 0;
}
