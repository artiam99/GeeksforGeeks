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
void check(Node* root , int &minlvl , int &count , bool &res , int height)//Preorder Traversal
{
    height++;
    
    if(!root)
    {
        if(minlvl == -1 || minlvl > height)// minlvl is the height of lowest level where we are getting a NULL so far
        {
            minlvl = height;
            count++; // how many times minlvl is changing its value so far
        }
        
        if(count > 2)// In complete binary Tree minlvl cannot change more than twice one last level and another for second lase level ... not more than that 
        res = 0;
        return;
    }
    if(minlvl != -1 && height >= minlvl) // As we are traverseing Preorder left to right if we get NULL at a level , we will never get a Node at that level again
    {
        res=0;
        return;
    }    
    
    check(root->left ,minlvl ,count ,res , height);
    
    check(root->right ,minlvl ,count ,res , height);
    
}
bool isCompleteBT(Node* root)
{
	int minlvl=-1;// Minimum level where we are getting a NULL
    
    bool res=1;// Final result
    
    int count=0;//Number of times minlvl is changing
    
    check(root,minlvl,count,res,0);
    
    return res;
}
signed main()
{
    Node *root = new Node(1);
    root->left     = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    if (isCompleteBT(root))
    cout << "Complete Binary Tree";
    else
    cout << "NOT Complete Binary Tree";
  
    return 0;
}
