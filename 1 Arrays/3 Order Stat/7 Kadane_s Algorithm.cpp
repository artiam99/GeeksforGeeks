#include <bits/stdc++.h> 
using namespace std;

void Max_Sum_Subarr(vector<int> &a , int n)
{
	int max_so_far = a[0];
	
	int max_curr = a[0];
	
	int start = 0 , end = 0 , temp_start = 0;
	
	for(int i = 1 ; i < n ; i++)
	{
		if(max_curr + a[i] < a[i])
		temp_start = i;
		
		max_curr = max(a[i] , max_curr + a[i]);
		
		max_so_far = max(max_so_far , max_curr);
		
		if(max_so_far == max_curr)
		{
			start = temp_start;
			
			end = i;
		}
	}
	
	cout << max_so_far << " Indices : " << start << " " << end << endl;
}

int main() 
{
	vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = a.size();
	
	Max_Sum_Subarr(a , n);
	
	return 0; 
}
