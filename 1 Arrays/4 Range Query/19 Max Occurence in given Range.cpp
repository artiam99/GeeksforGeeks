#include <bits/stdc++.h> 
using namespace std;

int Upper(vector<int> &a , int x)
{
	int l = 0 , r = a.size() - 1 , m , res;
	
	while(l <= r)
	{
		m =l + (r - l) / 2;
		
		if(a[m] > x)
		{
			res = m;
			
			r = m - 1;
		}
		
		else
		l = m + 1;
	}
	
	return res;
}

int Lower(vector<int> &a , int x)
{
	int l = 0 , r = a.size() - 1 , m , res;
	
	while(l <= r)
	{
		m = l + (r - l) / 2;
		
		if(a[m] < x)
		{
			res = m;
			
			l = m + 1;
		}
		
		else
		r = m - 1;
	}
	
	return res;
}

int Get_Max(int* st , int l , int r , int ql , int qr , int sti)
{
	if(l >= ql && r<= qr)
	return st[sti];
	
	if(l > qr || r < ql)
	return INT_MIN;
	
	int m = l + (r - l) / 2;
	
	return max(Get_Max(st , l , m , ql , qr , sti * 2 + 1) , Get_Max(st , m + 1 , r , ql , qr , sti * 2 + 2));
}

int Constructuntill(vector<int> &a , int l , int r , int* st , int sti)
{
	if(l == r)
	{
		st[sti] = a[l];
		
		return a[l];
	}
	
	int m = l + (r - l) / 2;
	
	st[sti] = max(Constructuntill(a , l , m , st , sti * 2 + 1) , Constructuntill(a , m + 1 , r , st , sti * 2 + 2));
	
	return st[sti];
}

int* Construct(vector<int> &a , int n)
{
	int p = (int)(ceil(log2(n)));
	
	int size = 2*(int)pow(2 , p) - 1;
	
	int* st = new int[size];
	
	Constructuntill(a , 0 , n-1 , st , 0);
	
	return st;
}

int main() 
{
	vector<int> a = {-5, -5, 2, 2, 2, 2, 3, 7, 7, 7};
	int n = a.size();
	
	vector<pair<int,int>> Q = {{0 , 9} , {4 , 9}};
	int q = Q.size();
	
	vector<int> freq(n);
	
	for(int i = 0 ; i < n ; i++)
	{
		int c = count(a.begin() , a.end() , a[i]);
		
		int j;
		
		for(j = i ; j < i + c ; j++)
		freq[j] = c;
		
		i = j - 1;
	}
	
	vector<int> id;
	
	id.push_back(0);
	
	for(int i = 1 ; i < n ; i++)
	{
		if(a[i] != a[i-1])
		
		id.push_back(i);
	}
	
	int *st = Construct(freq , n);
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].first;
	
		int r = Q[i].second;
	
		int ll = Upper(id , l);
	
		int rr = Lower(id , r);
	
		int ri , li;
	
		ri = id[ll] - l + 1;
		li = r - id[rr] + 1;
		
		int sum = max(ri , li);
		
		cout << max(sum , Get_Max(st , 0 , n-1 , id[ll] , id[rr] - 1 , 0)) << endl;
	}
	
	return 0; 
}
