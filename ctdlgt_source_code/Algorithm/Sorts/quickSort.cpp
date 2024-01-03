#include <iostream>

using namespace std;

// time complexity
// best case O(nlogn)
// worst case O(n^2) : when elements in left side of array are sorted
// => put pivot by middle index to reduce time complex to nlogn 
// ramdom quick sort -> chose pivot position ramdomly
// => time complexity: nlogn to n^2

// space: nlogn to n (when worst case -> call n stack)


// Hoare partition scheme
int partition(int* arr, int left, int right)
{
    int pivot = arr[left];
    int i = left + 1;
    int j = right - 1;

    while (i < j)
    {
        // i : leftmost index > pivot
        while (arr[i] <= pivot)
        {
            ++i;
        }
        
        // j : rightmost index < pivot
        while (arr[j] > pivot)
        {
            --j;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[left], arr[j]);
    return j; // now arr[j] is sorted
}

void quickSort(int* arr, int left, int right)
{
    if (left >= right) // invalid or remain 1 element
    {
        return;
    }
    int pi = partition(arr, left, right);
    quickSort(arr, left, pi);
    quickSort(arr, pi + 1, right);
}

int main()
{
    int n = 11;
    int arr[] = {5, 1, 8, 0, 3, 7, 9, 4, 0, 6, 2};
    int left = 0;
    int right = n;
    quickSort(arr, left, right);
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}