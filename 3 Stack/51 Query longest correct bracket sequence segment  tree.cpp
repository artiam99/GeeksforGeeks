#include<bits/stdc++.h>
using namespace std;

struct node
{
	int pair , open , close;
	
	node()
	{
		pair = open = close = 0;
	}
};

node merge(node left , node right)
{
	//at the begining each node contains number of unused open and closed brackets
	node parent;
	
	int minmatched = min(left.open , right.close);  //How many brackets are matching
	
	parent.pair = left.pair + right.pair + minmatched;
	
	parent.open = left.open + right.open - minmatched;
	
	parent.close = left.close + right.close - minmatched;
	
	return parent;
}

node query(node *st , int l , int r , int ql , int qr , int sti)
{
	if(l >= ql && r <= qr)
	return st[sti];
	
	if(l > qr || r < ql)
	{
		node nullnode;
	
		return nullnode;
	}
	
	int m = ((l + r) >> 1);
	
	return merge(query(st , l , m , ql , qr , sti * 2 + 1) , query(st , m+1 , r , ql , qr , sti * 2 + 2));
}

void constructuntill(string &s , int l , int r , node* st , int sti)
{
	if(l == r)
	{
		st[sti].pair = 0;
		
		st[sti].open = ((s[l] == '(') ? 1 : 0);
		
		st[sti].close = ((s[l] == ')') ? 1 : 0);
		
		cout << st[sti].pair << " " << st[sti].open << " " << st[sti].close << "  " << l << " " << r << endl;
		
		return;
	}
	
	int m = ((l + r) >> 1);
	
	constructuntill(s , l , m , st , sti * 2 + 1);
	
	constructuntill(s , m+1 , r , st , sti * 2 + 2);
	
	st[sti] = merge(st[sti * 2 + 1] , st[sti * 2 + 2]);
	
	cout << st[sti].pair << " " << st[sti].open << " " << st[sti].close << "  " << l << " " << r << endl;
}

node* constructst(string &s , int n)
{
	int p = (int)(ceil(log2(n)));
	
	int size = 2 * (int)pow(2 , p) - 1;
	
	node* st = new node[size];

	constructuntill(s , 0 , n-1 , st , 0);

	return st;
}

int Queries(node* st , int l , int r , int n)
{
	return 2 * query(st , 0 , n-1 , l , r , 0).pair;
}

signed main()
{
    cout << "( ) ) ( ( ) ) ( ( ) )  (" << endl;
    cout << "0 1 2 3 4 5 6 7 8 9 10 11" << endl;
    cout << "P O C  L R" << endl;
    
    string s = "())(())(())(";
	int n = s.length();
	
	vector<pair<int,int>> Q = {{4 , 11} , {4 , 5} , {1 , 2}};
	int q = Q.size();
	
	node* st = constructst(s , n);
	
	for(int i = 0 ; i < q ; i++)
	cout << Queries(st , Q[i].first , Q[i].second , n) << endl;
	
	return 0;
}

