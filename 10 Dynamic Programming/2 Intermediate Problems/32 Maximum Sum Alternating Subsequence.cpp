#include<bits/stdc++.h>
using namespace std;
int MSASS(vector<int> &a,int n)
{
	vector<int> dec(n) , inc(n);
	
	inc[0] = a[0];// Starting with a[0] as Increasing
	
	bool flag = 0;
	
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
	{
		if(a[j] > a[i])
		{
			dec[i] = max(dec[i] , inc[j] + a[i]);
			
			flag = 1;
		}
		else if(flag && a[j] < a[i])
		inc[i] = max(inc[i] , dec[j] + a[i]);
	}
	
	int mx = INT_MIN;
	
	for(int i=0;i<n;i++)
	mx = max(mx , max(dec[i] , inc[i]));
	
	return mx;
}
signed main()
{
	vector<int> a = {8, 2, 3, 5, 7, 9, 10};
	int n = a.size();
	
	cout<< MSASS(a,n) <<endl;
    
	return 0;
}
