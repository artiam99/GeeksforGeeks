#include<bits/stdc++.h>
using namespace std;

class Stack
{
	stack<int> s;

	int mx;

	public:

		void push(int x)
		{
			if(s.size() == 0)
			mx = x;

			if(x > mx)
			{
				s.push(2 * x - mx);
		    
				mx = x;
			}
			
			else
			s.push(x);
		}
		
		void pop()
		{
			if(s.size() && s.top() > mx)
			mx = 2 * mx - s.top();
		
			if(s.size() == 1)
			mx = -1;
		
			if(s.size())
			s.pop();
		}
		
		int top()
		{
			if(s.size())
			{
				if(s.top() > mx)
				return mx;
		
				return s.top();
			}
			return -1;
		}
		
		int curmax()
		{
			return mx;
		}
};

signed main()
{
	Stack s;
	
	cout << "Top : " << s.top() << " Curr_max : " << s.curmax() << endl;
	
	s.push(3);  cout << "Top : " << s.top() << " Curr_max : " << s.curmax() << endl;
	s.push(4);  cout << "Top : " << s.top() << " Curr_max : " << s.curmax() << endl;
	s.push(5);  cout << "Top : " << s.top() << " Curr_max : " << s.curmax() << endl;
	s.pop();  cout << "Top : " << s.top() << " Curr_max : " << s.curmax() << endl;
	s.pop();  cout << "Top : " << s.top() << " Curr_max : " << s.curmax() << endl;
	s.pop();  cout << "Top : " << s.top() << " Curr_max : " << s.curmax() << endl;
	s.pop();  cout << "Top : " << s.top() << " Curr_max : " << s.curmax() << endl;

	return 0;
}

