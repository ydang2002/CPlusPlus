#include<stdio.h>
#include<iostream>
using namespace std;

void docmang2chieu(int a[][100],int &dong,int &cot);
void xuat(int a[][100], int dong, int cot);
int tinhtong(int a[][100], int dong, int cot);
void tinhtongmoidongc3(int a[][100], int dong, int&cot);
void tinhtongmoidongc2(int a[][100], int dong, int cot);

int main()
{
    int dong,cot;
    int a[100][100];
    docmang2chieu(a,dong,cot);
    tinhtongmoidongc3(a,dong,cot);
    xuat(a,dong,cot);
    return 0;
}
/*
void docmang(char a[],int &n)
{
    int i;
    i=0;
    FILE *p = fopen("C:\Users\USER\Desktop\input.txt");
    while(!feof(p))
    {
        fscanf(p,"%c",&a[i]);
        i++;
    }
    n=i+1;
    fclose(p);
}

void ghimang(char a[],int n)
{
    int i;
    FILE *p = fopen("C:\Users\USER\Desktop\output.txt")
    for(i=0;i<n;i++)
    {
        fprintf(p,"%c",a[i]);
    }
}*/

void docmang2chieu(int a[][100],int &dong, int &cot)
{
    FILE* p;
    p=fopen("E:\\bangso.inp","rt");
    if(p!=NULL)
    {
        fscanf(p,"%d",&dong);
        fscanf(p,"%d",&cot);
        for(int i=0;i<dong;i++)
        {
            for(int j=0;j<cot;j++)
            {
                fscanf(p,"%d",&a[i][j]);
            }
        }

    }
    else
    {
        cout<<"khong ton tai tap tin";
    }
    fclose(p);
}

void xuat(int a[][100], int dong, int cot)
{
    for(int i=0;i<dong;i++)
        {
            for(int j=0;j<cot;j++)
            {
                cout<<" "<<a[i][j];
            }
            cout<<endl;
        }
}

int tinhtong(int a[][100], int dong, int cot)
{
    int S=0;
    for(int i=0;i<dong;i++)
        {
            for(int j=0;j<cot;j++)
            {
                S=S+a[i][j];
            }
        }
    return S;
}

void tinhtongmoidong(int a[][100], int dong, int cot)
{
    FILE *p=fopen("E:\\ketqua.out","wt");
    for(int i=0;i<dong;i++)
        {
            int S=0;
            for(int j=0;j<cot;j++)
            {
                S=S+a[i][j];
            }
            fprintf(p,"%d ", S);
        }
        fclose(p);
}

void tinhtongmoidongc2(int a[][100], int dong, int cot)
{
    int tongdong[dong];
    for(int k=0;k<dong;k++)
    {
        tongdong[k]=0;
    }
    for(int i=0;i<dong;i++)
        {
            for(int j=0;j<cot;j++)
            {
                tongdong[i]=tongdong[i]+a[i][j];
            }

        }
}

 void tinhtongmoidongc3(int a[][100], int dong, int&cot)
{
   cot=cot+1;
    for(int i=0;i<dong;i++)
        {
            int S=0;
            for(int j=0;j<cot-1;j++)
            {
                S=S+a[i][j];
            }
            a[i][cot-1]=S;
        }
}
