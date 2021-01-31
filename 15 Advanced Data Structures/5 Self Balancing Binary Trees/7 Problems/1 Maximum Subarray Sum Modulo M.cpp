#include <bits/stdc++.h> 
using namespace std;
int Max_Mod_Sum(vector<int> &a , int n , int m)
{
	int mx = INT_MIN , prefix = 0;
	
	set<int> s;
	
	for(int i = 0 ; i < n ; i++)
	{
		prefix = (prefix + a[i]) % m;
		
		mx = max(mx , prefix);
		
		auto it = s.lower_bound(prefix + 1);  // Smallest Number Greater than equal to prefix + 1
		
		if(it != s.end())
		mx = max(mx , prefix - (*it) + m);
		
		if(mx == m-1)  break;
	}
	
	return mx;
}
signed main() 
{ 
	vector<int> a = {3 , 3 , 9 , 9 , 5 };
	int n = a.size();
	int m = 7;
	
	cout << Max_Mod_Sum(a , n , m) << endl;

	return 0; 
} 

