#include <bits/stdc++.h>
using namespace std;

void sortstack(stack<int> &s)
{
	stack<int> s1;
	
	while(!s.empty())
	{
		int x = s.top();
	
		s.pop();
	
		while(!s1.empty() && s1.top() < x)
		{
			s.push(s1.top());
		
			s1.pop();
		}
		
		s1.push(x);
	}
	
	while(!s1.empty())
	{
		s.push(s1.top());
	
		s1.pop();
	}
}

void print(stack<int> &s)
{
    if(!s.size())
    {
    	cout << endl;

    	return;
	}
	
    cout << s.top() << " ";
    
	int x = s.top();
    
	s.pop();
    
	print(s);
    
	s.push(x);
}

int main()
{
	stack<int> s;

	s.push(5);
	s.push(1);
	s.push(4);
	s.push(2);
	s.push(3);

	print(s);

	sortstack(s);

	print(s);

	return 0;
}

