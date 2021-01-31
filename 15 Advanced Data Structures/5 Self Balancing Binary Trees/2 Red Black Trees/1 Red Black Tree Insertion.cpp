#include<bits/stdc++.h>
using namespace std;
enum Color{RED , BLACK};
struct Node
{
	int data;
	bool color;
	Node* left;
	Node* right;
	Node* parent;
};
Node* New_Red_Node(int data , Node* parent)
{
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->parent = parent;
    
    node->left = node->right = NULL;
    
    node->color = RED;
    
    node->data = data;
    
    return node;
}
Node* New_Black_Node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->parent = node->left = node->right = NULL;
    
    node->color = BLACK;
    
    node->data = data;
    
    return node;
}
bool is_Left_Child(Node* root)
{
    Node* parent = root->parent;
    
    return (parent->left == root);
}
Node* Find_Sibling_Node(Node* root)
{
    Node* parent = root->parent;
    
	return (is_Left_Child(root) ? parent->right : parent->left);
}
void Right_Rotate(Node* root , bool changeColor)
{
    Node* parent = root->parent;
    
    root->parent = parent->parent;
    
    if(parent->parent != NULL)
	{
        if(parent->parent->right == parent)
        parent->parent->right = root;
        
		else
		parent->parent->left = root;
    }
    
    Node* right = root->right;
    
	root->right = parent;
    
	parent->parent = root;
	
    parent->left = right;
    
    if(right != NULL)
    right->parent = parent;
    
    if(changeColor)
	{
        root->color = BLACK;
        
		parent->color = RED;
    }
}

void Left_Rotate(Node* root, bool changeColor)
{
    Node* parent = root->parent;
    
    root->parent = parent->parent;
    
    if(parent->parent != NULL)
	{
        if(parent->parent->right == parent)
        parent->parent->right = root;
        
		else
        parent->parent->left = root;
    }
    
    Node* left = root->left;
    
    root->left = parent;
    
    parent->parent = root;
    
    parent->right = left;
    
    if(left != NULL)
    left->parent = parent;
    
    if(changeColor)
	{
        root->color = BLACK;
        parent->color = RED;
    }
}
Node* Insert(Node* parent , Node* root , int data)
{
    if(root == NULL)
	{
        if(parent != NULL)
		return New_Red_Node(data , parent);

        return New_Black_Node(data);
    }

    bool isLeft;
    
    if(root->data > data)
	{
        Node* left = Insert(root , root->left, data);

        if(left == root->parent)
        return left;

        root->left = left;
        
        isLeft = true;
    }
    
	else if(root->data < data)
	{
        Node* right = Insert(root , root->right , data);

        if(right == root->parent)
		return right;
        
		root->right = right;
    
        isLeft = false;
    }
    
    else
	return root;

    if(isLeft)
	{
        if(root->color == RED && root->left->color == RED)
		{
            Node* sibling = Find_Sibling_Node(root);
            
            if(!sibling || sibling->color == BLACK)
			{
                if(is_Left_Child(root))
				Right_Rotate(root , true);
                
				else
                {
                    Right_Rotate(root->left , false);

                    root = root->parent;

                    Left_Rotate(root , true);
                }

            }
			else
			{
                root->color = BLACK;
                
				sibling->color = BLACK;
				
                if(root->parent->parent != NULL)
                root->parent->color = RED;
            }
        }
    }
	else
	{
        if(root->color == RED && root->right->color == RED)
		{
            Node* sibling = Find_Sibling_Node(root);
            
            if(!sibling || sibling->color == BLACK)
			{
                if(!is_Left_Child(root))
            	Left_Rotate(root , true);
                
				else
				{
                    Left_Rotate(root->right , false);
                    
					root = root->parent;
                    
					Right_Rotate(root , true);
                }
            }
			else
			{
                root->color = BLACK;
                
                sibling->color = BLACK;
                
                if(root->parent->parent != NULL)
                root->parent->color = RED;
            }
        }
    }
    
    return root;
}
void Inorder(Node* root)
{
	if(!root) return;
	
	Inorder(root->left);
	
	cout << root->data << "(" << ((root->color == RED) ? "RED) " : "BLACK) ");
	
	Inorder(root->right);
}
signed main()
{
	/* 
	In Red Black Tree we take Leaf Nodes as Black Nodes , So Red Black tree is Full Binary Tree (For each Root-Leaf Path Number of Black Nodes are Same)
	
	Height of Red Black Tree with N Nodes , h <= 2 * Log2(N+1)
	
	Proof  : 1> Minimum Root-Leaf Path Length k : n >= 2^k -1 (as n is minimum in Full Binary tree)
			2>  So Number of Black Nodes in Path = Log2(N+1)  [From 1]
			3>> So For Longest Root-Leaf Path Height is 2 * Log2(N+1) (Red Black Alternative)
	
	*/
	
	Node* root = NULL;
	
	root = Insert(NULL , root , 5);
	root = Insert(NULL , root , 1);
	root = Insert(NULL , root , 4);
	root = Insert(NULL , root , 7);
	root = Insert(NULL , root , 6);
	root = Insert(NULL , root , 3);
	root = Insert(NULL , root , 2);
	root = Insert(NULL , root , 9);
	root = Insert(NULL , root , 8);
	
	Inorder(root);
	cout << endl;
	
	return 0;
}
