#include <iostream>

using namespace std;

int linearExhaustiveSearch(int arr[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key) return i;
	}
	return -1;
}

int linearSentinelSearch(int arr[], int n, int key)
{
	// set the last element to sentinel 
	int lastEle = arr[n - 1];
	arr[n - 1] = key;
	int i = 0;
	while (arr[i] != key)
	{
		i++;
	}
	arr[n - 1] = lastEle;
	if (i < n - 1 || arr[n - 1] == key)
	{
		return i;
	}
	return -1;
}

int main()
{

	return 0;
}