// Bai4.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void TimMinMax(int a[], int dau, int cuoi, int& max1, int& max2,int n)
{
    int max11 = 0, max12 = 0, max21 = 0, max22 = 0;

    if (dau == cuoi)
    {
        max1 = a[dau];
        max2 = a[cuoi];
    }
    else
    {
        TimMinMax(a, dau, (dau + cuoi) / 2, max11,max21,n);
        TimMinMax(a, (dau + cuoi) / 2 + 1, cuoi, max21, max22,n);

        //min = min1 < min2 ? min1 : min2;
        //max = max1 > max2 ? max1 : max2;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max1)
            {
                max2 = max1;
                max1 = a[i];
            }
            else  if(a[i]>max2 && a[i]<max1)
            {
                max2 = a[i];
            }
        }
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
    int max1 = 0;
    int max2 = 0;
    NhapMang(a, n);
    XuatMang(a, n);
    cout << "\n ket qua la: ";
    TimMinMax(a, dau, cuoi, max1, max2,n);
    cout << " max1: " << max1;
    cout << " max2: " << max2;
    return 0;
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
