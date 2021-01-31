#include<bits/stdc++.h>  // https://practice.geeksforgeeks.org/problems/interesting-queries/0
using namespace std;

int blocksize;

bool comp(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2)
{
	if(p1.second.first / blocksize != p2.second.first  / blocksize)
	return (p1.second.first / blocksize < p2.second.first / blocksize);
	
	return (p1.second.second < p2.second.second);
}

void Query_Sum(vector<int> &a , int n , vector<pair<int,pair<int,int>>> &Q , int q , int k)
{
	blocksize = (int)sqrt(n);
	
	sort(Q.begin(),Q.end(),comp);
	
	int curl = 0 , curr = -1 , cursum = 0;
	
	vector<int> m(10001);
	
	vector<int> ans(q);
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].second.first;
		
		int r = Q[i].second.second;
		
		while(curr < r)
		{
		    curr++;
		    
			m[a[curr]]++;
			
			if(m[a[curr]] == k)
			cursum++;
		}
		
		while(curr > r)
		{
			m[a[curr]]--;
			
			if(m[a[curr]] == k - 1)
			cursum--;
			
			curr--;
		}
		
		while(curl < l)
		{
			m[a[curl]]--;
			
			if(m[a[curl]] == k - 1)
			cursum--;
			
			curl++;
		}
		
		while(curl > l)
		{
		    curl--;
		    
			m[a[curl]]++;
			
			if(m[a[curl]] == k)
			cursum++;
		}
		
		ans[Q[i].first] = cursum;
	}
	
	for(int i = 0 ; i < q ; i++)
	cout << ans[i] << " ";
	cout<<endl;
}

signed main()
{
	vector<int> a = {1, 1, 2, 1, 3};
	int n = a.size();
	int k = 1;
	
	vector<pair<int,pair<int,int>>> Q = {{0 , {0 , 4}} , {1 , {1 , 3}}};
	int q = Q.size();
	    
	Query_Sum(a , n , Q , q , k);
	
	return 0;
}
