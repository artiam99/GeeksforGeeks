#include<bits/stdc++.h>
using namespace std;
int SmallestArr(vector<int> &a,int n,int k)
{
	for(int i = 0 ; i < n-1 ; i++)
	{
		int mn = a[i] , mni = i;
		
		for(int j = i+1 ; j <= min(i+k , n-1) ; j++)
		if(mn > a[j])
		{
			mn = a[j];
			
			mni = j;
		}
		
		if(mni == i)
		continue;
	
		for(int j = mni ; j >= i+1 ; j--)
		swap(a[j] , a[j-1]);
		
		k -= (mni - i);
		
		if(k == 0)
		break;
		
	}
	
	for(auto i:a)
	cout<< i << " ";
	cout<<endl;
}
int main()
{
	vector<int> a = {7, 6, 9, 2, 1};
	int n = a.size();
	
	int k = 3;
	
	SmallestArr(a,n,k);
}
