#include<bits/stdc++.h> 
using namespace std;
int Nth_Magic_No(int n)  //  Pattern 0001 , 0010, 0011 , 0100, 0101 , 0110 , 0111 , ... instead of 2's Power 5's Power should be done
{
	int num = 0 , i = 1;
	
	while(n)
	{
		num += (n & 1) * pow(5,i++);
		
		n >>= 1;
	}
	
	return num;
}
int main() 
{ 
	int n = 5;
	
	cout << Nth_Magic_No(n) << endl;
	
	return 0; 
} 

