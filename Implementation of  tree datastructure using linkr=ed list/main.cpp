/*

Implementation of tree datastructure usinf doubly linked list
Author : Yogesh vishnole

*/

#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

// Defining the structure of each node of tree



class Tree
{
    Node *root;
public:
    Tree()
    {
        root = NULL;
    }


 // Concrete implementations of the tree datastructure functions
    void create()
    {
        Node *p,*t;
        int x;
        Queue q(100);
        cout<<"Enter the root : ";
        cin>>x;
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        q.enqueue(root);
        while(!q.isEmpty())
        {
            p = q.dequeue();
            cout<<"Enter the left Child of "<<p->data<<" : " ;
            cin>>x;
            if(x != -1)
            {
               t = new Node;
               t->data = x;
               t->lchild = t->rchild = NULL;
               p->lchild = t;
               q.enqueue(t);
            }
            cout<<"Enter the right Child of "<<p->data<<" : " ;
            cin>>x;
            if(x != -1)
            {
               t = new Node;
               t->data = x;
               t->lchild = t->rchild = NULL;
               p->rchild = t;
               q.enqueue(t);
            }

        }
    }

    void preorder(struct Node *t)
    {
       if(t)
       {
           cout<<t->data<<" ";
           preorder(t->lchild);
           preorder(t->rchild);
       }
    }

    void inorder(struct Node *t)
    {

        if(t)
        {
        inorder(t->lchild);
        cout<<t->data<<" ";
        inorder(t->rchild);
        }

    }

    void postorder(struct Node *t)
    {
        if(t)
        {
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<" ";
        }

    }

    // Iterative preorder

    void iterPreorder(struct Node *t)
    {
        Stack s;
        while((t != NULL) ||  (!s.isEmpty()) )
        {
            if(t!=NULL)
            {
                cout<<t->data<<" ";
                s.push(t);
                t = t->lchild;
            }
            else
            {
                t = s.pop();
                t = t->rchild;
            }
        }
    }

    // Iterative inorder

    void iterInorder(Node *t)
    {
        Stack s;
        while((t!=NULL) || (!s.isEmpty()))
        {
            if(t!=NULL)
            {
                s.push(t);
                t = t->lchild;
            }
            else
            {
                t = s.pop();
                cout<<t->data<<" ";
                t = t->rchild;
            }
        }
    }

    // Function in experiment

  /*  void iterPostorder(Node *t)
    {
        Stack  s;
        while((t!=NULL) && !s.isEmpty())
        {
            if(t!=NULL)
            {
             s.push(t->lchild);
             t = t->lchild;
            }
            else
            {
                t = s.pop();
                if(t>0)
                {
                    t = -t;
                    s.push(t);
                    t = ((Node*)t)->rchild;
                }
                else
                {
                    cout<<((Node *)t)->data<<" ";
                    t =NULL;
                }
            }

        }
    }
*/

// function for counting the number of levels of the tree

   int nL(Node *t)
   {
       int x,y;
       if(t!=NULL)
       {
           x = nL(t->lchild);
           y = nL(t->rchild);

           if(x>y)
           {
               return x+1;
           }
           else
           {
               return y+1;
           }
       }
       else
       {
         return 0;
       }

   }


   // Function for counting the number of nodes of tree

   int count(Node *t)
   {
       int x,y;
       if(t!=NULL)
       {
           x = count(t->lchild);
           y = count(t->rchild);
           return x+y+1;
       }
     return 0;
   }

   // Function for counting the number of leaf nodes

   int leafCount(Node *t)
   {
       if(t!=NULL)
       {
         if((t->lchild == NULL) && (t->rchild == NULL))
            return leafCount(t->lchild) + leafCount(t->rchild) + 1;
         else
            return leafCount(t->lchild) + leafCount(t->rchild);
       }
       return 0;
   }

   // Function for counting the nodes of degree 2

   int twoDegNodeCount(Node *t)
   {
       if(t!=NULL)
       {
         if((t->lchild != NULL) && (t->rchild != NULL))
            return twoDegNodeCount(t->lchild) + twoDegNodeCount(t->rchild) + 1;
         else
            return twoDegNodeCount(t->lchild) + twoDegNodeCount(t->rchild);
       }
       return 0;
   }

   // Function for counting the nodes of deg 1 0r 2

    int twoOneDegNodeCount(Node *t)
   {
       if(t!=NULL)
       {
         if((t->lchild != NULL) || (t->rchild != NULL))
            return twoOneDegNodeCount(t->lchild) + twoOneDegNodeCount(t->rchild) + 1;
         else
            return twoOneDegNodeCount(t->lchild) + twoOneDegNodeCount(t->rchild);
       }
       return 0;
   }

   // Function for counting the nodes of degree 1

    int oneDegNodeCount(Node *t)
   {
       if(t!=NULL)
       {
         if((t->lchild != NULL) ^ (t->rchild != NULL))
            return oneDegNodeCount(t->lchild) + oneDegNodeCount(t->rchild) + 1;
         else
            return oneDegNodeCount(t->lchild) + oneDegNodeCount(t->rchild);
       }
       return 0;
   }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions for providing a very descriptive and good interface of data structure tree


    void preorder()
    {
        preorder(root);
        cout<<endl;
    }


    void inorder()
    {
        inorder(root);
        cout<<endl;
    }


    void postorder()
    {
        postorder(root);
        cout<<endl;
    }

    void iterPreorder()
    {
        iterPreorder(root);
        cout<<endl;
    }

    void iterInorder()
    {
        iterInorder(root);
        cout<<endl;
    }

    int nL()
    {
       return nL(root);
    }

    int count()
    {
        return count(root);
    }

     int leafCount()
    {
        return leafCount(root);
    }

     int twoDegNodeCount()
    {
        return twoDegNodeCount(root);
    }

    int twoOneDegNodeCount()
    {
        return twoOneDegNodeCount(root);
    }

    int oneDegNodeCount()
    {
        return oneDegNodeCount(root);
    }

};


int main()
{

    Tree t;
    t.create();
    cout<<"Preorder  ";
    t.preorder();
    cout<<"Inorder  ";
    t.inorder();
    cout<<"Postorder  ";
    t.postorder();
    cout<<"IterPreorder ";
    t.iterPreorder();
    cout<<"IterInorder ";
    t.iterInorder();
    cout<<"No. of levels in tree "<<t.nL();
    cout<<endl;
    cout<<"No. of nodes in tree "<<t.count();
    cout<<endl;
    cout<<"No. of leaf nodes in tree "<<t.leafCount();
    cout<<endl;
    cout<<"No. of two deg nodes in tree "<<t.twoDegNodeCount();
    cout<<endl;
    cout<<"No. of two or one deg nodes in tree "<<t.twoOneDegNodeCount();
    cout<<endl;
    cout<<"No. of one deg nodes in tree "<<t.oneDegNodeCount();
    cout<<endl;

}
