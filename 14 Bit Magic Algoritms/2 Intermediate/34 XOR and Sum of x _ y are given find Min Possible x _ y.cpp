#include<bits/stdc++.h> 
using namespace std;
void Find_Numbers(int X,int S)
{
	int x = (S - X) >> 1;  // S = X + 2 * A => A = (S - X) / 2  works always
	
	int y = (S + X) >> 1;
	
	cout << x << " " << y << endl;
}
int main() 
{
	int X = 13 , S = 17;
	
	Find_Numbers(X,S);
	
	return 0;
}

