#include <bits/stdc++.h> 
using namespace std;

int block;

bool comp(pair<int,pair<int,int>> p1 , pair<int,pair<int,int>> p2)
{
	if(p1.second.first / block != p2.second.first / block)
	return (p1.second.first / block < p2.second.first / block);
	
	return (p1.second.second < p2.second.second);
}

void Ans_Queries(vector<int> &a , int n , vector<pair<int,pair<int,int>>> &Q , int q)
{
	block = (int)sqrt(n);
	
	sort(Q.begin() , Q.end() , comp);
	
	int curr = -1 , curl = 0;
	
	int x = 0;
	
	vector<int> ans(q);
	
	map<int,int> m;
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].second.first;
		
		int r = Q[i].second.second;
		
		int idx = Q[i].first;
		
		while(curr < r)
		{
			curr++;
			
			m[a[curr]]++;
			
			if(a[curr] == m[a[curr]])
			x++;
			
			else if(a[curr] + 1 == m[a[curr]])
			x--;
		}
		
		while(curr > r)
		{
			m[a[curr]]--;
			
			if(a[curr] - 1 == m[a[curr]])
			x--;
			
			else if(a[curr] == m[a[curr]])
			x++;
			
			curr--;
		}
		
		while(curl < l)
		{
			m[a[curl]]--;
			
			if(a[curl] - 1 == m[a[curl]])
			x--;
			
			else if(a[curl] == m[a[curl]])
			x++;
			
			curl++;
		}
		
		while(curl > l)
		{
			curl--;
			
			m[a[curl]]++;
			
			if(a[curl] == m[a[curl]])
			x++;
			
			else if(a[curl] + 1 == m[a[curl]])
			x--;
		}
		
		ans[idx] = x;
	}
	
	for(int i = 0 ; i < q ; i++)
	cout << ans[i] << " ";
	cout << endl;
}

int main() 
{ 
	vector<int> a = {1, 2, 2, 3, 3, 3}; 
	int n = a.size();
	
	vector<pair<int,pair<int,int>>> Q = {{0 , {0 , 1}} , {1 , {1 , 1}} , {2 , {0 , 2}} , {3 , {1 , 3}} , {4 , {3 , 5}} , {5 , {0 , 5}}};
	
	int q = Q.size();
	
	Ans_Queries(a , n , Q , q);
	
	return 0;
}

