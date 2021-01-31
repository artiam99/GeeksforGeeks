#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.second > b.second;
}
int Find(vector<int> &parent,int x)
{
    if(parent[x] != x)
    parent[x] = Find(parent , parent[x]);
    
    return parent[x];
}
void Union(vector<int> &parent,int sroot,int droot)
{
    parent[droot] = sroot;
}
void JobSeq(vector<pair<int,int>> &a,int n)
{
	sort(a.begin(),a.end());
	
	sort(a.begin(),a.end(),comp);
    
    int mx = INT_MIN;
    
    for(int i = 0 ; i < n ; i++)
    mx = max(mx , a[i].first);
    
    vector<int> parent(mx+1);
    
    for(int i = 0 ; i <= mx ; i++)
    parent[i] = i;
    
    int ans = 0 , cnt = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        int curr = Find(parent , a[i].first);
        
        if(curr > 0)
        {
            Union(parent , Find(parent , curr - 1) , curr);
            
            ans += a[i].second;
            
            cnt++;
        }
    }
    cout<< cnt << " " << ans << endl;
}
int main()
{
	vector<pair<int,int>> a = {{3,100} , {16,15} , {1,25} , {3,57} , {3,61} , {1,19} , {3,7}};
	int n = a.size();
	
	JobSeq(a,n);

	return 0;
}
