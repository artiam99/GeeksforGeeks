#include<bits/stdc++.h>
using namespace std;

vector<int> max_of_minimums_of_every_window_size(vector<int> &a , int n)
{
	stack<int> s;
	
	vector<int> l(n);
	vector<int> r(n);
	
	for(int i = 0 ; i < n ; i++)
	{
		while(!s.empty() && a[s.top()] >= a[i])
		s.pop();
		
		l[i] = ((s.empty()) ? 0 : s.top() + 1);
		
		s.push(i);
	}
	
	while(!s.empty())
	s.pop();
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		while(!s.empty() && a[s.top()] >= a[i])
		s.pop();
	
		r[i] = ((s.empty()) ? n-1 : s.top()-1);
	
		s.push(i);
	}
	
	vector<int> w(n);
	
	for(int i = 0 ; i < n ; i++)
	w[i] = r[i] - l[i] + 1;
	
	for(auto i : w)
	cout << i << " ";
	cout << endl;
	
	vector<int> ans(n);
	
	for(int i = 0 ; i < n ; i++)
	ans[w[i]-1] = max(ans[w[i]-1] , a[i]);
	
	for(int i = n-2 ; i >= 0 ; i--)
	ans[i] = max(ans[i] , ans[i+1]);
	
	return ans;
}

signed main()
{
	vector<int> a = {10, 10, 10, 10, 10};
	int n = a.size();

	vector<int> ans = max_of_minimums_of_every_window_size(a , n);

	for(auto i : ans)
	cout << i << " ";
	cout << endl;

	return 0;
}

