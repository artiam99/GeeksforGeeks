#include<bits/stdc++.h>
using namespace std;
void Number(int N)
{
	if(N == 0)	cout<< "0" << endl;
	
	if(N % 9 != 0)  cout<< (N % 9);
	
	for(int i = 0 ; i < N/9 ; i++)
	cout<< "9";
	
	for(int i = 0 ; i < N ; i++)
	cout<< "0";
	
	cout<< endl; 
}
signed main()
{
	int N = 20;
		
	Number(N);
	
    return 0;
}
