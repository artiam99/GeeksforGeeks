#include<bits/stdc++.h>
using namespace std;
int MSASS(vector<int> &a,int n)
{
	vector<int> dec(n,1) , inc(n,1);
		
	int mx = 1;
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j] > a[i])
			dec[i] = max(dec[i] , inc[j] + 1);

			else if(a[j] < a[i])
			inc[i] = max(inc[i] , dec[j] + 1);
		}
		mx = max(mx , max(dec[i] , inc[i]));
	}
	
	return mx;
}
signed main()
{
	vector<int> a = {10, 22, 9, 33, 49, 50, 31, 60};
	int n = a.size();
	
	cout<< MSASS(a,n) <<endl;
    
	return 0;
}
