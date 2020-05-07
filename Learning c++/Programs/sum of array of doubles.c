#include<stdio.h>

double sumDoubleArray(double arr[],int size)
{
    int i;
    double sum = 0;

    for(i = 0;i<size;i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{

double arr[5] = {0.3,0.2,0.2,0.2,0.2};
double sum = sumDoubleArray(arr,5);
printf("Sum is %g",sum);

}
