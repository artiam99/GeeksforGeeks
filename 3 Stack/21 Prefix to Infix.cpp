#include<bits/stdc++.h>
using namespace std;
int precedence(char c)
{
	if(c == '^')
	return 3;
	
	else if(c == '*' || c == '/')
	return 2;
	
	else if(c == '+' || c == '-')
	return 1;
	
	return -1;
}

void redundant_parentheses(string s)
{
	stack<int> st;

	for(int i = 0 ; i < s.length() ; i++)
	{
		if(s[i] == '(')
		st.push(i);
		
		else if(s[i] == ')')
		{
			int L = ((st.top() == 0) ? -1 : precedence(s[st.top()-1]));
			
			int R = ((i == s.length() - 1) ? -1 : precedence(s[i+1]));
			
			int out = max(L , R);
			
			int in = 4;
			
			int p = st.top();
			
			st.pop();
			
			if(out == -1)
			{
				s.erase(s.begin() + i);
				
				s.erase(s.begin() + p);
				
				i -= 2;
				
				continue;
			}
			
			for(int j = p+1 ; j <= i-1 ; j++)
			{
				if(s[j] == '(')
				{
					stack<char> sp;
					
					sp.push('(');
					
					j++;
					
					while(!sp.empty())
					{
						if(s[j] == '(')
						sp.push('(');
					
						else if(s[j] == ')')
						sp.pop();
						
						j++;
					}
				}
				
				if(s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/' || s[j] == '^')
				in = min(in , precedence(s[j]));
			}
			
			if(out <= in)
			{
				s.erase(s.begin() + i);
				
				s.erase(s.begin() + p);
				
				i -= 2;
			}
		}
	}
	
	cout << "Infix : " << s << endl;
}

void prefixtoinfix(string s)
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
			
			string c = '(' + a + s[i] + b + ')';
			
			ns.push(c);
		}
		
		else
		{
			string a;
		
			a += s[i];
		
			ns.push(a);
		}
	}
	redundant_parentheses(ns.top());
}

signed main()
{
	string s = "-+a*b^-^c^def^+g*hi-+-*-jkl^mnopq";

	cout << "Prefix : " << s << endl;

	prefixtoinfix(s);

	return 0;
}

