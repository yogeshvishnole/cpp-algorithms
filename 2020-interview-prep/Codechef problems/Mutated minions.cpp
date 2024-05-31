#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,T;
        cin>>N>>T;
        int A[N];
        for(int i = 0;i<N;i++)
        {
            cin>>A[i];
            A[i] += T;
        }
        int count = 0;
        for(auto i : A) // or we can also use for(int i:A)
        {
            if(i%7 == 0)
            {
                count++;
            }
        }

        cout<<count<<endl;
    }
}
