#include<bits/stdc++.h>
using namespace std;

pair<int,int> Max_Min(vector<int> &a , int l , int r)
{
	if(l < r)
	{
		int m = l + (r - l) / 2;
		
		pair<int,int> p1 = Max_Min(a , l , m);
		
		pair<int,int> p2 = Max_Min(a , m + 1 , r);
		
		pair<int,int> p3 = {min(p1.first , p2.first) , max(p1.second , p2.second)};
		
		return p3;
	}
	
	return {a[l] , a[l]};
}

int main() 
{
	vector<int> a = {2, 1, 3, 2, 4, 5, 7, 8, 12, 9, 78};
    int n = a.size();
    
	pair<int,int> p = Max_Min(a , 0 , n - 1);
    
	cout<< p.first << " " << p.second << endl;
    
	return 0; 
}
