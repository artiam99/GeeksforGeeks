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
int Sum(int* BIT1 , int* BIT2 , int ind)  //  Sum From 0 to ind
{
	return (Get_Element(BIT1 , ind) * (ind + 1)) - Get_Element(BIT2 , ind);
}
int Range_Sum(int* BIT1 , int* BIT2 , int l , int r)
{
	return Sum(BIT1 , BIT2 , r) - Sum(BIT1 , BIT2 , l-1); 
}
void Update(int* BIT1 , int* BIT2, int n , int l , int r , int val)
{
	Update_BIT(BIT1 , n , l+1 , val);  // This one for getting element at index i and adding a[i] * (i+1) to answer
	Update_BIT(BIT1 , n , r+2 , -val);
	
	Update_BIT(BIT2 , n , l+1 , val * l);  // This one for Substracting the (val * l)  from a[i] * (i+1)  to get Sum from 0 to i 
	Update_BIT(BIT2 , n , r+2 , -val * (r+1));
}
int main() 
{ 
	vector<int> a = {0, 0, 0, 0, 0, 0, 0, 0};
	int n = a.size();
	
	int *BIT1 = Construct_BIT(a , n);
	
	int *BIT2 = Construct_BIT(a , n);
	
	int l = 2 , r = 4 , val = 2;
	Update(BIT1 , BIT2 , n , l , r , val);

	l = 0 , r = 3 , val = 4;
	Update(BIT1 , BIT2 , n , l , r , val);
	
	l = 1 , r = 3;
	cout << "Sum in range [ " << l << " - " << r << " ] : " << Range_Sum(BIT1 , BIT2 , l , r) << endl;

	return 0; 
} 

