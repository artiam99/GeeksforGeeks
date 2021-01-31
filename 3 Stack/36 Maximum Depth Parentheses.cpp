#include<bits/stdc++.h>
using namespace std;
int Get_Depth(string &s)
{
	int n = s.length();
	
	stack<char> st;
	
	int mx = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(s[i] == '(')
		{
			st.push(s[i]);
		
			mx = max(mx , (int)st.size());
		}
		
		else if(s[i] == ')')
		{
		    if(st.empty())
			return -1;
			
			st.pop();	
		}
	}
	
	if(st.empty())
	return mx;
	
	return -1;
}

signed main()
{
	vector<string> a;

	a.push_back("( a(b) (c) (d(e(f)g)h) I (j(k)l)m)");
	a.push_back("( p((q)) ((s)t) )");
	a.push_back("");
	a.push_back("b) (c) ()");
	a.push_back("(b) ((c) ()");

	for(int i = 0 ; i < a.size() ; i++)
	cout << Get_Depth(a[i]) << endl;

	return 0;
}

