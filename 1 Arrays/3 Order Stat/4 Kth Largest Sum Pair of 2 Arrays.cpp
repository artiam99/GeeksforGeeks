#include<bits/stdc++.h>
using namespace std;

void Kth_Largest_Sum_Pair(vector<int> &a , vector<int> &b , int n , int k)
{
	sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    
    priority_queue<pair<int,pair<int,int>>> pq;
    
    pq.push({a[n-1] + b[n-1] , {n - 1 , n - 1}});
    
    set<pair<int,int>> s;
    
	s.insert({n - 1 , n - 1});
    
    vector<int> v;
    
    for(int c = 0 ; c < k ; c++)
    {
    	pair<int,pair<int,int>> temp = pq.top();
    	
		pq.pop();
    	
    	v.push_back(temp.first);
    	
    	int i = temp.second.first;
    	
		int j = temp.second.second;
    	
    	pair<int,int> temp1 = {i - 1 , j};
    	
    	if(s.find(temp1) == s.end())
    	{
    		s.insert(temp1);
    		
    		pq.push({a[temp1.first] + b[temp1.second] , {temp1.first , temp1.second}});
		}
		
		temp1 = {i , j - 1};
		
		if(s.find(temp1) == s.end())
    	{
    		s.insert(temp1);
    		
    		pq.push({a[temp1.first] + b[temp1.second] , {temp1.first , temp1.second}});
		}
	}
	
	for(int i = 0 ; i < k ; i++)
	cout << v[i] << " ";
}

int main() 
{
	vector<int> a = {4, 2, 5, 1};
    vector<int> b = {8, 0, 3, 5};
    int n = a.size();
    int k = 3;
    
    Kth_Largest_Sum_Pair(a , b , n , k);
	
    return 0; 
}
