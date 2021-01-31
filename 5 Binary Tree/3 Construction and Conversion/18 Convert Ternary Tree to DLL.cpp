#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	int data;
	Node* left;
	Node* middle;
	Node* right;
	Node(int x)
	{
		data=x;
		left=middle=right=NULL;
	}
};
void print_list(Node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->right;
	}
	cout<<endl;
}
void TernaryTreeToList(Node* root,Node* &head)
{
	stack<Node*> st;
	
	head=root;
	
	st.push(root);
	
	Node* temp2=NULL;
	
	while(st.size())
	{
		
		Node* temp=st.top();
		st.pop();
		
		if(temp->right)
		st.push(temp->right);
		
		if(temp->middle)
		st.push(temp->middle);
		
		if(temp->left)
		st.push(temp->left);
		
		if(st.size())
		temp->right=st.top();
		
		else
		temp->right=NULL;
		
		temp->middle=NULL;
		
		temp->left=temp2;
		
		temp2=temp;
	}
}
signed main()
{
	Node* root = new Node(30);
  
    root->left = new Node(5);
    root->middle = new Node(11);
    root->right = new Node(63);
  
    root->left->left = new Node(1);
    root->left->middle = new Node(4);
    root->left->right = new Node(8);
  
    root->middle->left = new Node(6);
    root->middle->middle = new Node(7);
    root->middle->right = new Node(15);
  
    root->right->left = new Node(31);
    root->right->middle = new Node(55);
    root->right->right = new Node(65);
  
    Node* head = NULL;
  
    TernaryTreeToList(root,head);
    
	print_list(head);
	
	return 0;
}
