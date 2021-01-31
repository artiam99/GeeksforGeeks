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
bool areIdentical(Node* root1,Node* root2)
{
	stack<Node*> s1,s2;
	
	while(1)
	{
		while(root1 && root2)
		{
			if(root1->data!=root2->data)
			return false;
			
			s1.push(root1);
			s2.push(root2);
			root1=root1->left;
			root2=root2->left;
		}
		
		if(!(!root1&&!root2))
		return false;
		
		if(s1.size()&&s2.size())
		{
			root1=s1.top()->right;
			root2=s2.top()->right;
			
			s1.pop();
			s2.pop();
		}
		
		else if(!s1.size()&&!s2.size())
		return true;
		
		else
		
		return false;
	}
}
signed main()
{
	Node *root1 = new Node(1); 
    root1->left = new Node(2); 
    root1->right = new Node(3); 
    root1->left->left = new Node(4); 
    root1->left->right = new Node(5); 
  
    Node *root2 = new Node(1); 
    root2->left = new Node(2); 
    root2->right = new Node(3); 
    root2->left->left = new Node(4); 
    root2->left->right = new Node(5); 
  
    areIdentical(root1, root2)? cout << "Yes"
                              : cout << "No"; 
    return 0;
}
