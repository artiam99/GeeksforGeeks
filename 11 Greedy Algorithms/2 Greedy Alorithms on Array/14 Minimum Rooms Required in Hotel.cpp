#include<bits/stdc++.h>
using namespace std;
int hotel(vector<int> &a,vector<int> &d,int n)
{
	sort(a.begin(),a.end());
	
	sort(d.begin(),d.end());
	
	int i = 1 , j = 0 , mn = 1;
	
	while(i < n)
	{
		if(a[i] >= d[j])
		{
			i++;  j++;
		}
		else
		{
			i++;  mn++;
		}
	}
	return mn;
}
int main()
{
	vector<int> a = {1 , 2 , 3};
	vector<int> d = {2 , 3 , 4};
	int n = a.size();
	
	cout<< hotel(a,d,n) << endl;
}
