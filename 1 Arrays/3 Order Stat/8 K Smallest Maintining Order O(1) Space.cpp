#include<bits/stdc++.h>
using namespace std;

void K_Smallest(vector<int> &a , int n , int k)
{
	for(int i = k ; i < n ; i++)
	{
		int pos = max_element(a.begin() , a.begin() + k) - a.begin();
		
		if(a[pos] > a[i])
		{
			for(int j = pos ; j < k - 1 ; j++)
			a[j] = a[j+1];
			
			a[k-1] = a[i];
		}
	}
	
	for(int i = 0 ; i < k ; i++)
	cout << a[i] << " ";
	cout << endl;
}

signed main()
 {
	vector<int> a = {6, 4, 5, 2, 1};
	int n = a.size();
	int k = 3;
	
	K_Smallest(a , n , k);
	
	return 0;
}
