#include<bits/stdc++.h>
using namespace std;

void Max_Span(vector<int> &a , vector<int> &b , int n)
{
	int prefsum1 = 0 , prefsum2 = 0;
	
	int l2 = -1 , r1 = -1 , r2 = -1;
	
	vector<int> diff(2 * n + 1 , -1);  //  diff can be in the range -n to n so 2*n+1
	
	for(int i = 0 ; i < n ; i++)
	{
		prefsum1 += a[i];
		
		prefsum2 += b[i];
		
		int curdiff = prefsum1 - prefsum2;

 		int diffidx = n + curdiff;
		
		if(curdiff == 0)
		r1 = i;
		
		else if(diff[diffidx] == -1)
		diff[diffidx] = i;
		
		else
		{
			if(i - diff[diffidx] > r2 - l2)
			{
				l2 = diff[diffidx] + 1;
				
				r2 = i;
			}
		}
	}
	
	if(r2 - l2 > r1 && r2 != -1)
	{
		cout << l2 << " " << r2 << endl;
		
		for(int i = l2 ; i <= r2 ; i++)
		cout << a[i] << " ";
		cout << endl;

		for(int i = l2 ; i <= r2 ; i++)
		cout << b[i] << " ";
		cout << endl;
	}
	
	else if(r2 == -1 && r1 == -1)
	cout << "Not Matched" << endl;
	
	else
	{
		cout << 0 << " " << r1 << endl;
		
		for(int i = 0 ; i <= r1 ; i++)
		cout << a[i] << " ";
		cout << endl;
		
		for(int i = 0 ; i <= r1 ; i++)
		cout << b[i] << " ";
		cout << endl;
	}
}

int main()
{
	vector<int> a = {0, 0, 1, 1, 0};
	vector<int> b = {1, 0, 0, 1, 1};
	int n = a.size();
	
	Max_Span(a , b , n);
	
	return 0;
}
