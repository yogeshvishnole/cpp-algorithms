// Iterators are nothing but the pointers in stl

// How to create iterator and how to use it so lets see

#include<iostream>
#include<list>

using namespace std;

int main()
{
    // Create an iterable datastructure
    list<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    // Now declaration of iterator for a given datastructure

    list<int> :: iterator it = numbers.begin();
    it = numbers.begin();  // It makes the it point on the next element after the 40

    list<int> :: iterator it2 ; // This line create a null pointer pointing to nowhere
    it2 = numbers.begin(); // This line makes the pointer pointing on the very first element of the iterable datastruvture list


    // Difference between an iterator and the pointer lets see by an example

    cout<<*it2<<endl;
    it2++;
    cout<<*it2<<endl;

    // But the above code is no possible with pointer for pointer we have to ue the following code   ptr = current->next;

    // Some more  use cases
    for(it;it!=numbers.end();it++)
        cout<<*it<<endl;




}

