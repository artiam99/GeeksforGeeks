#include<bits/stdc++.h>
using namespace std;

int blocksize;

bool comp(pair<int,pair<int,int>> p1 , pair<int,pair<int,int>> p2)
{
	if(p1.second.first / blocksize != p2.second.first / blocksize)
	return (p1.second.first / blocksize < p2.second.first / blocksize);
	
	return (p1.second.second < p2.second.second);
}

void Query_Sum(vector<int> &a , int n , vector<pair<int,pair<int,int>>> &Q , int q)
{
	blocksize = (int)sqrt(n);
	
	sort(Q.begin() , Q.end() , comp);
	
	int curl = 0 , curr = -1 , cursum = 0;
	
	vector<int> ans(q);
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].second.first;
		
		int r = Q[i].second.second;
		
		while(curr < r)  //line 24 ...... 44 maintain the order
		{
			curr++;
			
			cursum += a[curr];
		}
		
		while(curr > r)  //be careful about curr and curl........... curr is increased by 1 after sum is calculated and curl remains the same 
		{
			cursum -= a[curr];
			
			curr--;
		}
		
		while(curl < l)
		{
			cursum -= a[curl];
			
			curl++;
		}
		
		while(curl > l)
		{
			curl--;
			
			cursum += a[curl];
		}
		
		ans[Q[i].first] = cursum;
	}
	
	for(int i = 0 ; i < q ; i++)
	cout << ans[i] << endl;
}

signed main()
{
	vector<int> a = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10}; 
    int n = a.size();
	 
    vector<pair<int,pair<int,int>>> Q={{0 , {3 , 8}} , {1 , {1 , 6}} , {2 , {8 , 8}}};
	int q = Q.size();
	
    Query_Sum(a , n , Q , q);
	
	return 0;
}
