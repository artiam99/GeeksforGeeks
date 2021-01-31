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
		}

		void pop()
		{
			cout << "Pop : ";

			if(q.empty())
			{
				cout << " Empty" << endl;

				return;
			}

			int c = q.back();

			cout << c << endl;

			for(int i = 0;i<q.size()-1;i++)
			{
				q.push(q.front());

				q.pop();
			}

			q.pop();
		}

		void printstack()
		{
			if(q.front() == -1)
			return;

			int c = q.front();

			q.pop();

			q.push(c);

			printstack();

			cout << c << " ";
		}

		void print()
		{
			q.push(-1);

			printstack();

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
	s.pop();  s.print(); cout << endl;
	s.pop();  s.print(); cout << endl;
	s.pop();  s.print();  cout << endl;
	s.pop();  s.print();  cout << endl;

	return 0;
}

