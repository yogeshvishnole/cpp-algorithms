/*
 Implementation of queue data structure using the concept of arrays
Author : Yogesh vishnole

*/

#include<iostream>
using namespace std;



class Queue
{
private:
    int size;
    int front;
    int rear;
    int *q;
public:
    Queue()
    {
        size = 10;
        front = -1;
        rear = -1;
        q = new int[10];
    }
    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        q = new int[size];
    }

    void enqueue(int item)
    {
      if(rear == size-1)
      {
        cout<<"Queue is full"<<endl;
      }
      else
      {
           rear++;
           q[rear] = item;
      }

    }

    int dequeue()
    {
        int x = -1;
        if(front == rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            x = q[front+1];
            front++;
        }
        return x;
    }

    bool isEmpty()
    {
        return front == rear;
    }


};

int main()
{
    Queue *q = new Queue[10];
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);

    cout<<q->isEmpty()<<endl;
    cout<<q->dequeue()<<endl;
    cout<<q->dequeue()<<endl;
    cout<<q->dequeue()<<endl;
    cout<<q->isEmpty()<<endl;
}
