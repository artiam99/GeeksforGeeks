#include <bits/stdc++.h> 
using namespace std;

int Max_Sum(vector<int> &a , int n)
{
	int in = a[0] , ex = 0 , ex_prev;
	
	for(int i = 1 ; i < n; i++)
	{
		ex_prev = max(ex , in);
		
		in = ex + a[i];
		
		ex = ex_prev;
	}
	
	return max(in , ex);
}

int main() 
{
	vector<int> a = {4, 5, 10, 100, 10, 5};
	int n = a.size();
	
	cout << Max_Sum(a , n) << endl;
	
	return 0; 
} 

