#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
char arr[10];
void root(char c)
{
	if(arr[0]!='\0')
	cout<<"Already has root"<<endl;
	else
	arr[0]=c;
}
void set_left(char c,int p)
{
	if(arr[p]=='\0')
	cout<<"Can't set chile at "<<p*2+1<<". No parent found"<<endl;
	else
	arr[p*2+1]=c;
}
void set_right(char c,int p)
{
	if(arr[p]=='\0')
	cout<<"Can't set chile at "<<p*2+2<<". No parent found"<<endl;
	else
	arr[p*2+2]=c;
}
void print_tree()
{
	for(int i=0;i<10;i++)
	{
		if(arr[i]=='\0')
		cout<<'_'<<" ";
		else
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
signed main()
{
	root('A');
	set_right('C', 0); 
    set_left('D', 1); 
    set_right('E', 1); 
    set_right('F', 2); 
    print_tree(); 
	return 0;
}
