#include<bits/stdc++.h>
using namespace std;

int Pair_Count(vector<int> &a , int n1 , vector<int> &b , int n2)
{
	sort(b.begin() , b.end());
	
	int c = 0;
	
	int x = upper_bound(b.begin() , b.end() , 4) - b.begin();

	int o = count(b.begin() , b.end() , 1);

	int z = count(b.begin() , b.end() , 0);

	for(int i = 0 ; i < n1 ; i++)
	{
	    if(a[i] == 2 || a[i] == 3 || a[i] == 4)
	    {
	        int j;
	        
	        for(j = 0 ; j < x ; j++)
	        {
	            if(pow(a[i] , b[j]) > pow(b[j] , a[i]))
	            c++;
	        }
	        
	        int y = upper_bound(b.begin() + x , b.end() , a[i]) - b.begin();
	        
			c += n2 - y;
	    }
	    
	    else if(a[i] == 1 || a[i] == 0)
	    continue;
	    
		else
	    {
	        int y = upper_bound(b.begin() , b.end() , a[i]) - b.begin();
	        
			c += n2 - y;
	        
			c += o + z;
	    }
	}
}

signed main()
 {

	vector<int> a = {2, 1, 6};
	int n1 = a.size();
	
	vector<int> b = {1, 5};
	int n2 = b.size();
	
	cout << Pair_Count(a , n1 , b , n2) << endl;
	
	return 0;
}
