#include<bits/stdc++.h> 
using namespace std;
void Max_AND_Pair(vector<int> &a,int n)
{
	int res = 0;
	
	for(int i = 30 ; i >= 0 ; i--)
	{
		int cnt = 0;
		
		int new_pattern = ((1 << i) | res);
		
		for(int j = 0 ; j < n ; j++)
		if((new_pattern & a[j]) == new_pattern)  // res keeps the previous large pattern
		cnt++;
		
		if(cnt >= 2)  res = new_pattern;
	}
	
	cout << "Max AND Value : " << res << endl << endl;
	
	cout << "Pair : " ;
	
	int cnt = 0;
	
	for(int i = 0 ; i < n && cnt < 2 ; i++)
	if((a[i] & res) == res)
	{
		cout << a[i] << " ";
		
		cnt++;
	}
	
	cout << endl;
}
int main() 
{
	vector<int> a = {10 , 11, 12 , 13};
	int n = a.size();
	
	Max_AND_Pair(a,n);
	
	return 0;
}

