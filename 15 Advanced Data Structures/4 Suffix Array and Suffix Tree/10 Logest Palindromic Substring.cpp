#include <bits/stdc++.h> 
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

int activeEdge = -1 , activeLength = 0 , remainingSuffixCount = 0 , leafEnd = -1;

int *rootEnd = NULL , *splitEnd = NULL;

int size = -1 , size1 = 0;

Node *newNode(int start , int *end)
{
	Node *node = (Node*)malloc(sizeof(Node));
	
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
	if(n == root)
	return 0;
	
	return *(n->end) - (n->start) + 1;
}

int walkDown(Node *currNode)
{
	if (activeLength >= edgeLength(currNode)) 
	{
		activeEdge += edgeLength(currNode);
	
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
        if (activeLength == 0) 
        activeEdge = pos;
            
        if (activeNode->children[text[activeEdge]] == NULL)
        {
            activeNode->children[text[activeEdge]] = newNode(pos , &leafEnd);
                                          
            if (lastNewNode != NULL)
            {
                lastNewNode->suffixLink = activeNode;
                
                lastNewNode = NULL;
            }
        }
        
        else
        {
            Node *next = activeNode->children[text[activeEdge]];
            
            if (walkDown(next))
            continue;
            
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
			 
            activeNode->children[text[activeEdge]] = split;
            
            split->children[text[pos]] = newNode(pos , &leafEnd);
			
			next->start += activeLength; 
            
			split->children[text[next->start]] = next;
            
            if (lastNewNode != NULL)
            lastNewNode->suffixLink = split; 
            
            lastNewNode = split; 
        } 

        remainingSuffixCount--;
        
        if (activeNode == root && activeLength > 0)
        { 
            activeLength--;
            
            activeEdge = pos - remainingSuffixCount + 1;
        }
        
        else if (activeNode != root)
        activeNode = activeNode->suffixLink;
    } 
}

void setSuffixIndexByDFS(Node *n , int labelHeight) 
{ 
	if (n == NULL) return; 
	
	int leaf = 1;
	
	int i;
	
	for(i = 0 ; i < MAX_CHAR ; i++)
	{
		if (n->children[i] != NULL)
		{
			leaf = 0;
			
			setSuffixIndexByDFS(n->children[i] , labelHeight + edgeLength(n->children[i]));
		}
	}
	
	if (leaf == 1)
	{
		for(i = n->start ; i <= *(n->end) ; i++) 
		if(text[i] == '#')
		{ 
			n->end = (int*) malloc(sizeof(int));
			
			*(n->end) = i;
		}
		
		n->suffixIndex = size - labelHeight;
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
	
	*rootEnd = -1;
	
	root = newNode(-1 , rootEnd);

	activeNode = root;
	
	for(i = 0 ; i < size ; i++)
	extendSuffixTree(i);
	
	int labelHeight = 0;
	
	setSuffixIndexByDFS(root , labelHeight);
}

int doTraversal(Node *n , int labelHeight , int* maxHeight , int* substringStartIndex) 
{ 
    if(n == NULL)
    return -1; 
     
    int i = 0;
    
	int ret = -1;
    
	if(n->suffixIndex < 0)
    {
        for (i = 0 ; i < MAX_CHAR ; i++)
        if(n->children[i] != NULL) 
        { 
            ret = doTraversal(n->children[i], labelHeight + edgeLength(n->children[i]) , maxHeight, substringStartIndex); 
            
            if(n->suffixIndex == -1)
			n->suffixIndex = ret; 
            
			else if((n->suffixIndex == -2 && ret == -3) || (n->suffixIndex == -3 && ret == -2) || n->suffixIndex == -4)
            {
                n->suffixIndex = -4;
				 
                if(*maxHeight < labelHeight)
                {
                    *maxHeight = labelHeight;
                
				    *substringStartIndex = *(n->end) - labelHeight + 1;
                }
            }
        }
    }
    else if(n->suffixIndex > -1 && n->suffixIndex < size1)
    return -2;
    
    else if(n->suffixIndex >= size1)
    return -3;
    
    return n->suffixIndex;
}

void getLongestCommonSubstring()
{
    int maxHeight = 0;
    
    int substringStartIndex = 0;
    
    doTraversal(root, 0, &maxHeight, &substringStartIndex);
      
    int k;
    
    for (k=0; k<maxHeight; k++) 
    printf("%c", text[k + substringStartIndex]);
    
    if(k == 0)
    printf("No common substring");
    
	else
    printf(", of length: %d",maxHeight);
    
	printf("\n");
}

int main(int argc, char *argv[])
{
	size1 = 9; // lenght plus one
	
    printf("Longest Palindromic Substring in cabbaabb : ");
    
    strcpy(text, "cabbaabb#bbaabbac$"); buildSuffixTree();
    
    getLongestCommonSubstring();
    
    freeSuffixTreeByPostOrder(root);
	
	return 0;
}

