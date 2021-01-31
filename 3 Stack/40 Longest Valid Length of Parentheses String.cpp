#include<bits/stdc++.h>
using namespace std;

int Valid_Length(string &s)
{
	stack<int> st;  st.push(-1);
	
	int mx = 0;
	
	for(int i = 0 ; i < s.length() ; i++)
	{
		if(s[i] == '(')
		st.push(i);
		
		else
		{
			st.pop();
		
			if(!st.empty())
			mx = max(mx , i - st.top());
		
			else
			st.push(i);
		}
	}
	return mx;
}

signed main()
{
	string s = "((())()";

	cout << Valid_Length(s) << endl;

	return 0;
}

