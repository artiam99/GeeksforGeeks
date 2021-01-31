#include <bits/stdc++.h> 
using namespace std;

void Greatest_3(int a[] , int n)
{
	int f = -100000 , s = -100000 , t;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] > f)
		{
			int temp = s;
			
			s = f;
			
			f = a[i];
			
			t = temp;
		}
		
		else if(a[i] > s)
		{
			t = s;
			
			s = a[i];
		}
		
		else if(a[i] > t)  t = a[i];
	}
	
	cout << f << " " << s << " " << t << endl;
}

int main() 
{
	int a[] = {1, 1, 1, 1, 1};
	int n = sizeof(a) / sizeof(a[0]);
	
	Greatest_3(a , n);
	
	return 0;
}
