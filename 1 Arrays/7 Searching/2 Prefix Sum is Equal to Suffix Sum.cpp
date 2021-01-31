#include<bits/stdc++.h>
using namespace std;

void Pref_Suff(vector<int> &a , int n)
{
	int sum = accumulate(a.begin() , a.end() , 0);
	
	vector<int> c;
	
	int prefsum = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		prefsum += a[i];
		
		if(prefsum == sum)
		c.push_back(i);
		
		sum -= a[i];
	}
	
	for(auto i : c)
	cout << i << " ";
	cout << endl;
}

signed main()
{
	vector<int> a = {-1, 2, 3, 0, 3, 2, -1};
	int n = a.size();
	
	Pref_Suff(a , n);
	
	return 0;
}
