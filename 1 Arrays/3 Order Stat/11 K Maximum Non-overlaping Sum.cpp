#include <bits/stdc++.h> 
using namespace std;

void K_Max_Subarr(vector<int> &a , int n , int k)
{
	int maxcur , sofar , start , end , temp_start;
	
	for(int i = 0 ; i < k ; i++)
	{
		maxcur = a[0];
		
		sofar = a[0];
		
		start = 0 , end = 0 , temp_start = 0;
		
		for(int j = 1 ; j < n ; j++)
		{
			if(maxcur + a[j] < a[j])
			temp_start = j;
			
			maxcur = max(a[j] , a[j] + maxcur);
			
			sofar = max(sofar , maxcur);
			
			if(sofar == maxcur)
			{
				start = temp_start;
				
				end = j;
			}
		}
		
		cout << sofar << " " << start << " " << end << endl;

		for(int j = start ; j<= end ; j++)
		a[j] = -100000;
	}
}

int main() 
{
	vector<int> a = {4, 1, 1, -1, -3, -5, 6, 2, -6, -2 };
	int n = a.size();
	int k = 3;
	
	K_Max_Subarr(a , n , k);
	
	return 0; 
} 

