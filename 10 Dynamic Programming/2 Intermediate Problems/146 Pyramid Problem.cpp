#include<bits/stdc++.h>
using namespace std;
int MinCost(vector<int> &a,int n)
{
	int sum = accumulate(a.begin(),a.end(),0);
    
    if(n < 3)
    return sum -1;
    
    vector<int> left(n) , right(n);
    
    left[0] = 1;
    for(int i = 1 ; i < n-1 ; i++)
    left[i] = min(left[i-1] + 1 , a[i]);
    
    right[n-1] = 1;
    for(int i = n-2 ; i > 0 ; i--)
    right[i] = min(right[i+1] + 1 , a[i]);
    
    int mn = INT_MAX;
    
    for(int i = 1 ; i < n-1 ; i++)
    mn = min(mn , (int)(sum - pow(min(left[i],right[i]) , 2)) );
    
    return mn;
}
signed main()
{
	vector<int> a = {1, 2, 3, 4, 2, 1};
	int n = a.size();
	
	cout<< MinCost(a,n) <<endl;
	
	return 0;
}
