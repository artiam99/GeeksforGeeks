#include<bits/stdc++.h>
using namespace std;
int SetBits(int *st , int sti , int l , int r , int ql , int qr , int lazy[])
{
	if(lazy[sti])
	{
		st[sti] = lazy[sti];
		
		if(l != r)
		{
			int m = l + (r - l) / 2;
			
			lazy[sti * 2 + 1] = (m - l + 1) - st[sti * 2 + 1];
			
			lazy[sti * 2 + 2] = (r - m) - st[sti * 2 + 2];
		}
		
		lazy[sti] = 0;
	}
	
	if(l > qr || r < ql)  return 0;
	
	if(l >= ql && r <= qr)  return st[sti];
	
	int m = l + (r - l ) / 2;
	
	return SetBits(st , sti * 2 + 1 , l , m , ql , qr , lazy) + SetBits(st , sti * 2 + 2 , m + 1 , r , ql , qr , lazy);
}
void Toggle(int *st , int sti , int l , int r , int ql , int qr , int lazy[])
{
	if(lazy[sti])
	{
		st[sti] = lazy[sti];
		
		if(l != r)
		{
			int m = l + (r - l) / 2;
			
			lazy[sti * 2 + 1] = (m - l + 1) - st[sti * 2 + 1];
			
			lazy[sti * 2 + 2] = (r - m) - st[sti * 2 + 2];
		}
		
		lazy[sti] = 0;
	}

	if(l > qr || r < ql)  return;
	
	if(l >= ql && r <= qr)
	{
		st[sti] = (r - l + 1) - st[sti];
		
		if(l != r)
		{
			int m = l + (r - l) / 2;
			
			lazy[sti * 2 + 1] = (m - l + 1) - st[sti * 2 + 1];
			
			lazy[sti * 2 + 2] = (r - m) - st[sti * 2 + 2];
		}
		
		return;	
	}	
	
	int m = l + (r - l) / 2;
	
	Toggle(st , sti * 2 + 1 , l , m , ql , qr , lazy);
	
	Toggle(st , sti * 2 + 2 , m + 1 , r , ql , qr , lazy);
	
	st[sti] = st[sti * 2 + 1] + st[sti * 2 + 2];
}
void ConstructUntill(vector<bool> &a , int l , int r , int *st , int sti)
{
	if(l == r)
	{
		st[sti] = a[l];
		
		return;
	}
	
	int m = l + (r - l) / 2;
	
	ConstructUntill(a , l , m , st , sti * 2 + 1);
	
	ConstructUntill(a , m + 1 , r , st , sti * 2 + 2);
	
	st[sti] = st[sti * 2 + 1] + st[sti * 2 + 2];
}
int* Construct(vector<bool> &a,int n)
{
	int p = ceil(log2(n));
	
	int size = 2 * pow(2,p) - 1;
	
	int *st = new int[size];
	
	ConstructUntill(a , 0 , n - 1 , st , 0);
	
	return st;
}
int* Construct_Lazy(int n)
{
	int p = ceil(log2(n));
	
	int size = 2 * pow(2,p) - 1;
	
	int *lazy = new int[size];
	
	memset(lazy,0,sizeof(int)*size);
	
	return lazy;
}
signed main()
{
	vector<bool> a = {0 , 1 , 0 , 1 , 1 , 1 , 0 , 1};
	int n = a.size();
	
	int *st = Construct(a,n);
	
	int *lazy = Construct_Lazy(n);
	
	cout << SetBits(st , 0 , 0 , n - 1 , 1 , 4 , lazy) << endl;
	
	Toggle(st , 0 , 0 , n - 1 , 1 , 4 , lazy);
	
	cout << SetBits(st, 0 , 0 , n - 1 , 0 , 5 , lazy) << endl;
		
	return 0;
}
