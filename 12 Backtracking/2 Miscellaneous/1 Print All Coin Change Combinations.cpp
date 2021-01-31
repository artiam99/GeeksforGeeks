#include<bits/stdc++.h>
using namespace std;
void Rec(vector<int> &a,int n ,int mn,int sum,vector<int> &ans,bool &flag)
{
    if(sum == 0)
    {
        flag = false;
        
        for(auto i : ans)
        cout<< i << " ";
        cout<< endl;
        
        return;
    }
    
    if(sum < 0)  return;
    
    int i = lower_bound(a.begin(),a.end(),mn)-a.begin();    
    
    for(; i < n ; i++)
    {
        ans.push_back(a[i]);
        Rec(a,n,a[i],sum-a[i],ans,flag);
        ans.pop_back();
    }
}
void PrintAllComb(vector<int> &a,int n,int k)
{
	sort(a.begin(),a.end());
	    
    bool flag = true;
    vector<int> ans;
    Rec(a,n,INT_MIN,k,ans,flag);
    
    if(flag)
    cout<<"Empty";
    cout<< endl;
}
signed main()
{
	vector<int> a = {7, 2, 6, 5};
	int n = a.size();
	int k = 16;
	
	PrintAllComb(a,n,k);    
		    
	return 0;
}
