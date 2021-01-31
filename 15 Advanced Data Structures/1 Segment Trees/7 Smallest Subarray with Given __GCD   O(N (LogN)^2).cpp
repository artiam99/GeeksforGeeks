#include<bits/stdc++.h>
using namespace std;
int Get_Gcd(int *st , int sti , int l , int r , int ql , int qr)
{
    if(l >= ql && r <= qr)  return st[sti];
    
    if(l > qr || r < ql)  return 0;
    
    int m = l + (r - l) / 2;
    
    return __gcd(Get_Gcd(st , sti * 2 + 1 , l , m , ql , qr) , Get_Gcd(st , sti * 2 + 2 , m + 1 , r , ql , qr));
}
void ConstructUntill(vector<int> &a , int l ,int r , int *st , int sti)
{
    if(l == r)
    {
        st[sti] = a[l];
        
        return;
    }
    
    int m = l + (r - l) / 2;
    
    ConstructUntill(a , l , m , st , sti * 2 + 1);
    
    ConstructUntill(a , m + 1 , r , st , sti * 2 + 2);
    
    st[sti] = __gcd(st[sti * 2 + 1] , st[sti * 2 + 2]);
}
int* Construct(vector<int> &a,int n)
{
    int p = ceil(log2(n));
    
    int size = 2 * pow(2 , p) - 1;
    
    int *st = new int[size];
    
    ConstructUntill(a , 0 , n - 1 , st , 0);
    
    return st;
}
int Smallest_Subarr(vector<int> &a , int n, int g)
{
    bool found = false;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == g)  return 1;
        
        if(a[i] % g == 0)  found = true;
    }
    
    if(!found)  return -1;
    
    int *st = Construct(a,n);
    
    int mn = INT_MAX;
    
    for(int i = 0 ; i < n-1 ; i++)
    {
        if(a[i] % g)  continue;
        
        int l = i + 1 , r = n - 1;
        
        int closest = 0;
        
        while(1)
        {
            if(r - l <= 1)
            {
                if(Get_Gcd(st , 0 , 0 , n - 1 , i , l) == g)
                closest = l;
                
                else if(Get_Gcd(st , 0 , 0 , n - 1 , i , r) == g)
                closest = r;
                
                break;
            }
            
            int m = l + (r - l) / 2;
            
            int gcd = Get_Gcd(st , 0 , 0 , n - 1 , i , m);
            
            if(gcd > g)  l = m;
            
            else
            {
                if(gcd == g)  closest = m ;
                
                r = m;
            }
        }
        
        if(closest)  mn = min(mn , closest - i + 1);
    }
    
    return mn;
}
signed main()
{
	vector<int> a = {2, 33, 41, 30, 24, 12, 37, 33, 39, 30, 47, 37, 29, 26, 10, 49, 1, 41, 23, 16, 10, 31};
	int n = a.size();
	
	int g = 6;
	
	cout << Smallest_Subarr(a,n,g) << endl;
		
	return 0;
}
