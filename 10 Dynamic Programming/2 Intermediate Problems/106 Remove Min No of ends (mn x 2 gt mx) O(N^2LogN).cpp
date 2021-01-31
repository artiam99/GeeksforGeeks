#include<bits/stdc++.h>
using namespace std;
int getmin(int *st,int al,int ar,int ql,int qr,int sti)
{
	if(al >= ql && ar <= qr)  return st[sti];
	
	if(al > qr || ar < ql)  return INT_MAX;
	
	int amid = al + (ar - al) / 2;
	
	return min( getmin(st,al,amid,ql,qr,sti*2+1) , getmin(st,amid+1,ar,ql,qr,sti*2+2) );
}
int ConstMinuntill(vector<int> &a,int al,int ar,int *st,int sti)
{
	if(al==ar)
	{
		st[sti] = a[al];
		
		return a[al];
	}
	
	int m = al + (ar - al) / 2;
	
	st[sti] = min( ConstMinuntill(a,al,m,st,sti*2+1) , ConstMinuntill(a,m+1,ar,st,sti*2+2) );
	
	return st[sti];
}
int* ConstMin(vector<int> &a,int n)
{
	int p=(int)(ceil(log2(n)));
	
	int size=pow(2,p+1)-1;
	
	int *st=new int[size];
	
	ConstMinuntill(a,0,n-1,st,0);
	
	return st;
}
int getmax(int *st,int al,int ar,int ql,int qr,int sti)
{
	if(al >= ql && ar <= qr)  return st[sti];
	
	if(al > qr || ar < ql)  return INT_MIN;
	
	int amid = al + (ar - al) / 2;
	
	return max( getmax(st,al,amid,ql,qr,sti*2+1) , getmax(st,amid+1,ar,ql,qr,sti*2+2) );
}
int ConstMaxuntill(vector<int> &a,int al,int ar,int *st,int sti)
{
	if(al==ar)
	{
		st[sti] = a[al];
		
		return a[al];
	}
	
	int m = al + (ar - al) / 2;
	
	st[sti] = max( ConstMaxuntill(a,al,m,st,sti*2+1) , ConstMaxuntill(a,m+1,ar,st,sti*2+2) );
	
	return st[sti];
}
int* ConstMax(vector<int> &a,int n)
{
	int p=(int)(ceil(log2(n)));
	
	int size=pow(2,p+1)-1;
	
	int *st=new int[size];
	
	ConstMaxuntill(a,0,n-1,st,0);
	
	return st;
}
int MinRemove(vector<int> &a,int n)
{
	int *stmx = ConstMax(a,n);
	int *stmn = ConstMin(a,n);
	
	int dp[n][n];
	    
    for(int i = n-1 ; i >= 0 ; i--)
    for(int j = i ; j < n ; j++)
    {
        if(i==j) dp[i][j] = 0;
        
        else
        {
            int mn = getmin(stmn,0,n-1,i,j,0);
            int mx = getmax(stmx,0,n-1,i,j,0);
            
            dp[i][j] = ((mn*2 >= mx) ? 0 : min(dp[i+1][j] , dp[i][j-1]) + 1);
        }
    }
    return dp[0][n-1];
}
signed main()
{
	vector<int> a = {4 , 5, 100, 9, 10, 11, 12, 15, 200};
	int n = a.size();
	
	cout<< MinRemove(a,n) <<endl;
	
	return 0;
}
