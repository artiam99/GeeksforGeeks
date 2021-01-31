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

void Sorted_insert(queue<int> &q,int x)
{
	int c = 0;

	while(q.size()&&q.front()<x)
	{
		q.push(q.front());

		q.pop();

		c++;
	}
	
	q.push(x);

	for(int i = 0 ; i < q.size() - c - 1 ;i++)
	{
		q.push(q.front());

		q.pop();
	}
}

void Sort(queue<int> &q)
{
	if(q.empty())
	return;
	
	int x = q.front();
	q.pop();
	
	Sort(q);
	
	Sorted_insert(q,x);
}

signed main()
{
	queue<int> q;

	q.push(11);  q.push(16);  q.push(12);  q.push(17);  q.push(13);  q.push(18);  q.push(14);  q.push(19);  q.push(15);  q.push(20);

	print(q);

	Sort(q);

	print(q);

	return 0;
}

