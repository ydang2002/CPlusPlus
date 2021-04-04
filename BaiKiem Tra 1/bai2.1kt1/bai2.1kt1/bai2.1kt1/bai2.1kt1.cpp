// bai2.1kt1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n phan tu thu a[" << i << "]:";
        cin >> a[i];
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\t " << a[i];
    }
}


void FindMax2(int m, int& max1, int& max2)
{
    if (m > max1)
    {
        max2 = max1;
        max1 = m;
    }
    else if (m > max2)
    {
        max2 = m;
    }
}

void Recursive(int a[], int n, int& max1, int& max2)
{
    if (n == 2)
    {
        max1 = max2 = a[0];
        FindMax2(a[n - 1], max1, max2);
    }
    else
    {
        Recursive(a, n - 1, max1, max2);
        FindMax2(a[n - 1], max1, max2);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[100];
    int max1, max2;
    max1 = max2 = a[0];
    NhapMang(a, n);
    Recursive(a, n, max1, max2);
    cout << max2;
}

