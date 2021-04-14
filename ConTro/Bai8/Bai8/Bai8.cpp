/*Viết chương trình nhập mảng hai chiều a có m dòng n cột, các phần tử là các số
nguyên và một số nguyên x.
a. Hãy đếm xem trong mảng có bao nhiêu số bằng x.
b. Cho biết vị trí của các phần tử bằng x.*/

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
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(a + n * i + j) << " ";
        }
        cout << endl;
    }
}

int DemSoBangX(int* a, int m, int n,int x)
{
   int dem = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(a + n * i + j) == x)
            {
                dem++;
            }
        }
    }
    return dem;
}

void ViTriPhanTuBangX(int* a, int m, int n, int x)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(a + n * i + j) == x)
            {
                cout << "a[" << i << "][" << j << "] " << " ";
            }
        }
    }
}

int main()
{
    int n, m, * a;
    int x;
    cout << " moi nnhap x: ";
    cin >> x;
    NhapMang(a, m, n);
    XuatNang(a, m, n);
    cout<<DemSoBangX(a, m, n, x)<<"\n";
    ViTriPhanTuBangX(a, m, n, x);
}
