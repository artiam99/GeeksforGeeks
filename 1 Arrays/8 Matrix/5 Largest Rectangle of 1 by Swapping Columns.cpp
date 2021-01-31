#include<bits/stdc++.h>
using namespace std;

int Largest_Rectangle(vector<vector<bool>> &a , int r , int c)
{
	vector<vector<int>> hist(r,vector<int>(c));
    
    for(int i = 0 ; i < c ; i++)
    for(int j = 0 ; j < r ; j++)
    hist[j][i] = a[j][i] + ((a[j][i]) ? ((j > 0) ? hist[j-1][i] : 0) : 0);  // Histogram for each Cell from upward
    
    for(int i = 0 ; i < r ; i++)
    {
        int Count[r+1];  memset(Count,0,sizeof(Count));
        
        for(int j = 0 ; j < c ; j++)
        Count[hist[i][j]]++;
        
        int col = 0;
        
        for(int j = r ; j >= 0 ; j--)
        if(Count[j])
        {
			for(int k = 0 ; k < Count[j] ; k++)
	        {
	            hist[i][col] = j;
	            
	            col++;
	        }
		}
    }
    
    int mx = 0;
    
    for(int i = 0 ; i < r ; i++)
    for(int j = 0 ; j < c ; j++)
    mx = max(mx , (j+1) * hist[i][j]);
    
    return mx;
}

signed main()
{
	vector<vector<bool>> a = { { 1, 1 , 0 }, 
		                       { 1, 1 , 1 }, 
		                       { 0, 1 , 1 } };
    int r = a.size();
    int c = a[0].size();
    
    cout << "Largest Rectangle : " << Largest_Rectangle(a , r , c) << endl;
    
	return 0;
}
