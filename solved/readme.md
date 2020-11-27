```javascript

// Recursive
int fib(int n)
{
    if (n <= 1)
        return (n);
    return fib(n-1) + fib(n-2);
}

// DP
fib[0] = 0;
fib[1] = 1;

for(int i = 2; i <= n; i++)
    fib[i] = fib[i-1] + fib[i-2];
return fib[n];
```