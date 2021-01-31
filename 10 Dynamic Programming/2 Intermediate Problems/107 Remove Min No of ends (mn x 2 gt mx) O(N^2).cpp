#include<bits/stdc++.h>
using namespace std;
int MinRemove(vector<int> &a,int n)
{
	int longest_start = -1, longest_end = 0;

    for (int start = 0; start < n ; start++)
    {
        int mn = INT_MAX;
		int mx = INT_MIN;

        for (int end = start; end < n; end ++)
        {
            mn = min(mn , a[end]);
            
			mx = max(mx , a[end]);
            
            if (2 * mn <= mx) break;

            if (end - start > longest_end - longest_start ||  longest_start == -1)
            {
                longest_start = start;
                
                longest_end = end;
            }
        }
    }
    
    if (longest_start == -1) return n;

    return (n - (longest_end - longest_start + 1));
}
signed main()
{
	vector<int> a = {4 , 5, 100, 9, 10, 11, 12, 15, 200};
	int n = a.size();
	
	cout<< MinRemove(a,n) <<endl;
	
	return 0;
}
