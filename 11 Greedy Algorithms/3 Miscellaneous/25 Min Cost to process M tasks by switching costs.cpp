#include<bits/stdc++.h>
using namespace std;
int Min_Cost(vector<int> &a,int m,int n)
{
	vector<pair<int,int>> b(m);
	
	map<int,int> mp;

	for(int i = m-1 ; i >= 0 ; i--)
	b[i] = {mp[a[i]]++ , a[i]};
	
	vector<bool> on(m+1,false);
	
	vector<pair<int,int>> cores;
	
	int cost = 0;
	
	for(int i = 0 ; i < m ; i++)
	{
		if(on[b[i].second])
		{
			for(auto &j:cores)
			if(j.second == b[i].second)
			{
				j = b[i];
				break;
			}
			continue;
		}
		
		if(cores.size() < n)
		{
			cores.push_back(b[i]);
			
			on[b[i].second] = true;
			
			cost++;
		}
		else
		{
			int mn = INT_MAX , mni;
			
			for(int j = 0 ; j < cores.size() ; j++)
			if(mn > cores[j].first)
			{
				mn = cores[j].first;
				
				mni = j;
			}
			
			if(mn == 0)
			{
				on[cores[mni].second] = false;
				
				on[b[i].second] = true;
				
				cores[mni] = b[i];
				
				cost++;
			}
			else
			{
				vector<int> last(m+1,0);
				
				for(int j = m-1 ; j > i ; j--)
				if(on[b[j].second])
				last[b[j].second] = j;
				
				int ind = *max_element(last.begin(),last.end());
				
				for(int j = 0 ; j < cores.size() ; j++)
				if(cores[j].second == b[ind].second)
				{
					cores[j] = b[i];
					
					on[b[ind].second] = false;
					
					on[b[i].second] = true;
					
					cost++;
					
					break;
				}
			}
		}
	}
	
	return cost;
}
signed main()
{
	vector<int> a = {7, 11, 17, 10, 7, 10, 2, 9, 2, 18, 8, 10, 20, 10, 3, 20, 17, 17, 17, 1, 15, 10, 8, 3, 3, 18, 13, 2, 10, 10, 11};
	int m = a.size();
	int n = 3;
	
	cout<< Min_Cost(a,m,n) << endl;
	
    return 0;
}
