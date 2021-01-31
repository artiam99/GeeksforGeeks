#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> a)
{
	int n = a.size();
	
	int B = 0;
	
	stack<int> s;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(s.empty())
		s.push(a[i]);
		
		else
		{
			while(s.top() == B + 1)
			{
				s.pop();
		
				B++;
			}
		
			if(s.empty() || s.top() > a[i])
			s.push(a[i]);
			
			else
			return false;
		}
	}
	return true;
}

int main()
{
	vector<int> a = {5, 1, 4, 2, 3};
	
	if(check(a))
	cout << "Stack Sortable" << endl;
	
	else
	cout << "Not Stack Sortable" << endl;
	
	return 0;
}

