#include<bits/stdc++.h>
using namespace std;

signed main()
{
	vector<int> a = {1, 3, 2, 4};
	int n = a.size();
	
	stack<int> s;
	
	vector<int> b(n);
	
	for(int i = 0 ; i < n ; i++)
	{
		while(!s.empty() && a[s.top()] <= a[i])
		s.pop();
		
		b[i] = (s.empty()) ? -1 : s.top();
		
		s.push(i);
	}
	
	while(!s.empty())
	s.pop();
	
	vector<int> c(n);
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		while(!s.empty() && a[s.top()] <= a[i])
		s.pop();
		
		c[i] = (s.empty()) ? n : s.top();
		
		s.push(i);
	}
	
	vector<int> maxi(n);  // can contain from index 1 to n-1 as smallest diff is 1 when conicutive and highest n-1 when next[i]=n-1 and i=0
	
	for(int i = 0 ; i < n ; i++)
	if(c[i] != n)
	maxi[c[i]-i] = max(maxi[c[i]-i] , i - b[i]);
	
	int sum = 0;
	
	for(int i = 0 ; i < n ; i++)
	sum += maxi[i];
	
	set<pair<int,int>> st;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(c[i] != n)
		{
			for(int j = b[i] ; j < i ; j++)  //  O(N^2)
			st.insert({i-j , c[i]-j});
		}
	}
	
	cout << "Number of Pairs : " << sum << endl;
	cout << "Pairs : " << endl;
	
	for(auto i:st)
	cout << i.first << " " << i.second << endl;
	
	return 0;
}

