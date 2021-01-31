#include<bits/stdc++.h> 
using namespace std;
int Unique_Element(vector<int> &a,int n)
{
	int one = 0 , two = 0 , common_mask;
	
	for(int i = 0 ; i < n ; i++)
	{
		two |= (one & a[i]);  // two Store Bits that appear 2 , 5 , 8 times in the row
		
		one ^= a[i];  // one Store Bits that apper 1 , 4 , 7 times in the row
		
		common_mask = ~(one & two);  // Same Bit cannot apper in both times
		
		one &= common_mask;
		
		two &= common_mask;
	}
	return one;
}
int main() 
{
	vector<int> a = {5, 5, 4, 6, 4, 6, 6};
	int n = a.size();
	
	cout << Unique_Element(a,n) << endl;
	
	return 0;
}

