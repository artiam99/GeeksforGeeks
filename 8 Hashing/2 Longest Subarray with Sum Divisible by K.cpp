#include <bits/stdc++.h>
using namespace std;

int Pref(int prefix , int x , int k)
{
    if((prefix >= 0 && x <= 0) || (prefix <= 0 && x >= 0))
    x = (prefix + x) % k;
    
    else if(prefix >= 0 && x >= 0)
    x = (prefix % k + x % k) % k;
    
    else
    x = -((abs(prefix) % k + abs(x) % k) % k);
    
    int sign = ((x >= 0) ? 1 : -1);
    
    int mod = abs(x) % k;
    
    return sign * mod;
}

int Longest_Subarray(vector<int> &a , int n , int k)
{
	int fst[k][2];  memset(fst,-1,sizeof(fst));
    
    int mx = 0;
    
    int prefix = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        prefix = Pref(prefix , a[i] , k);
        
        if(prefix == 0)
        {
            mx = i + 1;
            
            continue;
        }
        
        if(prefix > 0)
        {
            if(fst[prefix][0] == -1)
            fst[prefix][0] = i;
            
            mx = max(mx , i - fst[prefix][0]);
            
            if(fst[k - prefix][1] != -1)
            mx = max(mx , i - fst[k - prefix][1]);
        }
        
        else
        {
            if(fst[abs(prefix)][1] == -1)
            fst[abs(prefix)][1] = i;
        
            mx = max(mx , i - fst[abs(prefix)][1]);
            
            if(fst[k - abs(prefix)][0] != -1)
            mx = max(mx , i - fst[k - abs(prefix)][0]);
        }
    }
    
    return mx;
}

int main()
{
	vector<int> a = {2, 7, 6, 1, 4, 5};
	int n = a.size();
	
	int k = 3;
	
	cout << Longest_Subarray(a , n , k);
	
	return 0;
}
