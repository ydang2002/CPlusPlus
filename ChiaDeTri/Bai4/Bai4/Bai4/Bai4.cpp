// Bai4.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Tìm phần tử có giá trị lớn nhất và phần tử có giá trị nhỏ nhất trong dãy gồm n phần
tử có giá trị nguyên.*/

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

void TimMinMax(int a[], int dau, int cuoi, int &min, int &max)
{
    int min1 = 0, min2 = 0, max1 = 0, max2 = 0;

    if (dau==cuoi)
    {
        min = a[dau];
        max = a[cuoi];
    }
    else
    {
        TimMinMax(a,dau, (dau + cuoi) / 2, min1, max1);
        TimMinMax(a, (dau + cuoi) / 2 + 1, cuoi, min2, max2);
        
        min = min1 < min2 ? min1 : min2;
        max = max1 > max2 ? max1 : max2;
    }
}

int main()
{
    int n;
    int a[100];
    cout << "\n nhap so phan tu: ";
    cin >> n;
    int dau = 0;
    int cuoi = n - 1;
    int min = 0;
    int max = 0;
    NhapMang(a, n);
    XuatMang(a, n);
    cout << "\n ket qua la: ";
    TimMinMax(a, dau, cuoi, min, max);
    cout << " min: " << min;
    cout << " max: " << max;
    return 0;
}
