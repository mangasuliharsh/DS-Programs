#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    int n,res;
    printf("Enter the N Fibo: ");
    scanf("%d",&n);
    //res = fib(n);
    printf("Fibonacci Series of %d:", n);
    for (int i = 0; i < n; ++i)
    {
        printf(" %d ",fib(i));
    }
}