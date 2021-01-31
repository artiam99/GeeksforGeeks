#include<bits/stdc++.h>
using namespace std;

vector<int> Smallest_Difference_Triplet(vector<int> &a1 , vector<int> &a2 , vector<int> &a3, int n)
{
	sort(a1.begin() , a1.end()); sort(a2.begin() , a2.end()); sort(a3.begin() , a3.end());
        
    int i1 = 0 , i2 = 0 , i3 = 0;
    
    int curr = INT_MAX;
    vector<int> ans(3);
    
    while(i1 < n && i2 < n && i3 < n)
    {
        int mx = max(a1[i1] , max(a2[i2] , a3[i3]));
        int mn = min(a1[i1] , min(a2[i2] , a3[i3]));
        
        if(mx - mn < curr)
        {
            curr = mx - mn;
            
            ans[0] = a1[i1] , ans[1] = a2[i2] , ans[2] = a3[i3];
        }
        
        if(a1[i1] == mn)  i1++;
        
        else if(a2[i2] == mn)  i2++;
        
        else  i3++;
    }
    
    sort(ans.begin(),ans.end());
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}

signed main()
{
	vector<int> a1 = {5 , 2 , 8 };
	vector<int> a2 = {10, 7 , 12};
	vector<int> a3 = {9 , 14, 6 };
	int n = a1.size();
	
	vector<int> ans = Smallest_Difference_Triplet(a1 , a2 , a3 , n);
	
	for(auto i : ans)
	cout << i << " ";
	cout << endl;
	
	return 0;
}
