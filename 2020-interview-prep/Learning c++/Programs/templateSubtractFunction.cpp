#include<iostream>
using namespace std;

template <class Subtractable>

Subtractable subtractArrayElements(const Subtractable arr[],int size,Subtractable subtract = 100)
{
    for(int i = 0;i<size;i++)
    {
        subtract -= arr[i];
    }
    return subtract;
}

int main()
{
  float arr[] = {100,100,100,100,100};
  cout<<subtractArrayElements(arr,5);
}
