/*Cho con trỏ p và mảng a gồm các phần tử là số nguyên
Viết chương trình sử dụng con trỏ tạo và nhập dữ liệu cho mảng a theo cấu trúc
mảng 2 chiều có n dòng và m cột.*/

#include <iostream>
using namespace std;

//Dung con tro de nhap mang hai chieu
void NhapMang(int a[][100],int &n,int &m)
{
    int* p = &a[0][0];
    //p = new int[n * m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "nhap phan tu thu p[" << i << "][" << j << "]: ";
            cin >> *(p + m * i + j);
            //cin >> a[i][j];
        }
    }
}

void XuatMang(/*int* a*/int a[][100], int n, int m)
{
    //int* p = &a[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //cout << *(a + m * i + j);
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    //int a[100][100];
    cout << "nhap n: ";
    cin >> n;
    cout << "nhap m: ";
    cin >> m;
    int  p = new int[n * m];
    NhapMang(p, n, m);
    //uatMang(p, n, m);
}

