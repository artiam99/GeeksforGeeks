#include <bits/stdc++.h>
using namespace std;
class Stack
{
	stack<int> s;
	
	int minl;
	
	public:
	
		Stack()
		{
			minl = std::numeric_limits<int>::max();
		}
		
		void push(int x)
		{
			cout << "Push : " << x << endl;
		
			if(s.empty() || x > minl)
            s.push(x);
			
			else
			s.push(2 * x - minl);
			
			minl=min(minl , x);
		}
		
		void pop()
		{
			cout << "Pop : ";
		
			if(s.empty())
			{
				cout << "Stack underflow" << endl;
			
				return;
			}
			
			if(s.top() < minl)
			{
				cout << minl << endl;
			
				minl = 2 * minl - s.top();
			}
			
			else
			cout << s.top() << endl;
			
			s.pop();
			
			if(s.empty())
			minl = std::numeric_limits<int>::max();
		}
		
		void minel()
		{
			cout << "Minimum element : ";
		
			if(s.empty())
			{
				cout << "Stack empty" << endl;
			
				return;
			}
			
			cout << minl << endl;
		}
};

int main()
{
	Stack stk;

	stk.push(4);  stk.minel();
	stk.pop();  stk.minel();
	stk.pop();  stk.minel();
	stk.push(3);  stk.minel();
	stk.push(5);  stk.minel();
	stk.push(2);  stk.minel();
	stk.push(1);  stk.minel();
	stk.push(6);  stk.minel();
	stk.pop();  stk.minel();
	stk.pop();  stk.minel();
	stk.pop();  stk.minel();

	return 0;
}
