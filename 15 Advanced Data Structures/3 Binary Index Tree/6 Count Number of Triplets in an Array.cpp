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
    
    sort(arr.begin(),arr.end());
    
    int i = 1 , j = 1 , prev = arr[0].first;
    
    a[arr[0].second] = j;
    
    while(i < n)
    {
        if(arr[i].first != prev)
        j++;
        
        a[arr[i].second] = j;
        
        prev = arr[i].first;
        
        i++;
    }
}
int No_of_Triplets(vector<int> &a , int n)
{
	Convert(a , n);  // Convert elements to numbers b/w 1 to n maintaining order ... eg. 3 4 7 7 11 3 9 6 8 => 1 2 4 4 7 1 6 3 5
		
	int* BIT1 = new int[n+1];  memset(BIT1,0,sizeof(int)*(n+1));  // Number of smaller elements so far
	
	int* BIT2 = new int[n+1];  memset(BIT2,0,sizeof(int)*(n+1));  // Number of smaller inversions so far

	int Triplets = 0;

	for(int i = 0 ; i < n ; i++)
	{
		int smaller = Get_Smaller(BIT1 , a[i] - 1);
		
		Update(BIT1 , n , a[i] , 1);
		
		Triplets += Get_Smaller(BIT2 , a[i] - 1);
		
		Update(BIT2 , n , a[i] , smaller);
	}
	
	return Triplets;  // Another concepte is No of smaller elements at left and greater at right and multiply them 
}
int main() 
{ 
	vector<int> a = {3, 4, 7, 7, 11, 3, 9, 6, 8};  // a[i] < a[j] < a[k]  while i < j < k
	int n = a.size();
	
	cout << No_of_Triplets(a , n) << endl;
	
	return 0; 
} 

