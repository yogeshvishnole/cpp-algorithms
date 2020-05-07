#include<iostream>
#include<climits>
using namespace std;

// Utility functions for implementation of dijkstras algorithm

int findMinVertex(bool *visited,int *weights,int V)
{
    int minVertex = -1;
    for(int i = 0;i<V;i++)
    {
        if(!visited[i] && ((minVertex == -1) || (weights[i]<weights[minVertex]) ))
        {
            minVertex = i;
        }
    }

    return minVertex;
}

// Implemenatation of dijkstra algorithm

void dijkstra(int **edges,int V)
{
    int *weights = new int[V];
    bool *visited = new bool[V];

    for(int i = 0;i<V;i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    weights[0] = 0;

    for(int i = 0;i<V-1;i++)
    {
        int minVertex = findMinVertex(visited,weights,V);
        visited[minVertex] = true;
        for(int j = 0;j<V-1;j++)
        {
            if(edges[minVertex][j] != 0 && !visited[j])
            {
                int temp = weights[minVertex] + edges[minVertex][j];
                if(temp<weights[j])
                {
                    weights[j] = temp;
                }
            }
        }
    }

    for(int i = 0;i<V;i++)
    {
        cout<<i<<" "<<weights[i]<<endl;
    }

    delete [] visited;
    delete [] weights;
}

int main()
{
    int V,E;
    cin>>V>>E;

    int** edges = new int*[V];

    for(int i = 0;i<V;i++)
    {
        edges[i] = new int[V];
        for(int j = 0;j<V;j++)
        {
            edges[i][j] = 0;
        }
    }




    for(int i = 0;i<E;i++)
    {
        int source,dest,weight;
        cin>>source>>dest>>weight;
        edges[source][dest] = weight;
        edges[dest][source] = weight;
    }


    dijkstra(edges,V);

    for(int i = 0;i<V;i++)
    {
        delete [] edges[i];
    }

    delete [] edges;

}
