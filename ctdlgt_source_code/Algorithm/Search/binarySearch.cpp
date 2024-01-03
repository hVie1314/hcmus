#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int key)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2; // left + (right - left) / 2
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (key < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	} 
	return -1;
}

int binarySearchRecursion(int arr[], int left, int right, int key)
{
	if (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (key < arr[mid])
		{
			return binarySearchRecursion(arr, left, mid + 1, key);
		}
		else
		{
			return binarySearchRecursion(arr, mid + 1, right, key);
		}
		return -1;
	}
}

int main()
{

	return 0;
}