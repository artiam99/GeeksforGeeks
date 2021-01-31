#include<bits/stdc++.h>
using namespace std;
bool Reconstruct(vector<int> &a , int n)
{
	map<int,int> mp;
	
	for(int i = 0 ; i < n ; i++)
	mp[a[i]]++;
	
	int height = log2(n) + 1;
	
	set<int> Q[height];
	
	Q[height - 1].insert(0);
	
	for(auto i : mp)
	{
		if(i.second > height || Q[i.second - 1].empty())  return false;
		
		int j = *(Q[i.second - 1].begin());
		
		Q[i.second - 1].erase(*(Q[i.second - 1].begin()));
		
		int level = 1;
		
		for(; j < n ; j = j * 2 + 1 , level++)
		{
			if(j * 2 + 2 < n)  Q[i.second - 1 - level].insert(j * 2 + 2);
			
			a[j] = i.first;
		}
	}
	return true;
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
