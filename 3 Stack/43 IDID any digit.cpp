#include<bits/stdc++.h>
using namespace std;

void ID(string &s , int n)
{
	stack<int> st;
	
	int c = 1;
	
	for(int i = 0 ; i <= n ; i++)
	{
		st.push(c++);
		
		if(i == n || s[i] == 'I')
		{
			while(!st.empty())
			{
				cout << st.top() << " ";
				
				st.pop();
			}
			
			c = 1;
		}
    }
}

signed main()
{
	string s = "DDIDDIIDIIIDIDDDIIDIID";
	int n = s.length();
	
	ID(s , n);
	
	return 0;
}

