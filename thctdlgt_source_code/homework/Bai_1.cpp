#include <iostream>

using namespace std;

// ham tim uoc so chung lon nhat khong dung de quy 
int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ham tim boi so chung nho nhat khong dung de quy
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

// ham tim uoc so chung lon nhat dung de quy
int GCD_recursion(int a, int b)
{
    if (b == 0) return a;
    return GCD_recursion(b, a % b);
} 

// ham tim boi so chung nho nhat dung de quy  
int LCM_recursion(int a, int b)
{
    static int multiple = 0;

    multiple += b;

    if (multiple % a == 0 && multiple % b == 0)
    {
        return multiple;
    }
    else
    {
        return LCM_recursion(a, b);
    }
}


int main()
{
    int a = 32;
    int b = 24;

    cout << "GCD: " << GCD(a, b) << endl;
    cout << "GCD_recursion: " << GCD_recursion(a, b) << endl;
    cout << "LCM: " << LCM(a, b) << endl;
    cout << "LCM_recursion: " << LCM_recursion(a, b) << endl;

    return 0;
}