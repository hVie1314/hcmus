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

int* inputArr(int &n)
{
    cin >> n;
    int* arr = createArr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

int findMax(int* arr, int n)
{
    int max = INT64_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int n = 0;
    int* arr = inputArr(n);
    int max = findMax(arr, n);
    cout << max << endl;

    delArr(arr);
    return 0;
}