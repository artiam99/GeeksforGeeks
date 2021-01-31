#include<bits/stdc++.h> 
using namespace std;

int No_of_Operation(vector<int> &a , int n , int k)
{
	int mx = INT_MAX;
	
	for(int i = 0 ; i < n ; i++)
	if(a[i] > mx)
	mx = a[i];
	
	int res = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if((mx - a[i]) % k == 0)
		res += (mx - a[i]) / k;
		
		else
		{
			res = -1;
		
			break;
		}
	}
	
	return res;
}

int main() 
{
	vector<int> a = {21, 33, 9, 45, 63};
	int n = a.size();
	int k = 6;
	
	cout << No_of_Operation(a , n , k) << endl;
	
	return 0;
}
