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
	Node* nextRight;
    Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
Node* getnextright(Node* root)
{
	Node* temp=root->nextRight;
	
	while(temp)
	{
		if(temp->left)
		return temp->left;
		
		if(temp->right)
		return temp->right;
		
		temp=temp->nextRight;
	}
	return NULL;
}
void connectRecur(Node* root)
{
	if(!root)
	return;
	
	connectRecur(root->nextRight);// when I'm here for the first time of a level I'm at the left most Node....and All nextright nodes are connected 
	
	if(root->left)
	{
		if(root->right)
		{
			root->left->nextRight=root->right;
			
			root->right->nextRight= getnextright(root);
		}
		else
		root->left->nextRight= getnextright(root);
		
		connectRecur(root->left);
	}
	
	else if(root->right)
	{
		root->right->nextRight= getnextright(root);
		
		connectRecur(root->right);
	}
	
	else
	connectRecur(getnextright(root));
}
void connect(Node* root)
{
	if(root)
	root->nextRight=NULL;
	
	connectRecur(root);
}
signed main()
{
    /*
              10 
            /   \ 
          8      2 
        /         \ 
      3            90 
    */
    struct Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(90);

    connect(root);
    
    printf("Following are populated nextRight pointers in the tree (-1 is printed if there is no nextRight) \n\n");
    printf("nextRight of %d is %d \n", root->data,
     root->nextRight ? root->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->data,
     root->left->nextRight ? root->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->data,
     root->right->nextRight ? root->right->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
     root->left->left->nextRight ? root->left->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
     root->right->right->nextRight ? root->right->right->nextRight->data : -1);
    return 0;
}
