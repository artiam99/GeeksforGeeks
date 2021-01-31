#include <bits/stdc++.h>
using namespace std;
void JobSeq(vector<pair<int,int>> &a,int n)
{
	sort(a.begin(),a.end());
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	int dead = 1 , profit = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i].first >= dead)
		{
			dead++;
			
			profit += a[i].second;
			
			pq.push(a[i].second);
		}
		else if(a[i].second > pq.top())
		{
			profit -= pq.top();
			
			pq.pop();
			
			profit += a[i].second;
			
			pq.push(a[i].second);
		}
	}
	cout<< dead-1 << " " << profit << endl;
}
int main()
{
	vector<pair<int,int>> a = {{3,100} , {16,15} , {1,25} , {3,57} , {3,61} , {1,19} , {3,7}};
	int n = a.size();
	
	JobSeq(a,n);

	return 0;
}
