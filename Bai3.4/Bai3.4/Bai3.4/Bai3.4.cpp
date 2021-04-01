// Bai3.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


void DocMang(int a[], int &n)
{
    FILE* p = fopen("dayso.txt", "rt");
    if (p!=NULL)
    {
        fscanf(p, "%d", &n);
        for (int i = 0; i <n; i++)
        {
            fscanf(p, "%d", &a[i]);
        }
        fclose(p);
    }
    else
    {
        cout << "Khong ton tai tap tin";
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void GhiCacDayConTangDan(FILE*p,int a[], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= a[i+1])
        {
            cout << a[i];
            fprintf(p, "%d", a[i]);
        }
        else
        {
            cout << a[i] << endl;
            fprintf(p, "%d\n", a[i]);
            
        }
    }
    //cout << a[n - 1];
    //fprintf(p, "%d", a[n - 1]);
    
}

int main()
{
    int a[100];
    int n;
    DocMang(a, n);
    XuatMang(a, n);
    FILE* p = fopen("ketqua.txt", "wt");
    GhiCacDayConTangDan(p,a, n);
    fclose(p);
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
