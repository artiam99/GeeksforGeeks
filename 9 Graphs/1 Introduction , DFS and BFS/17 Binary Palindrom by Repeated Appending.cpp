#include<bits/stdc++.h>
using namespace std;
int Binary_Palindrom(int N, int K)
{	    
	vector<bool> a(N);
	    
	for(int i = 0 ; i < N ; i+= K)
	a[i] = 1;
	    
	for(int i = 0 ; i < N ; i++)
	if(a[i] == 1)
	a[N-i-1] = 1;
	    
	int ans = 0;
	
	for(auto i:a)
	ans = ans * 10 + i;
	
	return ans;
}
signed main()
{
	int N = 10 , K = 4;
	
	cout<< Binary_Palindrom(N,K);
	
	return 0;
}
