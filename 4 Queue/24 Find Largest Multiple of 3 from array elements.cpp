#include<bits/stdc++.h>
using namespace std;

int find_largest_multiple(vector<int> &a , int n)
{
	vector<int> count(10);
	
	for(int i = 0 ; i < n ; i++)
	count[a[i]]++;
	
	for(int i = 0 , j = 0 ; i < 10 ; i++)
	{
		for(int k = 0 ; k < count[i] ; k++)
		a[j++] = i;
	}
	
	int sum = accumulate(a.begin() , a.end() , 0);
	
	int one = -1 , two = -1;
	if(sum % 3 == 1)
	{
		for(int i = 0 ; i < n && one == -1 ; i++)
		{
			if(a[i]%3 == 1)
			one = i;
		}
	}
	
	if(sum % 3 == 2)
	{
		for(int i = 0 ; i < n && one == -1; i++)
		{
			if(a[i] % 3 == 2)
			one = i;
		}
		
		if(one == -1)
			for(int i = 0 ; i < n && two == -1 ; i++)
	    	{
		    	if(a[i] % 3 == 1)
				{
					if(one == -1)
					one = i;
					
					else
					two = i;
				}
	        }
	}
	
	if(one != -1)
	a.erase(a.begin() + one);
	
	if(two != -1)
	a.erase(a.begin() + two - 1);
	
	int number = 0;
	
	for(int i = a.size() - 1 ; i >= 0 ; i--)
	number = (number * 10) + a[i];
	
	return number;
}

signed main()
{
	vector<int> a={6, 7, 0, 1};

	int n = a.size();

	cout << "Largest Multiple of 3 : " << find_largest_multiple(a , n) << endl;

	return 0;
}

