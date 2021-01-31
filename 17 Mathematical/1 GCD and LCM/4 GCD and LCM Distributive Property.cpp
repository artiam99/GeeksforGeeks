#include<bits/stdc++.h>
using namespace std;

//  GCD(LCM(x , y) , LCM(x , z)) = LCM(x , GCD(y , z)) , LCM(GCD(x , y) , GCD(x , z)) = GCD(x , LCM(y , z))

int Find_Val(int x , int y , int z)
{
	int g = __gcd(y , z);
	
	return ((x * g) / __gcd(x , g));
}
int main()
{
	int x = 30 , y = 40 , z = 400;
		
	cout << Find_Val(x , y , z) << endl;
		
	return 0;
}

