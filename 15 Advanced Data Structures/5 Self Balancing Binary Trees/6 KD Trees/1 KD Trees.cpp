#include<bits/stdc++.h>
using namespace std;

const int k = 2;

struct Node
{
	int point[k];
	
	Node *left , *right;
};

struct Node* newNode(int arr[])
{
	struct Node* temp = new Node;

	for (int i = 0 ; i < k ; i++)
	temp->point[i] = arr[i];

	temp->left = temp->right = NULL;
	
	return temp;
}

Node *insertRec(Node *root , int point[] , unsigned depth)
{
	if (root == NULL)
	return newNode(point);
	
	unsigned cd = depth % k;

	if (point[cd] < (root->point[cd])) 
	root->left = insertRec(root->left , point , depth + 1);

	else
	root->right = insertRec(root->right , point , depth + 1);

	return root;
}

Node* insert(Node *root, int point[])
{
	return insertRec(root, point, 0);
}

Node *minNode(Node *x, Node *y, Node *z, int d) 
{ 
	Node *res = x;
	
	if (y != NULL && y->point[d] < res->point[d])
	res = y; 
	
	if (z != NULL && z->point[d] < res->point[d])
	res = z;
	
	return res;
}
 
Node *findMinRec(Node* root , int d , unsigned depth)
{
	if (root == NULL)
	return NULL;

	unsigned cd = depth % k;

	if (cd == d)
	{
		if (root->left == NULL)
		return root;
		
		return findMinRec(root->left , d , depth+1);
	}
	
	return minNode(root , findMinRec(root->left , d , depth+1) , findMinRec(root->right , d , depth+1) , d);
}

Node *findMin(Node* root, int d)
{
	return findMinRec(root , d , 0);
}

bool arePointsSame(int point1[] , int point2[])
{
	for (int i = 0 ; i < k ; ++i)
	if (point1[i] != point2[i])
	return false;

	return true;
}

void copyPoint(int p1[] , int p2[])
{
	for (int i = 0 ; i < k ; i++) 
	p1[i] = p2[i]; 
} 

Node *deleteNodeRec(Node *root , int point[] , int depth)
{
    if (root == NULL)
    return NULL;

    int cd = depth % k;

    if (arePointsSame(root->point , point))
    {
        if (root->right != NULL)
        {
            Node *min = findMin(root->right , cd);
 
            copyPoint(root->point , min->point);
 
            root->right = deleteNodeRec(root->right , min->point , depth+1);
        }
        
        else if (root->left != NULL)
        {
            Node *min = findMin(root->left , cd);
            
			copyPoint(root->point , min->point);
            
			root->right = deleteNodeRec(root->left , min->point , depth+1);
            
			root->left = NULL;
        }
        
        else
        {
            delete root;
            
            return NULL;
    	}
        return root;
    }

    if (point[cd] < root->point[cd])
    root->left = deleteNodeRec(root->left , point , depth+1);
   
    else
    root->right = deleteNodeRec(root->right , point , depth+1);
    
	return root;
}

Node* deleteNode(Node *root , int point[])
{
	return deleteNodeRec(root , point , 0);
}

int main()
{
	struct Node *root = NULL;
	
	int points[][k] = {{30 , 40} , {5 , 25} , {70 , 70} , {10 , 12} , {50 , 30} , {35 , 45}}; 

	int n = sizeof(points)/sizeof(points[0]);

	for (int i = 0 ; i < n ; i++) 
	root = insert(root , points[i]); 

	root = deleteNode(root , points[0]);

	cout << "Root after deletion of (30, 40)\n";
	
	cout << root->point[0] << ", " << root->point[1] << endl;

	return 0; 
} 

