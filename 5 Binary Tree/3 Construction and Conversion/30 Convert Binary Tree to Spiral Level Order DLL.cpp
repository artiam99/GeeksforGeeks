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
void print_list(Node* head)
{
	Node* tail;
	while(head)
	{
		cout<<head->data<<" ";
		tail=head;
		head=head->right;
	}
	cout<<endl;
	while(tail)
	{
		cout<<tail->data<<" ";
		tail=tail->left;
	}
	cout<<endl;
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
void BTtoDLL(Node* root)
{
	stack<Node*> s1,s2;
	
	Node* prev=NULL;
	
	if(root)
	s1.push(root);
	
	while(s1.size()||s2.size())
	{
		while(s1.size())
		{
			Node* temp=s1.top();
			s1.pop();
			
			if(temp->right)
			s2.push(temp->right);
			
			if(temp->left)
			s2.push(temp->left);
			
			temp->left=prev;
			if(prev)
			prev->right=temp;
			prev=temp;
		}
		while(s2.size())
		{
			Node* temp=s2.top();
			s2.pop();
			
			if(temp->left)
			s1.push(temp->left);
		
			if(temp->right)
			s1.push(temp->right);
			
			temp->left=prev;
			if(prev)
			prev->right=temp;
			prev=temp;
		}
	}
}
signed main()
{
	Node *root =  new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
  
    root->left->left->left  = new Node(8);
    root->left->left->right  = new Node(9);
    root->left->right->left  = new Node(10);
    root->left->right->right  = new Node(11);
    root->right->left->right  = new Node(13);
    root->right->right->left  = new Node(14);
    
    SpiralBFT(root);cout<<endl<<endl;
    
    Node* head=root;
	
	BTtoDLL(root);
    
	print_list(head);
	
	return 0;
}
