#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct ListNode
{
	int data;
	ListNode* next;
};
struct TreeNode
{ 
	int data;
	TreeNode *left, *right;
};
void push(struct ListNode** head_ref, int new_data)
{
	struct ListNode* new_node = new ListNode;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
TreeNode* newTreeNode(int data)
{ 
	TreeNode *temp = new TreeNode;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void convertList2Binary(ListNode *head, TreeNode* &root)
{
	root=NULL;
    queue<TreeNode*> q;
    if(head)
    {
        root=(TreeNode*)malloc(sizeof(TreeNode));
        root->data=head->data;
        root->left=root->right=NULL;
        q.push(root);
        head=head->next;
    }
    while(head)
    {
        q.front()->left=(TreeNode*)malloc(sizeof(TreeNode));
        q.front()->left->data=head->data;
        q.front()->left->left=q.front()->left->right=NULL;
        q.push(q.front()->left);
        head=head->next;
        if(head)
        {
            q.front()->right=(TreeNode*)malloc(sizeof(TreeNode));
            q.front()->right->data=head->data;
            q.front()->right->left=q.front()->right->right=NULL;
            q.push(q.front()->right);
            head=head->next;
        }
        q.pop();
    }
}
void BFT(TreeNode* root)
{
	queue<TreeNode*> q;
	if(root)
	q.push(root);
	while(q.size())
	{
		cout<<q.front()->data<<" ";
		if(q.front()->left)
		q.push(q.front()->left);
		if(q.front()->right)
		q.push(q.front()->right);
		q.pop();
	}
	cout<<endl;
}
signed main()
{
	struct ListNode* head = NULL;
	push(&head, 36);
	push(&head, 30);
	push(&head, 25);
	push(&head, 15);
	push(&head, 12);
	push(&head, 10);

	TreeNode *root;
	convertList2Binary(head, root);
	
	cout<<"List: ";
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
	
	cout<<"Tree: ";
	BFT(root);
	return 0; 
} 

