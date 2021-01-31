#include<bits/stdc++.h>
using namespace std;
void prefixtopostfix(string s)
{
	stack<string> ns;
	
	for(int i = s.length()-1 ; i >= 0 ; i--)
	{
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
		{
			string a;
			
			a += ns.top();
			
			ns.pop();
			
			string b;
			
			b += ns.top();
			
			ns.pop();
			
			string c = a + b + s[i];
			
			ns.push(c);
		}
		
		else
		{
			string a;
		
			a += s[i];
		
			ns.push(a);
		}
	}
	
	cout << "Postfix : " << ns.top() << endl;
}

signed main()
{
	string s = "-+a*b^-^c^def^+g*hi-+-*-jkl^mnopq";

	cout << "Prefix : " << s << endl;

	prefixtopostfix(s);

	return 0;
}

