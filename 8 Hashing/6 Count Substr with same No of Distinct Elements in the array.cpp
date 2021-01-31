#include<bits/stdc++.h>
using namespace std;

int Count(vector<int> &a , int n)
{
	unordered_map<int,int> mp;
        
    for(int i = 0 ; i < n ; i++)
    mp[a[i]]++;
    
    int cnt = mp.size();
    
    mp.clear();
    
    int i = 0 , j = 0 , ans = 0;
    
    while(i < n)
    {
        mp[a[i]]++;
        
        if(mp.size() == cnt)
        {
        
            while(mp.size() == cnt)
            {
                mp[a[j]]--;
                
                if(!mp[a[j]])  mp.erase(a[j]);
                
                j++;
            }
            
            ans += j;
            
            j--;
            
            mp[a[j]]++;
        }
        i++;
    }
    
    return ans;
}

signed main()
{
	vector<int> a = {2, 1, 3, 2, 3};
	int n = a.size();
	
	cout << Count(a , n) << endl;
	
	return 0;
}
