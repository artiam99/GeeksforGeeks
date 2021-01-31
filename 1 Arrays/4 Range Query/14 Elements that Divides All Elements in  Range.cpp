#include <bits/stdc++.h> 
using namespace std;

struct stelement
{
	int mn , cnt , gcd;
};

stelement Query(int l ,int r , int ql , int qr , stelement *st , int sti)
{
	stelement temp;
	
	if(l >= ql && r <= qr)
	{
		temp = st[sti];
		
		temp.cnt = 0;
		
		if(st[sti].gcd == st[sti].mn)
		return st[sti];
		
		return temp;
	}
	
	if(l > qr || r < ql)
	{
		temp.gcd = temp.mn = temp.cnt = 0;
		
		return temp;
	}
	
	int m = ((l + r) >> 1);
	
	stelement temp1 = Query(l , m , ql , qr , st , sti * 2 + 1);
	
	stelement temp2 = Query(m + 1 , r , ql , qr , st , sti * 2 + 2);
	
	if(temp1.gcd && temp2.gcd)
	{
		temp.gcd = __gcd(temp1.gcd , temp2.gcd);
		
		temp.mn = min(temp1.mn , temp2.mn);
		
		if(temp.gcd != temp.mn)
		temp.cnt = 0;
		
		else
		{
			if(temp1.mn == temp2.mn)
			temp.cnt = temp1.cnt + temp2.cnt;
			
			else if(temp1.mn < temp2.mn)
			temp.cnt = temp1.cnt;
			
			else
			temp.cnt = temp2.cnt;
		}
		
		return temp;
	}
	
	else if(temp1.gcd)
	return temp1;
	
	else if(temp2.gcd)
	return temp2;
}

void Constructuntill(int a[] , int l , int r, stelement *st , int sti)
{
	if(l == r)
	{
		st[sti].gcd = st[sti].mn = a[r];
		
		st[sti].cnt = 1;
		
		return;
	}
	
	int m = ((l + r) >> 1);
	
	Constructuntill(a , l , m , st , sti * 2 + 1);
    Constructuntill(a , m + 1 , r , st , sti * 2 + 2);
	
	st[sti].gcd = __gcd(st[sti * 2 + 1].gcd , st[sti * 2 + 2].gcd);
	
	st[sti].mn = min(st[sti * 2 + 1].mn , st[sti * 2 + 2].mn);
	
	if(st[sti * 2 + 1].mn == st[sti * 2 + 2].mn)
	st[sti].cnt = st[sti * 2 + 1].cnt + st[sti * 2 + 2].cnt;
	
	else
	st[sti].cnt = ((st[sti * 2  + 1].mn < st[sti * 2 + 2].mn) ? st[sti * 2 + 1].cnt : st[sti * 2 + 2].cnt);
}

stelement* Construct(int a[] , int n)
{
	int p = (int)(ceil(log2(n)));
	
	int size = 2 * (int)pow(2 , p) - 1;
	
	stelement *st = new stelement[size];
	
	Constructuntill(a , 0 , n-1 , st , 0);
	
	return st;
}

int main() 
{ 
	int a[] = {1, 1, 4, 2, 2, 2, 8, 2, 8, 6, 12, 5, 3, 6, 9, 11}; 
	int n = sizeof(a) / sizeof(a[0]);
	
	vector<pair<int,int>> Q = {{0 , 3} , {2 , 10} , {12 , 14}};
	int q = Q.size();
	
	stelement *st = Construct(a , n);
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].first;
		
		int r = Q[i].second;
		
		cout << Query(0 , n-1 , l , r , st , 0).cnt << endl;
	}
	
	return 0; 
}

