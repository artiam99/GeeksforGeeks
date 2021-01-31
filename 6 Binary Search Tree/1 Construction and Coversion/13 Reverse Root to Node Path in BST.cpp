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
void reversePathuntill(Node* root,int k,queue<int> &q)
{
	if(!root)
	{
		while(q.size())
		q.pop();
		return;
	}
	
	q.push(root->data);
	
	if(root->data!=k)
	{
		if(root->data > k)
		reversePathuntill(root->left,k,q);
		else
		reversePathuntill(root->right,k,q);
	}
	
	if(q.size())
	{
		root->data=q.front();
		q.pop();
	}
}
void reversePath(Node* root,int k)
{
	queue<int> q;
	reversePathuntill(root,k,q);
}
signed main()
{
    /*        8
           /     \
          3       10
         /  \       \
       1    6         14
           /  \      /
          4    7    13   */
    
    Node* root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    
    int k=13;

    cout << "Before Reverse :" << endl;
    
    inorder(root);
    
    cout << "\n";
    
    reversePath(root, k);

    cout << "After Reverse :" << endl;

    inorder(root);

    return 0;
}
