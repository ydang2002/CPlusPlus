#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void Doc(int a[][100], int& m, int& n)
{
    FILE* p = fopen("TABLE.INP", "r");
    if (p == NULL)
    {
        cout << "khong co tap tin";
    }
    else
    {
        fscanf(p, "%d", &m);
        fscanf(p, "%d", &n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fscanf(p, "%d", &a[i][j]);
            }
        }
        fclose(p);
    }
}


void TongDong(FILE* F, int a[][100], int m, int n)
{
    fprintf(F, "Bai 19: ");
    for (int i = 0; i < m; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s = s + a[i][j];
        }
        fprintf(F, " %d", s);
    }
}

void TongCot(FILE* F, int a[][100], int m, int n)
{
    fprintf(F, "\n       :");
    for (int j = 0; j < n; j++)
    {
        int s = 0;
        for (int i = 0; i < m; i++)
        {
            s = s + a[i][j];
        }
        fprintf(F, " %d", s);
    }
}

void Tim(FILE* F, int a[][100], int m, int n, int e[])
{
    int max = 0;
    //fprintf(F, "Bai 19: ");
    for (int i = 0; i < m; i++)
    {
        int min = a[i][0];
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
                e[i] = min;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (e[i] > max)
        {
            max = e[i];
        }
    }
    cout << "\nmax: " << max;
    fprintf(F, "\nBai 20:  %d", max);
}

void SapXep(FILE* F, int a[][100], int m, int n)
{
    for (int k = 0; k < m; k++)
        for (int i = 0; i < n - 1; i++)
            for (int j = n - 1; j > i; j--)
                if (a[k][j] < a[k][j - 1])
                {
                    int temp = a[k][j];
                    a[k][j] = a[k][j - 1];
                    a[k][j - 1] = temp;
                }
}

void XuatMang(int a[][100], int m, int n)
{
    cout << endl << "Xuat mang" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "\t" << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void XuatMaTran(FILE* F, int a[][100], int m, int n)
{
    fprintf(F, "\nBai 21: ");
    for (int i = 0; i < m; i++)
    {
        fprintf(F, "\n");
        for (int j = 0; j < n; j++)
            fprintf(F, "\t%d", a[i][j]);
    }

}

//Tính tổng của các chữ số của một số tự nhiên n.
int Tinh(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return Tinh(n / 10) + n % 10;
    }
}
//cau22
void TinhTong(FILE* F, int a[][100], int m, int n)
{
    int tong = 0;
    for (int i = 0; i < m; i++)
    {
        int temp;
        for (int j = 0; j < n; j++)
        {
            temp = Tinh(a[i][j]);
            tong = tong + temp;
            //cout <<"\t"<< temp;
        }
    }
    cout << "\nKet qua: " << tong;
    fprintf(F, "\nBai 22:  %d", tong);
}

int main()
{
    int m, n, c[100], d[100], a[100][100];

    Doc(a, m, n);
    FILE* F = fopen("TABLE.OUT", "w");
    TongDong(F, a, m, n);
    TongCot(F, a, m, n);
    Tim(F, a, m, n, c);
    SapXep(F, a, m, n);
    XuatMaTran(F, a, m, n);
    TinhTong(F, a, m, n);
    fclose(F);
}

