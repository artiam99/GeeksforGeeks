#include <bits/stdc++.h>
using namespace std;

int Largest_Subarr(vector<int> &a , int n)
{
	int g = 0;
    
    for(int i = 0 ; i < n ; i++)
    g = __gcd(g , a[i]);
    
    if(g != 1)  return -1;
    
    return n;
}

signed main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    
    cout << Largest_Subarr(a , n) << endl;
    
    return 0;
}

