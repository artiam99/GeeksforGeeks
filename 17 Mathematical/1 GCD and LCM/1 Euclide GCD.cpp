#include<bits/stdc++.h>
using namespace std;

/*

PROOF :
GCD(A,B)=GCD(B,R1)=GCD(R1,R2)=...=GCD(RK,0)=RK WHRER A>B AND R IS REMAINDER

ASSUME D IS A COMMON DIVISOR OF A AND B

D|A & D|B

WE CAN SAY D|(A-BQ) WHERE Q>0 I.E. D|R

ASSUME E IS ANY COMMON DIVISOR OF B AND R

E|B & E|R

WE CAN SAY E|(R+BQ) I.E. E|A

SO IT IS PROVED THAT D WILL BE ACOMMON DIVISOR OF A AND B IF AND ONLY IF D IS A COMMON DIVISOR OF B AND R

SO IT IS PROVED THAT GCD(B,R)=GCD(A,B)

Complexity : 

n = a * b , decreasing factor d = a / a % b

T(n) = T(n / d) + c
T(n) = T(n / d ^ 2) + 2c;
..
T(n) = T(n / d ^ k) + kc

n / d ^ k = 1

T(n) = T(1) + kc

k = Logd (n);

So Time Complexity is : O(Log(a * b))

gcd(a , b , c) = gcd(a , gcd(b , c))

gcd(a , 0) = a

*/

int gcd(int a , int b)
{
	if(a < b)  return gcd(b , a);
	
	if(b == 0)  return a;
	
	return gcd(b , a % b);
}

int main()
{
	int a = 72 , b = 18;
	
	cout << gcd(a , b) << endl;
	
	return 0;
}
