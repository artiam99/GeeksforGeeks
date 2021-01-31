#include<bits/stdc++.h>
using namespace std;
int Median(int a1[],int a2[],int n)
{
	if(n == 0)  return -1;
	
	if(n == 1)  return (a1[0] + a2[0]) >> 1;
	
	if(n == 2)  return (max(a1[0],a2[0]) + min(a1[1],a2[1])) >> 1;
	
	int m1 = ((n & 1) ? a1[n/2] : (a1[n/2] + a1[n/2 + 1]) >> 1 );
	
	int m2 = ((n & 1) ? a2[n/2] : (a2[n/2] + a2[n/2 + 1]) >> 1 );
	
	if(m1 == m2)  return m1;
	
	else if(m1 < m2)
	{
		if(n & 1)  return Median(a1 + n/2 , a2 , n - n/2);
		
		return Median(a1 + n/2 - 1, a2 , n - n/2 + 1);
	}
	
	else
	{
		if(n & 1)  return Median(a2 + n/2 , a1 , n - n/2);
		
		return Median(a2 + n/2 - 1, a1 , n - n/2 + 1);
	}
}
signed main()
{
	int a1[] = {1, 2, 3, 6};
	int a2[] = {4, 6, 8, 10};
	int n = sizeof(a1) / sizeof(int);
	
	cout << Median(a1,a2,n) << endl;
	
	return 0;
}
