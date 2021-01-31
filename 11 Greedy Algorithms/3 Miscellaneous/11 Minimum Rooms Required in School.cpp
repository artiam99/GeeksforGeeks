#include<bits/stdc++.h>
using namespace std;
int findMinRooms(string slots[],int n,int m)
{
	int mx = 0;
	
	for(int i = 0 ; i < m ; i++)
	{
		int curr = 0;
		
		for(int j = 0 ; j < n ; j++)
		if(slots[j][i])
		curr++;
		
		mx = max(mx , curr);
	}
	return mx;
}
signed main()
{
	 int n = 3, m = 7;
	  
    string slots[n] = { "0101011",
                        "0011001",
                        "0110111" };
    
	cout << findMinRooms(slots, n, m) << endl;
    
    return 0;
}
