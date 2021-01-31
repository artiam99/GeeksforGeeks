#include<bits/stdc++.h>
using namespace std;
int First_Element(vector<int> &a,int n,int k)
{
	if(k >= n)  return 0;
	
	int i = 0 , cnt = 0;
	
	while(1)
	{
		if(a[i] > a[(i+1)%n])
		{
			swap(a[i] , a[(i+1)%n]);
			
			i = (i+1) % n;
			
			cnt++;
			
			if(cnt == k)  return a[i];
		}
		else
		{
			cnt = 0;
			
			i = (i+1) % n;
		}
	}
}
signed main()
{
	vector<int> a = {2, 1, 3, 4, 5};
	int n = a.size();
	int k = 2;
	
	cout<< First_Element(a,n,k) << endl;
	
	return 0;
}
