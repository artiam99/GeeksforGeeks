#include<bits/stdc++.h>
using namespace std;
int No_of_Ways(string &s1,int n1,string &s2,int n2)
{
	int lcsl[n1+2][n2+2] , lcsr[n1+2][n2+2];
   
    for(int i = 0 ; i <= n1+1 ; i++)
    for(int j = 0 ; j <= n2+1 ; j++)
    {
        if(i == 0 || j == 0 || i == n1+1 || j == n2+1)  lcsl[i][j] = 0;
        
        else if(s1[i-1] == s2[j-1])  lcsl[i][j] = 1 + lcsl[i-1][j-1];
        
        else  lcsl[i][j] = max(lcsl[i-1][j] , lcsl[i][j-1]);
    }
   
    for(int i = n1+1 ; i >= 0 ; i--)
    for(int j = n2+1 ; j >= 0 ; j--)
    {
        if(i == 0 || j == 0 || i == n1+1 || j == n2+1)  lcsr[i][j] = 0;
        
        else if(s1[i-1] == s2[j-1])  lcsr[i][j] = 1 + lcsr[i+1][j+1];
        
        else  lcsr[i][j] = max(lcsr[i+1][j] , lcsr[i][j+1]);
    }
    
    vector<int> pos[26];
   
    for(int i = 0 ; i < n2 ; i++)
    pos[s2[i]-'a'].push_back(i+1);
   
    int cnt = 0;
    
    for(int i = 0 ; i <= n1 ; i++)
    for(int c = 0 ; c < 26 ; c++)
    for(int j = 0 ; j < pos[c].size() ; j++)
    {
        int p = pos[c][j];
        
        if(lcsl[i][p-1] + lcsr[i+1][p+1] == lcsl[n1][n2])
        cnt++;
    }
    
    return cnt;
}
signed main()
{
	string s1 = "abcabc";
	int n1 = s1.size();
	
	string s2 = "abcd";
	int n2 = s2.size();
	
	cout<< No_of_Ways(s1,n1,s2,n2) <<endl;
    
	return 0;
}
