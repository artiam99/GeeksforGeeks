#include<bits/stdc++.h>
using namespace std;

int Max_Colinear_Points(int X[] , int Y[] , int N)
{
    int mx = 1;
    
     for(int i = 0 ; i < N ; i++)
     {
        map<pair<int,int>,int> mp;
        
        int vertical = 0 , overlap = 0 , curr_max = 0;
         
        for(int j = i + 1 ; j < N ; j++)
        {
            if(X[i] == X[j] && Y[i] == Y[j])
            overlap++;
                
            else if(X[i] == X[j])
            vertical++;
            
            else
            {
                int y_diff =  (Y[j] - Y[i]);
                int x_diff = (X[j] - X[i]);
                
                int g = __gcd(x_diff , y_diff);
                
                y_diff /= g;
                x_diff /= g;
                
                mp[{y_diff , x_diff}]++;
            
                curr_max = max(curr_max , mp[{y_diff , x_diff}]);
            }
        }
        
        curr_max = max(curr_max , vertical);
        
        mx = max(mx , curr_max + overlap + 1);
     }
     
     return mx;
}

int main()
{
	int X[] = {0, 0, 0};
	int Y[] = {4, 5, 6};
	int N = sizeof(X) / sizeof(int);
	
	cout << Max_Colinear_Points(X , Y , N) << endl;
	
	return 0;
}

