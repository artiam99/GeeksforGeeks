#include<bits/stdc++.h>
using namespace std;
int Max_Trains(vector<pair<int,pair<int,int>>> &arr,int m,int n)
{
	vector<pair<int,int>> a[n];
	
	for(int i = 0 ; i < m ; i++)
	a[arr[i].first-1].push_back(arr[i].second);
	
	int ans = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		sort(a[i].begin(),a[i].end());
		
		int first = INT_MIN , second = INT_MIN;
		
		for(int j = 0 ; j < a[i].size() ; j++)
		{
			if(a[i][j].first >= first)
			{
				ans++;
				
				first = a[i][j].second;
			}
			else if(a[i][j].first >= second)
			{
				ans++;
				
				second = a[i][j].second;
			}
			else
			{
				if(first > second)
				first = min(first , a[i][j].second);
				
				else
				second = min(second , a[i][j].second);
			}
		}
	}
	return ans;
}
int main()
{
	vector<pair<int,pair<int,int>>> a = {{1,{1000,1030}} , {1,{1010,1030}} , {2,{1000,1020}} , {2,{1030,1230}} , {3,{1200,1230}} , {1,{900,1050}}};
	int m = a.size();
	int n = 3;
	
	cout<< Max_Trains(a,m,n) << endl;
}
