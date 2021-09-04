#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void Doc(int a[][100], int& n)
{
    FILE* p = fopen("SQUARE.INP", "r");
    if (p == NULL)
    {
        cout << "khong co tap tin";
    }
    else
    {
        fscanf(p, "%d", &n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fscanf(p, "%d", &a[i][j]);
            }
        }
    }
    fclose(p);
}

//Cong tat ca phan tu tren duong cheo chinh
void TongDuongCheoChinh(FILE* F, int a[][100], int &n)
{
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                tong = tong + a[i][j];
        }
    }
    fprintf(F, "Cau a: %d", tong);
}

//Cong tat ca phan tu tren duong cheo phu
void TongDuongCheoPhu(FILE* F, int a[][100], int& n)
{
    int tong = 0;
    for (int i = 0; i < n; i++) // 2
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
            {
                tong = tong + a[i][j];
            }
        }
    }
    //cout << "tong" << tong;
    fprintf(F, " %d", tong);
}

void TongCacPhanTuThuocTamGiacTren(FILE* F, int a[][100], int& n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                tong =tong + a[i][j];
            }
        }
    }
    //cout << "tong" << tong;
    fprintf(F, "\ncau b: %d", tong);
}

void TongCacPhanTuThuocTamGiacDuoi(FILE* F, int a[][100], int& n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                tong = tong + a[i][j];
            }
        }
    }
    //cout << "tong" << tong;
    fprintf(F, " %d", tong);
}


int main()
{
    int n, a[100][100];

    Doc(a, n);
    FILE* F = fopen("SQUARE.OUT", "w");
    TongDuongCheoChinh(F,a,n);
    TongDuongCheoPhu(F, a, n);
    TongCacPhanTuThuocTamGiacTren(F, a, n);
    TongCacPhanTuThuocTamGiacDuoi(F, a, n);
    fclose(F);
}