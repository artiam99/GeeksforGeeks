#include<bits/stdc++.h> 
using namespace std;
void Missing_Numbers(vector<int> &a,int n)
{
	int x = 0;
	
	for(int i = 1 ; i <= n + 2 ; i++)
	x ^= i;
	
	for(int i = 0 ; i < n ; i++)
	x ^= a[i];
	
	int lsb = x & -x , p = 0 , q = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if((lsb & a[i]))  p ^= a[i];
		
		else  q ^= a[i];
	}
	
	for(int i = 1 ; i <= n + 2 ; i++)
	{
		if((lsb & i))  p ^= i;
		
		else  q ^= i;
	}
	
	if(p > q)  swap(p , q);
	
	cout << p << " " << q << endl;
}
int main() 
{
	vector<int> a = {1, 5, 3, 6};  // 2 , 4 Missing
	int n = a.size();
	
	Missing_Numbers(a,n);
	
	return 0;
}

