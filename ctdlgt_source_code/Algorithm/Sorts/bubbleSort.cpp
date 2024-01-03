#include <iostream>

using namespace std;

// O(n^2)
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            //decrease
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) // if no element is swapped by inner loop => array is sorted
        {
            break;
        }
    }
}

int main()
{
    int arr[11] = {5, 1, 8, 0, 3, 7, 9, 4, 0, 6, 2};
    bubbleSort(arr, 11);
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}