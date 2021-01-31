#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	int data;
	Node* left;
	Node* right;
    Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
int sumAtKthLevel(string s,int k)
{
	int sum=0;
	int lvl=-1;
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
		lvl++;
		
		else if(s[i]==')')
		lvl--;
		
		else if(s[i]>='0'&&s[i]<='9'&& lvl==k)
		sum+=s[i]-48;
	}
	return sum;
}
signed main()
{
	string tree = "(0(5(6()())(4()(9()())))(7(1()())(3()())))";  
    int k = 2; 
    cout << sumAtKthLevel(tree, k);  
    return 0; 
}
