#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main()
{
    int n,res;
    printf("Enter the N factorial: ");
    scanf("%d",&n);
    res = fact(n);
    printf("Factorial of %d: %d", n,res);
}