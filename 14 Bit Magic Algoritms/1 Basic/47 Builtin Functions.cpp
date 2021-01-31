#include <bits/stdc++.h> 
using namespace std;
int main() 
{
	int n = 5;
	
	cout << "Set Bits Count : " << __builtin_popcount(n) << endl;  // long : __builtin_popcountl(n) , long long : __builtin_popcountll(n)
	
	cout << "Parity : " << __builtin_parity(n) << endl;  // long : __builtin_parityl(n) , long long : __builtin_parityll(n) ,  (Odd or Evern Number of Set Bits)
	
	cout << "Leading Zero Count : " << __builtin_clz(n) << endl;  // long : __builtin_clzl(n) , long long : __builtin_clzll(n) , (For 7  : (32 - 3) = 29 )
	
	cout << "Tailing Zero Count : " << __builtin_ctz(n) << endl;  // long : __builtin_ctzl(n) , long long : __builtin_ctzll(n) , (For 8 (1000) : 3 )
	
	return 0; 
}
