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
vector<int> merge(Node* root1,Node* root2)
{
    vector<int> a;
    stack<Node*> s1,s2;
    
    while(1)
    {
        while(root1)
        {
            s1.push(root1);
            root1=root1->left;
        }
        while(root2)
        {
            s2.push(root2);
            root2=root2->left;
        }
        
        if(s1.empty()&&s2.empty())
            break;
        if(s1.size()&&s2.size())
        {
            if(s1.top()->data<s2.top()->data)
            {
                a.push_back(s1.top()->data);
                root1=s1.top()->right;
                s1.pop();
            }
            else
            {
                a.push_back(s2.top()->data);
                root2=s2.top()->right;
                s2.pop();
            }
        }
        else if(s1.size())
        {
            a.push_back(s1.top()->data);
            root1=s1.top()->right;
            s1.pop();
        }
        else
        {
            a.push_back(s2.top()->data);
            root2=s2.top()->right;
            s2.pop();
        }
        
    }
    return a;
}
signed main()
{
	/*
        100  
        / \  
       50 300  
      / \  
    20  70    */
    
    Node *root1 = new Node(100);
    root1->left     = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    /*
         80  
        / \  
      40  120  */
    
    Node *root2 = new Node(80);
    root2->left     = new Node(40);
    root2->right = new Node(120);
	
	vector<int> a=merge(root1,root2);
	
	for(auto i:a)
	cout<<i<<" ";
	cout<<endl;
	
	return 0;
}
