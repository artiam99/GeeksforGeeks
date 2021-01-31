#include <bits/stdc++.h> 
using namespace std;
void Print_AND_Set(int n)
{
	int len = 1;
	
	while(1)
	{
		if((n >> len) == 0)
		break;
		
		len++;
	}
	
	vector<int> a;
	
	a.push_back(0);
	
	int i = 0;	
	
	while(i < len)
	{
		if((n & (1 << i)))
		{
			int x = a.size();
			
			for(int j = 0 ; j < x ; j++)
			a.push_back(a[j] + (1 << i));
		}
		i++;
	}
	
	for(auto i : a)
	cout << i << " ";
	cout << endl;
}
int main() 
{
	int n = 36;
	
	Print_AND_Set(n);
	
	return 0; 
}
