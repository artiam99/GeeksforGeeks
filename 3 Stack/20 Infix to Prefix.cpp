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

void infixtoprefix(string s)
{
	stack<char> st;

	st.push('N');

	stack<string> ns;

	for(int i = 0 ; i < s.length() ; i++)
	{
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			string a;
			
			a += s[i];
			
			ns.push(a);
		}
		
		else if(s[i] == '(' || s[i] == ')')
		{
			if(s[i] == '(')
			st.push(s[i]);
			
			else
			{
				while(st.top() != '(')
				{
					string a = ns.top();
					
					ns.pop();
					
					string b = ns.top();
					
					ns.pop();
					
					string c;
					
					c += st.top();
					
					string d = c + b + a;
					
					ns.push(d);
					
					st.pop();
				}
				st.pop();
			}
		}
		
		else
		{
			while(st.top() != 'N' && ((st.top() == '^' && s[i] != '^') || (st.top() != '^' && precedence(st.top()) >= precedence(s[i]))))
			{
				string a = ns.top();
				
				ns.pop();
				
				string b = ns.top();
				
				ns.pop();
				
				string c;
				
				c += st.top();
				
				string d = c + b + a;
				
				ns.push(d);
				
				st.pop();
			}
			st.push(s[i]);
		}
	}
	
	while(st.top() != 'N')
	{
		string a = ns.top();
		
		ns.pop();
		
		string b = ns.top();
		
		ns.pop();
		
		string c;
		
		c += st.top();
		
		string d = c + b + a;
		
		ns.push(d);
		
		st.pop();
	}
	
	cout << "Prefix : " << ns.top() << endl;
}

signed main()
{
	string s = "a+b*(c^d^e-f)^(g+h*i)^((j-k)*l-m^n+o-p)-q";
	
	cout << "Infix : " << s << endl;
	
	infixtoprefix(s);
	
	return 0;
}

