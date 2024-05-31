#include<iostream>
using namespace std;

void insertionSort(int A[],int N)
{
    for(int i = 1;i<N;i++)
    {
        int x = A[i];
        int j;
        for(j = i-1;j>=0;j--)
        {
            if(A[j]>x)
            {
                A[j+1] = A[j];
            }else
            {
                break;
            }
        }
        A[j+1] = x;
    }
}



int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int N,k;
       cin>>N;
       int A[N];

       for(int i = 0;i<N;i++)
       {
           cin>>A[i];
       }

       cin>>k;

       insertionSort(A,N);

        for(int i = 0;i<N;i++)
       {
           cout<<A[i]<<" ";
       }

       cout<<A[k-1]<<endl;
   }
}
