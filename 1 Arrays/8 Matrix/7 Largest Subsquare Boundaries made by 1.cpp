#include<bits/stdc++.h>
using namespace std;

int Largest_Subsquare(vector<vector<bool>> &a , int r , int c)
{
	vector<vector<int>> histcol(r,vector<int>(c)) , histrow(r,vector<int>(c));
	    
    for(int i = 0 ; i < r ; i++)
    for(int j = 0 ; j < c ; j++)
    histrow[i][j] = a[i][j] + ((a[i][j]) ? ((j == 0) ? 0 : histrow[i][j-1]) : 0);
    
    for(int i = 0 ; i < c ; i++)
    for(int j = 0 ; j < r ; j++)
    histcol[j][i] = a[j][i] + ((a[j][i]) ? ((j == 0) ? 0 : histcol[j-1][i]) : 0);
    
    int mx = 0;
    
    for(int i = 0 ; i < r ; i++)
    for(int j = 0 ; j < c ; j++)
    {
        int mn = min(histrow[i][j] , histcol[i][j]);
        
        for(int k = mn ; k > 0 ; k--)
        if( j - k + 1 >= 0 && i - k +1 >= 0 && histcol[i][j-k+1] >= k && histrow[i-k+1][j] >= k)
        {
            mx = max(mx , k);
            
            break;
        }
    }
    
    return mx;
}

signed main()
{
	vector<vector<bool>> a = { {1 , 0 , 1 , 1 , 1 , 1},
		                       {1 , 0 , 1 , 1 , 0 , 1},
		                       {1 , 1 , 1 , 0 , 0 , 1},
		                       {0 , 1 , 1 , 1 , 1 , 1},
		                       {1 , 1 , 1 , 0 , 1 , 0},
		                       {0 , 0 , 1 , 0 , 0 , 0} };
    int r = a.size();
    int c = a[0].size();
    
    cout << Largest_Subsquare(a , r , c) << endl;
    
	return 0;
}
