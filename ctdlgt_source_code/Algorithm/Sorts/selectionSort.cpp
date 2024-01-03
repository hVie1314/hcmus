#include <iostream>

using namespace std;

// O(n^2)
//version 1
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        //decrease 
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

//version 2
// void selectionSort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 swap(arr[i], arr[j]);
//             }
//         }
//     }
// }s

int main()
{
    int arr[11] = {5, 1, 8, 0, 3, 7, 9, 4, 0, 6, 2};
    selectionSort(arr, 11);
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}


