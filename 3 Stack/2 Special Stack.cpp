#include <bits/stdc++.h>
using namespace std;
stack<int> m;

void push(int x , stack<int> &s)
{
	s.push(x);

	if(m.empty() || x <= m.top())
	m.push(x);
}

void pop(stack<int> &s)
{
	if(s.top() == m.top())
	m.pop();
	
	s.pop();
}

void getmin()
{
	cout << m.top() << endl;;
}

int main()
{
	stack<int> s;

	push(5 , s);  getmin();

	push(3 , s);  getmin();

	push(1 , s);  getmin();

	pop(s);  getmin();

	push(2 , s);  getmin();

	return 0; 
} 

