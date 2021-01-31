#include <bits/stdc++.h> 
using namespace std;

void Stock_Span(vector<int> &a , int n)
{
	stack<int> s;
	
	for(int i = 0 ; i < n ; i++)
	{
		while(!s.empty() && a[s.top()] <= a[i])
		s.pop();
		
		(s.empty()) ? cout << (i+1) : cout<< (i - s.top());
	
		cout << " ";
		
		s.push(i);
	}
}

int main() 
{ 
	vector<int> a = {100, 80, 60, 70, 60, 75, 85};
	int n = a.size();
	
	Stock_Span(a , n);
	
	return 0; 
} 

