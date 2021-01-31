#include<bits/stdc++.h>
using namespace std;
int Max_Area(vector<int> &a,int n)
{
	sort(a.begin(),a.end(),greater<int>());
	
	bool flag = 0;
	
	int len , sum = 0;
	
	for(int i = 0 ; i < n-1 ; i++)
	{
		if((a[i] == a[i+1] || a[i] - a[i+1] == 1) && !flag)
		{
			flag = 1;
			
			len = a[i+1];
			
			i++;
		}
		else if((a[i] == a[i+1] || a[i] - a[i+1] == 1) && flag)
		{
			flag = 0;
			
			sum += len * a[i+1];
			
			i++;
		}
	}
	return sum;
}
signed main()
{
	vector<int> a = {3, 4, 6 , 5};
	int n = a.size();
	
	cout<< Max_Area(a,n) << endl;
	
	return 0;
}
