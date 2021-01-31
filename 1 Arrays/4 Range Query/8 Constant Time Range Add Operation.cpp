#include<bits/stdc++.h> 
using namespace std;

void Add100(vector<int> &a , int n , vector<pair<int,pair<int,int>>> &Q , int q)
{
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].second.first;
		
		int r = Q[i].second.second;
		
		int v = Q[i].first;
		
		a[l] += v;
		
		a[r+1] -= v;
	}
	
	for(int i = 1 ; i < n ; i++)
	a[i] += a[i-1];
}

signed main() 
{ 
    vector<int> a(6,0);
    int n = a.size();
    
	vector<pair<int,pair<int,int>>> Q={{100 , {0 , 2}} , {200 , {1 , 5}} , {400 , {2 , 3}}};
    int q = Q.size();
    
	Add100(a , n , Q , q);
	
    for(int i = 0 ; i < n ; i++)
    cout << a[i] << " ";
    cout << endl;
    
	return 0; 
}
 
