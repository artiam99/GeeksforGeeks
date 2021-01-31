#include<bits/stdc++.h>
using namespace std;
bool ismatching(char a , char b)
{
    if((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')') || a == 'X')
    return true;
    
    return false;
}

bool isbalanced(string s , stack<char> st , int ind)
{
    if (ind == s.length())
    return st.empty();
    
    if(s[ind] == '{' || s[ind] == '(' || s[ind] == '[')
	{
        st.push(s[ind]);
        
        return isbalanced(s , st , ind + 1);
    }
    
    else if(s[ind] == '}' || s[ind] == ')' || s[ind] == ']')
	{
        if (st.empty() || !ismatching(st.top() , s[ind]))
        return false;
        
        st.pop();
        
		return isbalanced(s , st , ind + 1);
    }
    
    else if(s[ind] == 'X')
	{
        st.push(s[ind]);
        
        bool res = isbalanced(s , st , ind + 1);
        
		if (res)
        return true;
        
        st.pop();
        
		if(st.empty())
        return false;
        
		st.pop();
        return isbalanced(s , st , ind + 1);
    }
}

signed main()
{
	string s = "{(X[X])}";

	stack<char> st;

	if(isbalanced(s , st , 0))
	cout << "Balanced" << endl;
	
	else
	cout << "Not Balanced" << endl;

	return 0;
}

