#include <bits/stdc++.h> 
using namespace std;

int block;

bool comp(pair<pair<int,int>,pair<int,int>> q1 , pair<pair<int,int>,pair<int,int>> q2)
{
	if(q1.second.first / block != q2.second.first / block)
	return (q1.second.first / block < q2.second.first / block);
	
	return (q1.second.second < q2.second.second);
}

void Ans_Queries(vector<int> &a , int n , vector<pair<pair<int,int>,pair<int,int>>> &Q , int q)
{
	block=(int)sqrt(n);
	
	map<int,int> s;
	
	sort(Q.begin() , Q.end() , comp);
	
	int curl = 0 , curr = -1;
	vector<string> ans(q);
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].second.first - 1;
		
		int r = Q[i].second.second - 1;
		
		int val = Q[i].first.first;
		
		int idx = Q[i].first.second;
		
		while(curr < r)
		{
			curr++;
			
			s[a[curr]]++;
		}
		
		while(curr > r)
		{
			s[a[curr]]--;
			
			curr--;
		}
		
		while(curl < l)
		{
			s[a[curl]]--;
			
			curl++;
		}
		
		while(curl > l)
		{
			curl--;
			
			s[a[curl]]++;
		}
		
		if(s[val] <= 0)
		ans[idx] = "NO";
		
		else
		ans[idx] = "YES";
	}
	
	for(auto i : ans)
	cout << i << endl;
}

int main() 
{
	vector<int> a = {1, 4, 5, 6, 3, 5, 4, 2, 9, 0, 5, 8};
	int n = a.size();
	
	vector<pair<pair<int,int>,pair<int,int>>> Q = {{{2 , 0} , {5 , 9}} , {{0 , 1} , {9 , 11}} , {{3 , 2} , {1 , 4}}};
	int q = Q.size();
	
	Ans_Queries(a , n , Q , q);
	
	return 0;
} 

