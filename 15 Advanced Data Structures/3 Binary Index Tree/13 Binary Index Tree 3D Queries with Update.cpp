#include<bits/stdc++.h> 
using namespace std; 

const int MAX = 10001; 

void Update(int idx , int blk , int val , int BIT[][MAX]) 
{ 
	for (; idx < MAX ; idx += (idx & -idx)) 
	
	BIT[blk][idx] += val;
}

int Query(int l , int r , int k , int arr[] , int blk_sz , int BIT[][MAX]) 
{ 
	int sum = 0;
	
	while(l < r && l % blk_sz != 0 && l != 0)
	{
		if (arr[l] <= k) 
		sum++; 
		
		l++; 
	}
	
	while(l + blk_sz <= r) 
	{ 
		int idx = k; 
		
		for (; idx > 0 ; idx -= (idx & -idx)) 
		sum += BIT[l / blk_sz][idx];
		
		l += blk_sz; 
	}
	
	while(l <= r) 
	{ 
		if(arr[l] <= k) 
		sum++; 
		
		l++; 
	} 
	
	return sum; 
}

void Preprocess(int arr [], int blk_sz , int n , int BIT[][MAX]) 
{ 
	for (int i = 0 ; i < n ; i++)
	Update(arr[i] , i / blk_sz , 1 , BIT); 
}

void Preprocess_Update(int i , int v , int blk_sz , int arr[] , int BIT[][MAX])
{
	Update(arr[i] , i / blk_sz , -1 , BIT); 
	
	Update(v , i / blk_sz , 1 , BIT);
	 
	arr[i] = v; 
}

int main() 
{ 
	int arr[] = {5, 1, 2, 3, 4};
	int n = sizeof(arr)/sizeof(arr[0]); 

	int blk_sz = sqrt(n);
	
	int BIT[blk_sz+1][MAX];   memset(BIT , 0, sizeof(BIT)); 

	Preprocess(arr , blk_sz , n , BIT);
	
	cout << Query(1 , 3 , 1 , arr , blk_sz , BIT) << endl; 

	Preprocess_Update(3 , 10 , blk_sz , arr , BIT);
	 
	cout << Query(3 , 3 , 4 , arr , blk_sz , BIT) << endl; 
	
	Preprocess_Update(2 , 1 , blk_sz, arr , BIT); 
	
	Preprocess_Update(0 , 2 , blk_sz, arr , BIT); 
	
	cout << Query(0 , 4 , 5 , arr , blk_sz , BIT) << endl; 
	
	return 0;
}

