// Cau1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int TinhAn(int n)
{
    if (n <= 3)
    {
        return n;
    }
    else
    {
        return 24 * TinhAn(n - 1) + 25 * TinhAn(n - 2) + 10 * TinhAn(n - 3) + 2018;
    }
}

int TinhAnKhongDeQuy(int n)
{
    int A1 = 1;
    int A2 = 2;
    int A3 = 3;
    int k;
    if (n <= 3)
    {
        return n;
    }
    else
    {
        for (int i = 4; i <= n; i++)
        {
            k = 24 * A3 + 25 * A2 + 10 * A1 + 2018;
            A1 = A2;
            A2 = A3;
            A3 = k;
        }
        return k;
    }
}


int main()
{
    int n;
    cout << "\nNhap n: ";
    cin >> n;

    cout << TinhAnKhongDeQuy(n);
}

