#include<bits/stdc++.h>
using namespace std;
int DistinctSubsequences(string s,int n)
{
	vector<int> a(26);
	
	int mod = 1000000007;
	
	int sum = 1; // only NULL
	
	for(int i = 0 ; i < n ; i++)
	{
		int temp = (mod + (sum * 2 - a[s[i]-'a']) % mod) % mod;  // a + b - c => (a % mod + ( mod + (b - c) % mod) % mod) %mod
		
		a[s[i]-'a'] = (a[s[i]-'a'] % mod + (mod + (temp - sum) % mod) % mod) % mod;  // temp = sum * 2 - a[s[i]-'a'] .. sum is subsequences until i-1 index 
		                                                                            //  a[s[i]-'a'] is number of subsequences ended with s[i]
		sum = temp;
	}
	return sum;
}
signed main()
{
	string s = "gfg";
	int n = s.length();
	
	cout<< DistinctSubsequences(s,n) <<endl;
    
	return 0;
}
