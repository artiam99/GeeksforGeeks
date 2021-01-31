#include<bits/stdc++.h>
using namespace std;

class Queue
{
	stack<int> s1 , s2;

	public:
		void Enque(int x)
		{
			cout << "Enque : " << x << endl;
	
			while(!s1.empty())
			{
				s2.push(s1.top());
	
				s1.pop();
			}
	
			s1.push(x);
	
			while(!s2.empty())
			{
				s1.push(s2.top());
	
				s2.pop();
			}
		}
	
		void Deque()
		{
			cout << "Deque : ";
	
			if(s1.empty())
			{
				cout << "Queue Empty" << endl;
	
				return;
			}
	
			cout << s1.top() << endl;
	
			s1.pop();
		}
	
		void print()
		{
			if(s1.empty())
			return;
	
			int c = s1.top();
	
			s1.pop();
	
			cout << c << " ";
	
			print();
	
			s1.push(c);
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

