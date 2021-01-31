#include<bits/stdc++.h>
using namespace std;

int gcd(int a , int b)
{
    if(b == 0)  return a;
    
	return gcd(b , a % b);
}

void rightrotate(int *a , int l , int r , int d)
{
    d = d % (r - l + 1);
    
	int g = gcd(r - l + 1 , d);
    
	for(int i = r ; i >= r - g + 1 ; i--)
    {
        int temp = a[i];
        
		int j = i;
        
		while(1)
        {
            int k = j - d;
            
			if(k < l)
            k = r - (l - k - 1);
            
			if(k == i)
            break;
            
            a[j] = a[k];
            
			j = k;
        }
        a[j] = temp;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a)/sizeof(int);
    
	rightrotate(a , 0 , 3 , 2);
    
	for(int i = 0 ; i < n ; i++)
    cout << a[i] << " ";
    cout<<endl;
    
	rightrotate(a , 2 , 6 , 4);
    
	for(int i = 0 ; i < n ; i++)
    cout << a[i] << " ";
	cout << endl;
	
	return 0;
}
