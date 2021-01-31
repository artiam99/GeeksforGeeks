#include <bits/stdc++.h> 
using namespace std;
bool comp(pair<int,pair<int,int>> a1 , pair<int,pair<int,int>> a2)
{
	return a1.first > a2.first;
}
int Get_Sum(vector<vector<int>> &BIT , int x , int y)
{
	int sum = 0;
	
	for(int i = x + 1 ; i > 0 ; i &= (i - 1))
	for(int j = y + 1 ; j > 0 ; j &= (j - 1))
	sum += BIT[i][j];
	
	return sum;
}
void Update(vector<vector<int>> &BIT , int n , int m , int val , int x , int y)
{
	for(int i = x + 1 ; i <= n ; i += (i & -i))
	for(int j = y + 1 ; j <= m ; j += (j & -j))
	BIT[i][j] += val;
}
int Inversion_Pair(vector<vector<int>> &a , int n , int m)
{
	vector<vector<int>> BIT(n+1,vector<int>(m+1));
	
	vector<pair<int,pair<int,int>>> v;
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < m ; j++)
	v.push_back({a[i][j] , {i , j}});
	
	sort(v.begin(),v.end(),comp);
	
	int inv_pair_cnt = 0 , i = 0;
	
	while(i < v.size())
	{	
		int curr = i;
		
		vector<pair<int,int>> pairs;
		
		while(curr < v.size() && v[curr].first == v[i].first)
		{
			pairs.push_back({v[curr].second.first , v[curr].second.second});
			
			inv_pair_cnt += Get_Sum(BIT , v[curr].second.first , v[curr].second.second);
			
			curr++;
		}
		
		for(auto j : pairs)
		Update(BIT , n , m , 1 , j.first , j.second);
		
		i = curr;
	}
	
	return inv_pair_cnt;
}
int main() 
{ 
	vector<vector<int>> a = { { 4, 7, 2, 9 },
                      		  { 6, 4, 1, 7 },
                    		  { 5, 3, 8, 1 },
                    		  { 3, 2, 5, 6 } };
    int n = a.size();
    int m = a[0].size();
    
    cout << Inversion_Pair(a , n , m) << endl;
	
	return 0; 
} 

