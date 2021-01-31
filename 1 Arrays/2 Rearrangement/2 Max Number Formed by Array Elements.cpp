#include <bits/stdc++.h>
using namespace std;

bool comp(string a , string b)
{
	string ab = a.append(b);
	string ba = b.append(a);
	
	for(int i = 0 ; i < ab.length() ; i++)
	{
		if(ab[i] > ba[i])  return true;
		
		else if(ab[i] < ba[i])  return false;
	}
	
	return true;
}

string Max_Number(int a[] , int n)
{
	vector<string> s;  //vector of int to vector of string
    
    for(int i = 0 ; i < n ; i++)
    s.push_back(to_string(a[i]));
	
    sort(s.begin() , s.end() , comp);
    
    string str;
    
    for(int i = 0 ; i < n ; i++)
    str += s[i];
    
    return str;
}

int main()
{

    int a[] = {30 , 3 , 94 , 7 , 998 , 9};
    int n = sizeof(a)/sizeof(int);
    
    cout << Max_Number(a , n);
    
    return 0;
}
