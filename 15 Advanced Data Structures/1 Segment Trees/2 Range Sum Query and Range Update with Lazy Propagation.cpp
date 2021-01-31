#include<bits/stdc++.h>
using namespace std;
void Update(vector<int> &a , int l , int r , int ql , int qr , int diff , int *st , int sti , int lazy[])
{
	if(lazy[sti])
	{
		st[sti] += (r - l + 1) * lazy[sti];  // (r - l + 1) ... because adding lazy to this range
		
		if(l != r)
		{
			lazy[sti * 2 + 1] += lazy[sti];
			
			lazy[sti * 2 + 1] += lazy[sti];
		}
		
		lazy[sti] = 0;
	}
	
	if(l > qr || r < ql)  return;
	
	if(l >= ql && r <= qr)
	{
		st[sti] += (r - l + 1) * diff;
		
		if(l != r)
		{
			lazy[sti * 2 + 1] += diff;
			
			lazy[sti * 2 + 2] += diff;
		}
		
		return;
	}
	
	int m = l + (r - l) / 2;
	
	Update(a , l , m , ql , qr , diff , st , sti * 2 + 1 , lazy);
		
	Update(a , m + 1 , r , ql , qr , diff , st , sti * 2 + 2 , lazy);
	
	st[sti] = st[sti * 2 + 1] + st[sti * 2 + 2];
}
int GetSum(vector<int> &a , int l , int r , int ql , int qr , int *st , int sti ,int lazy[])
{
	if(lazy[sti])
	{
		st[sti] += (r - l + 1) * lazy[sti];
		
		if(l != r)
		{
			lazy[sti * 2 + 1] += lazy[sti];
			
			lazy[sti * 2 + 1] += lazy[sti];
		}
		
		lazy[sti] = 0;
	}
	
	if(l >= ql && r <= qr)  return st[sti];
	
	if(l > qr || r < ql)  return 0;
	
	int m = l + (r - l) / 2;
	
	return GetSum(a , l , m , ql , qr , st , sti * 2 + 1 , lazy) + GetSum(a , m + 1 , r , ql , qr , st , sti * 2 + 2 , lazy);
}
void ConstructUntill(vector<int> &a , int l , int r , int *st , int sti)
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
int* Construct(vector<int> &a , int n)
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
	vector<int> a = {2, 4, -5, 9, 0, 10};
	int n = a.size();
	
	int *st = Construct(a,n);
	
	int *lazy = Construct_Lazy(n);
	
	cout << GetSum(a , 0 , n - 1 , 1 , 4 , st , 0 , lazy) << endl;
	
	Update(a , 0 , n - 1 , 2 , 5 , 10 , st , 0 , lazy);
	
	cout << GetSum(a , 0 , n - 1 , 2 , 4 , st , 0 , lazy) << endl;
	
	return 0;
}
