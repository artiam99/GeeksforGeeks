#include<bits/stdc++.h>
using namespace std;
int lowerbound(vector<int> &a,int tail[],int l,int r,int x)
{
	int ans = r+1;
	
	while(l <= r)
	{
		int m = l + (r-l)/2;
		
		if(a[tail[m]] >= x)
		{
			ans = m;
			
			r = m-1;
		}
		else
		l = m+1;
	}
	return ans;
}
void LIS(vector<int> &a,int n,vector<int> &ans)
{
	int tail[n] , in[n];
	
	memset(in,-1,sizeof(in));
	
	int len = 1;
	
	tail[0] = 0;
	
	for(int i = 1 ; i < n ; i++)
	{
		if(a[i] < a[tail[0]])
		tail[0] = a[i];
		
		else if(a[i] > a[tail[len-1]])
		{
			tail[len] = i;
			
			in[i] = tail[len-1];
			
			len++;
		}
		
		else
		{
			int ind = lowerbound(a,tail,0,len-1,a[i]);
			
			tail[ind] = i;
			
			in[i] = tail[ind-1];
		}
	}
	
	for(int i = tail[len-1] ; i != -1 ; i = in[i])
	ans.push_back(a[i]);
}
void MaxBiot(vector<int> &a1,int n1,vector<int> &a2,int n2)
{
	vector<int> ans;
	
	LIS(a1,n1,ans);
	
	reverse(ans.begin(),ans.end());
	
	reverse(a2.begin(),a2.end());
	
	LIS(a2,n2,ans);
	
	for(auto i:ans)
	cout<< i <<" ";
	cout<<endl;
}
signed main()
{
	vector<int> a1 = {1, 5, 2, 4, 3, 5};
	int n1= a1.size();
	
	vector<int> a2 = {8, 6, 4, 7, 3, 2};
	int n2 = a2.size();
	
	MaxBiot(a1,n1,a2,n2);
	
	return 0;
}
