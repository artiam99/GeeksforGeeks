#include<bits/stdc++.h>
using namespace std;
void Sliding_Window_Maximum(vector<int> &a , int n , int k)
{
	stack<int> s;
	
	vector<int> r(n);
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		while(!s.empty() && a[s.top()] <= a[i])
		s.pop();
		
		r[i] = ((s.empty()) ? n : s.top());
		
		s.push(i);
	}
	
	int j = 0;
	
	for(int i = 0 ; i < n - k + 1 ; i++)
	{
	    while(j < i || r[j] < i + k)
	    j++;
	    
	    cout << a[j] << " ";
	}
	
	cout << endl;
}

signed main()
{
	vector<int> a = {6, 7, 5, 2, 1, 7, 2, 1, 10};
	int n = a.size();
	int k = 2;
	
	Sliding_Window_Maximum(a , n , k);
	
	return 0;
}

