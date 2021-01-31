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

void rev(queue<int> &q , int k)
{
	if(k == 0)
	return;

	int c = q.front();

	q.pop();

	k--;

	rev(q,k);

	q.push(c);
}

void Kreverse(queue<int> &q,int k)
{
	rev(q,k);

	for(int i = 0 ; i < q.size() - k ; i++)
	{
		q.push(q.front());

		q.pop();
	}
}

void Kreverse_using_stack(queue<int> &q,int k)
{
	int n = q.size()-k;

	stack<int> s;

	while(k != 0)
	{
		s.push(q.front());

		q.pop();

		k--;
	}

	while(!s.empty())
	{
		q.push(s.top());

		s.pop();
	}

	for(int i = 0 ; i < n ; i++)
	{
		q.push(q.front());

		q.pop();
	}
}

signed main()
{
	queue<int> q;

	q.push(1);  q.push(2);  q.push(3);  q.push(4);

	int k = 3;

	print(q);

	Kreverse(q , k);

	print(q);

	Kreverse_using_stack(q , k);

	print(q);

	return 0;
}

