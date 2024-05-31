#include<iostream>
#include<string>
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
            cin>>A[N];
        }

        string flag = "YES";

        if(N<6)
       {
           flag = "NO";
       }

       for(int i = 0;i<N;i++)
       {
        if(A[i] == 1)
        {
            for(int j = i+1;(j<=i+5) && (j<N);j++)
            {
                if(A[j] == 1)
                {
                    flag = "NO";
                    break;
                }
            }
            if(flag == "NO")
            {
                break;
            }
        }
       }


        cout<<flag<<endl;
    }
}
