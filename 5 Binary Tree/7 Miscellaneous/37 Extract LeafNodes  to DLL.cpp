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
void printList(Node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->right;
	}
}
Node* traverse(Node* root,Node* &prev,Node* &head)
{
    if(!root)
    return NULL;
    if(!root->left&&!root->right)
    {
        if(!head)
        head=root;
        root->left=prev;
        if(prev)
        prev->right=root;
        prev=root;
        return NULL;
    }
    root->left=traverse(root->left,prev,head);
    root->right=traverse(root->right,prev,head);
    return root;
}
Node* extractLeafList(Node *root)
{
    Node* head=NULL;
    Node* prev=NULL;
    traverse(root,prev,head);
    return head;
}
signed main()
{  
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout << "Inorder Trvaersal of given Tree is:\n";
    inorder(root);

    Node *head = extractLeafList(root);

    cout << "\nExtracted Double Linked list is:\n";
    printList(head);

    cout << "\nInorder traversal of modified tree is:\n";
    inorder(root);
    
    return 0;
}
