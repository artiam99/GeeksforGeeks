#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> x , pair<int,int> y)
{
	if(x.second == y.second)  return x.first < y.first;
	
	return x.second > y.second;
}
bool Check(vector<int> &a , int sti , int n)
{
	if(sti > n)  return true;
	
	if(!Check(a,sti * 2 + 1 , n))  return false;
	
	if(!Check(a,sti * 2 + 2 , n))  return false;
	
	return (sti * 2 + 1 >= n || a[sti] == min(a[sti * 2 + 1] , a[sti * 2 + 2])); 
}
bool Reconstruct(vector<int> &a , int n)
{
	unordered_map<int,int> mp;
	
	for(int i = 0 ; i < n ; i++)
	mp[a[i]]++;
	
	vector<pair<int,int>> st;
	
	for(auto i : mp)
	st.push_back({i.first , i.second});
	
	sort(st.begin(),st.end(),comp);
	
	int root = 0;
	
	for(int i = 0 ; i < st.size() ; i++)
	{
		int height = log2(n) - ((root == 0) ? 0 : log2(root)) + 1;
		
		if(height != st[i].second)  return false;
		
		for(int j = root ; j < n ; j = j * 2 + 1)
		a[j] = st[i].first;
		
		root += 2;
	}
	
	return Check(a,0,n);
}
signed main()
{
	vector<int> a = {1, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 6, 7, 8};  // 2 * N - 1 Elements where N is in 2's Power and This is RMQ Segment Tree of Array of N Distict elements
	int n = a.size();
	
	if(Reconstruct(a,n))
	{
		for(auto i : a)
		cout << i << " ";
		cout << endl;
	}
	
	else  cout << "Not Possible" << endl;
		
	return 0;
}
