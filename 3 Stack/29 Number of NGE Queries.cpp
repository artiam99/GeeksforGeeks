#include <bits/stdc++.h> 
using namespace std;

void Ans_Queries(vector<int> &a , int n , vector<pair<int,int>> &Q , int q)
{
	sort(Q.begin() , Q.end() , greater<pair<int,int>>());
	
	vector<int> ans(q);
	
	stack<int> s;
	
	int j = 0;
	
	for(int i = n-1 ; i >= Q[q-1].first ; i--)
	{
		while(!s.empty() && s.top() <= a[i])
		s.pop();
		
		if(i == Q[j].first)
		ans[Q[j++].second] = s.size();
		
		s.push(a[i]);
	}
	
	for(auto i : ans)
	cout << i << " ";
	cout << endl;
}

int main() 
{ 
	vector<int> a = {3, 4, 2, 7, 5, 8, 10, 6};
	int n = a.size();
	
	vector<pair<int,int>> Q = {{0 , 0} , {5 , 1} , {3 , 2}};
	int q = Q.size();
	
	Ans_Queries(a , n , Q , q);
	
	return 0; 
} 

