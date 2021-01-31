#include<bits/stdc++.h>
using namespace std;
class KQueue
{
	int n;

	int k;

	int *arr;

	int *front;

	int *rear;

	int *next;

	int next_available;

	public:

		KQueue(int n,int k)
		{
			this->k = k;

			this->n = n;
			
			next_available = 0;
			
			arr = new int[n];  memset(arr,0,sizeof(int)*n);
			
			front = new int[k];  memset(front,-1,sizeof(int)*k);
			
			rear = new int[k];
			
			next = new int[n];  iota(next,next+n-1,1);
			
			next[n-1] = -1;
		}
		
		void push(int x,int kth)
		{
			cout << "Push : ";
	
			if(next_available == -1)
			{
				cout << "KQueue Full" << endl;
	
				return;
			}
	
			cout << "Queue " << kth << "  : " << x << endl;
			
			arr[next_available] = x;
			
			if(front[kth] == -1)
			front[kth] = next_available;
		
			else
		    next[rear[kth]] = next_available;
			
			rear[kth] = next_available;
			
			int in = next_available;
			
			next_available = next[in];
		
			next[in] = -1;
		}
	
		void pop(int kth)
		{
			cout << "Pop : Queue " << kth << " : ";
	
			if(front[kth] == -1)
			{
				cout << "Emtpy" << endl;
	
				return;
			}
	
			cout << arr[front[kth]] << endl;
	
			arr[front[kth]] = 0;
			
			int next_index = front[kth];
			
			front[kth] = next[front[kth]];
			
			next[next_index] = next_available;
			
			next_available = next_index;
		}
	
		void print()
		{
			cout << "Arr : ";
	
			for(int i = 0;i<n;i++)
	
			cout << arr[i] << " ";cout << "    ";
			
			for(int i = 0;i<k;i++)
			{
				cout << "Queue " << i << " : ";
	
				int j = front[i];
	
				while(j != -1)
				{
					cout << arr[j] << " ";
	
					j = next[j];
				}
	
				cout << "    ";
			}
	
			cout << endl << endl;
		}
};

signed main()
{
	KQueue q(7,3);
	
	q.pop(0);  q.print();
	q.pop(1);  q.print();
	q.pop(2);  q.print();
	q.push(5 , 1);  q.print();
	q.push(4 , 1);  q.print();
	q.push(9 , 0);  q.print();
	q.push(8 , 0);  q.print();
	q.push(7 , 0);  q.print();
	q.pop(1);  q.print();
	q.push(3 , 2);  q.print();
	q.pop(0);  q.print();
	q.push(2 , 2);  q.print();
	q.push(1 , 2);  q.print();
	q.push(5 , 2);  q.print();
	q.push(3 , 1);  q.print();
	q.pop(0);  q.print();
	q.pop(0);  q.print();
	q.pop(2);  q.print();
	q.pop(2);  q.print();
	q.pop(2);  q.print();
	q.pop(2);  q.print();
	q.pop(2);  q.print();
	q.pop(1);  q.print();

	return 0;
}

