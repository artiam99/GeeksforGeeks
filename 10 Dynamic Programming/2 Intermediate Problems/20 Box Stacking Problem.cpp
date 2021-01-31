#include<bits/stdc++.h>
using namespace std;
int Maxheight(int h[],int w[],int l[],int n)
{
    vector<pair<pair<int,int>,pair<int,int>>> p;
    
    for(int i=0;i<n;i++)
    {
        p.push_back({ {w[i] * l[i] , h[i]} , {w[i] , l[i]} });
        p.push_back({ {h[i] * l[i] , w[i]} , {h[i] , l[i]} });
        p.push_back({ {w[i] * h[i] , l[i]} , {w[i] , h[i]} });
    }
    sort(p.begin(),p.end());
    
    vector<int> dp(p.size());
	
	for(int i=0;i<p.size();i++)
	dp[i]=p[i].first.second;
	
	int mx=dp[0];
    
    for(int i=1 ; i < p.size() ; i++)
    for(int j=0 ; j < i ; j++)
    {
        if((p[j].second.first < p[i].second.first && p[j].second.second < p[i].second.second) || (p[j].second.first < p[i].second.second && p[j].second.second < p[i].second.first))
        dp[i] = max(dp[i] , dp[j] + p[i].first.second);
        
        mx = max(mx , dp[i]);
    }
    return mx;
}
signed main()
{
	int n = 4;
	int height[] = {4,1,4,10};
	int width[] = {6,2,5,12};
	int length[] = {7,3,6,32};
	
	cout<< Maxheight(height,width,length,n) <<endl;
    
	return 0;
}
