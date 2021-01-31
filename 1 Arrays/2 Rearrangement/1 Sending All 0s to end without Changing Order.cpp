#include <bits/stdc++.h>
using namespace std;

void Send_Zero(int a[] , int n)
{
	int r = 0;
    
    for(int i = 0 ; i < n ; i++)  //just one traversal
    {
        if(a[i] != 0)
        swap(a[r++] , a[i]);
    }
}

int main()
{

    int a[] = {1, 0, 2, 3, 0, 4, 0, 5, 0, 6, 7};
    int n = sizeof(a)/sizeof(int);
    
    Send_Zero(a , n);
    
    for(int i = 0 ; i < n ; i++)
    cout << a[i] << " ";
    cout << endl;
    
    return 0;
}
