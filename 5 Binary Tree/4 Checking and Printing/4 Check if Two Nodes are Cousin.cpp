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
void traverse(Node* root,Node* Node1,Node* Node2,bool &p,int &h1,int &h2,int h)
{
	if(!root)
	return;
	
	h++;
	
	if(root->left&&root->right&&((root->left==Node1&&root->right==Node2)||(root->left==Node2&&root->right==Node1)))
	p=0;
	
	if(root==Node1)
	h1=h;
	
	if(root==Node2)
	h2=h;
	
	traverse(root->left,Node1,Node2,p,h1,h2,h);
	traverse(root->right,Node1,Node2,p,h1,h2,h);
	
}
bool check(Node* root,Node* Node1,Node* Node2)
{
	bool p=1;//if not siblings
	int h1=-1,h2=-1;
	traverse(root,Node1,Node2,p,h1,h2,0);
	return (h1!=-1&&h2!=-1&&h1==h2&&p);
}
signed main()
{
	Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(15);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
  
    Node *Node1,*Node2;
    Node1 = root->left->left;
    Node2 = root->right->right;
    
    if(check(root,Node1,Node2))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;
    
	return 0;
}
