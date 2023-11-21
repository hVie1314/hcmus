#include <iostream>
#include <vector>

using namespace std;

// in day fibo khong su dung de quy 
void fibo(int n)
{
    if (n <= 0) return;
    long long a = 0;
    long long b = 1; 
    long long next = 0;

    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
}

// n day fibo dung dp
long long fibo_recursion(int n, vector<long long>& memo)
{
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];

    memo[n] = fibo_recursion(n - 1, memo) + fibo_recursion(n - 2, memo);
    return memo[n];
}

void print_fibo_recursion(int n)
{
    vector<long long> memo(n, -1);

    for (int i = 0; i < n; i++)
    {
        cout << fibo_recursion(i, memo) << " ";
    }
}

int main()
{
    int n = 50;
    fibo(n);
    cout << endl;
    print_fibo_recursion(n);

    return 0;
}