#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Huyền; Y
double X(int n);
double Y(int n);
double X(int n)
{
    if(n == 0)
        return 1;
    else
        return X(n-1)/(3*1.0) + Y(n-1)/(2*1.0) +5;
}

double Y(int n)
{
    if(n == 0)
        return 2;
    else
        return X(n-1)/(2*1.0) + Y(n-1)/(3*1.0) +6;
}

void doctaptin ()
{
    char*s=new char[300];
    FILE* f=fopen("chuoi.inp","rt");
    if(f!=NULL)
    {
        while(!feof(f))
        {
            fgets(s,100,f);
            //làm gì
            //ví dụ in ra màn i=hình
            puts(s);
        }
        fclose(f);
    }
    else{
        cout<<"khong tim thy tap tin";
    }
}

int sotucoKkt (char* s, int k)
{
    int dem=0;
    //strcat(s," "); //cách 1 xử lý thêm 1 khoảng trắng vào sau chuỗi s
    char* vtdau=s;
    char* vitriKT= strchr(s,' ');//tim thay 1 tu được ghi lại là vị trí khảng trắng
    while(vitriKT!=NULL)
    {
        int sokitu=vitriKT-vtdau;
        if(sokitu==k)
            dem++;
        vtdau = vitriKT+1;//vị trí đầu cập nhật bằng vị trí khoảng trắng +1
        vitriKT= strchr(vitriKT+1,' ');//tìm khoảng trắng kế tiếp
    }

        if(strlen(vtdau)==k)
        dem++;

    return dem;
}

int sotucoKkt_2(char *s, int k)
{
	int dem=0;
	int sokytumoitu=0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != ' ')
            sokytumoitu++;
        else
        {
            //cout<<sokytumoitu<<" ";
            if (sokytumoitu == k)
                dem++;
            sokytumoitu = 0;
        }

    }
    return dem;

}
//Lê Ngô Hậu
char* laykKT(char* s,int k)
{
    char* s2=new char[k+1];//co ki tu ket thuc chuoi
    for(int i=0;i<k;i++)
    {
        s2[i]=s[i];
    }
    return s2;
}
//lấy chuỗi gồm k từ bên trái trong s
char* tachKtu (char* s)
{
    char* s1=new char[100];
    strcpy (s1,s);

}

char* layKtu(char* s,int k)
{
    char* s2=new char[strlen(s)+1];
    char* temp;
    int wordcount=1;
    strcpy(s2,s);
    temp=strchr(s2,' ');//giả thiết đề bài luôn khác NULL
    while(temp!=NULL&&wordcount<k)
    {
        wordcount++;
        temp=strchr(temp+1,' ');
    }
    if(wordcount<k)
    {
        printf("chuoi khong du k tu\n");
    }
    else
    {
        *(temp)='\0';
    }
    return s2;
}
void Read_Array (int a[], int &n)
{
    FILE* p = fopen("input_ot2.txt", "rt");
    if(p == NULL)
        cout<<"ko tim dc file";
    else
    {
        fscanf(p, "%d", &n);
        for(int i = 0; i < n; i++)
            fscanf(p, "%d", &a[i]);
    }
    fclose(p);
}
//Y Dang Huynh Nhu
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
//b.	Tìm hai số có khoảng cách xa nhau nhất trong dãy đã cho
//(khoảng cách của 2 số x và y là |x - y|).

void maxdistance(FILE* F,int a[],int n) //mảng đã có thứ tự
{
    fprintf(F,"%d ",a[0]);
    fprintf(F,"%d\n",a[n-1]);
    fprintf(F,"%d",abs(a[n-1]-a[0]));
}
/*
Cho mảng hai chiều a có m dòng và n cột (m,n<=200);
các phần tử là các số nguyên dương.
Tìm tổng các phần tử trong một mảng con 3 dòng và 3 cột
trên a sao cho tổng các số trong mảng con đó là lớn nhất.
Ghi kết quả lên tập tin,
dòng 1 ghi tổng của mảng con, dòng kế tiếp ghi mảng con tìm được.
*/
int tongHCN (int a[100][100], int i, int j) //tâm của HCM
{
    int s=0;
    s=a[i][j]+a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
    return s;
}

int timHCNMax (int a[100][100],int dong, int cot, int &toado_x, int &toado_y)
{
    int max=0; //vì đề bài cho mảng cố nguyên dương
    for(int i=1;i<dong-1;i++)
         for(int j=1;j<cot-1;j++)
        {
            int temp=tongHCN(a,i,j);
            if(temp>max)
            {
                max=temp;
                toado_x=i;
                toado_y=j;
            }

        }
     fprintf(F, "%d  \n", max);
     fprintf(F, "%d  ", a[toado_x-1][toado_y-1]);
     fprintf(F, "%d  ", a[toado_x-1][toado_y]);
     fprintf(F, "%d  ", a[toado_x-1][toado_y+1]);
     fprintf(F, "  \n");

    return max;
}
int main()
{
    char s[100]="Xin chao cac ban than men";
    //puts(laykKT(s,10));
    puts(layKtu(s,8));
    //bài 3
    int a[100];
    int n;
     Read_Array (a,n);
     SapXepMangGiamDan(a,n);
     FILE* F = fopen("ketqua.txt", "w");
     TimPhanTuLonThuK(F,a,n,k);
     fclose(F);
    return 1;
}
