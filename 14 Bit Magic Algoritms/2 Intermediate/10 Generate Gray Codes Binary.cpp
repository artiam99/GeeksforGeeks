#include<bits/stdc++.h> 
using namespace std;
void Gray_Codes(int n)
{
	vector<string> ans;
     
     ans.push_back("0"); ans.push_back("1");
     
     n--;
     
     while(n--)
     {
        for(int i = ans.size()-1 ; i >= 0 ; i--)
        {
            ans.push_back('1' + ans[i]);
            
            ans[i] = '0' + ans[i];
        }
     }
	
	for(auto i : ans)
	cout << i << " ";
	cout << endl;
}
int main() 
{ 
	int n = 4;  // 0 1  =>  00 01 11 10 (add 0 as prefix + Reverse and add 1 as prefix)  =>  0_00  0_01  0_11  0_10     1_10  1_11  1_01  1_00
	
	Gray_Codes(n);
	
	return 0; 
} 

