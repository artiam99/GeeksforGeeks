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

void infixtopostfix(string s)
{
	stack<char> st;

	st.push('N');

	string ns;

	for(int i = 0 ; i < s.length() ; i++)
	{
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		ns += s[i];
		
		else if(s[i] == '(' || s[i] == ')')
		{
			if(s[i] == '(')
			st.push(s[i]);
			
			else
			{
				while(st.top() != '(')
				{
					ns += st.top();
					
					st.pop();
				}
				
				st.pop();
			}
		}
		
		else
		{
			while(st.top() != 'N' && ((st.top() == '^' && s[i] != '^') || (st.top() != '^' && precedence(st.top()) >= precedence(s[i]))))
			{
				ns += st.top();
				
				st.pop();
			}
			
			st.push(s[i]);
		}
	}
	
	while(st.top() != 'N')
	{
		ns += st.top();
	
		st.pop();
	}
	
	cout << "Postfix : " << ns << endl;
}

signed main()
{
	string s = "a+b*(c^d^e-f)^(g+h*i)^((j-k)*l-m^n+o-p)-q";
	
	cout << "Infix : " << s << endl;
	
	infixtopostfix(s);
	
	return 0;
}

