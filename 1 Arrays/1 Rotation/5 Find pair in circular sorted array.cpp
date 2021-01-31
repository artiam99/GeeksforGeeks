#include<bits/stdc++.h>
using namespace std;
int pairf(int a[] , int n , int x)
{
	int l = 0 , r = n - 1 , m , prev , next;
	
	int d , c = 0;
	
	while(l <= r)
	{
		m = l + (r - l) / 2;
		
		next = (m + 1) % n;
		
		prev = (m - 1 + n) % n;
		
		if(a[l] <= a[r])
		{
			d = l;
			
			break;
		}
		
		if(a[m] <= a[prev] && a[m] <= a[next])
		{
			d = m;
			
			break;
		}
		
		else if(a[m] <= a[r])
		r = m - 1;
		
		else
		l = m + 1;
	}
	
	l = d;
	
	r = (l - 1 + n) % n;
	
	while(l != r)
	{
		if(a[l] + a[r] == x)
		{
			c++;
			
			if(l == (r - 1 + n) % n)  //both are changing so termination cindition is required
		    return c;
		    
			l = (l + 1) % n;
			
			r = (r - 1 + n) % n;
		}
		
		else if(a[l] + a[r] < x)  //only one parameter is increasing or decreasing so it will terminate in l==r
		l = (l + 1) % n;
		
		else
		r = (r - 1 + n) % n;
	}
	
	return c;
}
int main()
 {
	int a[] = {5, 6, 1, 2, 3, 4};
	int n = sizeof(a)/sizeof(int);
	
	cout << pairf(a , n , 7) << endl;
	
	return 0;
}
