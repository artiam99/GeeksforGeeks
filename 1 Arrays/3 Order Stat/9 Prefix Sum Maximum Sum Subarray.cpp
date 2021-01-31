#include<bits/stdc++.h>
using namespace std;

int Max_Sum_Subarr(vector<int> &a , int n)
{
	vector<int> b(n);
	
	b[0] = a[0];
	
	for(int i = 1 ; i < n ; i++)
	b[i] = b[i-1] + a[i];
	
	int minp = 0;
	
	int res = INT_MIN;
	
	for(int i = 0 ; i < n ; i++)
	{
		res = max(res , b[i] - minp);
		
		minp = min(minp , b[i]);
	}
	
	return res;	
}

int main() 
{
	vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = a.size();
	
	cout << Max_Sum_Subarr(a , n) << endl;

    return 0; 
}
