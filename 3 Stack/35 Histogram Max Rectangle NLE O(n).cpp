#include<bits/stdc++.h>
using namespace std;
int Get_Max_Area(vector<int> &a , int n)
{
	stack<int> s;
	
	vector<int> l(n);
	
	for(int i = 0 ; i < n ; i++)
	{
		while(!s.empty() && a[s.top()] >= a[i])
		s.pop();
		
		l[i] = ((s.empty()) ? -1 : s.top());
		
		s.push(i);
	}
	
	while(!s.empty())
	s.pop();
	
	vector<int> r(n);
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		while(!s.empty() && a[s.top()] >= a[i])
		s.pop();
		
		r[i] = ((s.empty()) ? n : s.top());
		
		s.push(i);
	}
	
	int mx = std::numeric_limits<int>::min();
	
	for(int i = 0 ; i < n ; i++)
	mx = max(mx , (r[i] - l[i] - 1) * a[i]);
	
	return mx;
}

signed main()
{
	vector<int> a = {6, 2, 5, 4, 5, 1, 6};
	int n = a.size();
	
	cout << "Maximum area of rectangle : " << Get_Max_Area(a , n) << endl;

	return 0;
}

