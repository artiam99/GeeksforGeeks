#include<bits/stdc++.h>
using namespace std;

class Stack
{
	deque<int> d;

	public:

		void push(int x)
		{
			cout << "Push : " << x << endl;

			d.push_front(x);
		}

		void pop()
		{
			cout << "Pop : ";

			if(d.empty())
			{
				cout << "Empty" << endl;

				return;
			}

			cout << d.front() << endl;

			d.pop_front();
		}

		void print()
		{
			d.push_back(-1);

			while(d.front() != -1)
			{
				d.push_back(d.front());

				cout << d.front() << " ";

				d.pop_front();
			}

			d.pop_front();
		}
};

class Queue
{
	deque<int> d;

	public:

		void push(int x)
		{
			cout << "Push : " << x << endl;

			d.push_back(x);
		}

		void pop()
		{
			cout << "Pop : ";

			if(d.empty())
			{
				cout << "Empty" << endl;

				return;
			}

			cout << d.front() << endl;

			d.pop_front();
		}
	
		void print()
		{
			d.push_back(-1);
	
			while(d.front() != -1)
			{
				d.push_back(d.front());
	
				cout << d.front() << " ";
	
				d.pop_front();
			}
	
			d.pop_front();
		}
};

signed main()
{
	cout << "Stack" << endl;

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
	
	cout << "Queue" << endl;

	Queue q;

	q.pop();  q.print();  cout << endl;
	q.push(4);  q.print();  cout << endl;
	q.push(3);  q.print();  cout << endl;
	q.push(2);  q.print();  cout << endl;
	q.push(1);  q.print();  cout << endl;
	q.pop();  q.print();  cout << endl;
	q.pop();  q.print();  cout << endl;
	q.pop();  q.print();  cout << endl;
	q.pop();  q.print();  cout << endl;
	q.pop();  q.print();  cout << endl;
	q.pop();  q.print();  cout << endl;

	return 0;
}

