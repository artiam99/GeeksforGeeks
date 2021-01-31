#include<bits/stdc++.h>
using namespace std;

int No_of_Triangles(vector<int> &a , int n)
{
	sort(a.begin() , a.end());
	
	int c = 0;
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		int l = 0 , r = i-1;
		
		while(l < r)
		{
			if(a[i] < a[l] + a[r])
			{
				c += r-l;  //     a[i] and a[r] is fixed
				
				r--; 
			}
			
			else
			l++;
		}		
	}
	
	return c;
}

int main()
{
	vector<int> a = {6, 4, 9, 7, 8};
	int n = a.size();
	
	cout << No_of_Triangles(a , n) << endl;
	
	return 0;
}
