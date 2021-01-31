#include<bits/stdc++.h>
using namespace std;
bool Rec(vector<vector<int>> &a,int lx,int ly,int rx,int ry,int X)
    {
        if(lx > rx || ly > ry)  return false;
        
        if(lx == rx && ly == ry)  return (a[lx][ly] == X);
        
        int mx = (lx + rx) / 2 , my = (ly + ry) / 2;
        
        if(a[mx][my] == X)  return true;
        
        else if(a[mx][my] < X)
        {
            if(Rec(a,lx,my+1,mx,ry,X))  return true;
            
            if(Rec(a,mx+1,ly,rx,my,X))  return true;
            
            if(Rec(a,mx+1,my+1,rx,ry,X))  return true;
        }
        
        else
        {
            if(Rec(a,lx,my,mx-1,ry,X))  return true;
            
            if(Rec(a,mx,ly,rx,my-1,X))  return true;
            
            if(Rec(a,lx,ly,mx-1,my-1,X))  return true;
        }
        
        return false;
    }
bool Search(vector<vector<int>> &a,int n,int m,int x)
{
	return Rec(a,0,0,n-1,m-1,x);
}
int main()
{
	vector<vector<int>> a = { {10, 20, 30, 40},
                              {15, 25, 35, 45},
                              {27, 29, 37, 48},
                              {32, 33, 39, 50} };
	int n = a.size();
	int m = a[0].size();
	int x = 37;
	
	if(Search(a,n,m,x))  cout << "Present" << endl;
	
	else  cout << "Not Present" << endl;
	 
    return 0;
}
