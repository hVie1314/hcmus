#include <iostream>

using namespace std;

// time complexity
// best case O(nlogn)
// worst case O(n^2) : when elements in left side of array are sorted
// => put pivot by middle index to reduce time complex to nlogn 
// ramdom quick sort -> chose pivot position ramdomly
// => time complexity: nlogn to n^2

// space: nlogn to n (when worst case -> call n stack)

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left;
    int j = right;
    
    while (i < j)
    {
        do {
            i++;
        } while (arr[i] <= pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[left], arr[j]);
    return j;
}

void quickSort(int arr[], int left, int right)
{
    if (left >= right) return;
    int j = partition(arr, left, right);
    quickSort(arr, left, j);
    quickSort(arr, j + 1, right);
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