#include <bits/stdc++.h>
using namespace std;
class Stack
{
	priority_queue<pair<int,int>> pq;
	
	int cnt;
	
	public:
	
		Stack()
		{
			cnt = 0;
		}
		
		void push(int x)
		{
			cnt++;
		
			pq.push({cnt , x});
		
			cout << x << " was pushed" << endl;
		}
		
		void pop()
		{
			if(pq.empty())
			return;
			
			cnt--;
			
			cout << pq.top().second << " was removed" << endl;
			
			pq.pop();
		}
		
		bool isempty()
		{
			return pq.empty();
		}
};

int main()
{
	Stack *s = new Stack();

	s->push(1);
	s->push(2);
	s->push(3);
	s->push(4);

	while(!s->isempty())
	{
		s->pop();
	}
	
	return 0;
}
