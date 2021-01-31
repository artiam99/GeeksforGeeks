#include<bits/stdc++.h> 
using namespace std;
void MakeZero(vector<int> &a)
{
	a[a[1]] = a[!a[1]];
}
int main() 
{ 
	vector<int> a = {0 , 1};
	
	MakeZero(a);
	
	for(auto i : a)
	cout << i << " ";
	cout << endl;
	
	vector<int> b = {1 , 0};
	
	MakeZero(b);
	
	for(auto i : b)
	cout << i << " ";
	cout << endl;
	
	return 0; 
} 

