#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>//    Remember This
using namespace std;
using boost::multiprecision::cpp_int;//Rempmber This
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()

vector<cpp_int> a(101);

cpp_int fucn(int n)
{
	if(a[n]!=0)
	return a[n];

	cpp_int sum=0;

	for(int i=0;i<n;i++)
	sum+=func(i)*func(n-1-i);// left*Right 0*n-1 + 1*n-2 + ..... + n-1*0

	a[n]=sum;

	return sum;
}

signed main()
{
	a[0]=1;
	
	func(100);
	
	cout<<a[10]<<endl;//Cn = (2n)!/(n+1)!*n!
	
	return 0;
}
