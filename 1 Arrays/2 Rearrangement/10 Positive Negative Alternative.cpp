#include <bits/stdc++.h> 
using namespace std;

void rotate(vector<int> &a , int l , int r)
{
	int temp = a[r];
	
	for(int i = r ; i > l ; i--)
	a[i] = a[i-1];
	
	a[l] = temp;
}

void Pos_Neg_Alt(vector<int> &a , int n)
{
	int outofplace = -1;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(outofplace != -1)
		{
			if((a[i] < 0 && a[outofplace] >= 0) || (a[i] >= 0 && a[outofplace] < 0))
			{
				rotate(a , outofplace , i);
				
				if(i - outofplace >= 2)  outofplace += 2;
				
				else  outofplace = -1;
			}
		}
		
		if(outofplace == -1)
		{
			if((a[i] < 0 && i % 2 == 0) || (a[i] >= 0 && i % 2 != 0))
			outofplace = i;
		}
	}
	
	for(auto i : a)
	cout << i << " ";
}

int main() 
{
	vector<int> a = {2, 5, 4, -1, 6, 3, -8, -9};
	int n = a.size();
	
	Pos_Neg_Alt(a , n);
	
	return 0; 
}

