#include <bits/stdc++.h> 
using namespace std;

int Max_Profit(vector<int> &a , int n)
{
	vector<int> profit(n);
	
	int max_el = a[n-1];
	
	for(int i = n-2 ; i >= 0 ; i--)
	{
		if(a[i] > max_el)
		max_el = a[i];
		
		profit[i] = max(profit[i+1] , max_el - a[i]);
	}
	
	int min_el = a[0];
	
	for(int i = 1 ; i < n ; i++)
	{
		if(a[i] < min_el)
		min_el = a[i];
	
		profit[i] = max(profit[i-1] , profit[i] + a[i] - min_el);
	}
	
	return profit[n-1];
}

int main() 
{
	vector<int> a = {10, 22, 5, 75, 65, 80};  //22-10 +80-5 max.....we need 2 non overlapping sub array one after another where sum of last - first will be maximium 
	int n = a.size();
	
	cout << Max_Profit(a , n) << endl;
	
	return 0; 
}
