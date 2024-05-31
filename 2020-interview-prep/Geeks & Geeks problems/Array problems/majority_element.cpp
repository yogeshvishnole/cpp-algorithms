#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
	cin>>t;

	while(t--)
	{
	    long n;
	    cin>>n;

	    int A[n];
	    for(long i = 0;i<n;i++)
	    {
	        cin>>A[i];
	    }

	    int IterationHolder[n] = {0};

	    for(long i = 0;i<n;i++)
	    {
	        for(long j = 0;j<n;j++)
	        {
	            if(A[i] == A[j])
                {
                    IterationHolder[i]++;
                }

	        }
	    }



	   int maxElement = *max_element(IterationHolder,IterationHolder + n);

	   int flag;

	   for(long i = 0;i<n;i++)
       {
           if(maxElement == IterationHolder[i])
           {
               flag = i;
               break;
           }
       }

	   if (maxElement > n/2)
	   {
	       cout<<A[flag]<<endl;
	   }
	   else
	   {
	       cout<<-1<<endl;
	   }

	}

	return 0;
}
