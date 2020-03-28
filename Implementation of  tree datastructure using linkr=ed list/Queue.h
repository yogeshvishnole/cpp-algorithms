#include<iostream>
using namespace std;

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;

};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **q;
public:
    Queue()
    {
        size = 10;
        front = -1;
        rear = -1;
        q = new Node*[10];
    }
    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        q = new Node*[size];
    }

    void enqueue(Node *item)
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

    Node *dequeue()
    {
        Node *x = NULL;
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




#endif // QUEUE_H_INCLUDED
