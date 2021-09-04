
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

void DocMang(int a[], int& n, int &m)
{
    FILE* F = fopen("NUM.INP", "r");
    if (F != NULL)
    {

        fscanf(F, "%d", &n);
        fscanf(F, "%d", &m);
        cout << n << endl;
        cout << m << endl;
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
float TinhTrungBinhCong(FILE* F, int a[], int n)
{
    float tbc;
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong = tong + a[i];
    }
    tbc = (float)tong / n;
    fprintf(F, "Bai 14: %f ", tbc);
    return tbc;
}

int KTSoNguyenTo(int n)
{
    if (n<2)
    {
        return 0;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int DemSoNguyenTo(FILE* F, int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (KTSoNguyenTo(a[i])==1)
        {
            dem++;
        }
    }
    fprintf(F, "\nBai 15: %d ",dem);
    //cout <<"ket qua: "<< dem;
    return dem;
}

int KTSoChinhPhuong(int n)
{
    if (n<1)
    {
        return 0;
    }
        if (sqrt(n)*sqrt(n)==n)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

int DemSoChinhPhuong(FILE* F, int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (KTSoChinhPhuong(a[i])==1)
        {
            dem++;
        }
    }
    fprintf(F, " %d ", dem);
    return dem;
}

bool KTSoHoanChinh(int n)
{
    int sum = 0;//khai bao biem sum
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n)
    {
        return true; // tra ve true
    }
    else
    {
        return false;
    }
}

int DemSoHoanHao(FILE* F, int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (KTSoHoanChinh(a[i])==true)
        {
            dem++;
        }
    }
    fprintf(F, " %d ", dem);
    return dem;
}
   
int DemCapSoTongbangM(FILE* F, int a[], int n,int m)
{
    int dem = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i]+a[j]==m)
            {
                dem++;
            }
        }
    }
    fprintf(F, "\nBai16: %d ", dem);
    return dem;
}

int DemSoPhanTuTangLientiep(FILE* F, int a[], int n)
{
    int max = 1, phantu = 1;
    for (int i = 0; i < n-1; i++)
    {
        if (a[i]<a[i+1])
        {
            phantu ++;
        }
        else
        {
            if (phantu>max)
            {
                max = phantu;
            }
            phantu = 1;
        }
    }
    if (phantu>max)
    {
        return max;
    }
    fprintf(F, "\nBai17: %d ", max);
}

void HoanVi(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

void SapXepTangDan(FILE* F, int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i]>a[j])
            {
                HoanVi(a[i], a[j]);
            }
        }
    }
    fprintf(F, "\nBai18:");
    for (int i = 0; i < n; i++)
    {
        fprintf(F, " %d ", a[i]);
    }
    
}

int main()
{
    int a[100], n, m;
    DocMang(a, n,m);
    
    FILE* F = fopen("NUM.OUT", "w");
    TinhTrungBinhCong(F, a, n);
    DemSoNguyenTo(F, a, n);
    DemSoChinhPhuong(F, a, n);
    DemSoHoanHao(F, a, n);
    DemCapSoTongbangM(F, a, n,m);
    DemSoPhanTuTangLientiep(F, a, n);
    SapXepTangDan(F, a, n);
    fclose(F);
}

