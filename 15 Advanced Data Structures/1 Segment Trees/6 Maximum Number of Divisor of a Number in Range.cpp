#include<bits/stdc++.h>
using namespace std;
int Fill_Smallest_Prime(int Smallest_Prime[] , int n)  // Seive of Eratosthanes
{	
	for(int i = 0 ; i <= n ; i++)
	Smallest_Prime[i] = INT_MAX;
		
	for(int i = 2 ; i <= n ; i++)
	{
		if(Smallest_Prime[i] == INT_MAX)
		{
			Smallest_Prime[i] = i;
			
			for(int j = i * i ; j <= n ; j += i)
			if(Smallest_Prime[j] > i)
			Smallest_Prime[j] = i;
		}
	}
}
void Fill_Divisor(int Divisor[] , int Smallest_Prime[] , int n)
{
	Divisor[0] = 0;
	
	for(int i = 1 ;  i <= n ; i++)
	{
		Divisor[i] = 1;
		
		int N = i , P = Smallest_Prime[i] , k = 0;
		
		while(N > 1)
		{
			N /= P;
			
			k++;
			
			if(P != Smallest_Prime[N])
			{
				Divisor[i] *= (k + 1);
				
				k = 0;
				
				P = Smallest_Prime[N];
			}
		}
	}
}
int Get_Max(int *st , int sti , int l , int r , int ql , int qr)
{	
	if(l >= ql && r <= qr)  return st[sti];
	
	if(l > qr || r < ql)  return INT_MIN;
	
	int m = l + (r - l) / 2;
	
	return max(Get_Max(st , sti * 2 + 1 , l , m , ql , qr) , Get_Max(st , sti * 2 + 2 , m + 1 , r , ql , qr));
}
void ConstructUntill(int Divisor[] , int l , int r , int *st , int sti)
{
	if(l == r)
	{
		st[sti] = Divisor[l];
		
		return;
	}
	
	int m = l + (r - l) / 2;
	
	ConstructUntill(Divisor , l , m , st , sti * 2 + 1);
	
	ConstructUntill(Divisor , m + 1 , r , st , sti * 2 + 2);
	
	st[sti] = max(st[sti * 2 + 1] , st[sti * 2 + 2]);
}
int* Construct(int Divisor[] , int n)
{
	int p = ceil(log2(n));
	
	int size = 2 * pow(2 , p) - 1;
	
	int *st = new int[size];
	
	ConstructUntill(Divisor , 0 , n - 1 , st , 0);
	
	return st;
}
signed main()
{
	int n = 100;  // 0 to 100 is there
	
	int Smallest_Prime[n+1];  Fill_Smallest_Prime(Smallest_Prime , n);  // Smallest Prime Number in Prime Factorization of i
	
	int Divisor[n+1];  Fill_Divisor(Divisor , Smallest_Prime , n);  // i = p1^k1 * p2^k2 * .. * pj^kj (Prime Factorization), No of Divisors of i = (k1 + 1) * (k2 + 1) * ... * (kj + 1)
	
	int *st = Construct(Divisor , n+1);
	
	vector<pair<int,int>> Q = {{1 , 10} , {34 , 37} , {10 , 99}};
	int q = Q.size();
	
	for(int i = 0 ; i < q ; i++)
	cout << Get_Max(st , 0 , 1 , n , Q[i].first , Q[i].second) << endl;
		
	return 0;
}
