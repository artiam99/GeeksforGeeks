#include<bits/stdc++.h> 
using namespace std;
int mn(int x,int y)
{
	return (((x - y) & (1 << 31)) ? x : y);
}
int Smallest(int x,int y,int z)
{
	return mn(x , mn(y , z));
}
int main() 
{ 
	int x = 6 , y = 5 , z = 7;
	
	cout << Smallest(x,y,z) << endl;
	
	return 0; 
} 

