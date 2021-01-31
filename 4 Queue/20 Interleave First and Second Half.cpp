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

void interleave(queue<int> &q)
{
	int n = q.size();

	stack<int> s;

	for(int i = 0 ; i < n/2 ; i++)
	{
		q.push(q.front());

		q.pop();
	}

	for(int i = 0 ; i < n/2 ; i++)
	{
		s.push(q.front());

		q.pop();
	}

	while(!s.empty())
	{
		q.push(s.top());

		s.pop();
	}

	for(int i = 0 ; i < n/2 ; i++)
	{
		q.push(q.front());

		q.pop();
	}

	for(int i = 0 ; i < n/2 ; i++)
	{
		s.push(q.front());

		q.pop();
	}

	while(!s.empty())
	{
		q.push(q.front());

		q.pop();

		q.push(s.top());

		s.pop();
	}
}

signed main()
{
	queue<int> q;

	q.push(11);  q.push(12);  q.push(13);  q.push(14);  q.push(15);  q.push(16);  q.push(17);  q.push(18);  q.push(19);  q.push(20);

	print(q);

	interleave(q);

	print(q);

	return 0;
}

