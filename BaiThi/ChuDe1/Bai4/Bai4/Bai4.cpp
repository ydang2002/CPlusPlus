// Bai4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhap phan tu a[" << i << "]:";
        cin >> a[i];
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << a[i];
    }
}

int KTsoNguyenTo(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i <= sqrt((float)n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int DemSoNguyenTo(int a[], int n)
{
    if (n<1)
    {
        return 0;
    }
    else
    {
        if (KTsoNguyenTo(a[n - 1]) == 1) 
        return 1 + DemSoNguyenTo(a, n - 1);
        return DemSoNguyenTo(a, n - 1);
    }
}

int main()
{
    int n;
    int a[100];
    cout << "NHAP N: ";
    cin >> n;
    NhapMang(a, n);
    XuatMang(a, n);
    cout << "\n so lương so nguyên to: " << DemSoNguyenTo(a, n);
}

