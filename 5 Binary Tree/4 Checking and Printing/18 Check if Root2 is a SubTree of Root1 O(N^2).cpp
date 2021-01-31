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
bool issame(Node* root1,Node* root2)
{
    if(!root1&&!root2)
    return true;
    
    if(root1&&root2&&root1->data==root2->data&&issame(root1->left,root2->left)&&issame(root1->right,root2->right))
    return true;
    
    return false;
}
void check(Node* T,Node * S,bool &res)
{
    if(!T)
    return;
    
    if(issame(T,S))
    res=0;
    
    if(res)
    check(T->left,S,res);
    
    if(res)
    check(T->right,S,res);
    
}
bool isSubTree(Node* T, Node* S)
{
    bool res=1;
    check(T,S,res);
    return !res;
}
signed main()
{
	Node* T = new Node('a'); 
    T->left = new Node('b'); 
    T->right = new Node('d'); 
    T->left->left = new Node('c'); 
    T->right->right = new Node('e'); 
  
    Node* S = new Node('a'); 
    S->left = new Node('b'); 
    S->left->left = new Node('c'); 
    S->right = new Node('d'); 
  
    if (isSubTree(T,S)) 
        cout << "Yes: S is a subtree of T"; 
    else
        cout << "No: S is NOT a subtree of T"; 
  
    return 0; 
    
    return 0; 
}
