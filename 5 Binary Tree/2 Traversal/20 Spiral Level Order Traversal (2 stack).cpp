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
	else
	insert(x,&((*root)->right));
}
void SpiralBFT(Node* root)
{
	stack<Node*> s1,s2;
	s1.push(root);
	while(s1.size()||s2.size())
    {
    	if(s1.size())
        {
            while(s1.size())
            {
                if(s1.top()->right)
                s2.push(s1.top()->right);
                if(s1.top()->left)
                s2.push(s1.top()->left);
                cout<<s1.top()->data<<" ";
                s1.pop();
            }
        }
        else
        {
            while(s2.size())
            {
                if(s2.top()->left)
                s1.push(s2.top()->left);
                if(s2.top()->right)
                s1.push(s2.top()->right);
                cout<<s2.top()->data<<" ";
                s2.pop();
            }
        }
    }
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	cout<<"Breadth Fisrt Traversal : ";SpiralBFT(root);
	return 0;
}
