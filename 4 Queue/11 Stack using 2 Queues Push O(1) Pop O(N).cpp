#include<bits/stdc++.h>
using namespace std;

class Stack
{
	queue<int> q1 , q2;

	public:

		void push(int x)
		{
			cout << "Push : " << x << endl;

			q1.push(x);
		}

		void pop()
		{
			cout << "Pop : ";

			if(q1.empty())
			{
				cout << "Stack Empty" << endl;

				return;
			}

			while(q1.size()>1)
			{
				q2.push(q1.front());

				q1.pop();
			}

			int c = q1.front();

			q1.pop();

			cout << c << endl;

			while(q2.size())
			{
				q1.push(q2.front());

				q2.pop();
			}
		}

		void printstack()
		{
			if(q1.front() == -1)
			return;

			int c = q1.front();
			q1.push(c);

			q1.pop();

			printstack();

			cout << c << " ";
		}

		void print()
		{
			q1.push(-1);

			printstack();

			q1.pop();
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

