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
Node* Insert(Node* root,int key)
{
	if(!root)
	return new Node(key);
	
	if(root->data==key)
	return root;
	
	else if(root->data>key)
	root->left=Insert(root->left,key);
	
	else
	root->right=Insert(root->right,key);
}
Node* deleteNode(Node *root,  int X)
{
    Node* p=root;
    Node* q=NULL;
    while(p)
    {
        
        if(p->data>X)
        {
        	q=p;
        	p=p->left;
		}
        
        else if(p->data<X)
        {
        	q=p;
        	p=p->right;
		}
        
        else
        {
        	
            if(!p->left)
            {
                if(q)
                {
                    if(q->left==p)
                    q->left=p->right;
                    else
                    q->right=p->right;
                }
                else
                root=p->right;
                //delete p;
            }
            else if(!p->right)
            {
                if(q)
                {
                    if(q->left==p)
                    q->left=p->left;
                    else
                    q->right=p->left;
                }
                else
                root=p->left;
                //delete p;
            }
            else
            {
                Node* succ=p->right;
                Node* succparent=p;
                while(succ->left)
                {
                    succparent=succ;
                    succ=succ->left;
                }
                if(succparent==p)
                p->right=succ->right;
                else
                succparent->left=succ->right;
                
                p->data=succ->data;
               delete succ;
            }
            p=NULL;
        }
    }
    return root;
}

signed main()
{
	Node* root=NULL;
	
	root=Insert(root,30);
    root=Insert(root,20);
    root=Insert(root,40);
    root=Insert(root,70);
    root=Insert(root,60);
    root=Insert(root,80);
    
	inorder(root);cout<<endl<<endl;
	
	cout<<"Delete 40"<<endl<<endl;
	root=deleteNode(root,40);
	inorder(root);cout<<endl<<endl;
	
	cout<<"Delete 60"<<endl<<endl;
	root=deleteNode(root,60);
	inorder(root);cout<<endl;
	
	return 0;
}
