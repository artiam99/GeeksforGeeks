#include<bits/stdc++.h>
using namespace std;
string LargestSubstring(string s,int n,int k)
{
	int alpha[26];  memset(alpha,0,sizeof(alpha));
	
	for(int i = 0 ; i < n ; i++)
	alpha[s[i]-'a']++;
	
	string ans;
	
	int j = 0;
	
	for(int i = 25 ; i >= 0 ; i--)
	{
		if(alpha[i] >= k)
		{
			for(; j < n ; j++)
			{
				if(s[j] == 'a'+i)
				{
					ans += s[j];
					
					alpha[i]--;
					
					if(alpha[i] == 0)
					break;
				}
				else
				alpha[s[j]-'a']--;
			}
		}
	}
	return ans;
}
signed main()
{
	string s = "banana";
	int n = s.length();
	int k = 2;
	
	cout<< LargestSubstring(s,n,k) << endl;
	
    return 0;
}
