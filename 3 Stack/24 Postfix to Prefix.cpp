#include<bits/stdc++.h>
using namespace std;
void postfixtoprefix(string s)
{
	stack<string> ns;
	
	for(int i = 0 ; i < s.length() ; i++)
	{
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
		{
			string a;
			
			a += ns.top();
			
			ns.pop();
			
			string b;
			
			b += ns.top();
			
			ns.pop();
			
			string c = s[i] + b + a;
			
			ns.push(c);
		}
		
		else
		{
			string a;
		
			a += s[i];
		
			ns.push(a);
		}
	}
	cout << "Prefix : " << ns.top() << endl;
}

signed main()
{
	string s = "abcde^^f-ghi*+jk-l*mn^-o+p-^^*+q-";

	cout << "Postfix : " << s << endl;

	postfixtoprefix(s);

	return 0;
}

