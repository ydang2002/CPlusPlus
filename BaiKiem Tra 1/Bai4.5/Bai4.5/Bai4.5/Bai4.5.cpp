// Bai4.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    cout << endl;
}


void TimMaxSecond(int a[], int dau, int cuoi, int& max, int& maxSecond, int n)
{
    // Truong hop tat ca phan tu deu bang nhau?
    if (n < 2)
    {
        maxSecond = -1;
        return;
    }

    int max1 = 0, maxSecond1 = 0, max2 = 0, maxSecond2 = 0;

    if (dau == cuoi)
    {
        max = a[dau];
        maxSecond = a[dau];
    }
    else
    {
        TimMaxSecond(a, dau, (dau + cuoi) / 2, max1, maxSecond1, n);
        TimMaxSecond(a, (dau + cuoi) / 2 + 1, cuoi, max2, maxSecond2, n);
        
        if (max1 > max2)
        {
            max = max1;
            if (dau == cuoi)
            {
            maxSecond = max2;

            }                                                                                                                                        
            else {

            if (maxSecond1 > max2)
            {
                maxSecond = maxSecond1;
            }
            else
            {
                maxSecond = max2;
            }
			}
        }
        else 
        {
            max = max2;
            if (dau == cuoi)
            {
                maxSecond = max1;
                
            }
            else {
                if (maxSecond2 > max1)
                {
                    maxSecond = maxSecond2;
                }
                else
                {
                    maxSecond = max1;
                }
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
    TimMaxSecond(a, dau, cuoi, max1, max2, n);
    cout << "max2: " << max2;
    return 0;
}
