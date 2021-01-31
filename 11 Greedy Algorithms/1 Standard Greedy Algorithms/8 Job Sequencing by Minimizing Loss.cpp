#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
{
	return a.second.first * b.second.second > b.second.first * a.second.second;
}
void Minimize_Loss(vector<int> &L,vector<int> &T,int n)
{
	vector<pair<int,pair<int,int>>> a(n);
	
	for(int i = 0 ; i < n ; i++)
	a[i].first = i+1 , a[i].second = {L[i],T[i]};
	
	stable_sort(a.begin(),a.end(),comp);
	
	for(int i = 0 ; i < n ; i++)
	cout<< a[i].first << " ";
	cout<<endl;
}
int main()
{
	vector<int> L = {3, 1, 2, 4};
	vector<int> T = {4, 1000, 2, 5};
	int n = L.size();
	
	Minimize_Loss(L,T,n);
	
	return 0;
}
