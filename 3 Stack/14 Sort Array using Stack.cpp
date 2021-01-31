#include <bits/stdc++.h>
using namespace std;
void sorted_insert(int x , stack<int> &s)
{
	if(s.empty() || s.top() >= x)
	{
		s.push(x);

		return;
	}

	int y = s.top();
	
	s.pop();
	
	sorted_insert(x , s);
	
	s.push(y);
}

void sortarr(int *arr , int n)
{
	stack<int> s;
	
	for(int i = 0 ; i < n ; i++)
	sorted_insert(arr[i] , s);
	
	int i = 0;
	
	while(s.size())
	{
		arr[i++] = s.top();
	
		s.pop();
	}
}

int main()
{
	int arr[] = {5, 1, 4, 2, 3};
	int n = sizeof(arr)/sizeof(int);

	sortarr(arr , n);
	
	for(int i = 0 ; i < n ; i++)
	cout << arr[i] << " ";
	cout << endl;
	
	return 0;
}
