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
void BFTLinebyLine(Node* root)
{
	cout<<endl;
	queue<Node*> q1,q2;
    q1.push(root);
    while(q1.size()||q2.size())
    {
        if(q1.size())
        {
            while(q1.size())
            {
                if(q1.front()->left)
                q2.push(q1.front()->left);
                if(q1.front()->right)
                q2.push(q1.front()->right);
                cout<<q1.front()->data<<" ";
                q1.pop();
            }
        }
        else
        {
            while(q2.size())
            {
                if(q2.front()->left)
                q1.push(q2.front()->left);
                if(q2.front()->right)
                q1.push(q2.front()->right);
                cout<<q2.front()->data<<" ";
                q2.pop();
            }
        }
        cout<<endl;
    }
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	cout<<"Breadth Fisrt Traversal : ";BFTLinebyLine(root);
	return 0;
}
