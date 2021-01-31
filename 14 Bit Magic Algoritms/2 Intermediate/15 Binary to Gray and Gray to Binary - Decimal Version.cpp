#include<bits/stdc++.h> 
using namespace std;
int Binary_to_Gray(int B)
{
	return B ^ (B >> 1);
}
int Gray_to_Binary(int G)
{
	int B = 0;
	
	while(G)
	{
		B ^= G;
		
		G >>= 1;
	}
	return B;
}
int main() 
{ 
	int B = 7;
	
	cout << Binary_to_Gray(B) << endl;

	int G = 4;
	
	cout << Gray_to_Binary(G) << endl;
	
	return 0; 
} 

