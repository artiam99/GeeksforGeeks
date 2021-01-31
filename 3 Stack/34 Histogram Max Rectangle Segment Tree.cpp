#include<bits/stdc++.h>
using namespace std;

int RMQ(vector<int> &a , int l , int r , int *st , int ql , int qr , int sti)
{
	if(l >= ql && r <= qr)
	return st[sti];
	
	if(l > qr || r < ql)
	return -1;
	
	int m = ((l + r) >> 1);

	int i1 = RMQ(a , l , m , st , ql , qr , sti * 2 + 1);

	int i2 = RMQ(a , m+1 , r , st , ql , qr , sti * 2 + 2);

	if(i1 == -1)
	return i2;
	
	if(i2 == -1)
	return i1;

	return ((a[i1] < a[i2]) ? i1 : i2);
}

int Constructuntill(vector<int> &a , int l , int r , int* st , int sti)
{
	if(l == r)
	{
		st[sti] = l;
		
		return l;
	}
	
	int m = ((l + r) >> 1);
	
	int i1 = Constructuntill(a , l , m , st , sti * 2 + 1);
	int i2 = Constructuntill(a , m+1 , r ,st , sti * 2 + 2);
	
	st[sti] = ((a[i1] < a[i2]) ? i1 : i2);
	
	return st[sti];
}

int* Construct_st(vector<int> &a , int n)
{
	int p = ceil(log2(n));
	
	int size = 2 * pow(2 , p) - 1;
	
	int *st = new int[size];
	
	Constructuntill(a , 0 , n-1 , st , 0);
	
	return st;
}

int Get_Max(vector<int> &a , int n , int l , int r , int *st)
{
	if(l > r)
	return std::numeric_limits<int>::min();

	if(l == r)
	return a[l];

	int m = RMQ(a , 0 , n-1 , st , l , r , 0);

	return max(max(Get_Max(a , n , l , m-1 , st) , Get_Max(a , n , m+1 , r , st)) , (r - l + 1) * a[m]);
}

int Get_Max_Area(vector<int> &a , int n)
{
	int *st = Construct_st(a , n);
	
	return Get_Max(a , n , 0 , n-1 , st);
}

signed main()
{
	vector<int> a = {6, 2, 5, 4, 5, 1, 6};
	int n = a.size();
	
	cout << "Maximum area of rectangle : " << Get_Max_Area(a , n) << endl;
	
	return 0;
}

