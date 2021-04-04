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
    int a[100];
    int max1, max2;
    max1 = max2 = a[0];
    NhapMang(a, n);
    Recursive(a, n, max1, max2);
    cout << max2;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
