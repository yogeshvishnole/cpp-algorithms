#include<iostream>
using namespace std;

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        long N;
        cin>>N;
        int A[N-1];
        long missing = -1;
        for(long i = 0;i<N-1;i++)
        {
            cin>>A[i];

        }

        for(long i = 0;i<N-1;i++)
        {
            if(A[i] != i+1)
            {
               missing = i+1;
            }
        }
        if(missing == -1)
        {
            missing = N;
        }
        cout<<missing<<endl;

    }
}
