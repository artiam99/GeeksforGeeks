#include<bits/stdc++.h>
using namespace std;

vector<int> blocksum;

int blocksize;

int Query(int l , int r , vector<int> &a)
{
	int sum = 0;
	
	while(l < r && l % blocksize != 0 && l!= 0)
	{
		sum += a[l];
		
		l++;
	}
	
	while(l + blocksize <= r)
	{
		sum += blocksum[l / blocksize];
		
		l += blocksize;
	}
	
	while(l <= r)
	{
		sum += a[l];
		
		l++;
	}
	
	return sum;
}

void Update(int ind , int val , vector<int> &a)
{
	blocksum[ind / blocksize] += val - a[ind];
	
	a[ind] = val;
}

void Preprocess(vector<int> &a , int n)
{
	blocksize = (int)sqrt(n);
	
	int ind = -1;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(i % blocksize == 0)
		{
			blocksum.push_back(a[i]);
			
			ind++;
		}
		
		else
		blocksum[ind] += a[i];
	}
}

signed main()
{
	vector<int> a = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10}; 
    int n = a.size(); 
  
    Preprocess(a, n); 
    
    cout<< Query(3 , 8 , a) << endl; 
    cout<< Query(1 , 6 , a) << endl; 
    
    Update(8 , 0 , a); 
    
    cout<< Query(8 , 8 , a) << endl; 
    
	return 0;
}
