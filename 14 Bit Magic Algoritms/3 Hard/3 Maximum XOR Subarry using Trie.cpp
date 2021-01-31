#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode* children[2];
    TrieNode ()
    {
        children[0] = children[1] = NULL;
    }
};
void Insert(TrieNode* root , int key , int bit_size)
{
    for(int i = bit_size ; i >= 0 ; i--)
    {
        bool bit = (key & (1 << i));
        
        if(!root->children[bit])  root->children[bit] = new TrieNode();
        
        root = root->children[bit];
    }
}
void Max_XOR(TrieNode* root , int &mx , int key , int curr , int bit_size)
{
    for(int i = bit_size ; i >= 0 ; i--)
    {
        bool bit = (key & (1 << i));
        
        if(root->children[1-bit])
        {   
            curr |= (((int)(1-bit)) << i);
            root = root->children[1-bit];
        }
        else if(root->children[bit])
        {
            curr |= (((int)(bit)) << i);
            root = root->children[bit];
        }
    }
    mx = max(mx , (key ^ curr));
}
int Max_Xor_Subarr(vector<int> &a , int n)
{
	long long m = *max_element(a.begin(),a.end());
        
    m |= (m >> 1);  m |= (m >> 2);  m |= (m >> 4);  m |= (m >> 8);  m |= (m >> 16);  m++;  m >>= 1;
    
    int bit_size = 0;
    
    while(m)
    {
        bit_size++;
        m >>= 1;
    }
    
    bit_size = max(1 , bit_size);
    
    TrieNode* root = new TrieNode();
    
    Insert(root , 0 , bit_size);
    
    int mx = 0 , pre_xor = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
    	pre_xor ^= a[i];
    	
        Max_XOR(root , mx , pre_xor , 0 , bit_size);
        
        Insert(root , pre_xor , bit_size);
    }
    
    return mx;
}
signed main()
{	
	vector<int> a = {8, 1, 2, 12, 7, 6};
	int n = a.size();
	
	cout << Max_Xor_Subarr(a,n) << endl;
	
	return 0;
}
