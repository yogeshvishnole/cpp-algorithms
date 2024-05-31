#include <iostream>
#include <algorithm>
#define M 1000000007

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;
        long A[N];
        for(int i = 0;i<N;i++)
        {
            cin>>A[i];
        }
        int n = sizeof(A)/sizeof(A[0]);
        int profit = 0;
        sort(A,A+n);
        for(int i = N-1,j = 0;i>=0;i--,j++)
        {
            int temp = A[i]-j;
            if((A[i]-j)<0)
            {
                temp = 0;
            }
            profit += temp%M;
        }
        cout<<profit<<endl;
    }

}
