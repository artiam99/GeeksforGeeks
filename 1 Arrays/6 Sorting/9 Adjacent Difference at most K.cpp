#include<bits/stdc++.h>
using namespace std;

void Search(vector<int> &a , int n , int x , int k)
{
	int c = -1 , i = 0;
	
	while(i < n)
    {
    	c++;
    	
    	if(a[i] == x)
    	cout << i << " ";
		
    	int diff = ceil(abs(a[i] - x) / k);
    	
    	i += max((int)1 , diff);
	}
}

signed main()
{
	vector<int> a = {20, 40, 50, 70, 50, 30, 20, 40, 20, 40, 60, 70, 60, 40, 20};
	int n = a.size();
	int x = 20;  //search x
	int k = 20;  //adjacent element differs by at most k

	Search(a , n , x , k);
	
	return 0;
}
