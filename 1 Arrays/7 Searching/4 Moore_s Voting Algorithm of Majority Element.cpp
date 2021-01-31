#include<bits/stdc++.h>
using namespace std;

void Majority_Element(vector<int> &a , int n)
{
	int count = 1 , majel = a[0];
	
	for(int i = 1 ; i < n ; i++)
	{
		if(a[i] == majel)
		count++;
		
		else
		count--;
		
		if(count == 0)
		{
			majel = a[i];
			count = 1;
		}
	}
	
	count = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] == majel)
		
		count++;
	}
	
	if(count > n / 2)
	cout << "Majority eleemnt is : " << majel << " count is : " << count << endl;
	
	else
	cout << "No Majority Elements found " << endl;
}

signed main()
{
	vector<int> a = {3, 1, 2, 3, 3};
	int n = a.size();
	
	Majority_Element(a , n);
	
	return 0;
}
