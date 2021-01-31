#include <bits/stdc++.h>
using namespace std;
class kstack
{
	int n;
	
	int k;
	
	int *arr;
	
	int *top;
	
	int *next;
	
	int nextavailable;
	
	public:
	
		kstack(int n , int k)
		{
			this->k = k;
			
			this->n = n;
			
			arr = new int[n];
			
			top = new int[k];
			
			next = new int[n];
			
			nextavailable = 0;
			
			for(int i = 0 ; i < n ; i++)
			arr[i] = 0;
			
			for(int i = 0 ; i < k ; i++)
			top[i] = -1;
			
			for(int i = 0 ; i < n-1 ; i++)
			next[i] = i+1;
			
			next[n-1] = -1;
		}
		
		void push(int x , int k)
		{
			if(nextavailable == -1)
			{
				cout << "Stack " << k << " Overflow" << endl;
				
				return;
			}
			
			cout << x << " was Pushed in Stack " << k << endl;
			
			arr[nextavailable] = x;
			
			int i = nextavailable;
			
			nextavailable = next[i];
			
			next[i] = top[k];
			
			top[k] = i;
		}
		
		void pop(int k)
		{
			if(top[k] == -1)
			{
				cout << "Stack " << k << " Underflow" << endl;
		
				return;
			}
			
			cout << arr[top[k]] << " was Poped from Stack " << k << endl;
			
			arr[top[k]] = 0;
			
			int t = top[k];
			
			top[k] = next[top[k]];
			
			next[t] = nextavailable;
			
			nextavailable = t;
		}
		
		void print()
		{
			for(int i = 0 ; i < n ; i++)
			cout << arr[i] << " ";
			cout << endl;
		}
		
		void stack(int k)
		{
			cout << "Stack " << k << " : ";
			
			int i = top[k];
			
			if(i == -1)
			{
				cout << "Empty Stack " << k << endl;
				
				return;
			}
			
			while(i != -1)
			{
				cout << arr[i] << " ";
				
				i = next[i];
			}
			
			cout << endl;
		}
};

int main()
{
	kstack stk(6 , 3);
	
	stk.push(55 , 0);  stk.print();
	stk.pop(0);  stk.print();
	stk.pop(0);  stk.print();
	stk.push(51 , 0);  stk.print();
	stk.push(52 , 0);  stk.print();
	stk.push(56 , 1);  stk.print();
	stk.pop(0);  stk.print();
	stk.push(57 , 2);  stk.print();
	stk.push(58 , 2);  stk.print();
	stk.push(66 , 0);  stk.print();
	stk.push(90 , 1);  stk.print();
	stk.push(55 , 0);  stk.print();
	stk.push(45 , 1);  stk.print();
	stk.push(35 , 1);  stk.print();
	stk.stack(0);
	stk.stack(1);
	stk.stack(2);
	return 0;
}

