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

void reverse(queue<int> &q)
{
	if(q.empty())
	return;

	int c = q.front();

	q.pop();

	reverse(q);

	q.push(c);
}

void reverse_using_stack(queue<int> &q)
{
	stack<int> s;

	while(!q.empty())
	{
		s.push(q.front());

		q.pop();
	}

	while(!s.empty())
	{
		q.push(s.top());

		s.pop();
	}
}

signed main()
{
	queue<int> q;

	q.push(1);  q.push(2);  q.push(3);  q.push(4);

	print(q);

	reverse(q);

	print(q);

	reverse_using_stack(q);

	print(q);

	return 0;
}

