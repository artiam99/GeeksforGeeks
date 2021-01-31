#include<bits/stdc++.h> 
using namespace std;
int Next_Set_Bit_Number(int num)
{
	if(!num)  return num;
	
	int i = 0;
	
	while(!(num & (1 << i)))  i++;  // Skip Trailing Zeros
	
	int j = i , temp = 0;
	
	while((num & (1 << j)))  temp |= (1 << j) , j++;  // Find First 1's Pattern
	
	temp |= (1 << j--);
	
	temp &= ~(1 << j--);  // take next unset bit and left most set bit of the patter. Flip them
	
	int temp2 = (((((1 << (j - i + 1)) - 1 ) << i) & temp) >> i);  // Slide the rest Pattern to right most side
	
	temp &= ~((1 << (j+1)) - 1);
	
	temp |= temp2;
	
	num &= ~((1 << (j+3)) - 1);
	
	num |= temp;
	
	return num;
}
int Number(int M,int K)
{
	int num = (1 << K) - 1;
	
	for(int i = 1 ; i < M ; i++)
	num = Next_Set_Bit_Number(num);
	
	return num;
}
int main() 
{
	int M = 6 , K = 4;
	
	cout << Number(M,K) << endl;
	
	return 0;
}

