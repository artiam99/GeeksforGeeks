#include <bits/stdc++.h> 
using namespace std;

void NGE(vector<int> &a , int n)
{
	vector<int> L(n);
	vector<int> R(n);
	
	stack<int> s;
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		while(!s.empty() && a[s.top()] <= a[i])
		s.pop();
		
		R[i] = (s.empty()) ? -1 : s.top();
		
		s.push(i);
	}
	
	while(s.size())
	s.pop();
	
	for(int i = 0 ; i < n ; i++)
	{
		while(!s.empty() && a[s.top()] <= a[i])
		s.pop();
		
		L[i] = (s.empty()) ? -1 : s.top();
		
		s.push(i);
	}
	
	for(int i = 0 ; i < n ; i++)
	cout << (L[i] + 1) * (R[i] + 1) << " ";
	cout << endl;
}

int main() 
{ 
	vector<int> a = {5,4,3,4,5};
	int n = a.size();
	
	NGE(a , n);
	
	return 0; 
} 

