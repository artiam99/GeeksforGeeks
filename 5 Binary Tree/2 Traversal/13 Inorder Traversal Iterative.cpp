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
	int count;
	Node(int x)
	{
		data=x;
		left=right=NULL;
		count=1;
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
	if(x<(*root)->data)
	insert(x,&((*root)->left));
	else if(x>(*root)->data)
	insert(x,&((*root)->right));
	else
	(*root)->count++;
}
void inorder(Node* root)
{
	stack<Node*> st;
	Node* curr=root;
	while(curr||st.size())//just going to left untill getting NULL .. if getting NULL going back one step , printing and going right
	{
		while(curr)
		{
			st.push(curr);
			curr=curr->left;
		}
		cout<<st.top()->data<<"("<<st.top()->count<<") ";
		curr=st.top()->right;
		st.pop();
	}
	cout<<endl;
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	inorder(root);
	return 0;
}
