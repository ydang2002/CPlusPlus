
#include <iostream>
using namespace std;

void NhapMang(int*& a, int& n)
{
    cout << "\nNhap so luong phan tu:";
    cin >> n;
    a = new int[n];
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

void TimMAX(int *a, int n)
{
    int dem = 0;
    int Max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > Max)
        {
            Max = a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i]==Max)
        {
            dem++;
        }
    }
    cout << "\nMax La:" << Max << endl;
    cout << "\n so luong so bang Max:" << dem;
}

int main()
{
    int* a, n;
    NhapMang(a, n);
    TimMAX(a, n);
    XuatMang(a, n);
}

