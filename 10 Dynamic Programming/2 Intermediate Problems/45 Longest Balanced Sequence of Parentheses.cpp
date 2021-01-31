#include<bits/stdc++.h>
using namespace std;
int LBS(string s,int n)
{
	int invalidOpen = 0 , invalidClose = 0;
	
	for(int i=0;i<n;i++)
	{
		if(s[i] == '(')  invalidOpen++;
		
		else
		{
			if(invalidOpen == 0)
			invalidClose++;
			
			else
			invalidOpen--;
		}
	}
	return n - (invalidOpen + invalidClose);
}
signed main()
{
	string s = "()(((((()"; // Subsequence not Substring ... Stack for Substring
    int n = s.length();
    
    cout<< LBS(s,n) <<endl;
  
    return 0;
}
