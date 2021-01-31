#include <bits/stdc++.h> 
using namespace std;
bool comp(pair<pair<int,int>,int> Q1 , pair<pair<int,int>,int> Q2)
{
	return Q1.first.second < Q2.first.second;
}
int Get_Distinct(int BIT[] , int ind)
{
	int sum = 0;
	
	for(; ind > 0 ; ind -= (ind & -ind))
	sum += BIT[ind];
	
	return sum;
}
void Update(int BIT[] , int n , int ind , int val)
{
	for(; ind <= n ; ind += (ind & -ind))
	BIT[ind] += val;
}
void Ans_Queries(vector<int> &a , int n , vector<pair<pair<int,int>,int>> &Q , int q)
{
	sort(Q.begin() , Q.end() , comp);  // Sorting Queries wrt r to maintain prefix distinct count ... suppose a[2] == a[4] when at 2 include 2 ... whent at 4 exclude 2 include 4
	                                  //  Number of elements in 0 4  remains same by excluding 2 
	int ans[q];
	
	int BIT[n+1];  memset(BIT , 0 , sizeof(BIT));
	
	map<int,int> last_vis;
	
	int j = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(last_vis[a[i]])
		Update(BIT , n , last_vis[a[i]] , -1);
		
		last_vis[a[i]] = i+1;
		Update(BIT , n , i+1 , 1);
		
		while(j < q && Q[j].first.second == i)
		{
			ans[Q[j].second] = Get_Distinct(BIT , i+1) - Get_Distinct(BIT , Q[j].first.first);
			
			j++;
		}
	}
	
	for(int i = 0 ; i < q ; i++)
	cout << ans[i] << " ";
	cout << endl;
}
int main() 
{
	vector<int> a = {1, 1, 2, 1, 3};
	int n = a.size();
	
	vector<pair<pair<int,int>,int>> Q = {{{0 , 4} , 0} , {{1 , 3} , 1} , {{2 , 4} , 2}};
	int q = Q.size();
	
	Ans_Queries(a , n , Q , q);
	
	return 0; 
} 

