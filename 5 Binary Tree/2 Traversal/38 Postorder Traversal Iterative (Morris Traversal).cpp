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
void insert(int x,Node** root)
{
	if(!(*root))
	{
		Node* temp=new Node(x);
		*root=temp;
		return;
	}
	if(x<=(*root)->data)
	insert(x,&((*root)->left));
	else if(x>(*root)->data)
	insert(x,&((*root)->right));
}
void postorder(Node* root)
{
    Node *dummyRoot=new Node(0);
    dummyRoot->left = root;
    Node *curr=dummyRoot,*pre,*first,*middle,*last;
    while(curr)
    {
        if(!curr->left)
        curr=curr->right;
        else
        {
            pre=curr->left;
            while(pre->right&&pre->right!=curr)
            pre = pre->right;

            if(!pre->right)
            {
                pre->right=curr;    
                curr=curr->left;
            }
            else
            {
                first=curr;
                middle=curr->left;
                while(middle!=curr)
                {
                    last = middle->right;
                    middle->right = first;
                    first = middle;
                    middle = last;
                }
                first=curr;
                middle=pre;
                while(middle!=curr)
                {
                    cout<<middle->data<<" ";
                    last = middle->right;
                    middle->right = first;
                    first = middle;
                    middle = last;
                }
                pre->right = NULL;
                curr=curr-> right;
            }
        }
    }    	
	cout<<endl;
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	postorder(root);
	return 0;
}
