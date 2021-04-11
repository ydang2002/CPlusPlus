//tím giá trị lon nhất trong mảng 2 chiều sử dụng cấp phát động

#include <iostream>
using namespace std;

void NhapMang(int*& a, int& m, int& n)
{
    cout << " nhap vao so dong: ";
    cin >> m;
    cout << " nhap vao so cot: ";
    cin >> n;
    a = new int[m * n];
    for (int  i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " phan tu thu a[" << i << "]" << "[" << j << "]: ";
            cin >> *(a + n * i + j);
        }
    }
}

void XuatNang(int* a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n ;j++)
        {
            cout << *(a + n * i + j) << " ";
        }
        cout << endl;
    }
}

int TimMax(int* a, int m, int n)
{
    int Max = *a;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Max<*(a+n*i+j))
            {
                Max = *(a+n*i+j);
            }
        }
    }
    return Max;
}

int main()
{
    int n,m, *a;
    NhapMang(a, m, n);
    XuatNang(a, m, n);
    cout << " max: " << TimMax(a, m, n);
}

