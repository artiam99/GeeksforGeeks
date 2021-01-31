#include <bits/stdc++.h>
using namespace std;

int Final_Value(vector<int> &a , int n , vector<pair<int,int>> &Q , int q , int idx)
{
	for(int i = q - 1 ; i >= 0 ; i--)             //  reverse calculation is happening
    if(idx >= Q[i].first && idx <= Q[i].second)
    {
    	if(idx == Q[i].first)  idx = Q[i].second;
    	
		else  idx--;
	}
	
	return a[idx];
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    
    vector<pair<int,int>> Q = {{0 , 2} , {0 , 3}};
    int q = Q.size();
    
    int idx = 1;
    
    cout << Final_Value(a , n , Q , q , idx) << endl;
	
	return 0;
}
