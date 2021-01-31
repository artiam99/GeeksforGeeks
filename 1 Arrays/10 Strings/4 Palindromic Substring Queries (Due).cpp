#include<bits/stdc++.h>
using namespace std;

int Rank(string &s , int n)
{
	int fact[20];
    
    fact[0] = 1;
    
    for(int i = 1 ; i < 20 ; i++)
    fact[i] = fact[i-1] * i;
    
    int alpha[26];  memset(alpha,0,sizeof(alpha));
    
    bool flag = false;
    
    for(int i = 0 ; i < n ; i++)
    alpha[s[i] - 'a']++;
    
    for(int i = 0 ; i < 26 ; i++)
    if(alpha[i] > 1)
    {
        flag = true;
        
        break;
    }
    
    int rank = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        int cnt = 0 , den = 1;
        
        for(int j = 0 ; j < 26 ; j++)
        den *= fact[alpha[j]];
        
        for(int j = 0 ; j < s[i] - 'a' ; j++)
        if(alpha[j])
        rank += ((fact[n - i - 1] * fact[alpha[j]]) / (fact[alpha[j] - 1] * den));  // Be carefull while using mod for Division
        
        alpha[s[i] - 'a']--;
    }
    
    return rank + 1;
}

signed main()
{
	string s = "cab";
	int n = s.length();
	
	cout << Rank(s , n) << endl;
	
	return 0;
}
