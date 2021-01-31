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
	Node* parent;
    Node(int x,Node* p)
	{
		data=x;
		left=right=NULL;
		parent =p;
	}
};
Node* findRightSibling(Node* node)
{
    Node* curr=node->parent , *prev=node;
    
    int lvl=1;
    
    while(curr)
    {
        if(curr->right==prev)
        {
            prev=curr;
            curr=curr->parent;
            lvl++;
            continue;
        }
        
        Node* temp=curr->right;
        int templvl=lvl-1;
       
        while(temp)
        {
            if(templvl==0)
            return temp;
            
            if(temp->left)
            temp=temp->left;
            
            else if(temp->right)
            temp=temp->right;
           
            else
            temp=NULL;
            
            templvl--;
        }
        
        prev=curr;
        curr=curr->parent;
        lvl++;
    }
    return NULL;
}
signed main()
{
    /*       1
            / \
           2   3
          /  \  \
         4    6  5
        /      \  \
       7        9  8
       /         \
      10         12    */
    Node* root = new Node(1, NULL); 
    root->left = new Node(2, root); 
    root->right = new Node(3, root); 
    root->left->left = new Node(4, root->left); 
    root->left->right = new Node(6, root->left); 
    root->left->left->left = new Node(7, root->left->left); 
    root->left->left->left->left = new Node(10, root->left->left->left); 
    root->left->right->right = new Node(9, root->left->right); 
    root->right->right = new Node(5, root->right); 
    root->right->right->right = new Node(8, root->right->right); 
    root->right->right->right->right = new Node(12, root->right->right->right); 

    Node* res = findRightSibling(root->left->left->left->left);
    
    if (res == NULL)
    printf("No right sibling");
    
    else
    printf("%d", res->data);
    
    return 0;
}
