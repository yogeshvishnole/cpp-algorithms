/*

Kruskals algorithm implementation
Author : Yogesh vishnole

*/

#include<bits\stdc++.h>
#include<iostream>
using namespace std;



// Data structure for storing the single edge of the graph
class Edge
{
public:
    int source;
    int dest;
    int weight;
};

// compare function for sorting
bool compare(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}

//Find the set of vertex i
int findParent(int i,int parent[])
{
 if(parent[i] == i)
    return i;
 else findParent(parent[i],parent);
}

// Function for implementing krukals algorithm

void kruskals(Edge *input,int n,int E)
{
    // 1. sort all the edges in the ascending order
    sort(input,input + E,compare);

    Edge *output = new Edge[n-1];
    int count = 0;
    int i = 0;

    int parent[n];
    for(int j = 0;j<n;j++)
    {
        parent[j] = j;
    }

    while(count < n-1)
    {
        Edge currentEdge = input[i];

        // Check if the edge is suitable for mst or not
        int sourceParent = findParent(currentEdge.source,parent);
        int destParent = findParent(currentEdge.dest,parent);

        if(sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    for(int i = 0;i<count;i++)
    {
        if(output[i].source<output[i].dest)
        {
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else
        {
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }


}



int main()
{
    int n,E;
    cin>>n>>E;

    Edge *input = new Edge[E];

    for(int i  = 0;i<E;i++)
    {
        cin>>input[i].source>>input[i].dest>>input[i].weight;

    }

    kruskals(input,n,E);
}

