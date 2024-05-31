#include<iostream>
#include<cstring>
#include<climits>
using namespace std;


// utility functions used in implementation of prims algorithm

int minVertex(int *weight,bool *visited,int V )
{

  int minV = -1;
  for(int i = 0;i<V;i++)
  {
         if(!visited[i] && ((minV == -1) || (weight[i]<weight[minV])))
         {
            minV = i;
         }
  }
  return minV;
}

// Implementation of prims algorithm

void prims(int **adjMat,int V)
{
    int *parent;
    int *weight;
    bool *visited;

    parent = new int[V];
    weight = new int[V];
    visited = new bool[V];



    for(int i = 0;i<V;i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }

    parent[0] = -1;


    weight[0] = 0;

    for(int i = 0;i<V;i++)
    {
       int a = minVertex(weight,visited,V);
       visited[a] = true;

       for(int j = 0;j<V-1;i++)
       {
           if((adjMat[a][j] != 0) && (!visited[j]))
           {
               if(adjMat[a][j] < weight[j])
               {
                   weight[j] = adjMat[a][j];
                   parent[j] = a;
               }
           }
       }

    }

    for(int i = 1;i<V;i++)
    {
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }


}



int main()
{
    // V = no of vertex
    //E = no of edges
    int V,E;


    cin>>V>>E;
    cout<<endl;

    int **adjMat;

    adjMat = new int*[V];

    for(int i = 0;i<V;i++)
    {
        adjMat[i] = new int[V];

        for(int j = 0;j<V;j++)
        {
            adjMat[i][j] = 0;
        }
    }



    for(int i = 0;i<E;i++)
    {
        int a,b,weight;
        cin>>a>>b>>weight;
        adjMat[a][b] = weight;
        adjMat[b][a] = weight;
    }


    prims(adjMat,V);
}
