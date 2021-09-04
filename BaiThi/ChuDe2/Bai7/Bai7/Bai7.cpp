#include <iostream>
using namespace std;

void NhapMang(int*& a, int& m, int& n)
{
    cout << " nhap vao so dong: ";
    cin >> m;
    cout << " nhap vao so cot: ";
    cin >> n;
    a = new int[m * n];
    for (int i = 0; i < m; i++)
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
    
}

int TinhTong(int* a, int m, int n)
{
    int s = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s = s + *(a + n * i + j);
        }
    }
    return s;
}

int main()
{
    int n, m, * a;
    NhapMang(a, m, n);
    cout<<"\n tong la: "<<TinhTong(a, m, n);
}
