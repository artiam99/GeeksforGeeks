#include<bits/stdc++.h>
using namespace std;
#define int uint64_t
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	int data;
	Node* left;
	Node* right;
	int count;
	Node(int x)
	{
		data=x;
		left=right=NULL;
		count=1;
	}
};
int finddepth(string &s,int &i)
{
	if(s[i]=='l')
	{
		i++;
		return 1;
	}
	i++;
	return max( finddepth(s,i) , finddepth(s,i) ) + 1;
}
signed main()
{
	string s="nnlnllnnlnllnlnll";
	int i=0;
	cout<<finddepth(s,i);
	return 0;
}
