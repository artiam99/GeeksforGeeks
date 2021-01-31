#include<bits/stdc++.h>
using namespace std;
int Min_Sum(vector<int> &a,int n,int k)
{
	int op = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] >= k && a[i] % k == 0)
		continue;
		
		else
		{
			if(a[i] < k)
			op += min(abs(a[i]-0) , abs(a[i]-k));
			
			else
			op += min(a[i] - floor(a[i]/(double)k) * k , ceil(a[i]/(double)k) * k - a[i]);
		}
	}
	return op;
}
signed main()
{
	vector<int> a = {4, 5, 6};
	int n = a.size();
	int k = 5;
	
	cout<< Min_Sum(a,n,k) << endl;
	
	return 0;
}
