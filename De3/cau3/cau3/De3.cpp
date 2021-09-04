/*vĐọc 1 tập tin có cấu trúc như sau:
+Dòng đầu ghi số n.
+Trong các dòng tiếp theo ghi n số; các số cách nhau ít nhất một khoảng trắng.
a. Tìm tất cả các số nguyên tố và ghi các giá trị tìm được vào tập tin tên “soNT.out”.
b. Xóa phần tử có giá trị k trong mảng.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void DocMang(int a[], int& n)
{
    FILE* F = fopen("dayso.txt", "r");
    if (F != NULL)
    {
        //phan tu dau tien la so phan tu trong mang
        fscanf(F, "%d", &n);
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            fscanf(F, "%d\t", &a[i]);
            cout << "\t" << a[i];
        }
        fclose(F);
    }
    else
    {
        cout << "khong ton tai tap tin";
    }
}


void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

//kiem ta so ngguyen to
bool KiemTraSoNguyenTo(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void GHiSoNguyenToVaoTapTin(FILE*F,int a[], int n)
{
    for (int i = 0; i <n; i++)
    {
        if (KiemTraSoNguyenTo(a[i])==true)
        {
            fprintf(F, "%d\t", a[i]);
        }
    }
}

void xoa1vitrik(int a[], int n)

{

    int k;

    cout<<"\nnhap vi tri can xoa: ";

    cin >> k;

    for (int i = 0; i < n; i++)
    {
        a[k] = a[k + 1];
        n--;
    }
    
}

int main()
{
    int a[100];
    int n;
    DocMang(a, n);
    //XuatMang(a, n);
    /*FILE* F = fopen("soNT.out", "wt");
    GHiSoNguyenToVaoTapTin(F,a, n);
    fclose(F);*/
    xoa1vitrik(a, n);
    XuatMang(a, n);
}