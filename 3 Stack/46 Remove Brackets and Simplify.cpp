#include<bits/stdc++.h>
using namespace std;

string Simplify(string &s)
{
	int n = s.length();
	
	stack<int> sn;
	
	int si = 1;
	
	string s1;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			if(i == 0 || s[i-1] == '(' || s[i-1] == '+')
			{
				if(si == 1)
			    s1 += '+';
			    
			    else
			    s1 += '-';
			    
				s1 += s[i];
			}
			
			else
			{
				if(si == -1)
			    s1 += '+';
			
			    else
			    s1 += '-';
			    
				s1 += s[i];
			}
		}
		
		else if(s[i] == '(')
		{
			sn.push(i);
			
			if(i != 0 && s[i-1] == '-')
			si *= -1;
		}
		
		else if(s[i] == ')')
		{
			int c = sn.top();
			
			sn.pop();
			
			if(c != 0 && s[c-1] == '-')
			si *= -1;
		}
	}
	
	if(s1[0] == '+')
	s1.erase(s1.begin());
	
	return s1;
}

signed main()
{
	string s = "a-(b-c-(d+e))-f";

	cout << Simplify(s) << endl;

	return 0;
}

