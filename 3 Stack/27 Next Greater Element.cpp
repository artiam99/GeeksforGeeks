#include <bits/stdc++.h> 
using namespace std;

void NGE(vector<int> &a , int n)
{
	vector<int> b(n);
	
	stack<int> s;
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		while(!s.empty() && s.top() <= a[i])
		s.pop();
		
		b[i] = (s.empty()) ? -1 : s.top();
		
		s.push(a[i]);
	}
	
	for(auto i : b)
	cout << i << " ";
	cout << endl;
}

int main() 
{ 
	vector<int> a = {85, 75, 60, 70, 60, 80, 100};
	int n = a.size();
	
	NGE(a , n);
	
	return 0; 
} 

