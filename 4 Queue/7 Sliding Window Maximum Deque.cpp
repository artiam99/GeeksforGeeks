#include<bits/stdc++.h>
using namespace std;

void Sliding_Window_Max(vector<int> &a , int n , int k)
{
	deque<int> dq;
	
	for(int i = 0 ; i <= n ; i++)
	{
		if(i >= k)
		{
			cout << a[dq.front()] << " ";
			
			if(i == n)
			break;
			
			while(!dq.empty() && dq.front() <= i-k)
			dq.pop_front();
		}
		
		while(!dq.empty() && a[dq.back()] <= a[i])
		dq.pop_back();
			
		dq.push_back(i);
	}
}

signed main()
{
	vector<int> a={3, 4, 2, 6, 4, 6, 7};
	int n = a.size();
	int k = 3;
	
	Sliding_Window_Max(a , n , k);
	
	return 0;
}
