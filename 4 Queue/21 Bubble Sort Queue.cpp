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

void Sort(queue<int> &q)
{
	int n = q.size();

	for(int i = 0;i<n;i++)
	{

		int temp = q.front();

		q.pop();

		for(int j = 1;j<n;j++)
		{
			if(temp<q.front())
			{
				q.push(temp);

				temp = q.front();

				q.pop();
			}
			else
			{
				q.push(q.front());

				q.pop();
			}
			print(q);
		}
		q.push(temp);

		cout << endl << endl;
	}
}

signed main()
{
	queue<int> q;

	q.push(5);  q.push(3);  q.push(4);  q.push(2);  q.push(1);

	print(q);

	Sort(q);

	print(q);

	return 0;
}

