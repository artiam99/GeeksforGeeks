#include<bits/stdc++.h> 
using namespace std;

void Updateuntill(int *st , int l , int r , int i , int diff , int sti)
{
	if(i < l || i > r)
	return;
	
	st[sti] += diff;
	
	if(l != r)
	{
		int m = l + (r - l) / 2;
		
    	Updateuntill(st , l , m , i , diff , sti * 2 + 1);
    	
    	Updateuntill(st , m + 1 , r , i , diff , sti * 2 + 2);
	}
}

int Update(int a[] , int *st , int n , int ind , int nw)
{
	int diff = nw - a[ind];
	
	a[ind] = nw;
	
	Updateuntill(st , 0 , n-1 , ind , diff , 0);
}

int Get_gcd(int *st , int l , int r , int ql , int qr , int sti)
{
	if(l >= l && r <= qr)
	return st[sti];
	
	if(l > qr || r < ql)
	return 0;
	
	int m = l + (r - l) / 2;
	
	return __gcd(Get_gcd(st , l , m , l , r , sti * 2 + 1) , Get_gcd(st , m + 1 , r , ql , qr , sti * 2 + 2));

}
int Constructuntill(int a[] , int l , int r , int *st , int sti)
{
	if(l == r)
	{
		st[sti] = a[l];
		
		return a[l];
	}
	
	int m = l + (r - l) / 2;
	
	st[sti] = __gcd(Constructuntill(a , l , m , st , sti * 2 + 1) , Constructuntill(a , m + 1 , r , st , sti * 2 + 2));
	
	return st[sti];
}

int* Constructst(int a[] , int n)
{
	int p = (int)(ceil(log2(n)));
	
	int size = 2 * pow(2 , p) - 1;
	
	int *st = new int[size];
	
	Constructuntill(a , 0 , n-1 , st , 0);
	
	return st;
}

int main() 
{ 
    int a[] = {1, 3, 6, 9, 9, 11};
    int n = sizeof(a)/sizeof(int);
    
	int *st = Constructst(a , n);
	
    cout << Get_gcd(st , 0 , n-1 , 1 , 3 , 0) << endl;
    
	Update(a , st , n , 1 , 6);
	
    cout << Get_gcd(st , 0 , n-1 , 0 , 1 , 3);
    
	return 0; 
}
 
