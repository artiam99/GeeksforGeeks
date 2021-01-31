#include<bits/stdc++.h>
using namespace std;

int Max_Diff(vector<int> &a , int n , int k)
{
	sort(a.begin(),a.end());
	
	int ans = a[n-1]-a[0];  //if we do same operation in both end max and min will be the ends
	
	int small = a[0] + k , big = a[0] - k;
	
	if(big<small)  swap(big,small);
	
	for(int i = 0 ; i < n ; i++)
	{
		int add = a[i] + k , sub = a[i] - k;
		
		if(add <= big || sub >= small)
		continue;
		
		if(add - small < big - sub)  big = add;
	
		else  small = sub;
	}
	
	return min(ans , big - small);
}

int main()
{
	vector<int> a = {1, 5, 8, 10};
	int n = a.size();
	int k = 2;
	
	cout << Max_Diff(a , n , k) << endl;
	
	return 0;
}
