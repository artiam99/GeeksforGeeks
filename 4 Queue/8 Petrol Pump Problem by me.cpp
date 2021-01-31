#include<bits/stdc++.h>
using namespace std;

int first_petrol_pump(vector<pair<int,int>> &a , int n)
{
	int start = 0;
	
	int sum = 0;
	int ext_sum = 0;  //sum to be added at the end
	
	for(int i = 0 ; i < n ; i++)
	{
		sum += a[i].first - a[i].second;  //remaining petrol
		
		while(start <= i && sum < 0)  //remaing petrol must be at least 0 to reach next petrol pump
		{
			sum -= a[start].first - a[start].second;
			
			ext_sum += a[start].first - a[start].second;
			
			start++;
		}
	}
	
	if(sum+ext_sum >= 0)  //total remaining
	return start;
	
	return -1;
}

signed main()
{
	vector<pair<int,int>> a = {{4 , 6} , {6 , 5} , {7 , 3} , {4 , 5}};  //  Petrol , Distance of next pump
	int n = a.size();

	cout << "First Petrol Pump to finish the journey : " << first_petrol_pump(a , n);

	return 0;
}
