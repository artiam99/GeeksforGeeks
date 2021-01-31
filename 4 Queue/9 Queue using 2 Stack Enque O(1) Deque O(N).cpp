#include<bits/stdc++.h>
using namespace std;

class Queue
{
	stack<int> s1 , s2;
	
	public:
		void Enque(int x)
		{
			cout << "Enque : " << x << endl;

			s1.push(x);
		}
	
		void Deque()
		{
			cout << "Deque : ";
	
			if(s1.empty())
			{
				cout << "Queue Empty" << endl;
	
				return;
			}
	
			while(s1.size() > 1)
			{
				s2.push(s1.top());
	
				s1.pop();
			}
	
			int c = s1.top();
	
			s1.pop();
	
			cout << c << endl;
	
			while(s2.size())
			{
				s1.push(s2.top());
	
				s2.pop();
			}
		}
	
		void print()
		{
			if(s1.empty())
			return;
	
			int c = s1.top();
	
			s1.pop();
	
			this->print();
	
			s1.push(c);
	
			cout << s1.top() << " ";
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
