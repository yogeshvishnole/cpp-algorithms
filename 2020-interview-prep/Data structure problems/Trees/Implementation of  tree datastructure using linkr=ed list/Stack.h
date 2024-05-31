#include<iostream>
#include "Queue.h"
#include<climits>
using namespace std;

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

// Here  we implement the stack datastructure using the linked list

class StackNode
{
public:
    Node *data;
    StackNode *next;
};

class Stack
{
    StackNode *top;
public:

    Stack()
    {
       top = NULL;
    }

    void push(Node *data)
    {
        StackNode *temp;
        temp = new StackNode;
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    Node *pop()
    {
        Node *x = top->data;
        StackNode *t = top;
        top = top->next;
        delete t;
        return x;
    }

    bool isEmpty()
    {
        if(top == NULL)
            return true;
        return false;
    }

    int stackTop()
    {
        if(top != NULL)
          return top->data->data;
        else
            return INT_MIN;
    }

};



#endif // STACK_H_INCLUDED

