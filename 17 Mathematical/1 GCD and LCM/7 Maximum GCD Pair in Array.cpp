#include <bits/stdc++.h>
using namespace std;

int Max_GCD(vector<int> &a , int n)
{
	int mx = *max_element(a.begin() , a.end());
        
    int cnt[mx+1];  memset(cnt , 0 , sizeof(cnt));
    
    for(int i = 0 ; i < n ; i++)
    cnt[a[i]]++;
    
    for(int i = mx ; i >= 1 ; i--)
    {
        if(cnt[i] >= 2)
		return i;
        
        int j = i , counter = 0;
        
        while(j <= mx)
        {
            if(cnt[j])
            counter++;
            
            if(counter == 2)
            return i;
            
            j += i;
    	}
    }
    
    return -1;
}

signed main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    
    cout << Max_GCD(a , n) << endl;
    
    return 0;
}

