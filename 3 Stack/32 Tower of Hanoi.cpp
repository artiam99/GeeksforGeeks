#include <bits/stdc++.h>
using namespace std;

void print(stack<int> &s)
{
	if(s.empty())
	return;
	
	cout << s.top() << " ";
	
	int c = s.top();
	
	s.pop();
	
	print(s);
	
	s.push(c);
}

void towerofhanoi(int n , int from , int to , int aux , stack<int> &s1 , stack<int> &s2 , stack<int> &s3)
{
	if(n > 0)
	{
		towerofhanoi(n-1 , from , aux , to , s1 , s2 , s3);
		
		stack<int> *sf;
		
		stack<int> *st;
		
		stack<int> *sa;
		
		if(from == 1)
		sf = &s1;
		
		else if(from == 2)
		sf = &s2;
		
		else
		sf = &s3;
		
		if(to == 1)
		st = &s1;
		
		else if(to == 2)
		st = &s2;
		
		else
		st = &s3;
		
		if(aux == 1)
		sa = &s1;
		
		else if(from == 2)
		sa = &s2;
		
		else
		sa = &s3;
		
		(*st).push((*sf).top());
		
		(*sf).pop();
    	
		cout << "S1 : [ ";  print(s1);  cout << "] S2: [ ";  print(s2);  cout << "]  S3: [ ";  print(s3);  cout << "]" << endl << endl;
		
		towerofhanoi(n-1 , aux , to , from , s1 , s2 , s3);
	}
}

int main()
{
	int n = 10;

	stack<int> s1;
	stack<int> s2;
	stack<int> s3;

	for(int i = n ; i >= 1 ; i--)
	s1.push(i);

	cout << "Number of rings to Move form 1 to 3 using 2 : " << n << endl;

	cout << "S1 : [ ";  print(s1);  cout<< "] S2: [ ";  print(s2);  cout << "]  S3: [ ";  print(s3);  cout << "]" << endl << endl;

	towerofhanoi(n , 1 , 3 , 2 , s1 , s2 , s3);

	return 0;
}

