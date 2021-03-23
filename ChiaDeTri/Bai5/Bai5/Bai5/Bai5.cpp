// Bai5.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Chia mảng thành 2 phần. Phần 1 gồm K phần tử và phần thứ 2 gồm n-k phần tử. Di
chuyển phần 1 về sau phần 2 trong mảng, các phần tử trong mỗi phần được giữ
nguyên vị trí.*/

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
}

int ChuyenKPhanTuDauSangCacPhanTuConLai(int a[], int b[], int c[], int k, int l, int r,int n)
{
    if (n < 10)
    {
        return -1;
    }
    else
    {
         ChuyenKPhanTuDauSangCacPhanTuConLai(a, b, c, k, l, k, n);
        for (int i = 0; i < n; i++)
        {
            if (i <= k)
            {
                b[i] = a[i];
            }
        }

         ChuyenKPhanTuDauSangCacPhanTuConLai(a, b, c, k, k + 1, r, n);
        {
            for (int i = k + 1; i < n; i++)
            {
                if (i <= n)
                {
                    c[i] = a[i];
                }
            }
        }



        for (int i = 0; i < n; i++)
        {
            c[i] = b[i];
        }
    }
}


int main()
{
    int n, k;
    int a[100];
    int b[100];
    int c[100];
    cout << " \nnhap n phan tu: ";
    cin >> n;
    cout << "\n nhap k:  ";
    cin >> k;
    int l = 0;
    int r = n-1;
    NhapMang(a, n);
    XuatMang(a, n);
    cout<<"\nket qua"<<ChuyenKPhanTuDauSangCacPhanTuConLai(a,b,c,k,l,r,n);

}


