#include<bits/stdc++.h>
using namespace std;

void Multiply(vector<vector<int>> &M , vector<vector<int>> &A , vector<vector<int>> &B , int m)
{
    for(int i = 0 ; i < 3 ; i++)
    for(int j = 0 ; j < 3 ; j++)
    for(int k = 0 ; k < 3 ; k++)
    M[i][j] = (M[i][j] % m + (A[i][k] % m * B[k][j] % m) % m) % m;
}

void Mat_Pow(vector<vector<int>> &A , int n , int m)
{
    int sz = 0 , N = n;
    
    while(N)
    {
        sz++;
        
        N >>= 1;
    }
    
    vector<vector<int>> dp[sz];
    
    dp[0] = vector<vector<int>>(3,vector<int>(3));
    
    for(int i = 0 ; i < 3 ; i++)
    for(int j = 0 ; j < 3 ; j++)
    dp[0][i][j] = A[i][j];
    
    for(int i = 1 ; i < sz ; i++)
    {
        dp[i] = vector<vector<int>>(3,vector<int>(3));
        
        Multiply(dp[i] , dp[i-1] , dp[i-1] , m);
    }
    
    for(int i = 0 ; i < 3 ; i++)
    for(int j = 0 ; j < 3 ; j++)
    {
        if(i == j)  A[i][j] = 1;
        
        else  A[i][j] = 0;
    }
    
    for(int i = 0 ; i < sz ; i++)
    if((n & (1 << i)))
    {
        vector<vector<int>> M(3 , vector<int>(3));
        
        Multiply(M , A , dp[i] , m);
        
        A = M;
    }
}

int G_of_N(int a , int b , int c , int n , int m)
{
	vector<vector<int>> A = {{a , b , c} , {1 , 0 , 0 } , {0 , 0 , 1}};
	    
    Mat_Pow(A , n - 2 , m);
                                                                     //               | G(2) |
    int ans = (A[0][0] % m + (A[0][1] % m + A[0][2] % m) % m) % m;  // (A ^ n - 2 ) X | G(1) |
                                                                   //                 |  1   |
    return ans;
}

signed main()
{
	int a = 2 , b = 2 , c = 2 , n = 4 , m = 100;  // G(n) = a * G(n-1) + b * G(n-2) + c , G(1) = 1 , G(2) = 1 ... Find G(4) % 100
	
	/*                                                         n-2
		| G(N)   |    | a  b  c |     | G(N-1) |    | a  b  c |     | G(2) |
		| G(N-1) | =  | 1  0  0 |  x  | G(N-2) | =  | 1  0  0 |  x  | G(1) |
		|   1    |    | 0  0  0 |     |   1    |    | 0  0  0 |     |  1   |
	    
	          | a  b  c |
	    A  =  | 1  0  0 |  
	          | 0  0  0 | , To Find A ^ N , we will do Binary Exponentiation Method in O(Log N) , Say N = 13 (1101) , So A ^ 13 = (A ^ 8) * (A ^ 4) * (A ^ 1) , Calculate using Dp Array
	*/
	
	cout << G_of_N(a , b , c , n , m) << endl;
	
	
	return 0;
}
