#include<bits/stdc++.h>
using namespace std;
int Max_XOR_Subset(vector<int> &a,int n)
{
	int ind = 0;
    
    for(int i = 30 ; i >= 0 ; i--)
    {
        int mxind , mx = INT_MIN;
        
        for(int j = ind ; j < n ; j++)
        if( (a[j] & (1 << i)) && a[j] > mx )
        {
        	mx = a[j];
			mxind = j;
    	}
    	
        if(mx == INT_MIN)  continue;
        
        swap(a[ind] , a[mxind]);
        
        for(int j = 0 ; j < n ; j++)
        if( j != ind && (a[j] & (1 << i)) )
        a[j] ^= a[ind];
        
        ind++;
    }
    
    int res = 0;
    
    for(int i = 0 ; i < n ; i++)
    res ^= a[i];
    
    return res;
}
signed main()
{
	vector<int> a = {2 , 3};
	int n = a.size();
	
	cout << Max_XOR_Subset(a,n) << endl;
	
	return 0;
}
