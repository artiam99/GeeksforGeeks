#include<bits/stdc++.h> 
using namespace std;
void Print(int n)
{
	int x = 1 , y = 2;
	
	while(1)
	{
		if(x > n) break;
		
		cout << x << " ";
		
		x |= (x << 2);
		
		if(y > n)  break;
		
		cout << y << " ";
		
		y |= (y << 2);
	}
	cout << endl;
}
int main() 
{
	int n = 10;
	
	Print(n);
	
	return 0;
}

