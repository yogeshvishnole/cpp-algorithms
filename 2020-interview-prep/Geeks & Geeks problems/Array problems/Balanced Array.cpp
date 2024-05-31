#include<iostream>
#include<numeric>
#include<cstdlib>
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
        int left_sum = 0;
        int right_sum = 0;
        left_sum = accumulate(A,A+(n/2),left_sum);
        right_sum = accumulate(A+(n/2),A+n,right_sum);
        cout<<left_sum<<" "<<right_sum;
        int diff = abs(left_sum - right_sum);
        cout<<diff<<endl;
    }


}
