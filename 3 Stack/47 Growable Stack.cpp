#include<bits/stdc++.h>
using namespace std;
class Stack
{
    int *p;
    
	int bound;
	
	int tp;
	
	public:
	
		int length;
	
	    Stack()
	    {
	    	tp = -1;
	
	    	length = 0;
	
	    	bound = 4;
		}
		
		int* createnew(int* a)
		{
			length = length + bound;
		
			a = new int[length];
		
			for(int i = tp ; i >= 0 ; i--)
			a[i] = p[i];
		
			return a;
		}
		
		void push(int x)
		{
			if(tp == length - 1)
			p = createnew(p);
		
			p[++tp] = x;
		}
		
		void pop()
		{
			if(tp > -1)
			tp--;
		}
		
		int top()
		{
			if(tp != -1)
			return p[tp];
		
			return -1;
		}
};

signed main()
{
	Stack s;

	cout << s.top() << " " << s.length << endl;

	s.push(5);  cout << s.top() << " " << s.length << endl;
	s.push(6);  cout << s.top() << " " << s.length << endl;
	s.push(7);  cout << s.top() << " " << s.length << endl;
	s.push(8);  cout << s.top() << " " << s.length << endl;
	s.push(9);  cout << s.top() << " " << s.length << endl;
	s.pop();  cout << s.top() << " " << s.length << endl;
	s.pop();  cout << s.top() << " " << s.length << endl;
	s.pop();  cout << s.top() << " " << s.length << endl;
	s.pop();  cout << s.top() << " " << s.length << endl;
	s.pop();  cout << s.top() << " " << s.length << endl;
	s.pop();  cout << s.top() << " " << s.length << endl;
	s.pop();  cout << s.top() << " " << s.length << endl;

	return 0;
}

