#include<bits/stdc++.h>
using namespace std;

void Print(int n)
{
	queue<string> q;
	
	string s = "1";
	
	q.push(s);
	
	while(n--)
	{
		cout << q.front() << endl;
		
		string s1 = q.front();
	
		string s2 = q.front();
		
		q.pop();
		
		s1 += '0';
	
		s2 += '1';
		
		q.push(s1);
	
		q.push(s2);
	}
}

signed main()
{
	int n = 10;
	
	Print(n);
	
	return 0;
}
