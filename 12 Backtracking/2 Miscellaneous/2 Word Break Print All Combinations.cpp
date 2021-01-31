#include<bits/stdc++.h>
using namespace std;
void Rec(string &s,int &n,unordered_set<string> &a,int i,string &w,vector<string> &ans,bool &flag)
{
    if(i == n)
    {
        if(w.length() == 0)
        {
            flag = false;
            
            cout<< "(";
            
            for(int j = 0 ; j < ans.size() ; j++)
            {
                cout<< ans[j];
            
			    if(j<ans.size()-1)
                cout<< " ";
            }
            
            cout<< ")";
        }
        return;
    }
    
    w.push_back(s[i]);
    
	if(a.find(w) != a.end())
    {
        ans.push_back(w);
    
	    string w1;
    
	    Rec(s,n,a,i+1,w1,ans,flag);
    
	    ans.pop_back();
    }
    
	Rec(s,n,a,i+1,w,ans,flag);
}
void AllWordBreak(vector<string> &dictionary,string s,int n)
{
	unordered_set<string> a;
    
	for(auto i : dictionary)
    a.insert(i);
    
    string w;  vector<string> ans;
    
    bool flag = true;
    
    Rec(s,n,a,0,w,ans,flag);
    
    if(flag)
    cout<< "Empty";
    
    cout<< endl;
}
signed main()
{
	vector<string> dictionary = {"lr", "m", "lrm", "hcdar", "wk"};
	
	string s = "hcdarlrm";
	int n = s.length();
	
	AllWordBreak(dictionary,s,n);
	
	return 0;
}
