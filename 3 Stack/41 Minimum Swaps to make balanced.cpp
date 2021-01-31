#include<bits/stdc++.h>
using namespace std;

int Min_Swap(string &s)
{
	if(s.length() % 2 == 1)
	return -1;
	
	stack<int> st;
	
	for(int i = 0 ; i < s.length() ; i++)
	{
		if(s[i] == '{')
		st.push(s[i]);
		
		else
		{
			if(!st.empty() && st.top() == '{')
			st.pop();
		
			else
			st.push(s[i]);
		}
	}
	
	int c = 0;
	
	while(!st.empty())
	{
		char r = st.top();
		
		st.pop();
		
		char l = st.top();
		
		st.pop();
	
		if(r == '{')
		c++;
	
		if(l == '}')
		c++;
	}
	
	return c;
}

signed main()
{
	string s = "{{}{{{}{{}}{";

	cout << Min_Swap(s) << endl;

	return 0;
}

