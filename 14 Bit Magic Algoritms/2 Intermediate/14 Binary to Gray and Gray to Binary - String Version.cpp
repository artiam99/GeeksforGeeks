#include<bits/stdc++.h> 
using namespace std;
string Binary_to_Gray(string &B)  //  MSB is Same .. Rest is => G[i] = B[i] ^ B[i-1]
{
	string G;  int i = 0;
    
    while(B[i] == '0')  G.push_back(B[i++]);
    
    if(i < B.length())  G.push_back(B[i++]);
    
    while(i < B.length())
    {
        if(B[i] == B[i-1])  G.push_back('0');
        
        else  G.push_back('1');
        
        i++;
    }
    return G;
}
string Gray_to_Binary(string &G)  // MSB is Same .. Rest is =>  if G[i] == 0  B[i] = B[i-1] , else  B[i] = !B[i-1]
{
	string B;  int i = 0;
    
    while(G[i] == '0')  B.push_back(G[i++]);
    
    if(i < G.length())  B.push_back(G[i++]);
    
    while(i < G.length())
    {
        if(G[i] == '1')  B.push_back((1 - (B[i-1] - 48)) + 48);
        
        else  B.push_back(B[i-1]);
        
        i++;
    }
    return B;
}
int main() 
{ 
	string B = "00110";
	
	cout << Binary_to_Gray(B) << endl;

	string G = "00101";
	
	cout << Gray_to_Binary(G) << endl;
	
	return 0; 
} 

