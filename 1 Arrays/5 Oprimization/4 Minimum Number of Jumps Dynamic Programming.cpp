#include<bits/stdc++.h>
using namespace std;

void Min_Jump(vector<int> &a , int n)
{
	vector<int> minjump(n);
	
	vector<int> jumpidx(n);
	
	for(int i = 1 ; i < n ; i++)
	{
		minjump[i] = INT_MAX;
		
		for(int j = 0 ; j < i ; j++)
		{
			if(i <= j + a[j])
			{
				minjump[i] = minjump[j] + 1;
			
				jumpidx[i] = j;
			
				break;
			}
		}
	}
	
	if(minjump[n-1] == INT_MAX)
	cout << "Not possible";

	else
	{
		cout << "Minimum Number of steps to reach end : " << minjump[n-1] << endl;
    	
		vector<int> jumps;
    	
		int i = n-1;
    	
		while(i != 0)
    	{
	    	jumps.push_back(a[i]);
    		
			i = jumpidx[i];
    	}
    	
    	jumps.push_back(a[i]);
     	
		for(auto i = jumps.rbegin() ; i != jumps.rend() ; i++)
    	cout << *i << " ";
		cout << endl;
    }
}

int main()
{
	vector<int> a = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = a.size();
	
	Min_Jump(a , n);
	
	return 0;
}
