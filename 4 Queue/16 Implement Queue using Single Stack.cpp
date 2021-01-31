#include<bits/stdc++.h>
using namespace std;

class Queue
{
	stack<int> s;

	public:

		void push_end(int x)
		{
			if(s.empty())
			{
				s.push(x);

				return;
			}

			int c = s.top();

			s.pop();

			push_end(x);

			s.push(c);
		}

		void Enque(int x)
		{
			cout << "Enque : " << x << endl;

			push_end(x);
		}

		void Deque()
		{
			cout << "Deque : ";

			if(s.empty())
			{
				cout << "Queue Empty" << endl;

				return;
			}

			cout << s.top() << endl;

			s.pop();
		}

		void print()
		{
			if(s.empty())

			return;

			int c = s.top();

			s.pop();

			cout << c << " ";

			print();

			s.push(c);
		}
};

signed main()
{
	Queue q;
	
	q.Deque();  q.print();  cout << endl;
	q.Enque(4);  q.print();  cout << endl;
	q.Enque(3);  q.print();  cout << endl;
	q.Enque(2);  q.print();  cout << endl;
	q.Enque(1);  q.print();  cout << endl;
	q.Deque();  q.print();  cout << endl;
	q.Deque();  q.print();  cout << endl;
	q.Deque();  q.print();  cout << endl;
	q.Deque();  q.print();  cout << endl;
	q.Deque();  q.print();  cout << endl;
	q.Deque();  q.print();  cout << endl;
	
	return 0;
}
