#include<bits/stdc++.h>
using namespace std;
#define int long long
struct compare
{
	bool operator()(pair<int,int> p1 , pair<int,int> p2)
	{
		if(p1.second == p2.second)
		return (p1.first > p2.first);
		
		return (p1.second > p2.second);
	}
};

void K_Max_Occurence(vector<int> &a , int n , int k)
{
	unordered_map<int,int> mp;
	
    for(auto i:a)
    mp[i]++;
    
	priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    
	for(auto j : mp)
    {
    	if(pq.size() < k)
    	pq.push({j.first , j.second});
    	
		else
    	{
    		if(pq.top().second < j.second)
    		{
    			pq.pop();
    			
    			pq.push({j.first , j.second});
			}
			else if(pq.top().second == j.second && pq.top().first < j.first)
			{
				pq.pop();
				
				pq.push({j.first , j.second});
			}
		}
	}
	
	vector<pair<int,int>> v;
	
	for(int i = 0 ; i < k ; i++)
	{
		v.push_back(pq.top());
	
		pq.pop();
	}
	
	for(auto i = v.rbegin() ; i !=v.rend() ; i++)
	cout << i->first << " " << i->second << endl;
}

signed main()
{
	vector<int> a = {7, 10, 11, 5, 2, 5, 5, 7, 11, 9, 8};
    int n = a.size();
    int k = 5;
    
    K_Max_Occurence(a , n , k);
    
	return 0;
}
