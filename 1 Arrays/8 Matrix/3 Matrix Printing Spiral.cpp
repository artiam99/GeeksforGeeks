#include<bits/stdc++.h>
using namespace std;

void Print_Loop(vector<vector<int>> &a, int rl, int rr , int cu , int cd)
{
	if(cu == cd)
	{
		for(int i = rl ; i <= rr ; i++)
		cout << a[cu][i] << " ";
		
		return;
	}
	
	for(int i = cu ; i <= cd ; i++)
	cout << a[i][rl] << " ";
	
	if(rr == rl)
	return;
	
    for(int i = rl + 1 ;i <= rr ; i++)
   	cout << a[cd][i] << " ";
	
	for(int i = cd - 1 ; i >= cu ; i--)
    cout << a[i][rr] << " ";
    
	for(int i = rr - 1 ; i >= rl + 1 ; i--)
    cout << a[cu][i] << " ";
}

void Print(vector<vector<int>> &a , int n , int m)
{
	int rl = 0 , rr = m-1 , cu = 0 , cd = n-1;

	while(rl <= rr && cu <= cd)
	{
		Print_Loop(a , rl , rr , cu , cd);
		
		rl++;
		
		rr--;
		
		cu++;
		
		cd--;
	}
}

signed main()
{
	vector<vector<int>> a= { { 1, 2 , 3 }, 
		                     { 5, 6 , 7 }, 
		                     { 9, 10, 11} };
    int n = a.size();
    int m = a[0].size();
    
	Print(a , n , m);	
	
	return 0;
}
