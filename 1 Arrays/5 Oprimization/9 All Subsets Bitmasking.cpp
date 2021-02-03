#include<bits/stdc++.h>
using namespace std;

void All_Subset(vector<int> &a , int n)
{
	int size = pow(2,n);
	
	for(int i = 0 ; i < size ; i++)
	{
		vector<int> s;
		
		for(int j = 0 ; j < n ; j++)
		{
			if((i & (1 << j)))
			s.push_back(a[j]);
		}
		
		for(auto i : s)
		cout << i << " ";
		cout << endl;
	}
}

int main()
{
	vector<int> a = {1, 2, 3};
	int n = a.size();
	
	All_Subset(a , n);
	
	return 0;
}
