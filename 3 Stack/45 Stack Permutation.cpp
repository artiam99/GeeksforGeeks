#include<bits/stdc++.h>
using namespace std;

bool Is_Permutation(vector<int> &a , vector<int> &b , int n)
{
	stack<int> s;
	
	int j = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		s.push(a[i]);
		
		while(!s.empty() && s.top() == b[j])
		{
			s.pop();
			
			j++;
		}
	}

	return s.empty();
}

signed main()
{
	vector<int> a = {1, 2, 3};
	vector<int> b = {3, 1, 2};
	int n = a.size();
	

	if(Is_Permutation(a , b , n))
	cout << "Yes" << endl;
	
	else
	cout << "No" << endl;
	
	return 0;
}
