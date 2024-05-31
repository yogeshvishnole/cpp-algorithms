#include<iostream>
using namespace std;

template <class T>

T sumArrayElements(const T arr[],int size,T sum = 0) // Here in parameters we uses a const parameter and there is also a defaut parameter.
{
   for(int i = 0;i<size;i++)
   {
       sum += arr[i];
   }
   return sum;
}

int main()
{
    int integerArray[5] = {10,20,30,40,50};
    cout<<sumArrayElements(integerArray,5)<<endl;

    double doubleArray[] = {0.1,0.2,0.3,0.4,0.5};
    cout<<sumArrayElements(doubleArray,5)<<endl;
}
