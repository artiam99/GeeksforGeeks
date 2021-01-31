#include <bits/stdc++.h> 
using namespace std;
int Get_Smaller(int* BIT , int ind)
{
	int sum = 0;
	
	while(ind)
	{
		sum += BIT[ind];
		
		ind &= (ind-1);
	}
	return sum;
}
void Update(int* BIT , int n , int ind , int val)
{
	while(ind <= n)
	{
		BIT[ind] += val;
		
		ind += (ind & -ind);
	}
}
void Convert(vector<int> &a , int n)
{
	vector<pair<int,int>> arr;
	
	for(int i = 0 ; i < n ; i++)
	arr.push_back({a[i] , i});
	
	sort(arr.begin() , arr.end());
	
	for(int i = 0 ; i < n ; i++)
	a[arr[i].second] = i+1;
}
int No_of_Inversions(vector<int> &a , int n)
{
	Convert(a , n);  // Convert Elements in 1 to n maintaining orders .. 8 4 2 1  =>  4 3 2 1
		
	int* BIT = new int[n+1];  memset(BIT,0,sizeof(int)*(n+1));

	int inversions = 0;

	for(int i = n-1 ; i >= 0 ; i--)
	{
		inversions += Get_Smaller(BIT , a[i] - 1); // No of Numbers Smaller than a[i] so far ... BIT Stores Prefix Sum of Occurance . if 2 is present 1 will be added to BIT - 2 , 4 , 8
		
		Update(BIT , n , a[i] , 1);
	}
	
	return inversions;
}
int main() 
{ 
	vector<int> a = {8, 4, 2, 1};
	int n = a.size();
	
	cout << No_of_Inversions(a , n) << endl;
	
	return 0; 
} 

