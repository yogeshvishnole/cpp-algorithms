#include<iostream>
using namespace std;

// Utility function for calculating gcd of two numbers

int gcd(int a,int b)
{
    return b == 0?a : gcd(b,a%b);
}

// Three methods for array rotation

// No.1 using an temp array

void temArrRot(int N,int D,int A[])
{
 int AD[D];

        for(int i = 0,j = 0;i<N;i++,j++)
        {
            cin>>A[i];
            if(j<D)
            {
                AD[j] = A[i];
            }
        }

        for(int i = 0;i<(N-D);i++)
        {
            A[i] = A[i+D];
        }

        for(int i = N-D,j = 0;i<N;i++,j++)
        {
            A[i] = AD[j];
        }

        for(int i = 0;i<N;i++)
        {
            cout<<A[i]<<" ";
        }
}

// 2nd Method by rotating by 1 D times

// utility function

void rotOne(int N,int A[])
{
    int temp = A[0];
    for(int i = 0;i<N-1;i++)
    {
        A[i] = A[i+1];
    }
    A[N-1] = temp;

}

void oneArrRot(int N,int D,int A[])
{
    for(int i = 0,j = 0;i<N;i++,j++)
        {
            cin>>A[i];

        }
    for(int i = 0;i<D;i++)
    {
        rotOne(N,A);
    }
    for(int i = 0;i<N;i++)
        {
            cout<<A[i]<<" ";
        }
}

// 3rd method by juggling algorithm

void jugAlgRotArr(int N,int D,int A[])
{
     for(int i = 0,j = 0;i<N;i++,j++)
     {
      cin>>A[i];
     }

    int g_c_d = gcd(D, N);
    for (int i = 0; i < g_c_d; i++) {
        /* move i-th values of blocks */
        int temp = A[i];
        int j = i;

        while (1) {
            int k = j + D;
            if (k >= N)
                k = k - N;

            if (k == i)
                break;

            A[j] = A[k];
            j = k;
        }
        A[j] = temp;
    }
  for(int i = 0;i<N;i++)
        {
            cout<<A[i]<<" ";
        }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,D;
        cin>>N>>D;
        int A[N];
        //cout<<gcd(N,D);
        //temArrRot(N,D,A);
       // cout<<endl;
        jugAlgRotArr(N,D,A);
        cout<<endl;

    }
}
