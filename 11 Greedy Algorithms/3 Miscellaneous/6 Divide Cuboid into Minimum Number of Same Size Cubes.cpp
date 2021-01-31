#include<bits/stdc++.h>
using namespace std;
void Max_Cube(int l,int b,int h)
{
	int side = __gcd(l,__gcd(b,h));
	
	int num = (l/side) * (b/side) * (h/side);
	
	cout<< side << " " << num << endl;
}
signed main()
{
	int l = 2 , b = 4 , h = 6;
	
	Max_Cube(l,b,h);
    
    return 0;
}
