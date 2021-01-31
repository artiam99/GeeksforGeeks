#include<bits/stdc++.h>
using namespace std;
int SetBits(int n)
{
	int sum = 0;
    
    while(1)
    {
        if(n == 0 || n == 1)
        {
            sum += n;
            
            break;
        }

        int len = log2(n) + 1;
        
        if(n != (1 << len) - 1)  len--;
        
        sum += len * (1 << (len - 1));  //  1 to 1111 => 4 * (2 ^ 3)  ... b * (2 ^ b)
        
        sum += n - (1 << len) + 1;
        
        n -= (1 << len);
    }
    
    return sum;
}
signed main()
{
	int n = 17;
	
	cout << SetBits(n) << endl;
	
	return 0;
}
