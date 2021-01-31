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
int countPairs(Node* root1, Node* root2, int x)
{
    stack<Node*> s1,s2;
    
	int count=0;
    
	while(1)
    {
        while(root1)
        {
            s1.push(root1);
            root1=root1->left;
        }
        while(root2)
        {
            s2.push(root2);
            root2=root2->right;
        }
        
        if(s1.empty()||s2.empty())
        return count;
        
        if(s1.top()->data+s2.top()->data==x)
        {
            count++;
        
            root1=s1.top()->right;
            root2=s2.top()->left;
            s1.pop();
            s2.pop();
        }
        else if(s1.top()->data + s2.top()->data < x)
        {
            root1=s1.top()->right;
            s1.pop();
        }
        else
        {
            root2=s2.top()->left;
            s2.pop();
        }
    }
}
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
signed main()
{
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6); 
    root1->right->right = new Node(8); 
    
    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11); 
    root2->right->right = new Node(18); 

    int x = 16; 
    cout << "Pairs = "<< countPairs(root1, root2, x); 
    
    return 0;
}
