#include<bits/stdc++.h>
using namespace std;
void MaxMinProd(vector<int> &a,int n)
{
	int Min_Res = a[0] , Max_Res = a[0] , Max_Curr = a[0] , Min_Curr = a[0];
	
	for(int i = 1 ; i < n ; i++)
	{	
		if(a[i] < 0)
		swap(Max_Curr , Min_Curr);
			
		Max_Curr = max(a[i] , Max_Curr * a[i]);
		
		Min_Curr = min(a[i] , Min_Curr * a[i]);
		
		Min_Res = min(Min_Res , Min_Curr);
		
		Max_Res = max(Max_Res , Max_Curr);
	}
	
	cout<< Max_Res << " " << Min_Res << endl;
}
signed main()
{
	vector<int> a = {-1, -1, -2, 4, 3, 0};
	int n = a.size();
	
	cout<< "Max Prod Subset && Min Prod Subarray : " ;
	
	MaxMinProd(a,n);
	
	return 0;
}
