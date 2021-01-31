#include<bits/stdc++.h>
using namespace std;
bool DFS(vector<string> &a,int n,int m,int i,int j,string &x,int ind,bool l,bool r,bool u,bool d,bool lu,bool ld,bool ru,bool rd)
{
    if(a[i][j] != x[ind])  return false;
    
    if(ind == x.length()-1)  return true;   
    
    if(u && i-1 >= 0 && DFS(a,n,m,i-1,j,x,ind+1,0,0,1,0,0,0,0,0))
    return true;
    
    if(d && i+1 < n && DFS(a,n,m,i+1,j,x,ind+1,0,0,0,1,0,0,0,0))
    return true;
    
    if(l && j-1 >= 0 && DFS(a,n,m,i,j-1,x,ind+1,1,0,0,0,0,0,0,0))
    return true;
    
    if(r && j+1 < m && DFS(a,n,m,i,j+1,x,ind+1,0,1,0,0,0,0,0,0))
    return true;
    
    if(lu && i-1 >= 0 && j-1 >= 0 && DFS(a,n,m,i-1,j-1,x,ind+1,0,0,0,0,1,0,0,0))
    return true;
    
    if(ld && i+1 < n && j-1 >= 0 && DFS(a,n,m,i+1,j-1,x,ind+1,0,0,0,0,0,1,0,0))
    return true;
    
    if(ru && i-1 >= 0 && j+1 < m && DFS(a,n,m,i-1,j+1,x,ind+1,0,0,0,0,0,0,1,0))
    return true;
    
    if(rd && i+1 < n && j+1 < m && DFS(a,n,m,i+1,j+1,x,ind+1,0,0,0,0,0,0,0,1))
    return true;
    
    return false;
}
void Print(vector<string> &a,int n,int m,string &x)
{
    bool flag = true;
    
    for(int i = 0 ; i < n ; i++)
    
    for(int j = 0 ; j < m ; j++)
    if(DFS(a,n,m,i,j,x,0,1,1,1,1,1,1,1,1))
    {
        cout<< i << " " << j << ", ";
        
        flag = false;
    }
    if(flag)
    cout<< -1;
}
signed main()
{
	vector<string> a = {"GEEKSFORGEEKS",
			                  "GEEKSQUIZGEEK",
			                  "IDEQAPRACTICE"};
	int n = a.size();
	int m = a[0].length();
	
	string x = "GEEKS";
	
	Print(a,n,m,x);
	
	return 0;
}
