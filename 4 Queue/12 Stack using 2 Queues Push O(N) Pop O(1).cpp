#include<bits/stdc++.h>
using namespace std;

class Stack
{
	queue<int> q1 , q2;
	
	public:
	
		void push(int x)
		{
			cout << "Push : " << x << endl;

			while(q1.size())
			{
				q2.push(q1.front());
	
				q1.pop();
			}
	
			q1.push(x);
	
			while(q2.size())
			{
				q1.push(q2.front());
	
				q2.pop();
			}
		}
	
		void pop()
		{
			cout << "Pop : ";
	
			if(q1.empty())
			{
				cout << " Empty" << endl;
	
				return;
			}
	
			cout << q1.front() << endl;
	
			q1.pop();
		}
	
		void print()
		{
			q1.push(-1);
	
			while(q1.front() != -1)
			{
				q1.push(q1.front());
	
				cout << q1.front() << " ";
	
				q1.pop();
			}
	
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

