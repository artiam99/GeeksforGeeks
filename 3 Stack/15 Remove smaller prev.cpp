#include <bits/stdc++.h>
using namespace std;
void remove_smaller_prev(int *arr , int n)
{
	stack<int> s;
	
	for(int i = 0 ; i < n ; i++)
	{
		while(!s.empty() && s.top() < arr[i])
		s.pop();
		
		s.push(arr[i]);
	}
	
	vector<int> v;
	
	while(!s.empty())
	{
		v.push_back(s.top());
	
		s.pop();
	}
	
	for(auto i = v.rbegin() ; i != v.rend() ; i++)
	cout << *i << " ";
	cout << endl;
}

int main()
{
	int arr[] = {23, 45, 11, 77, 18};
	int n = sizeof(arr)/sizeof(int);

	remove_smaller_prev(arr , n);

	return 0;
}

