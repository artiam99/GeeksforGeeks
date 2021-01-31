#include <bits/stdc++.h> 
using namespace std;

void NGF(vector<int> &a , int n)
{
	unordered_map<int,int> m;
	
	for(int i = 0 ; i < n ; i++)
	m[a[i]]++;
	
	vector<int> b(n);
	
	for(int i = 0 ; i < n ; i++)
	b[i] = m[a[i]];
	
	vector<int> c(n);
	
	stack<int> s;
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		while(!s.empty() && b[s.top()]<=b[i])
		s.pop();
		
		c[i] = (s.empty()) ? -1 : a[s.top()];
		
		s.push(i);
	}
	
	for(auto i : c)
	cout << i << " ";
	cout << endl;
}

int main() 
{ 
	vector<int> a = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
	int n = a.size();
	
	NGF(a , n);
	
	return 0; 
} 

