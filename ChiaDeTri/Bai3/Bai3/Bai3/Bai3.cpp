// Bai3.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Tìm kiếm phần tử có giá trị X có trong dãy gồm n phần tử có thứ tự và có giá trị là
số nguyên. Nếu tìm thấy trả về giá trị của phần tử có giá trị bằng x, nếu không tìm
thấy trả về -1 ?*/

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

void SapXepMangTangDan(int a[], int n)
{
    int tg;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                // Hoan vi 2 so a[i] va a[j]
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout <<"\t"<< a[i];
    }
}

int TimX(int a[], int n,int left,int right,int x)
{
    


        if (left > right)
        {
            return -1;
        }

        int mid = (left + right) / 2;

        if (x == a[mid])
        {
            return a[mid];
        }
        else if (x < a[mid])
        {
            return TimX(a, n, left, mid + 1, x);
        }
        else if (x > a[mid])
        {
            return TimX(a, n, mid - 1, right, x);
        }

    

    return - 1;
}

int main()
{
    
    int x;
    int n;
    int a[100];
    cout << " \n nhap n phan tu: ";
    cin >> n;
    cout << "\n nhap so x: ";
    cin >> x;
    int left = 0;
    int right = n;
    NhapMang( a,n);
    SapXepMangTangDan(a,n);
    XuatMang(a, n);
    cout <<"ket qua la:"<< TimX(a, n, left, right, x);
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
