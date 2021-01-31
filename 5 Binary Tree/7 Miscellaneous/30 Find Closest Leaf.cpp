#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	char data;
	Node* left;
	Node* right;
    Node(char x)
	{
		data=x;
		left=right=NULL;
	}
};
int Minheight(Node* root)
{
	if(!root)
	return 0;
	
	if(!root->left && !root->right)
	return 1;
	
	
	if(!root->left)
	return Minheight(root->right)+1;
	
	if(!root->right)
	return Minheight(root->left)+1;
	
	return min(Minheight(root->left),Minheight(root->right))+1;
}
int traverse(Node* root,char c,int &mn)
{
	if(!root)
	return 0;
	
	if(root->data==c)
	{
		mn=Minheight(root)-1;
		return 1;
	}
	
	int l=traverse(root->left,c,mn);
	
	if(l)
	{
		mn=min(mn,Minheight(root->right)+l);
		return l+1;
	}
	
	int r=traverse(root->right,c,mn);
	
	if(r)
	{
		mn=min(mn,Minheight(root->left)+r);
		return r+1;
	}
	
	return 0;
	
}
int findClosest(Node* root,char c)
{
	int mn=intmax;
	bool b=0;
	traverse(root,c,mn);
	return mn;
}
signed main()
{
    Node *root        = new Node('A'); 
    root->left               = new Node('B'); 
    root->right              = new Node('C'); 
    root->right->left        = new Node('E'); 
    root->right->right       = new Node('F'); 
    root->right->left->left  = new Node('G'); 
    root->right->left->left->left  = new Node('I'); 
    root->right->left->left->right = new Node('J'); 
    root->right->right->right      = new Node('H'); 
    root->right->right->right->left = new Node('K'); 
  
    char k = 'H'; 
    cout << "Minheight of the closest key from " << k << " is "<< findClosest(root, k) << endl;
         
    k = 'C';
    cout << "Minheight of the closest key from " << k << " is "<< findClosest(root, k) << endl;
         
    k = 'E';
    cout << "Minheight of the closest key from " << k << " is "<< findClosest(root, k) << endl;
         
    k = 'B'; 
    cout << "Minheight of the closest key from " << k << " is "<< findClosest(root, k) << endl;
    
    return 0;
}
