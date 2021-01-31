#include<bits/stdc++.h>
using namespace std;

void ID(string &s , int n)
{
	stack<int> st;
	
	for(int i = 0 ; i <= n ; i++)
	{
		st.push(i+1);
		
		if(i == n || s[i] == 'I')
		{
			while(!st.empty())
			{
				cout << st.top() << " ";
				
				st.pop();
			}
		}
    }
}

signed main()
{
	string s = "DDIDDIID";
	int n = s.length();

	ID(s , n);

	return 0;
}

