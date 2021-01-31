#include<bits/stdc++.h>
using namespace std;
void K_Max_Sum_SubArr(vector<int> &a,int n,int k)
{
	for(int i = 1 ; i < n ; i++)
	a[i] += a[i-1];
	
	vector<int> minp(k,INT_MAX);
	
	minp[0] = 0;
	
	vector<int> ans(k,INT_MIN);
	
	vector<int> cand(k);
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < k ; j++)
		cand[j] = ((minp[j] == INT_MAX) ? INT_MIN : a[i] - minp[j]);
		
		vector<int> temp(k);
		
		int i1 = 0 , i2 = 0 , it = 0;
        
        while(i1 < k && i2 < k)
        temp[it++] = ((ans[i1] > cand[i2]) ? ans[i1++] : cand[i2++]);
        
        for(int j = 0 ; j < k ; j++)
        ans[j] = temp[j];
		
		for (int j = 0 ; j < k; j++)
		{ 
        	if (a[i] < minp[j])
			{
			    for(int l = k-1 ; l > j ; l--)
			    minp[l]=minp[l-1];
			    
            	minp[j]=a[i];
            	
            	break;
			}
        }
	}
	
	for(int i = 0 ; i < k ; i++)
	if(ans[i] != INT_MIN)
	cout<< ans[i] <<" ";
	cout<<endl;
}
signed main()
{
	vector<int> a = {4 , -8, 9, -4, 1, -8, -1, 6};
	int n = a.size();
	
	int k = 4;
	
	K_Max_Sum_SubArr(a,n,k);
    
	return 0;
}
