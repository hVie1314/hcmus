#include <iostream>

using namespace std;

int* createArr(int n)
{
    int* arr = new int[n];
    if (!arr) return nullptr;
    return arr;
}

void delArr(int* arr)
{
    if (arr == nullptr) return;
    delete[] arr;
    arr = nullptr;
}

void inputArr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void outputArr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void mergeArr(int* c, int lenghtC, int* a, int lengthA, int* b,  int lengthB)
{
    int iA = 0;
    int iB = 0;
    int iC = 0;

    while (iA < lengthA && iB < lengthB)
    {
        c[iC++] = a[iA++];
        c[iC++] = a[iB++];
    }
    while (iA < lengthA)
    {
        c[iC++] = a[iA++];
    }
    while (iB < lengthB)
    {
        c[iC++] = b[iB++];
    }
}

int main()
{
    int lengthA = 0;
    int lengthB = 0;
    cout << "Nhap so luong phan tu cua mang a: "; cin >> lengthA;
    int* a = createArr(lengthA);
    cout << "Nhap cac phan tu cua mang a: ";
    inputArr(a, lengthA);
    cout << "Nhap so luong phan tu cua mang b: "; cin >> lengthB;
    int* b = createArr(lengthB);
    cout << "Nhap cac phan tu cua mang b: ";
    inputArr(b, lengthB);

    int lengthC = lengthA + lengthB;
    int* c = createArr(lengthC);
    mergeArr(c, lengthC, a, lengthA, b, lengthB);

    outputArr(c, lengthC);

    delArr(a);
    delArr(b);
    delArr(c);
    return 0;
}