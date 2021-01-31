#include<bits/stdc++.h>
using namespace std;

class Stack
{
	queue<int> q;

	public:

		void push(int x)
		{
			cout << "Push : " << x << endl;

			q.push(x);

			while(q.front() != x)
			{
				q.push(q.front());

				q.pop();
			}
		}

		void pop()
		{
			cout << "Pop : ";

			if(q.empty())
			{
				cout << " Empty" << endl;

				return;
			}

			cout << q.front() << endl;

			q.pop();
		}

		void print()
		{
			q.push(-1);

			while(q.front() != -1)
			{
				q.push(q.front());

				cout << q.front() << " ";

				q.pop();
			}
	
			q.pop();
		}
};

signed main()
{
	Stack s;
	
	s.pop();  s.print();  cout << endl;
	s.push(4);  s.print();  cout << endl;
	s.push(3);  s.print();  cout << endl;
	s.push(2);  s.print();  cout << endl;
	s.push(1);  s.print();  cout << endl;
	s.pop();  s.print();  cout << endl;
	s.pop();  s.print();  cout << endl;
	s.pop();  s.print();  cout << endl;
	s.pop();  s.print();  cout << endl;
	s.pop();  s.print();  cout << endl;
	s.pop();  s.print();  cout << endl;
	
	return 0;
}

