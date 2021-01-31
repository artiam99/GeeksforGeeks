#include<bits/stdc++.h>
using namespace std;

template<typename t>
class Deque
{
	struct node
	{
		t data;

		node* next;
	};

	node* front;

	node* rear;

	public:

		Deque()
		{
			front = NULL;

			rear = NULL;	
		}
		
		void push_back(t x)
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
        
        void push_front(t x)
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
        	
			rear = temp1;
        	
			front = temp;
        }
        
        void pop_front()
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
        }
        
        void pop_back()
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
        	
			node* prev;
         	
			do
        	{
        		prev = temp;
        		
        		temp = temp->next;
        	
			}while(temp->next != front);
			
         	prev->next = front;
        	
			delete temp;
        	
			rear = prev;
        }
        
        bool empty()
        {
        	if(front == NULL)
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
	Deque<int> q;

	cout << q.Front() << " " << q.Rear() << endl;

	q.push_back(2);

	cout << q.Front() << " " << q.Rear() << endl;

	q.push_front(1);

	cout << q.Front() << " " << q.Rear() << endl;

	q.push_back(3);

	cout << q.Front() << " " << q.Rear() << endl;

	if(q.empty())
	cout << "Empty" << endl;

	else
	cout << "Not empty" << endl;

	q.pop_front();

	cout << q.Front() << " " << q.Rear() << endl;

	q.pop_back();

	cout << q.Front() << " " << q.Rear() << endl;

	q.pop_front();

	cout << q.Front() << " " << q.Rear() << endl;

	if(q.empty())
	cout << "Empty" << endl;
	
	else
	cout << "Not empty" << endl;
	
	return 0;
}
