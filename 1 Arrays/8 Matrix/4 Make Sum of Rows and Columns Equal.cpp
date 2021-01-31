#include<bits/stdc++.h>
using namespace std;

int Make_Sums_Equal(vector<vector<int>> &a , int r , int c)
{
	int rowsum[r] , colsum[c];  memset(rowsum,0,sizeof(rowsum));  memset(colsum,0,sizeof(colsum));
        
    for(int i = 0 ; i < r ; i++)
    for(int j = 0 ; j < c ; j++)
    rowsum[i] += a[i][j] , colsum[j] += a[i][j];
    
    int maxsum = max(*max_element(rowsum , rowsum + r) , *max_element(colsum , colsum + c));
    
    int i = 0 , j = 0 , cnt = 0;
    
    while(i < r && j < c)
    {
        int diff = min(maxsum - rowsum[i] , maxsum - colsum[j]);
        
        a[i][j] += diff , cnt += diff , rowsum[i] += diff , colsum[j] += diff;
        
        (rowsum[i] == maxsum) ? i++ : j++;
    }
    
    return cnt;
}

signed main()
{
	vector<vector<int>> a= { { 1, 2 , 3 }, 
		                     { 5, 6 , 7 }, 
		                     { 9, 10, 11} };
    int r = a.size();
    int c = a[0].size();
    
    cout << "Minimum Operation : " << Make_Sums_Equal(a , r , c) << endl;
    
    for(auto i : a)
	{
		for(auto j : i)
		cout << j << " ";
		cout << endl;
	}
    
	return 0;
}
