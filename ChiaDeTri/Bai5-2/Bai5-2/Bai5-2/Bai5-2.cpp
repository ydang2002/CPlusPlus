// Bai5-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void nhap_mang(int& n, int a[])
{
    cout << "\nNhap so luong phan tu trong mang: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

void di_chuyen_mang(int n, int k, int p, int a[], int temp[], int& t)
{
    for (int i = p; i < n; i++)
    {
        temp[t++] = a[i];
    }
    for (int i = 0; i <= k; i++)
    {
        temp[t++] = a[i];
    }
}

void xuat_mang(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n, k, a[100], temp[100], t = 0;
    nhap_mang(n, a);
    cout << "\nSo luong phan tu phan 1 cua mang: ";
    cin >> k;
    di_chuyen_mang(n, k, n - k, a, temp, t);
    xuat_mang(t, temp);
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
