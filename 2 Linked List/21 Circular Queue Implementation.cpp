#include<bits/stdc++.h>
using namespace std;

template<typename t>
class circular_queue
{
	struct node
	{
		t data;

		node* next;
	};

	node* front;

	node* rear;

	public:

		circular_queue()
		{
			front = NULL;
			
			rear = NULL;	
		}
		
		void push(t x)
        {
        	node* temp = new node();
        
		   	temp->data = x;
        
			if(front == NULL)
        	{
        		temp->next = temp;
        		
				front = temp;
        		
				rear = temp;
        	}
        	
        	node* temp1 = front;
        	
			do
        	{
     		    temp1 = temp1->next;
        	
			}while(temp1->next != front);
        	
			temp1->next = temp;
			
        	temp->next = front;
        	
			rear = temp;
        }
        
        void pop()
        {
        	if(front == NULL)
        	return;
        	
        	if(front->next == front)
        	{
        		delete front;
        		
	        	front = NULL;
		        
				rear = NULL;
		        
				return;
	        }
	        
        	node* temp = front;
         	
			do
        	{
        		temp = temp->next;
        		
        	}while(temp->next != front);
        	
         	temp->next = front->next;
         	
        	delete front;
        	
        	front = temp->next;
        	
        	rear = temp;
        }

        bool empty()
        {
        	if(front==NULL)
          	return true;

           	return false;
        }

		t Front()
        {
        	if(front == NULL)
        	return -1;
   
         	return front->data;
        }
        
		t Rear()
        {
        	if(rear == NULL)
        	return -1;
        
			return rear->data;
        }
};

int main() 
{
	circular_queue<int> q;

	cout << q.Front() << " " << q.Rear() << endl;

	q.push(1);

	cout << q.Front() << " " << q.Rear() << endl;

	q.push(2);

	cout << q.Front() << " " << q.Rear() << endl;

	q.push(3);

	cout << q.Front() << " " << q.Rear() << endl;

	if(q.empty())
	cout << "Empty" << endl;
	
	else
	cout << "Not empty" << endl;
	
	q.pop();
	
	cout << q.Front() << " " << q.Rear() << endl;
	
	q.pop();
	
	cout << q.Front() << " " << q.Rear() << endl;
	
	q.pop();
	
	cout << q.Front() << " " << q.Rear() << endl;
	
	if(q.empty())
	cout << "Empty" << endl;
	
	else
	cout << "Not empty" << endl;
	
	return 0;
}

