#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
	string data;
	Node* left;
	Node* right;
	Node(string x)
	{
		data=x;
		left=right=NULL;
	}
};
int eval(Node* root)
{
    if(root->data!="+"&&root->data!="-"&&root->data!="*"&&root->data!="/")
    {
    	int j=0;
    	if(root->data[0]=='-')
    	j++;
        int num=0;
        for(int i=j;i<root->data.length();i++)
        num=(num*10)+(root->data[i]-48);
        if(j==1)
        num*=-1;
        return num;
    }
    int l=eval(root->left) , r=eval(root->right);
    if(root->data=="+")
    return l+r;
    else if(root->data=="-")
    return l-r;
    else if(root->data=="*")
    return l*r;
    return l/r;
}
signed main()
{
	Node *root = new Node("+");  
    root->left = new Node("*");  
    root->left->left = new Node("5");  
    root->left->right = new Node("-4");  
    root->right = new Node("-");  
    root->right->left = new Node("100");  
    root->right->right = new Node("20");  
    cout << eval(root) << endl;  
  
	return 0;
}
