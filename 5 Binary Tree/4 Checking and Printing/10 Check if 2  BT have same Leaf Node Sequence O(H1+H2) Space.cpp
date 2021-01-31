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
bool isSame(Node* root1,Node* root2)
{
	stack<Node*> s1,s2;
	
	s1.push(root1);
	s2.push(root2);
	while(s1.size()&&s2.size())
	{
		while(s1.top()->left||s1.top()->right)
		{
			Node* temp=s1.top();
			s1.pop();
			if(temp->right)
			s1.push(temp->right);
			if(temp->left)
			s1.push(temp->left);
		}
		while(s2.top()->left||s2.top()->right)
		{
			Node* temp=s2.top();
			s2.pop();
			if(temp->right)
			s2.push(temp->right);
			if(temp->left)
			s2.push(temp->left);
		}
		if(s1.top()->data!=s2.top()->data)
		return false;
		s1.pop();
		s2.pop();
	}
	if(s1.size()||s2.size())
	return false;
	return true;
}
signed main()
{
	Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    
    Node* root2 = new Node(0);
    root2->left = new Node(1);
    root2->right = new Node(5);
    root2->left->right = new Node(4);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    
    if(isSame(root1, root2))
    cout << "Same";
    else
    cout << "Not Same";
    
    return 0; 
}
