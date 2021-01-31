#include <bits/stdc++.h> 
using namespace std;
int main() 
{
	bitset<32> b1; // Size should be runtime constant
	
	bitset<32> b2(20);
	
	bitset<32> b3(string("1010"));
	
	cout << b1 << endl << b2 << endl << b3 << endl;
	
	b1[1] = 1;
	b1[4] = b1[1];
	
	cout << b1 << endl;
	
	cout << b1.test(1) << " " << b1.test(3) << endl;  // Test if set or not	
	
	cout << b1.any() << " " << b1.none() << endl;  // if bitset has any setbit and if bitset is 0 or not
	
	b1.set();  cout << b1 << endl;  // Set all bits to 1
	
	b1.set(4,0);  cout << b1 << endl;  // set 4th bit to 0
	
	b1.set(4);  cout << b1 << endl;  // set 4th bit to default 1
	
	b1.reset(3); cout << b1 << endl;  // reset 3rd bit to 0
	
	b1.reset();  cout << b1 << endl;  // reset all bits
	
	b1.flip(3); cout << b1 << endl;  // flip 3rd bit
	
	b1.flip();  cout << b1 << endl;  // flip all bits
	
	int n = 100;
	
	cout << "Decimal : " << n << "  Binary : " << bitset<32>(n) << endl;
	
	bitset<4> bb1(9);
	bitset<4> bb2(3);
	
	cout << bb1 << " " << bb2 << endl;
	
	cout << (bb1 ^ bb2) << endl;
	
	cout << (bb1 & bb2) << endl;
	
	cout << (bb1 | bb2) << endl;
	
	cout << (~bb1) << endl;
	
	cout << (bb1 << 2) << endl;
	
	cout << (bb1 >> 1) << endl; 
	
	cout << (bb1 == bb2) << endl;
	
	bb1 ^= bb2;  cout << bb1 << endl;
	
	return 0; 
}
