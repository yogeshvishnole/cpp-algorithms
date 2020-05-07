// Maps are used a s key value pair data structure

// Under the hood map uses th Binary Search trees

// Remember their properties

//1. They dont allow the duplicates
//2. Searching time is logn for an element
//3. left side small elements
//4. right side larger elements
//5. Inorder traversal is the sorted order

#include<iostream>
#include<map>

using namespace std;

int main()
{
    // Coffee shop menu example

    map<string,int> coffeeShopMenu;

    coffeeShopMenu["Espresso"] = 25;
    coffeeShopMenu["Cappuccino"] = 20;
    coffeeShopMenu["Tea"] = 10;

    cout<<coffeeShopMenu["Espresso"]<<endl;

    // Other method to put values in the map

    map<int,string> studentData {
    {
        1,"Yogesh"
    },
    {
        2,"Poornesh"
    }
    };

    cout<<studentData[1]<<endl;

}
