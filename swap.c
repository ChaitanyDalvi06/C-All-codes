#include<stdio.h>
int main ()
{
int a,b,c;
    printf("enter the value of a");
    scanf("%d",&a);
     printf("enter the value of b");
    scanf("%d",&b);
    c = b;
    b = a;
    a = c;
    printf("the value of a%d,the value of b%d",a,b);
    return 0;
}