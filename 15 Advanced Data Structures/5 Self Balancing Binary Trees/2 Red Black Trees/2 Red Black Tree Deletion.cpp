#include<bits/stdc++.h>
using namespace std;
enum Color{RED , BLACK};
struct Node
{
	int data;
	bool color;
	bool isleaf;
	Node* left;
	Node* right;
	Node* parent;
};
Node* New_Leaf_Node(Node* parent)
{
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->parent = parent;
	
	node->left = node->right = NULL;
	
	node->color = BLACK;
	
	node->isleaf = true;
	
	return node;
}
Node* New_Red_Node(int data , Node* parent)
{
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->parent = parent;
    
    node->left = New_Leaf_Node(node);
    
	node->right = New_Leaf_Node(node);
    
    node->color = RED;
    
    node->data = data;
    
    node->isleaf = false;
    
    return node;
}
Node* New_Black_Node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->parent = NULL;
    
    node->left = New_Leaf_Node(node);
    
    node->right = New_Leaf_Node(node);
    
    node->color = BLACK;
    
    node->data = data;
    
    node->isleaf = false;
    
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
    if(root == NULL || root->isleaf)
	{
		if(root)  delete root;
		
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
            
            if(sibling->color == BLACK)
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
            
            if(sibling->color == BLACK)
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

void DeleteCase1(Node* , Node* &);void DeleteCase2(Node* , Node* &);
void DeleteCase3(Node* , Node* &);void DeleteCase4(Node* , Node* &);
void DeleteCase5(Node* , Node* &);void DeleteCase6(Node* , Node* &);

void DeleteCase1(Node* doubleBlackNode , Node* &rootRef)
{
    if(doubleBlackNode->parent == NULL)
	{
        rootRef = doubleBlackNode;
        
		return;
    }
    
    DeleteCase2(doubleBlackNode , rootRef);
}

void DeleteCase2(Node* doubleBlackNode , Node* &rootRef)
{
    Node* sibling = Find_Sibling_Node(doubleBlackNode);
    
    if(sibling->color == RED)
	{
        if(is_Left_Child(sibling))
        Right_Rotate(sibling , true);
        
		else
        Left_Rotate(sibling , true);
    
        if(sibling->parent == NULL)
		rootRef = sibling;
    }
    
    DeleteCase3(doubleBlackNode , rootRef);
}

void DeleteCase3(Node* doubleBlackNode, Node* &rootRef)
{
	Node* sibling = Find_Sibling_Node(doubleBlackNode);

    if(doubleBlackNode->parent->color == BLACK && sibling->color == BLACK && sibling->left->color == BLACK && sibling->right->color == BLACK)
	{
        sibling->color = RED;
        
    	DeleteCase1(doubleBlackNode->parent , rootRef);
    	
    	return;
    }
    
	DeleteCase4(doubleBlackNode, rootRef);
}

void DeleteCase4(Node* doubleBlackNode , Node* &rootRef)
{
    Node* sibling = Find_Sibling_Node(doubleBlackNode);
    
    if(doubleBlackNode->parent->color == RED && sibling->color == BLACK && sibling->left->color == BLACK && sibling->right->color == BLACK)
	{
        sibling->color = RED;
        
		doubleBlackNode->parent->color = BLACK;
        
		return;
    }
    
	DeleteCase5(doubleBlackNode , rootRef);
}

void DeleteCase5(Node* doubleBlackNode , Node* &rootRef)
{
	Node* sibling = Find_Sibling_Node(doubleBlackNode);
	
    if(sibling->color == BLACK)
	{
        if (is_Left_Child(doubleBlackNode) && sibling->right->color == BLACK && sibling->left->color == RED)
		Right_Rotate(sibling->left , true);
            
        else if(!is_Left_Child(doubleBlackNode) && sibling->left->color == BLACK && sibling->right->color == RED)
        Left_Rotate(sibling->right, true);
    }

    DeleteCase6(doubleBlackNode , rootRef);
}

void DeleteCase6(Node* doubleBlackNode , Node* &rootRef)
{
    Node* sibling = Find_Sibling_Node(doubleBlackNode);
    
    sibling->color = sibling->parent->color;
    
    sibling->parent->color = BLACK;
    
    if(is_Left_Child(doubleBlackNode))
	{
        sibling->right->color = BLACK;
        
		Left_Rotate(sibling , false);
    }
	else
	{
        sibling->left->color = BLACK;
        
        Right_Rotate(sibling , false);
    }
 
    if(sibling->parent == NULL)
    rootRef = sibling;
    
}

void Replace_Node(Node* root , Node* child , Node* &rootRef)
{
    child->parent = root->parent;
    
    if(root->parent == NULL)
    rootRef = child;
    
    else
	{
	    if(is_Left_Child(root))
        root->parent->left = child;
        
		else
        root->parent->right = child;
    }
}

void DeleteOneChild(Node* nodeToBeDelete , Node* &rootRef)
{
    Node* child = (nodeToBeDelete->right ? nodeToBeDelete->right : nodeToBeDelete->left);

	Replace_Node(nodeToBeDelete , child , rootRef);

    if(nodeToBeDelete->color == BLACK)
	{
        if(child->color == RED)  child->color = BLACK;
        
		else  DeleteCase1(child , rootRef);
    }
}

Node* Find_Smallest(Node* root)
{
	if(!root)  return root;
	
    while(root->left)
	root = root->left;
    
    return root->parent;
}

void Delete(Node* root , int data , Node* &rootRef)
{
    if(!root)  return;
    
    if(root->data == data)
	{
        if(root->right->isleaf || root->left->isleaf)
		DeleteOneChild(root , rootRef);
		
        else
		{
            Node* inorderSuccessor = Find_Smallest(root->right);
            
            root->data = inorderSuccessor->data;
            
            Delete(root->right , inorderSuccessor->data , rootRef);
        }
    }
    
    if(root->data < data)
	Delete(root->right , data , rootRef);
    
	else
    Delete(root->left , data , rootRef);
}

Node* Delete(Node* root , int data)
{
    Node* rootRef = NULL;
    
    Delete(root , data , rootRef);
    
	return (rootRef ? rootRef : root);
}

void Inorder(Node* root)
{
	if(root->isleaf) return;
	
	Inorder(root->left);
	
	cout << root->data << "(" << ((root->color == RED) ? "RED) " : "BLACK) ");
	
	Inorder(root->right);
}
signed main()
{	
	Node* root = NULL;
	
	root = Insert(NULL , root , 5);
	root = Insert(NULL , root , 1);
	root = Insert(NULL , root , 4);
	root = Insert(NULL , root , 7);
	root = Insert(NULL , root , 6);
	root = Insert(NULL , root , 1);
	root = Insert(NULL , root , 2);
	root = Insert(NULL , root , 9);
	root = Insert(NULL , root , 8);
	
	Inorder(root);
	cout << endl;
	
	root = Delete(root , 6);
	root = Delete(root , 9);
	
	Inorder(root);
	cout << endl;
	
	return 0;
}
