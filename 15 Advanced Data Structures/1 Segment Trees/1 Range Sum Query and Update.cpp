#include<bits/stdc++.h>
using namespace std;
void Update(vector<int> &a , int l , int r , int ind , int diff , int *st , int sti)
{
	if(ind < l || ind > r)  return;
	
	st[sti] += diff;
	
	int m = l + (r - l) / 2;
	
	if(l < r)
	{
		Update(a , l , m , ind , diff , st , sti * 2 + 1);
		
		Update(a , m + 1 , r , ind , diff , st , sti * 2 + 2);
	}
}
int GetSum(vector<int> &a , int l , int r , int ql , int qr , int *st , int sti)
{
	if(l >= ql && r <= qr)  return st[sti];
	
	if(l > qr || r < ql)  return 0;
	
	int m = l + (r - l) / 2;
	
	return GetSum(a , l , m , ql , qr , st , sti * 2 + 1) + GetSum(a , m + 1 , r , ql , qr , st , sti * 2 + 2);
}
void Answer_Queries(vector<int> &a , int n , vector<pair<int,pair<int,int>>> &Q , int q , int *st)
{
	for(int i = 0 ; i < q ; i++)
	{
		if(Q[i].first)  Update(a , 0 , n - 1 , Q[i].second.first , Q[i].second.second - a[Q[i].second.first] , st , 0);
		
		else  cout << GetSum(a , 0 , n - 1 , Q[i].second.first , Q[i].second.second , st , 0) << endl;
	}
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
signed main()
{
	vector<int> a = {2, 4, -5, 9, 0, 10};
	int n = a.size();
	
	vector<pair<int,pair<int,int>>> Q = {{0 , {1 , 4}} , {1 , {3 , 11}} , {0 , {2 , 4}}};
	int q = Q.size();
	
	int *st = Construct(a,n);
	
	Answer_Queries(a,n,Q,q,st);
		
	return 0;
}
