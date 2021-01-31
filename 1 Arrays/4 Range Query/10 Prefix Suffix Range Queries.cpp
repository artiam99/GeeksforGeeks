#include <bits/stdc++.h>
using namespace std;

void Pref_Suff(vector<int> &a , int n , vector<pair<int,int>> &Q , int q)
{
	vector<int> prefix(n) , suffix(n);
    
    prefix[0] = a[0];
    
    for(int i = 1 ; i < n ; i++)
    prefix[i] = __gcd(prefix[i-1] , a[i]);
    
    suffix[n-1] = a[n-1];
    
	for(int i = n-2 ; i >= 0 ; i--)
    suffix[i] = __gcd(suffix[i+1] , a[i]);
    
    for(int i = 0 ; i < q ; i++)
    {
        int l = Q[i].first;
        int r = Q[i].second;
        
		cout << __gcd(prefix[l-1] , suffix[r+1]) << endl;
    }
}

int main()
{
    vector<int> a = {2, 6, 9};
    int n = a.size();
    
    vector<pair<int,int>> Q = {{0 , 0} , {1 , 1} , {1 , 2}};
    int q = Q.size();
    
    Pref_Suff(a , n , Q , q);
    
    return 0;
}
