#include<bits/stdc++.h>
using namespace std;
#define int long long
static int R[9][9];
static int C[9][9];
static int B[9][9];
bool Rec(int ind,int a[][9])
{
    if(ind == 81)  return true;

    int x = ind / 9 , y = ind % 9;

    if(a[x][y])  return Rec(ind+1,a);

    for(int i = 1 ; i <= 9 ; i++)
    if(!R[x][i-1] && !C[y][i-1] && !B[(x/3)*3 + y/3][i-1])
    {
        a[x][y] = i;

        R[x][i-1] = C[y][i-1] = B[(x/3)*3 + y/3][i-1] = true;

        if(Rec(ind+1,a))  return true;

        R[x][i-1] = C[y][i-1] = B[(x/3)*3 + y/3][i-1] = false;

        a[x][y] = 0;
    }

    return false;
}
void solve(int a[][9])
{
    memset(R,false,sizeof(R));  memset(C,false,sizeof(C));  memset(B,false,sizeof(B));
    
    for(int i = 0 ; i < 9 ; i++)
    for(int j = 0 ; j < 9 ; j++)
    if(a[i][j])
    R[i][a[i][j]-1] = C[j][a[i][j]-1] = B[(i/3)*3 + j/3][a[i][j]-1] = true;

    Rec(0,a);
    
    for(int i = 0 ; i < 9 ; i++)
    {
		for(int j = 0 ; j < 9 ; j++)
    	cout<< a[i][j] << " ";
    	cout<< endl;
    }
}
signed main()
{
	int a[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
                    { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                    { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
                    { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
                    { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
                    { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
                	{ 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
                    { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
                    { 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; ;
	
	solve(a);
	
	return 0;
}
