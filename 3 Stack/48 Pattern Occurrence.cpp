#include<bits/stdc++.h>
using namespace std;
int Count(string &s , string &txt)
{
	int n = txt.length();
	
	stack<char> st;
	
	string p;
	
	int c = 0;
	
	for(int i = 0 ; i < s.length() ; i++)
	{
		st.push(s[i]);
		
		if(!p.size() && st.size() >= n)
		{
			for(int j = 0 ; j < n ; j++)
			{
				p.insert(p.begin() , 1 , st.top());
			
				st.pop();
			}
			
			for(int j = 0 ; j < n ; j++)
			st.push(p[j]);
		}
		
		else if(p.size() == n)
		{
			p.erase(p.begin());
			
			p += st.top();
		}
		
		if(p == txt)
		{
			c++;
			
			for(int j = 0 ; j < n ; j++)
			st.pop();
			
			p.clear();
		}
	}
	
	return c;
}

signed main()
{
	string s = "AAABAABABCCBAABAAAAAABBB";

	string txt = "AAB";

	cout << "Count is : " << Count(s , txt) << endl;

	return 0;
}

