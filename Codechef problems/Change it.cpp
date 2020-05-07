#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i<N;i++)
        {
            cin>>A[i];
        }
        int n = sizeof(A)/sizeof(A[0]);
        int k = *max_element(A,A+n);
        k++;

        for(int i = 0;i<N;i++)
        {
            A[A[i]%k] += k;
        }

        int in = max_element(A,A+n)-A;
        for(int i = 0;i<N;i++)
        {
            A[i] = A[i]%k;
        }
        int co = 0;
        for(int i = 0;i<N;i++)
        {
            if(A[i] == A[in])
            {
                co++;
            }
        }
        cout<<N-co<<endl;
    }
}
