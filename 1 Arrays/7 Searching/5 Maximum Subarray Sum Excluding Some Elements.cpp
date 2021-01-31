#include<bits/stdc++.h>
using namespace std;

int Max_Sum(vector<int> &a , int n , vector<int> &b , int m)
{
	unordered_set<int> s;
	
	for(int i = 0 ; i < m ; i++)
	s.insert(b[i]);
	
	int curr = 0 , sofar = INT_MIN;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(s.find(a[i]) != s.end())
		{
			curr = 0;
			
			continue;
		}
		
		curr = max(a[i] , a[i] + curr);
		
		sofar = max(curr , sofar);
	}
	
	return sofar;
}

signed main()
{
	vector<int> a = {1, 7, -10, 6, 2};
	int n = a.size();
	
	vector<int> b = {5, 6, 7, 1};
	int m = b.size();
	
	cout << Max_Sum(a , n , b , m) << endl;
	
	return 0;
}
