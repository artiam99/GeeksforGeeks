#include <bits/stdc++.h> 
using namespace std;
int Get_Element(int *BIT , int index)
{
	int sum = 0 , i = index + 1;
	
	for(; i > 0 ; i &= (i-1))
	sum += BIT[i];
	
	return sum;
}
void Update_BIT(int *BIT , int n , int i , int x)
{
	for(; i <= n ; i += (i & -i))
	BIT[i] += x;
}
int* Construct_BIT(vector<int> &a , int n)
{
	int* BIT = new int[n+1];
	
	memset(BIT,0,sizeof(int)*(n+1));
	
	for(int i = 0 ; i < n ; i++)
	Update_BIT(BIT , n , i+1 , a[i]);
	
	return BIT;
}
void Update(int *BIT , int n , int l , int r , int val)
{
	Update_BIT(BIT , n , l+1 , val);
	
	Update_BIT(BIT , n , r+2 , -val);
}
int main() 
{ 
	vector<int> a = {0, 0, 0, 0, 0, 0, 0, 0}; // Remember it Adds number to a particular range .. not changes the value of the particular range
	int n = a.size();
	
	int *BIT = Construct_BIT(a , n);  // Binary Index tree means it stores Prifix Sums for particular range(for index i - (i w/o lsb - i))
	
	int l = 2 , r = 4 , val = 2;
	Update(BIT , n , l , r , val);  // so Basically we add 2 to a[l] and -2 to a[r+1] and check for Prefix sum : Prefix[index] 
	
	int index = 4;
	cout << "Element at index " << index << " :  " << Get_Element(BIT , index) << endl;

	l = 0 , r = 3 , val = 4;
	Update(BIT , n , l , r , val);

	index = 3;
	
	cout << "Element at index " << index << " :  " << Get_Element(BIT , index) << endl;

	return 0; 
} 

