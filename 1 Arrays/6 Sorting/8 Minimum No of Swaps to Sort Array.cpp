#include<bits/stdc++.h>
using namespace std;

int No_of_Swap(vector<int> &arr , int n)
{
	pair<int,int> a[n];
	
	for(int i = 0 ; i < n ; i++)
	{
		a[i].first = arr[i];
		
		a[i].second = i + 1;
	}
	
	sort(a , a + n);
	
	int c = 0;
	
	for(int i = 0 ; i < n ; i++)
	if(a[i].second != -1 && a[i].second != i + 1)
	{
		int j = a[i].second;
		
		while(i + 1 != j)
		{
			c++;
			
			int x = a[j-1].second;
			
			a[j-1].second = -1;
			
			j = x;
		}
	}
	
    return c;
}

signed main()
 {
 	vector<int> arr = {1, 3, 4, 5, 2};
 	int n = arr.size();
 	
 	cout << No_of_Swap(arr , n) << endl;
 	
 	return 0;
}

