#include<bits/stdc++.h>
using namespace std;

void Ans_Queries(string s , int n , vector<pair<int,int>> &Q , int q)
{
	int pref[26][n+1];
	
	for(int i = 0 ; i < 26 ; i++)
	pref[i][0] = 0;
	    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < 26 ; j++)
        pref[j][i+1] = pref[j][i];
        
        pref[s[i] - 'a'][i+1]++;
    }
    
    for(int i = 0 ; i < q ; i++)
    {
        int l = Q[i].first , r = Q[i].second;
        
        int ans = 0;
        
        for(int j = 0 ; j < 26 ; j++)
        ans += (bool)(pref[j][r] - pref[j][l-1]);
        
        cout << ans << " ";
    }
    
    cout << endl;
}

signed main()
{
	string s = "abcbaed";
	int n = s.length();
	
	vector<pair<int,int>> Q = {{1 , 4} , {2 , 4} , {1 , 7}};
	int q = Q.size();
	
	Ans_Queries(s , n , Q , q);
	
	return 0;
}
