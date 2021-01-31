#include<bits/stdc++.h>
using namespace std;

void K_Largest(vector<int> &a , int n , int k)
{
	set<int> s;
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(int i = 0 ; i < n ; i++)
	if(s.find(a[i]) == s.end())
	{
		if(pq.size() < k)
		{
			pq.push(a[i]);
				
			s.insert(a[i]);
		}
		
		else if(pq.top() < a[i])
		{
			pq.pop();
				
			pq.push(a[i]);
				
			s.insert(a[i]);
		}
	}
	
	while(!pq.empty())
	{
		cout << pq.top() << " ";
		
		pq.pop();
	}
	
	cout << endl;
}

int main() 
{
	vector<int> a = {7, 8, 6, 9, 5, 4, 3, 2, 1, 3, 1, 6, 7, 8, 9};
	int n = a.size();
	int k = 4;
	
	K_Largest(a , n , k);
	
    return 0; 
}
