// Bai3.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void GhiCacdayConTangDan(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i]<=a[i+1])
        {
            cout << a[i];
        }
        else
        {
            cout << a[i] << endl;
        }
    }
    cout << a[n - 1];
}

int main()
{
    int n;
    int a[100];
    cout << "\n nhap so phan tu n:";
    cin >> n;
    NhapMang(a, n);
    GhiCacdayConTangDan(a, n);

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
