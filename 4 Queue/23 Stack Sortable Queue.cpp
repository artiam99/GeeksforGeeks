#include<bits/stdc++.h>
using namespace std;

void print(queue<int> q)
{
	while(q.size())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void Stack_sortable(queue<int> q)
{
	int c=1;

	stack<int> s;
	
	while(!q.empty())
	{
		s.push(q.front());
	
		q.pop();
	
		while(s.size() && c == s.top())
		{
			s.pop();
	
			c++;
		}
	}
	
	if(s.empty())
	cout << "Stack Sortable" << endl;
	
	else
	cout << "Not Stack Sortable" << endl;
}

signed main()
{
	queue<int> q;

	q.push(2);  q.push(5);  q.push(1);  q.push(4);  q.push(3);

	print(q);

	Stack_sortable(q);
	
	while(q.size())
	q.pop();
	
	q.push(2);  q.push(1);  q.push(5);  q.push(4);  q.push(3);

	print(q);

	Stack_sortable(q);

	return 0;
}

