#include <iostream>
using namespace std;

// O(nlogn)

void merge(int* arr, int begin, int mid, int end)
{
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;

    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    // asign values for 2 subarrays
    for (int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[begin + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = begin;

    // merge two subarrays 
    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
        }
        else
        {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < leftSize)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < rightSize)
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int* arr, int begin, int end)
{
    if (end <= begin) return;

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int main()
{
    const int n = 11;
    int arr[n] = {5, 1, 8, 0, 3, 7, 9, 4, 0, 6, 2};
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

