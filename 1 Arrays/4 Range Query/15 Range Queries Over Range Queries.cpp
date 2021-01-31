#include<bits/stdc++.h>
using namespace std;

void Ans_Queries(vector<int> &a , int n , vector<pair<pair<int,int>,pair<int,int>>> &Q , int q)
{
	for(int i = q-1 ; i >= 0 ; i--)
	if(Q[i].first.first == 2)
	{
		for(int j = Q[i].second.first - 1 ; j<= Q[i].second.second - 1 ; j++)
		Q[j].first.second += Q[i].first.second;
	}
	
	for(int i = 0 ; i < q ; i++)
	{
		if(Q[i].first.first == 1)
		{
			for(int j = Q[i].second.first - 1 ; j <= Q[i].second.second - 1 ; j++)
			a[j] += Q[i].first.second;
		}
		
		for(auto i : a)
		cout << i << " " ;
		cout<<endl;
	}
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
}

signed main()
 {
	vector<int> a(5);
	int n = 5;
	
	vector<pair<pair<int,int>,pair<int,int>>> Q = {{{1 , 1} , {1 , 2}} , {{1 , 1} , {4 , 5}} , {{2 , 1} , {1 , 2}} , {{2 , 1} , {1 , 3}} , {{2 , 1} , {3 , 4}}};
	int q = Q.size();
	
	Ans_Queries(a , n , Q , q);
	
	return 0;
}
