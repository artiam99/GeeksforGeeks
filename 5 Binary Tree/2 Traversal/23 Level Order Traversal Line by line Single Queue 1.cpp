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
	queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()!=1)
    {
        if(q.front())
        {
            if(q.front()->left)
            q.push(q.front()->left);
            if(q.front()->right)
            q.push(q.front()->right);
            cout<<q.front()->data<<" ";
            q.pop();
        }
        else
        {
            q.pop();
            cout<<endl;
            q.push(NULL);
        }
    }
    cout<<endl;
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	cout<<"Breadth Fisrt Traversal : ";BFTLinebyLine(root);
	return 0;
}
