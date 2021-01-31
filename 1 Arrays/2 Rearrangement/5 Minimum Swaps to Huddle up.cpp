#include<bits/stdc++.h>
using namespace std;
int Huddle_Negative(vector<int> &a , int n)
{
	int c = 0;
	
	for(int i = 0 ; i < n ; i++)
	if(a[i] < 0)
	c++;
	
	int bad = 0;
	
	for(int i = 0 ; i < c ; i++)
	if(a[i] >= 0)
	bad++;
	
	int ans = bad;
	
	for(int i = 0 , j = c ; j < n ; i++ , j++)
	{
		if(a[i] >= 0)
		bad--;
		
		if(a[j] >= 0)
		bad++;
		
		ans = min(ans , bad);
	}
	
	return ans;
}

int main()
{
	vector<int> a = {-1, 4, 5, -2, -3, 4, 5, 6, 7, -7, -9, -5, 5, 6, 7, -4, -8};
	int n = a.size();
	
	cout << Huddle_Negative(a,n) << endl;
	
	return 0; 
} 

