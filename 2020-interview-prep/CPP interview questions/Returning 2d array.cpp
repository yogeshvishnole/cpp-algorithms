#include<iostream>
using namespace std;
const int N = 3;

// Using Static keyword

int (*(getArray)())[N]()
{
    static int arr[N][N] = {{0,1,2},{1,2,3},{2,3,4}}
    return arr;
}


// Using the dynamic array

void printArray(int** arr,int N)
{
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

void printArray2(int arr[][N])
{
  for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

int** get2dArray(int N)
{
    int** arr = new int*[N];
    for(int i = 0;i<N;i++)
    {
        arr[i] = new int[N];
        for(int j = 0;j<N;j++)
        {
            arr[i][j] = i+j;
        }
    }
    return arr;
}

int main()
{
    int N = 3;
    int** arr = get2dArray(N);
   // printArray(arr,N);
   int (*arr1)[N];
   arr1 = getArray();
   printArray2(arr1);
}
