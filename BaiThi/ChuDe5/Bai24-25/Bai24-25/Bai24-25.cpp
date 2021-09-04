#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct phanso
{
    float tu;
    float mau;
};

void DocFILE(int& n,phanso ps[])
{
    FILE* p = fopen("fraction.inp", "r");
    if (p == NULL)
    {
        cout << "khong co tap tin";
    }
    else
    {
        fscanf(p, "%d", &n);
        for (int i = 0; i < n; i++)
        {
            fscanf(p, "%f", &ps[i].tu);
            fscanf(p, "%f", &ps[i].mau);
        }
        fclose(p);
    }
    fclose(p);
}

void bai24(FILE* F, int n, phanso ps[])
{
    phanso temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ps[i].tu / ps[i].mau > ps[j].tu / ps[j].mau)
            {
                temp = ps[i];
                ps[i] = ps[j];
                ps[j] = temp;
            }
        }  
    }  
    fputs("\nBai 24: ", F);
    for (int i = 0; i < n; i++)
    {
        fprintf(F, " %.0f/%.0f ", ps[i].tu, ps[i].mau);
    }
}

/*void xuatphanso(phanso ps)
{
    printf("Phan so: %d / %d", ps.tu, ps.mau);
}*/

// bai 25
int UCLN(int a, int b)
{
    while (a != 0 && b != 0)
        if (a > b)
            a = a % b;
        else
            b = b % a;
    return a + b;
}
phanso bai25(FILE* F,phanso ps[], int n)
{
    phanso sum = ps[0];
    for (int i = 1; i < n; i++)
    {
        sum.tu = sum.tu * ps[i].mau + sum.mau * ps[i].tu;
        sum.mau = sum.mau * ps[i].mau;
    }
    int UC = UCLN(sum.tu, sum.mau);
    sum.tu = sum.tu / UC;
    sum.mau = sum.mau / UC;
    fputs("\nBai 25: ", F);
    fprintf(F, "%.0f/%.0f ", sum.tu, sum.mau);
    return sum;
    
}



int main()
{
    int n;
    phanso ps[100];

    DocFILE(n,ps);
    FILE* F = fopen("fraction.out", "w");
    bai24(F,n,ps);
    bai25(F, ps, n);
    //phanso sum = bai25(F,ps, n);
    //xuatphanso(sum);
    fclose(F);
}