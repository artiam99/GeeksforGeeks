#include<bits/stdc++.h>
using namespace std;

#define MAX_CHAR 256 

struct SuffixTreeNode
{ 
	struct SuffixTreeNode *children[MAX_CHAR];

	struct SuffixTreeNode *suffixLink;
	
	int start;
	
	int *end;

	int suffixIndex;
};

typedef struct SuffixTreeNode Node;

char text[100];

Node *root = NULL;

Node *lastNewNode = NULL , *activeNode = NULL;

int cnt = 0 , activeEdge = -1 , activeLength = 0 , remainingSuffixCount = 0 , leafEnd = -1 , size = -1;

int *rootEnd = NULL , *splitEnd = NULL;

Node *newNode(int start , int *end) 
{ 
	cnt++;
	
	Node *node =(Node*) malloc(sizeof(Node)); 
	
	int i; 
	
	for (i = 0 ; i < MAX_CHAR ; i++)
	node->children[i] = NULL;

	node->suffixLink = root;
	
	node->start = start;
	
	node->end = end;

	node->suffixIndex = -1;
	
	return node;
}

int edgeLength(Node *n)
{
	return *( n->end ) - ( n->start ) + 1;
}

int walkDown(Node *currNode)
{
	if (activeLength >= edgeLength(currNode))
	{
		activeEdge = (int)text[activeEdge + edgeLength(currNode)] - (int)' ';
		
		activeLength -= edgeLength(currNode);
		
		activeNode = currNode;
		
		return 1;
	}
	
	return 0;
}

void extendSuffixTree(int pos)
{
	leafEnd = pos; 

	remainingSuffixCount++;

	lastNewNode = NULL;

	while(remainingSuffixCount > 0)
	{
		if (activeLength == 0)  activeEdge = (int)text[pos] - (int)' ';

		if (activeNode->children[activeEdge] == NULL)
		{
			activeNode->children[activeEdge] = newNode(pos , &leafEnd); 

			if (lastNewNode != NULL)
			{
				lastNewNode->suffixLink = activeNode;
				
				lastNewNode = NULL;
			}
		}

		else
		{
			Node *next = activeNode->children[activeEdge];
			
			if (walkDown(next))  continue;

			if (text[next->start + activeLength] == text[pos])
			{
				if(lastNewNode != NULL && activeNode != root)
				{
					lastNewNode->suffixLink = activeNode;
					
					lastNewNode = NULL;
				}

				activeLength++;

				break; 
			}

			splitEnd = (int*) malloc(sizeof(int));
			
			*splitEnd = next->start + activeLength - 1;

			Node *split = newNode(next->start, splitEnd);
			
			activeNode->children[activeEdge] = split;

			split->children[(int)text[pos]-(int)' '] = newNode(pos, &leafEnd);
			
			next->start += activeLength;
			
			split->children[activeEdge] = next;

			if (lastNewNode != NULL)
			lastNewNode->suffixLink = split;

			lastNewNode = split;
		}

		remainingSuffixCount--;
		
		if (activeNode == root && activeLength > 0)
		{ 
			activeLength--;
			
			activeEdge = (int)text[pos - remainingSuffixCount + 1] - (int)' ';
		}

		else if (activeNode != root)  activeNode = activeNode->suffixLink;
	}
}

void print(int i, int j)
{ 
	int k;
	
	for (k = i ; k <= j ; k++)
	printf("%c", text[k]);
} 

void setSuffixIndexByDFS(Node *n , int labelHeight)
{ 
	if (n == NULL) return; 

	if (n->start != -1)
	print(n->start, *(n->end)); 
	
	int leaf = 1;
	
	int i;
	
	for (i = 0 ; i < MAX_CHAR ; i++)
	{
		if (n->children[i] != NULL)
		{ 
			if (leaf == 1 && n->start != -1) 
			printf(" [%d]\n", n->suffixIndex); 

			leaf = 0;
			
			setSuffixIndexByDFS(n->children[i] , labelHeight + edgeLength(n->children[i]));
		}
	}
	
	if (leaf == 1)
	{
		n->suffixIndex = size - labelHeight;
		
		printf(" [%d]\n", n->suffixIndex);
	}
} 

void freeSuffixTreeByPostOrder(Node *n)
{
	if (n == NULL)  return; 
	
	int i; 
	
	for (i = 0 ; i < MAX_CHAR ; i++)
	if (n->children[i] != NULL)
	freeSuffixTreeByPostOrder(n->children[i]); 
	
	if (n->suffixIndex == -1) 
	free(n->end); 
	
	free(n); 
} 

void buildSuffixTree()
{
	size = strlen(text);
	
	int i;
	
	rootEnd = (int*) malloc(sizeof(int));
	
	*rootEnd = - 1;

	root = newNode(-1, rootEnd);

	activeNode = root;
	
	for (i = 0 ; i < size ; i++)
	extendSuffixTree(i);
	
	int labelHeight = 0;
	
	setSuffixIndexByDFS(root , labelHeight);

	freeSuffixTreeByPostOrder(root);
}

int main(int argc, char *argv[])
{ 
	strcpy(text, "abbc");
	
	buildSuffixTree();
	
	printf("\nNumber of nodes in suffix tree are %d \n" , cnt);
	
	return 0;
}

