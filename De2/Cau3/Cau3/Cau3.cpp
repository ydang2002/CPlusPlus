/*Đọc 1 tập tin có cấu trúc như sau:
+Dòng đầu ghi số n.
+Trong các dòng tiếp theo ghi n số; các số cách nhau ít nhất một khoảng trắng.
a. Tìm giá trị lớn nhất, giá trị lớn thứ k trong dãy.
b. Tìm hai số có khoảng cách xa nhau nhất trong dãy đã cho (khoảng cách của 2 số x và y là |x - y|).
• Kết quả ghi vào file songuyen.out gồm 2 dòng; dòng đầu ghi 2 giá trị, dòng thứ hai ghi một giá trị
tương ứng với yêu cầu bài toán.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#define MIN -10000
using namespace std;

void DocMang(int a[], int& n)
{
    FILE* F = fopen("dayso.txt", "r");
    if (F != NULL)
    {
        
        fscanf(F, "%d", &n);
        cout << n << endl;
        //day cac phan tu trong mang
       //a = new int[n];
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

void TimMAX(FILE* F,int n, int a[])
{
    int Max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > Max)
        {
            Max = a[i];
        }
    }
    cout << "\nMax La:" << Max << endl;
    fprintf(F, "%d  ", Max);
}

void SapXepMangGiamDan(int a[], int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for  (int j = i+1; j <n;  j++)
        {
            if (a[i]<a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void TimPhanTuLonThuK(FILE*F,int a[], int n, int k)
{
    SapXepMangGiamDan(a, n);
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]!=a[i+1])
        {
            dem++;
        }
        if (dem==k)
        {
            cout << "gia tri lon thu k:" << a[i] << endl;
            fprintf(F, "%d  ", a[i]);
        }
    }
}

void TimHaiSoCoKhoangCachXaNhauNhat(FILE*F,int a[], int n)
{
    SapXepMangGiamDan(a, n);
    int phantu1;
    int phantu2;
    for (int i = 0; i < n; i++)
    {
        phantu1=a[0];
        phantu2=a[n-1];
    }
    cout << "\nhai so co khoang cach xa nhau nhat trong day da cho: ";
    cout <<"\n"<< a[0];
    cout << " " << a[n - 1];
    fprintf(F, "\n%d  ", a[0]);
    fprintf(F, "%d\n  ", a[n - 1]);
    fprintf(F, "%d", abs(a[n - 1] - a[0]));
}

int main()
{
    int a[100], n,k;
    cout << "\n nhap vi tri k: ";
    cin >> k;
    DocMang(a, n);
    FILE* F = fopen("ketqua.txt", "w");
    TimMAX(F, n,a);
    TimPhanTuLonThuK(F, a, n, k);
    TimHaiSoCoKhoangCachXaNhauNhat(F,a,n);
    fclose(F);

}