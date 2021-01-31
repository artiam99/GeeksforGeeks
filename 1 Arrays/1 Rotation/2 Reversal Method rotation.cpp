#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &a , int l , int r)
{
    while(l < r)
    {
        swap(a[l] , a[r]);
        
		l++;
        r--;
    }
}

void rotate(vector<int> &a , int n , int d)
{
    reverse(a , 0 , d - 1);
    reverse(a , d , n - 1);
    reverse(a , 0 , n - 1);
}

int main()
{
	vector<int> a ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int n = a.size();
	
	rotate(a , n , 3);
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
	
	return 0;
}
