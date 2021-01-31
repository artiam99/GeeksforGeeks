#include<bits/stdc++.h> 
using namespace std;
int AND_in_Range(int x,int y)
{
	while(x < y)  // Flipping LSB
	y &= (y-1);
	
	return y;
}
int main() 
{ 
	int x = 10 , y = 15;
	
	cout << AND_in_Range(x,y) << endl;
	
	return 0; 
} 

