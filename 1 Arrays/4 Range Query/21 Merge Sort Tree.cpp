#include <bits/stdc++.h> 
using namespace std;

void Build_MST(vector<int> MST[] , int l , int r , vector<pair<int,int>> &a , int msi)
{
	if(l == r)
	{
		MST[msi].push_back(a[l].second);
		
		return;
	}
	
	int m = l + (r - l) / 2;

	Build_MST(MST , l , m , a , msi * 2 + 1);

	Build_MST(MST , m + 1 , r , a , msi * 2 + 2);
	
	merge(MST[msi * 2 + 1].begin() , MST[msi * 2 + 1].end() , MST[msi * 2 + 2].begin() , MST[msi* 2 + 2].end() , back_inserter(MST[msi]));
}

int Query(int l , int r , int ql , int qr , int k , int msi , vector<int> MST[])
{
	if(l == r)
	return MST[msi][0];
	
	int last_left = upper_bound(MST[msi * 2 + 1].begin() , MST[msi * 2 + 1].end() , qr) - MST[msi * 2 + 1].begin();
	
	int first_right = lower_bound(MST[msi * 2 + 1].begin() , MST[msi * 2 + 1].end() , ql) - MST[msi * 2 + 1].begin();
	
	int m = last_left - first_right;
	
	int mid = l + (r - l) / 2;
	
	if(m >= k)
	return Query(l , mid , ql , qr , k , msi * 2 + 1 , MST);
	
	else
	return Query(mid + 1 , r , ql , qr , k - m , msi * 2 + 2 , MST);
}

int main() 
{
	vector<int> a = {3, 2, 5, 1, 8, 9};
	int n = a.size();
	
	vector<pair<int,int>> arr;
	
	for(int i = 0 ; i < n ; i++)
	arr.push_back({a[i] , i});
	
	sort(arr.begin() , arr.end());
	
	int size = 2*(int)pow(2,(int)(ceil(log2(n)))) - 1;
	
	vector<int> MST[size];
	
	Build_MST(MST , 0 , n-1 , arr , 0);
	
	vector<pair<int,pair<int,int>>> Q = {{2 , {2 , 5}} , {4 , {1 , 6}}};
	int q = Q.size();
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].second.first - 1;
		
		int r = Q[i].second.second - 1;
		
		int k = Q[i].first;
		
		int kth_idx = Query(0 , n-1 , l , r , k , 0 , MST);
		
		cout << a[kth_idx] << endl;
	}
	
	return 0; 
}
