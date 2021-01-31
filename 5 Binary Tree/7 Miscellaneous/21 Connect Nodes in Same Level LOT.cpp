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
void connect(Node* root)
{
	queue<Node*> q;
    if(root)
    q.push(root);
    while(q.size())
    {
        int size=q.size();
        Node* prev=NULL;
        while(size--)
        {
            if(prev)
            prev->nextRight=q.front();
            prev=q.front();
            if(q.front()->left)
            q.push(q.front()->left);
            if(q.front()->right)
            q.push(q.front()->right);
            q.pop();
        }
        prev->nextRight=NULL;
    }
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
