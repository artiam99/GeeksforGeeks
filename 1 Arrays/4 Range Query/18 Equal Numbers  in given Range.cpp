#include <bits/stdc++.h> 
using namespace std;

void Ans_Queries(vector<int> &a , int n , vector<pair<int,int>> &Q , int q)
{
	vector<int> b(n);
	
	for(int i = 0 ; i < n-1 ; i++)
	{
		if(a[i] == a[i+1])
		b[i]++;
	}
	
	for(int i = 1 ; i < n ; i++)
	b[i] += b[i-1];
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].first;
		
		int r = Q[i].second;
		
		if(l != 0)
		cout << b[r-1] - b[l-1] << endl;
		
		else
		cout << b[r-1] << endl;
	}
}

int main() 
{ 
	vector<int> a = {1, 2, 2, 2, 3, 3, 4, 4, 4}; 
	int n = a.size();
	
	vector<pair<int,int>> Q = {{1 , 8} , {0 , 4}};
	int q = Q.size();
	
	Ans_Queries(a , n , Q , q);
	
	return 0; 
} 

