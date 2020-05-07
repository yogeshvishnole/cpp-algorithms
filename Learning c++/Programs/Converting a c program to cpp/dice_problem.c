#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIDES 6
#define R_SIDES (rand() % SIDES + 1)

int main()
{
    int trials;
    int ndice = 2;
    int i = 0,j = 0,d1 = 0,d2 = 0;
    int outcomes[ndice*SIDES];
    srand(clock());
    printf("Enter the number of trials");
    scanf("%d",&trials);

    for(j = 0;j<trials;++j)
    {
        outcomes[(d1 = R_SIDES) + (d2 = R_SIDES)]++;
        printf("Probability\n");
        for(j = 2;j<ndice*SIDES + 1;++j)
            printf("j = %d  p  = %lf\n",j,(double)(outcomes[j]/trials));
    }
}

