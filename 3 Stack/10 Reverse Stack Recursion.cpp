#include <bits/stdc++.h>
using namespace std;
void insert_bottom(int x , stack<int> &s)
{
	if(!s.size())
	s.push(x);

	else
	{
		int y = s.top();
		
		s.pop();
		
		insert_bottom(x , s);
		
		s.push(y);
	}
}

void reverse(stack<int> &s)
{
	if(!s.size())
	return;

	int x = s.top();

	s.pop();

	reverse(s);

	insert_bottom(x , s);
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

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	print(s);

	reverse(s);

	print(s);

	return 0;
}

