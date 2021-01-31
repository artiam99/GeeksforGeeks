#include<bits/stdc++.h>
using namespace std;
int longestSubsequenceCommonSegment(int k,string s1,string s2)
{
	int n = s1.length();
	int m = s2.length();
	
	vector<vector<int>> cnt(n+1,vector<int>(m+1)) , lcs(n+1,vector<int>(m+1));
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1]);
		
		if(s1[i-1] == s2[j-1])
		cnt[i][j] = cnt[i-1][j-1] + 1;
		
		if(cnt[i][j] >=k)
		{
			for(int l=k;l <= cnt[i][j] ; l++)
			lcs[i][j] = max(lcs[i][j] , lcs[i-l][j-l] + l);
		}
	}
	return lcs[n][m];
}
signed main()
{
	int k = 4;
    string s1 = "aggasdfa";
    string s2 = "aggajasdfa";
    
    cout << longestSubsequenceCommonSegment(k, s1, s2) <<endl;
  
    return 0;
}
