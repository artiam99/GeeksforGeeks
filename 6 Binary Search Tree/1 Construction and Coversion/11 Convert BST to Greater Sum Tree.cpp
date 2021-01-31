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
void inorder(Node* root)
{
	if(!root)
	return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void convertuntill(Node* root,int &sum)
{
	if(!root)
	return;
	
	convertuntill(root->right,sum);
	
	sum+=root->data;
	
	root->data=sum - root->data;
	
	convertuntill(root->left,sum);
}
void convert(Node* root)
{
	int sum=0;
	convertuntill(root,sum);
}
signed main()
{
	Node *root = new Node(11);
    root->left = new Node(2);
    root->right = new Node(29);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(40);
    root->right->right->left = new Node(35);
    
    cout << "Inorder Traversal of given tree\n";
    inorder(root);
    
    convert(root);
    
    cout << "\n\nInorder Traversal of transformed tree\n";
    inorder(root);

    return 0;
}
