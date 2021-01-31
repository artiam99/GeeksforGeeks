#include<bits/stdc++.h>
using namespace std;
bool Rec(vector<int> &a,int &n,int &k,int i,int ans[],int &sz,int &n1)
{
    if(i == n)
    {
        if(sz == k)
        {
            for(int j = 0 ; j < k ; j++)
            if(ans[j] != n1)
            return false;

            return true;
        }
        return false;
    }

    for(int j = 1 ; j <= sz ; j++)
    if((j == sz || ans[j] != ans[j-1] ) && ans[j-1] + a[i] <= n1 && k - sz <= n - i - 1)
    {
        ans[j-1] += a[i];
        
		if(Rec(a,n,k,i+1,ans,sz,n1))  return true;
        
		ans[j-1] -= a[i];
    }

    if(sz < k)
    {
        ans[sz++] = a[i];
        
    	if(Rec(a,n,k,i+1,ans,sz,n1))  return true;
    	
    	sz--;
    }
    
    return false;
}
bool isKPartitionPossible(vector<int> &a, int &n, int &k)
{
    sort(a.begin(),a.end(),greater<int>());
    
    int sum = accumulate(a.begin(),a.end(),0) , mx = a[n-1];
	
	if(sum % k != 0)  return false;
	
	int n1 = sum / k;
    
    if(n1 < mx)  return false;
    
	int ans[k];  ans[0] = a[0];  int sz = 1;
    
    return Rec(a,n,k,1,ans,sz,n1);
}
signed main()
{
	vector<int> a = {10,10,10,7,7,7,7,7,7,6,6,6};
	int n = a.size();
	int k = 3;
	
	cout<< isKPartitionPossible(a,n,k) << endl;
	
	return 0;
}
