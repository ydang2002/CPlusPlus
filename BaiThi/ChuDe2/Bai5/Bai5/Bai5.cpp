#include <iostream>
using namespace std;

void NhapMang(int *&a, int &n)
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

void XoaPhanTuP(int*& a, int n)
{
    int p;
    cout << "\nXoa phan tu thu: ";
    cin >> p;
    for (int i = p; i < n-1; i++)
    {
        a[i] = a[i + 1];
    }
    n = n - 1;
}

int main()
{
    int* a, n;
    NhapMang(a, n);
    XoaPhanTuP(a, n);
    XuatMang(a, n);
}


