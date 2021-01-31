#include <bits/stdc++.h>
using namespace std;
string reverseindword(string s)
{
	stack<char> st;
	
	int in = 0;
	
	for(int i = 0 ; i < s.length() ; i++)
	{
		if(s[i] != ' ')
		st.push(s[i]);
		
		if(s[i] == ' ' || i == s.length() - 1)
		{
			while(st.size())
			{
				s[in++] = st.top();
				
				st.pop();
			}
			in++;
		}
	}
	
	return s;
}

int main()
{
	string s = "Geeks for geeks";

	cout << reverseindword(s) << endl;

	return 0;
}
