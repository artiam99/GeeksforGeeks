#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
{
	return a.second.second < b.second.second;
}
int Activity_Selection(vector<pair<int,int>> &a,int n)
{
	vector<pair<int,pair<int,int>>> arr(n);
	
	for(int i = 0 ; i < n ; i++)
	arr[i].first = i+1 , arr[i].second.first = a[i].first , arr[i].second.second = a[i].second;
	
	sort(arr.begin(),arr.end(),comp);
	
	int j = 0;
	
	cout<< arr[j].first << " ";
	
	for(int i = 0 ; i < n ; i++)
	{
		if(arr[j].second.second < arr[i].second.first)
		{
			j = i;
			
			cout<< arr[j].first << " ";
		}
	}
	cout<< endl;
}
int main()
{
	vector<pair<int,int>> a = {{3,4} , {0,6} , {5,7} , {8,9} , {5,9} , {1,2}};
	int n = a.size();
	
	Activity_Selection(a,n);

	return 0;
}
