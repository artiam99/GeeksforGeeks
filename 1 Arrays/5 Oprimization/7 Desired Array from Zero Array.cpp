#include<bits/stdc++.h>
using namespace std;

int Step_Count(vector<int> &a , int n)
{
	int c = 0;
	
	while(1)
	{
		int zero = 0 , i;
		
		for(i = 0 ; i < n ; i++)
		{
			if((a[i] & 1))
			break;
			
			if(a[i] == 0)
			zero++;
		}
		
		if(zero == n)
		break;
		
		if(i == n)
		{
			c++;
			
			for(int j = 0 ; j < n ; j++)
			a[j] /= 2;
		}
		
		for(int j = 0 ; j < n ; j++)
		{
			if((a[j] & 1))
			{
				a[j]--;
				
				c++;
			}
		}
	}
	
	return c;
}

int main()
{
	vector<int> a = {16, 16, 16};
	int n = a.size();
	
	cout << Step_Count(a , n) << endl;
	
	return 0;
}
