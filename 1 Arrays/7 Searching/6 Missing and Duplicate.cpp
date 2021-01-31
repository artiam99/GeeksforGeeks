#include<bits/stdc++.h>
using namespace std;

void Missing_Duplicate(vector<int> &a , int n)
{
	int x = 0;
        
    for(int i = 0 ; i < n ; i++)
    x ^= a[i];
    
    for(int i = 1 ; i <= n ; i++)
    x ^= i;
    
    int st = (x & -x);
    
    int x1 = 0 , x2 = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        if((st & a[i]))  x1 ^= a[i];
        
        else  x2 ^= a[i];
    }
    
    for(int i = 1 ; i <= n ; i++)
    {
        if((st & i))  x1 ^= i;
        
        else  x2 ^= i;
    }
    
    for(int i = 0 ; i < n ; i++)
    if(x2 == a[i])
    {
        swap(x1 , x2);
        
        break;
    }
    
    cout << "Duplicate : " << x1 << " and Missing : " << x2 << endl;
}

signed main()
{
	vector<int> a = {1, 4, 1, 3, 2, 6};
	int n = a.size();
	
	Missing_Duplicate(a , n);
	
	return 0;
}
