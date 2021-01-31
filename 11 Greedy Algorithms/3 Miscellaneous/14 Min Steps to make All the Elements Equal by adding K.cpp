#include<bits/stdc++.h>
using namespace std;
int Min_Steps(vector<int> &a,int n,int k)
{
	int mx = *max_element(a.begin(),a.end());
	
	int res = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if((mx - a[i]) % k != 0)
		return -1;
		
		res += (mx - a[i]) / k;
	}
	
	return res;
}
signed main()
{
	vector<int> a = {4, 7, 19, 16};
	int n = a.size();
	int k = 3;
	
	cout<< Min_Steps(a,n,k) << endl;
    
    return 0;
}
