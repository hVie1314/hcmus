#include <iostream>

using namespace std;

// O(n^2)
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int j = i - 1;
        int data = arr[i];
        while (j >= 0 && data < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = data;
    }
}

int main()
{
    int arr[11] = {5, 1, 8, 0, 3, 7, 9, 4, 0, 6, 2};
    insertionSort(arr, 11);
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}