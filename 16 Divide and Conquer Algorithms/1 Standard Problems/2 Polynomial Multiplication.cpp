#include<bits/stdc++.h>
using namespace std;
void Multiply(vector<int> &a1,int n1,vector<int> &a2,int n2)
{
	vector<int> ans(n1+n2-1);
	    
    for(int i = 0 ; i < n1 ; i++)
    for(int j = 0 ; j < n2 ; j++)
    ans[i+j] += a1[i] * a2[j];
    
    for(auto i : ans)
    cout << i << " ";
    cout << endl;
}
int main()
{
	vector<int> a1 = {1, 0, 3, 2};
	int n1 = a1.size();
	
	vector<int> a2 = {2, 0, 4};
	int n2 = a2.size();
	
	Multiply(a1,n1,a2,n2);
 
    return 0;
}
