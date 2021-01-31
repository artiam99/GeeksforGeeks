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
int height(Node* root)
{
	if(!root)
	return 0;
	return max(height(root->left),height(root->right))+1;
}
int diameter(Node* root)
{
	if(!root)
	return 0;
	
	return max( height(root->left) + height(root->right) + 1 , max( diameter(root->left) , diameter(root->right) ) );
}
signed main()
{
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    printf("Diameter is %d\n", diameter(root));
    
    return 0; 
}
