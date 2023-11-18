#include <iostream>

using namespace std;

// just use with non-positive elements if use array
// positive -> use map
// n <= 10^7
// O(n + max)

int count[10001] = { 0 }; //10000001

void countingSort(int arr[], int n)
{
    int max = INT_MIN;
    // find max element in arr and counting 
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    //return value from count to arr
    int index = 0; 
    for (int i = 0; i <= max; i++)
    {
        if (count[i] != 0)
        {
            for (int j = 0; j < count[i]; j++)
            {
                arr[index++] = i;
            }
        }
    }
}

int main()
{
    int arr[11] = {5, 1, 8, 0, 3, 7, 9, 4, 0, 6, 2};
    countingSort(arr, 11);
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}