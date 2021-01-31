#include<bits/stdc++.h>
using namespace std;
int Left_Rotate(int N,int D,int B)
{
	D %= B;
	
	return ((N << D) | (N >> (B - D)) & ((1 << 16) - 1));
}
int Right_Rotate(int N,int D,int B)
{
	D %= B;
	
	return ((N >> D) | (N << (B - D)) & ((1 << 16) - 1));
}
signed main()
{
	int N = 34 , D = 2 , B = 16;  // Rotate N by D in B Bits Binary Representation , B <= 32
	
	cout<< Left_Rotate(N,D,B) << endl;
	
	cout<< Right_Rotate(N,D,B) << endl;
	
	return 0;
}
