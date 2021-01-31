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
bool isTripletPresent(Node *root)
{
    Node* head=NULL,*tail=NULL;
    BSTtoDLL(root,head,tail);
    
    if(head==tail)
    return false;
    
    Node* curr=head->right,*l,*r;
    while(curr!=tail)
    {
        l=head;
        r=tail;
        while(l!=curr && r!=curr)
        {
            if(l->data+r->data==-curr->data)
            return true;
            else if(l->data+r->data<-curr->data)
            l=l->right;
            else
            r=r->left;
        }
        curr=curr->right;
    }
    return false;
}
signed main()
{
    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
    
	if (isTripletPresent(root))
    cout << "Present";
    
	else
    cout << "Not Present";
    
	return 0; 
}
