/*

Implementation of binary search trees
Author : Yogesh vishnole

*/

/*

What is BST ?
BST is a binary tree in which for every node the elements in
its left subtree are smaller than that node while elements in
the right subtree are greater than that node.

*/


#include <iostream>
using namespace std;

// class which defines the single node of the tree
class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class BST
{
private:
    Node *root;
public:
    BST()
    {
        root = NULL;
    }


    // Function for inserting a new node in BST
    void insert(int key)
    {
        Node *t = root;
        Node *r = NULL,*p ;

        if(root == NULL)
        {
            p = new Node;
            p->data = key;
            p->lchild = NULL;
            p->rchild = NULL;
            root = p;
            return;
        }

        while(t != NULL)
        {
            r = t;

            if(key<t->data)
            {
                t = t->lchild;
            }
            else if(key>t->data)
            {
                t = t->rchild;
            }
            else
                return ;
        }
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        if(key<r->data)
        {
            r->lchild = t;
        }
        else
        {
            r->rchild = t;
        }

    }

    // Function for searching in the BST

    Node *search(int key)
    {
        Node *t;
        t = root;
        while(t!=NULL)
        {
            if(key == t->data)
                return t;
            else if(key < t->data)
                t = t->lchild;
            else
                t = t->rchild;
        }
        return t;
    }

    // Function for the recursive search

    Node *rsearch(Node *t,int key)
    {
        t = root;
        if(t == NULL)
            return t;
        else if(key == t->data)
            return t;
        else if(key<t->data)
        {
            return rsearch(t->lchild,key);
        }
        else
        {
            return rsearch(t->rchild,key);
        }
    }

    // Recursive function for inserting in the binarty search tree

    Node* rinsert(Node *t,int data)
    {
        Node *p = NULL;
        if(t == NULL)
        {
            p = new Node;
            p->data = data;
            p->lchild = p->rchild = NULL;
            return p;
        }
        else if(data<t->data)
        {
            t->lchild = rinsert(t->lchild,data);
        }
        else if(data>t->data)
        {
            t->rchild = rinsert(t->rchild,data);
        }
        return t;
    }


    // Function for finding the height of the tree

    int Height(Node *t)
    {
        int x,y;
        if(t == NULL) return 0;
        x = Height(t->lchild);
        y = Height(t->rchild);
        return x>y ? x+1 : y+1;
    }


    // Function for finding the inorder predecessor of a node

    Node *Inpre(Node *p)
    {
        while(p && p->rchild!=NULL)
        {
            p = p->rchild;
        }
        return p;
    }

    // Function for finding the inorder successor of a node

    Node *Insucc(Node *p)
    {
        while(p && p!=NULL)
        {
            p = p->lchild;
        }
        return p;
    }

    // Function for deleting a node in the binary search tree

    Node *Delete(Node *p,int data)
    {
        Node *q;
        if(p  == NULL)
            return NULL;
        if((p->lchild == NULL) && (p->rchild == NULL) )
        {
            if(p == root)
                root = NULL;
            delete p;
            return NULL;
        }
        if(data<p->data)
        {
            p->lchild = Delete(p->lchild,data);
        }
        else if(data>p->data)
        {
            p->rchild = Delete(p->rchild,data);
        }
        else
        {
            if(Height(p->lchild)>Height(p->rchild))
            {
                q = Inpre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild,q->data);
            }
            else
            {
                q = Insucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild,q->data);
            }
        }
        return p;
    }



    void inorder(Node *t)
    {
        if(t)
        {
            inorder(t->lchild);
            cout<<t->data<<" ";
            inorder(t->rchild);
        }
    }

    void inorder()
    {
        inorder(root);
        cout<<endl;
    }

    Node *Delete(int data)
    {
        return Delete(root,data);
    }


};

using namespace std;

int main()
{
  BST T1;

  T1.insert(9);
  T1.insert(15);
  T1.insert(5);
  T1.insert(20);
  T1.insert(16);
  T1.insert(8);
  T1.insert(12);
  T1.insert(3);
  T1.insert(6);
  T1.inorder();
  cout<<endl;



 T1.Delete(6);
 T1.Delete(12);
  T1.inorder();
  cout<<endl;
  T1.Delete(9);
T1.inorder();
  cout<<endl;
}
