#include <bits/stdc++.h>
using namespace std;
class Stack
{
	int maxsize;

	int minl;

	int top;

	vector<pair<int,int>> arr;

	public:

		Stack(int maxsize)
		{
			this->maxsize = maxsize;

			top = -1;

			minl = std::numeric_limits<int>::max();
		}
		
		void push(int x)
		{
			cout << "Push : ";
		
			if(top + 1 == maxsize)
			{
				cout << "Stack overflow" << endl;
			
				return;
			}
			
			cout << x << endl;
			
			top++;
			
			minl = ((minl < x) ? minl : x);
			
			arr.push_back({x , minl});
		}
		
		void pop()
		{
			cout << "Pop : ";
		
			if(top == -1)
			{
				cout << "Stack underflow" << endl;
			
				return;
			}
			
			cout << arr[top].first << endl;
			
			top--;
			
			if(top != -1)
			minl = arr[top].second;
			
			else
			minl = std::numeric_limits<int>::max();
		}
		
		void min()
		{
			cout << "Minimum element : ";
		
			if(top != -1)
			cout << arr[top].second << endl;
			
			else
			cout << "Stack Empty" << endl;
		}
		
		bool isempty()
		{
			return (top == -1);
		}
};

int main()
{
	Stack *s = new Stack(3);

	s->push(4);  s->min();
	s->push(3);  s->min();
	s->push(2);  s->min();
	s->push(1);  s->min();

	while(!s->isempty())
	{
		s->pop();
	
		s->min();
	}
	s->pop();
	
	return 0;
}
