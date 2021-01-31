#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a,pair<int,int> b)
{
	return (a.first / (double)a.second) > (b.first / (double)b.second);
}
double MaxValue(vector<pair<int,int>> &a,int n,int W)
{
	sort(a.begin(),a.end(),comp);
	
	double ans = 0.0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(W >= a[i].second)
		{
			ans += a[i].first;
			
			W -= a[i].second;
		}
		else
		{
			ans += (W / (double)a[i].second) * a[i].first;
			
			W = 0;
		}
		
		if(!W) break;
	}
	
	return ans;
}
int main()
{
	vector<pair<int,int>> a = {{60,10} , {100,20} , {120,30}};
	int n = a.size();
	int W = 50;
	
	cout<< fixed;
	cout<< setprecision(2);
	cout<< MaxValue(a,n,W) <<endl;

	return 0;
}

