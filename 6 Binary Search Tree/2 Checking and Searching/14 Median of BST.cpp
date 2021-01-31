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
Node* insert(Node* node, int key)
{
    if (node == NULL)
	return new Node(key); 

    if (key < node->data)
    node->left  = insert(node->left, key);
    
    else if (key > node->data)
    node->right = insert(node->right, key);

    return node;
}
int Size(Node* root)
{
	if(!root)
	return 0;
	return Size(root->left)+Size(root->right)+1;
}
void median(Node* root,Node* &prev,int size,float &ans,int &c)
{
	if(!root)
	return;
	
	median(root->right,prev,size,ans,c);
	
	c++;
	if(c==size/2+1)
	{
		if(size&1)
		ans=root->data;
		else
		ans=(root->data+prev->data)/2.0;
	}
	prev=root;
	median(root->left,prev,size,ans,c);
}
float findMedian(Node* root)
{
	int size=Size(root);
	
	Node* prev=NULL;
	float ans=-1;
	int c=0;
	median(root,prev,size,ans,c);
	return ans;
}
signed main()
{
    /*
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80   */
    
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    cout << "\nMedian of BST is "<< findMedian(root);
    
    return 0;
}
