#include<bits/stdc++.h>
using namespace std;
int Max_Diff(vector<int> &a,int n,int k)
{
	int sum = accumulate(a.begin(),a.end(),0);
	
	k = max(k , n-k);
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	int sum2 = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(pq.size() < k)
		pq.push(a[i]);
		
		else if(pq.top() < a[i])
		{
			sum2 += pq.top();
			
			pq.pop();
			
			pq.push(a[i]);
		}
		
		else
		sum2 += a[i]; 
	}
	
	return sum - 2 * sum2;
}
signed main()
{
	vector<int> a = {8, 4, 5, 2, 10};
	int n = a.size();
	int k = 2;
	
	cout<< Max_Diff(a,n,k) << endl;
	
	return 0;
}
