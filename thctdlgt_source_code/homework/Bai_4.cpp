#include <iostream>

using namespace std;

int* createArr(int n)
{
    int* arr = new int[n];
    if (!arr) return nullptr;
    return arr;
}

void delArr(int*& arr)
{
    if (arr == nullptr) return;
    delete[] arr;
    arr = nullptr;
}

int* inputArr(int n)
{
    int* arr = createArr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

void outputArr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 5;
    int* arr = inputArr(n);
    outputArr(arr, n);

    delArr(arr);
    return 0;
}