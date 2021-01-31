#include<bits/stdc++.h> 
using namespace std;
void Endian(char* start , int sz)
{
    for (int i = 0; i < sz; i++) 
    printf(" %.2x", start[i]); 
    cout << endl;
}
int main() 
{ 
	int i = 0x01234567;
	
	Endian((char*) &i , sizeof(i));
	
	return 0; 
} 

