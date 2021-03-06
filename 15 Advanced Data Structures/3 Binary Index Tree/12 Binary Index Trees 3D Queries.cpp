#include<bits/stdc++.h>
using namespace std;

bool compa(pair<int,int> a1 , pair<int,int> a2)
{
	return (a1.first < a2.first);
}

bool compq(pair<pair<int,int>,pair<int,int>> q1 , pair<pair<int,int>,pair<int,int>> q2)
{
	return (q1.second.second < q2.second.second);
}

void Update(vector<int> &BIT , int idx , int val , int n)
{
	while(idx <= n)
	{
		BIT[idx] += val;
		
		idx += (idx & -idx);
	}
}

int Query(vector<int> &BIT , int idx)
{
	int sum = 0;
	
	while(idx > 0)
	{
		sum += BIT[idx];
		
		idx -= (idx & -idx);
	}
	
	return sum;
}

void Less_Than_Or_Equal_To(vector<pair<int,int>> a,int n,vector<pair<pair<int,int>,pair<int,int>>> Q,int q)
{
	sort(a.begin() , a.end() , compa);
	
	sort(Q.begin() , Q.end() , compq);
	
	vector<int> BIT(n+1);
	
	vector<int> ans(q);
	
	int idxa = 0;
	
	for(int i = 0 ; i < q ; i++)
	{
		while(a[idxa].first <= Q[i].second.first && idxa < n)
		{
			Update(BIT , a[idxa].second + 1 , 1 , n);
			
			idxa++;
		}
		
		ans[Q[i].second.second] = Query(BIT , Q[i].first.second + 1) - Query(BIT , Q[i].first.first);
	}
	
	for(int i = 0 ; i < q ; i++)
	cout << ans[i] << " ";
	cout << endl;
}

signed main()
{
	vector<pair<int,int>> a = {{2 , 0} , {3 , 1} , {4 , 2} , {5 , 3}};
	int n = a.size();
	
	vector<pair<pair<int,int>,pair<int,int>>> Q = {{{0 , 2} , {2 , 0}} , {{0 , 3} , {5 , 1}}};
	int q = Q.size();
	
	Less_Than_Or_Equal_To(a , n , Q , q);
	
	return 0;
}

