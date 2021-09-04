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
        cout <<"\t"<< a[i];
    }
}

int Max(int a[], int n)
{
    if (n == 0)
        return -1;
    if (n == 1)
        return a[0];
    else
    {
        if (a[n - 1] > Max(a, n - 1))
            return a[n - 1];
        else
            return Max(a, n - 1);
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
    cout <<"\n so lon nhat la: "<< Max(a, n);
}