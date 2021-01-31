#include <bits/stdc++.h>
using namespace std;

void sortedinsert(int x , stack<int> &s)
{
	if(!s.size() || s.top()<x)
	{
		s.push(x);
		
		return;
	}
	
	int y = s.top();

	s.pop();

	sortedinsert(x , s);

	s.push(y);
}

void sortstack(stack<int> &s)
{
	if(!s.size())
	return;

	int x = s.top();

	s.pop();

	sortstack(s);

	sortedinsert(x , s);
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

