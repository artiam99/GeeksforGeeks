#include<bits/stdc++.h>
using namespace std;

int Kth_Largest_Sum(vector<int> &a , int n , int k)
{
	vector<int> b(n);
	
	b[0] = a[0];
	
	for(int i = 1 ; i < n ; i++)
	b[i] = b[i-1] + a[i];
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i ; j < n ; j++)
		{
			int x;
		
			if(i == 0)  x = b[j];
		
			else  x = b[j] - b[i-1];
		
			if(pq.size() < k)  pq.push(x);
		
			else if(pq.top() < x)
			{
				pq.pop();
				
				pq.push(x);
			}
		}
	}
		
	return pq.top();
}

int main() 
{
	vector<int> a = {20, -5, -1};
	int n = a.size();
	int k = 4;
	
	cout << Kth_Largest_Sum(a , n , k) << endl;
	
    return 0; 
}
