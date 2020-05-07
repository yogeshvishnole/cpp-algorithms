// List is  data structure like array but have lots of flexibility

//Lists are internally implemented as doubly linked list

#include<iostream>
#include<list>

using namespace std;

int main()
{
    // Declaring the list
    list<int> L;

    // How to insert the data into the list

    //1. At the front
     L.push_front(1);
     L.push_back(2);

     cout<<L[0]<<L[1];
}
