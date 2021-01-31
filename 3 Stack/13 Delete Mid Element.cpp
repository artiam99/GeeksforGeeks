#include <bits/stdc++.h>
using namespace std;
void deletemid(stack<int> &s , int n , int cur)
{
	if(!s.size() || cur > n/2)
	return;
	
	int x = s.top();
	
	s.pop();
	
	deletemid(s , n , cur + 1);
	
	if(cur != n/2)
	s.push(x);
}

void print(stack<int> &s)
{
    if(!s.size())
    {
    	cout << endl;

    	return;
	}
	
    cout << s.top() << " ";
    
	int x = s.top();
    
	s.pop();
    
	print(s);
    
	s.push(x);
}

int main()
{
	stack<int> s;

	s.push(5);
	s.push(1);
	s.push(4);
	s.push(2);
	s.push(3);

	print(s);

	deletemid(s,s.size(),0);

	print(s);

	return 0;
}

