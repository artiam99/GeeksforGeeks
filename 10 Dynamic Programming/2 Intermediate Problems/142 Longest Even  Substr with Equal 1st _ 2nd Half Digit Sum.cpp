#include<bits/stdc++.h>
using namespace std;
int LongestSubString(string &s)
{
	int n = s.length();
	
	int mx = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		int l = i , r = i+1;
		
		int lsum = 0 , rsum = 0;
		
		while(l >= 0 && r < n)
		{
			lsum += s[l]-48;
			rsum += s[r]-48;
			
			if(lsum == rsum)
			mx = max(mx , r-l+1);
			
			l--;
			r++;
		}
	}
	return mx;
}
signed main()
{
	string s = "1234123";
	
	cout<< LongestSubString(s) <<endl;
	
	return 0;
}
