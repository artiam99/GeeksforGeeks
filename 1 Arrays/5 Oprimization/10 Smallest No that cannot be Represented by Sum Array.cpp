#include<bits/stdc++.h>
using namespace std;

int Smallest_No(vector<int> &a , int n)
{
	sort(a.begin() , a.end());
	
	int r = 1;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] > r)
		break;
		
		r += a[i];
	}
	
	return r;
}

int main()
{
	vector<int> a={1, 2, 3};
	int n = a.size();
	
	cout << Smallest_No(a , n) << endl;
	
	return 0;
}
