#include<bits/stdc++.h> 
using namespace std;
void PrintEven(vector<int> &a,int n)
{
	long long x = 0 , one = 1;
	
	for(int i = 0 ; i < n ; i++)
	x ^= (one << a[i]);
	
	for(int i = 0 ; i < n ; i++)
	{
		if(!(x & (one << a[i])))
		{
			cout << a[i] << " ";
			
			x |= (one << a[i]);
		}
	}
	cout << endl;
}
int main() 
{ 
	vector<int> a = {1, 1, 2, 1, 4, 2, 5, 3, 3};  //  0 <= a[i] <= 64
	int n = a.size();
	
	PrintEven(a,n);
	
	return 0; 
} 

