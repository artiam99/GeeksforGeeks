#include <bits/stdc++.h>
using namespace std;

int Longest_Consecutive_Sequence(vector<int> &a , int n)
{
	unordered_set<int> st;
	
	for(int i = 0 ; i < n ; i++)
	st.insert(a[i]);
	
	int mx = 0;
	
	for(int i = 0 ; i < n ; i++)
	if(st.find(a[i]) != st.end())
	{
		int cnt = 0;
		
		int l = a[i];
		
		while(st.find(l) != st.end())
		{
			cnt++;
			
			st.erase(l);
			
			l--;
		}
		
		int r = a[i] + 1;
		
		while(st.find(r) != st.end())
		{
			cnt++;
			
			st.erase(r);
			
			r++;
		}
		
		mx = max(mx , cnt);
	}
	return mx;
}

int main()
{
	vector<int> a = {2, 4, 3, 1, 9, 5, 6};
	int n = a.size();
	
	cout << Longest_Consecutive_Sequence(a , n) << endl;
	
	return 0;
}
