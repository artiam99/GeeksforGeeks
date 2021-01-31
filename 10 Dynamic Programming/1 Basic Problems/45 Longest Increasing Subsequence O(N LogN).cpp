#include<bits/stdc++.h>
using namespace std;
int LISS(vector<int> &a,int n)
{
	vector<int> tail(n); // Tails of Active Sequences
	
	tail[0] = a[0];
	
	int len = 1;
	
	for(int i=1;i<n;i++)
	{
		if(a[i] < tail[0])
		tail[0] = a[i];
		
		else if(a[i] > tail[len-1])
		tail[len++] = a[i];
		
		else
		tail[ lower_bound(tail.begin() , tail.begin() + len , a[i]) - tail.begin() ] = a[i];
	}
	return len;
}
signed main()
{
	vector<int> a = {5, 8, 3, 7, 9, 1};
	int n=a.size();
    
    cout<< LISS(a,n) <<endl;
    
	return 0;
}
