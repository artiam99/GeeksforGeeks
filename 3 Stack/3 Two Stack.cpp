#include <bits/stdc++.h>
using namespace std;

class two_stack
{
	int *arr;

	int top1;

	int top2;

	int size;

	public:

		two_stack(int n)
		{
			size = n;

			arr = new int[size];

			top1 = -1;

			top2 = size;
		}
		
		void push1(int x)
		{
			if(top1 + 1 == top2)
			{
				cout << "Stack 1 Overflow" << endl;
				
				return;
			}
			
			arr[++top1] = x;
			
			cout << x << " was pushed in Stack 1" << endl;
		}
		
		void push2(int x)
		{
			if(top2 - 1 == top1)
			{
				cout << "Stack 2 Overflow" << endl;
				
				return;
			}
			
			arr[--top2] = x;
			
			cout << x << " was pushed in Stack 2" << endl;
		}
		
		int pop1()
		{
			if(top1 == -1)
			{
				cout << "Stack 1 empty : ";
				
				return -1;
			}
			
			int x = arr[top1--];
			
			cout << "Top 1 : ";
			
			return x;
		}
		
		int pop2()
		{
			if(top2 == size)
			{
				cout << "Stack 2 empty : ";
			    
				return -1;
			}
			
			int x = arr[top2++];
			
			cout << "Top 2 : ";
			
			return x;
		}
};
int main()
{
	two_stack tstk(5);// Size of array

	tstk.push1(1);
	tstk.push1(2);
	tstk.push2(5);
	tstk.push2(4);
	tstk.push2(3);
	tstk.push1(6);
	tstk.push2(7);

	cout << tstk.pop1() << endl;
	cout << tstk.pop1() << endl;
	cout << tstk.pop1() << endl;
	cout << tstk.pop2() << endl;
	cout << tstk.pop2() << endl;
	cout << tstk.pop2() << endl;
	cout << tstk.pop2() << endl;

	return 0;
}

