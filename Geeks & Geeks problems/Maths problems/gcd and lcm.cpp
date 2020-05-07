#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    cout<<"Enter two numbers : ";
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<" "<<lcm(a,b);
}
