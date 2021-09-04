/*Cho mảng hai chiều a có m dòng và n cột (m,n<=200); các phần tử là các số nguyên dương. Tìm
tổng các phần tử trong một mảng con 3 dòng và 3 cột trên a sao cho tổng các số trong mảng con đó là
lớn nhất. Ghi kết quả lên tập tin, dòng 1 ghi tổng của mảng con, dòng kế tiếp ghi mảng con tìm được.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void NhapMang(int a[][100], int& m, int& n)
{
    cout << "\n nhap so dong: ";
    cin >> n;
    cout << "\n nhap so cot: ";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\nNhap phan tu thu[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void XuatMang(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
            cout<<"\t"<< a[i][j];
        }
        cout << endl;
    }
}

//int TinhTong(int a[][100])
//{
//    int tong = 0;
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            tong = tong + a[i][j];   
//        }
//    }
//    return tong;
//}
//
//int tongHCN(int a[100][100], int i, int j) //tâm của HCM
//{
//    int s = 0;
//    s = a[i][j] + a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
//    return s;
//}
//
//int TinhTong3Dong3CotLonNhat(int a[][100], int m, int n)
//{
//    int max = 0;
//    for (int i = 1; i < m-1; i++)
//    {
//        for (int j = 1; j < n-1; j++)
//        {
//            int temp = TinhTong(a);
//            if (temp > max)
//            {
//                max = temp;
//            }
//        }
//    }
//    return max;
//}

int tongHCN(int a[100][100], int i, int j) //tâm của HCM
{
    int s = 0;
    s = a[i][j] + a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
    return s;
}

int timHCNMax(FILE *F,int a[100][100], int m, int n, int& toado_x, int& toado_y)
{
    int max = 0; //vì đề bài cho mảng cố nguyên dương
    for (int i = 1; i < m - 1; i++)
        for (int j = 1; j < n - 1; j++)
        {
            int temp = tongHCN(a, i, j);
            if (temp > max)
            {
                max = temp;
                toado_x = i;
                toado_y = j;
            }

        }
    fprintf(F, "%d  \n", max);
    fprintf(F, "%d  ", a[toado_x - 1][toado_y - 1]);
    fprintf(F, "%d  ", a[toado_x - 1][toado_y]);
    fprintf(F, "%d  ", a[toado_x - 1][toado_y + 1]);
    fprintf(F, "\n%d  ", a[toado_x ][toado_y - 1]);
    fprintf(F, "%d  ", a[toado_x ][toado_y]);
    fprintf(F, "%d  ", a[toado_x ][toado_y + 1]);
    fprintf(F, "\n%d  ", a[toado_x + 1][toado_y - 1]);
    fprintf(F, "%d  ", a[toado_x + 1][toado_y]);
    fprintf(F, "%d  ", a[toado_x + 1][toado_y + 1]);
    return max;
    fclose(F);
}

int main()
{
    int x, y;
    int m, n,c[100], a[100][100];
    NhapMang(a, m, n);
    XuatMang(a, m, n);
    FILE* F = fopen("ketqua.txt", "w");
    cout<< timHCNMax(F,a, m, n,x,y);
    fclose(F);
}

