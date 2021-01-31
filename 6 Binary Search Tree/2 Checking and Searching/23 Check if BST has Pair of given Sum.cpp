#include<bits/stdc++.h>
using namespace std;
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
Node* insert(Node* root, int key)  
{  
    if(root == NULL)
    return new Node(key);
    
    if (root->data > key)
    root->left = insert(root->left, key);
    
	else
    root->right = insert(root->right, key);
    
	return root;
}
void BSTtoDLL(Node* root,Node* &head,Node* &tail)
{
    if(!root)
    return;
    BSTtoDLL(root->left,head,tail);
    if(!head)
    head=root;
    
    if(tail)
    tail->right=root;
    
    root->left=tail;
    
    tail=root;
    
    BSTtoDLL(root->right,head,tail);
}
bool isPairPresent(struct Node *root, int target)
{
    Node* head=NULL,*tail=NULL;
    BSTtoDLL(root,head,tail);
    
    while(head != tail)
    {
        if(head->data+tail->data==target)
        return true;
        else if(head->data+tail->data<target)
        head=head->right;
        else
        tail=tail->left;
    }
    return false;
}
signed main()
{
	/* 
           15 
        /     \ 
      10      20 
     / \     /  \ 
    8  12   16  25    */
    Node* root = NULL;
    root = insert(root,15); 
    root = insert(root,10); 
    root = insert(root,20); 
    root = insert(root,8); 
    root = insert(root,12); 
    root = insert(root,16); 
    root = insert(root,25);
    
	if (isPairPresent(root,33))
    cout << "Present";
    
	else
    cout << "Not Present";
    
	return 0; 
}
