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
void traverse(Node* root,int &hl,bool &p,int h)
{
	if(!root)
	return;
	
	h++;
	
	if(!root->left&&!root->right)
	{
		if(hl!=-1&&h!=hl)
		p=0;
		
		hl=h;
	}
	traverse(root->left,hl,p,h);
	traverse(root->right,hl,p,h);
}
bool check(Node* root)
{
	int hl=-1;
	bool p=1;
	traverse(root,hl,p,0);
	return p;
}
signed main()
{
	Node *root = new Node(12);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->left->left->left = new Node(1);
    root->left->right->left = new Node(1);

  
    if(check(root))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;
    
	return 0;
}
