#include<iostream>
using namespace std;

// Node structure for a AVL tree

struct Node
{
    Node *lchild;
    int data;
    int height;
    Node *rchild;
}*root = NULL;

// Function for calculating the height of a node

int nodeHeight(Node *t)
{
    int hl,hr;
    hl = t && t->lchild ? t->lchild->height : 0;
    hr = t && t->rchild ? t->rchild->height : 0;

    return hl>hr ? hl + 1 : hr + 1;
}

// Function for calculating the balance factor

int balanceFactor(Node *t)
{
    int hl,hr;
    hl = t && t->lchild ? t->lchild->height : 0;
    hr = t && t->rchild ? t->rchild->height : 0;

    return hl - hr;
}

// Function for LL rotation

Node *LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if(root == p)
    {
        root = pl;
    }

    return p;
}

// Function for LR rotation

Node *LRRotation(Node *p)
{
    Node *pl,*plr
    pl->rchild = plr->lchild;;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    plr->height = nodeHeight(plr);

    return p;
}



// Function for inserting a node in a AVL tree

Node *rinsert(Node *t,int key)
{
    Node *c = NULL;
    if(t == NULL)
    {
        c = new Node;
        c->data = key;
        c->lchild = c->rchild = NULL;
        c->height = 0;
    }

    if(key<t->data)
    {
        t->lchild = rinsert(t->child);
    }
    else if(key>t->data)
    {
        t->rchild = rinsert(t->rchild);
    }

    t->height = nodeHeight(t);

    if((balanceFactor(t) == 2) && (balanceFactor(t) == 1))
        return LLRotation(t);
    if((balanceFactor(t) == 2) && (balanceFactor(t) == -1))
         return LRRotation(t);
    if((balanceFactor(t) == -2) && (balanceFactor(t) == -1))
        return RRRotation(t);
    if((balanceFactor(t) == -2) && (balanceFactor(t) == 1))
        return RLRotation(t);

    return t;
}


int main()
{

}
