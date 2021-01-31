#include<bits/stdc++.h>
using namespace std;

int Sum(vector<int> &a , int n)
{
	unordered_set<int> st;
	     
    int i = 0 , j = 0 , ans = 0;
     
    while(i < n)
    {
        if(st.find(a[i]) == st.end())
        st.insert(a[i]);
         
        else
        {
            while(j < i && a[j] != a[i])
            st.erase(a[j]) , j++;
            
            j++;
        }
         
        ans += (((i - j + 1) * (i - j + 2)) / 2) ;
         
        i++;
    }
    
    return ans;
}

signed main()
{
	vector<int> a = {1, 2, 3, 4, 1};
	int n = a.size();
	
	cout << Sum(a , n) << endl;
	
	return 0;
}
