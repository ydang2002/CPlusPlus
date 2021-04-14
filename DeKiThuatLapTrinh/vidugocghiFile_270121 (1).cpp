#include <iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#define fi "D:\\mang1chieu.inp"
#define fo "D:\\dayso.out"
#define fi2 "D:\\dayso.inp"

#define max 100
void docMang (int a[max], int&n) ;
void xuatmang(int a[max], int n);
void ghiKetqua(int a[max], int n);
int tinhTong(int a[max], int n);
int timMax(int a[max], int n);
void ghi_bosung(int n);
void sapxeptangdan(int a[max], int n);
void ghiketqua2(int a[max], int n);
void ghiketqua3(int a[max], int n);
void docMang2 (int a[max], int &n);
void sapxepgiamdan(int a[max], int n);
int timGTLonthuK (int a[max], int n, int rank);

int main()
{
    int a,b,c;
    docdulieu (a,b,c);
    cout<<a<<b<<c;

   int a[max],n,k;
    int a[]={5,6,8,12,1,20,100,50};
    Ghimang1chieu(a,8);
   docMang(a,n);
   //sapxeptangdan(a,n);

   xuatmang(a,n);
   sapxepgiamdan(a,n);
   cout<<"moi ban nhap hang phan tu can tim";
   cin>>k;
   cout<<timGTLonthuK (a,n,k);
   ghi_bosung(timGTLonthuK (a,n,k));

  // ghiKetqua(a,n);
  //ghi_bosung(tinhTong(a,n));
   //ghi_bosung(timMax(a,n));
   //ghiketqua3(a,n);
   ghi_bosung(so)
    return 1;
}

void Ghisonguyen (char* tentaptin, int n)
{

	//File phai duoc viet in hoa
	FILE *p=fopen(tentaptin,"a");
	//printf ("Moi ban nhap so n");
	//scanf ("%d",&n);
	fprintf(p,"%d \n",n);
	for(int i=0;i<10;i++)
            fprintf(p,"%d ",i);
	fclose(p);
}

void taomang (int a[], int n)
{
    for (int i=0;i<n;i++)
        a[i]=rand()%100;
}
void Ghimang1chieu(int a[max], int n)
{
	FILE *p=fopen(fi,"wt");
	fprintf(p,"%d\n",n);
	for(int i=0;i<n;i++)
		fprintf (p,"%d ",a[i]);
	fclose(p);
}
void docdulieu (int& a, int& b, int& c) //từ tập tin
{
    FILE* p=fopen(fi,"rt");
    if(p!=NULL)
    {
        // phan tu dau tien la so phan tu cua mang đọc cho n
        fscanf(p,"%d ",&a);
        fscanf(p,"%d ",&b);
        fscanf(p,"%d ",&c);
        fclose(p);
    }
    else cout<<"Khong ton tai tap tin";
}


void docMang (int a[max], int&n) //từ tập tin
{
    FILE* p=fopen(fi,"rt");
    if(p!=NULL)
    {
        // phan tu dau tien la so phan tu cua mang đọc cho n
        fscanf(p,"%d ",&n);
        //đọc các phần tử của mảng
        for(int i=0;i<n;i++)
            fscanf(p,"%d ",&a[i]);
        fclose(p);
    }
    else cout<<"Khong ton tai tap tin";
}
void docMang2chieu (int a[max][max], int& m,int&n) //từ tập tin
{
    FILE* p=fopen(fi,"rt");//int n; n->939495066 giá trị rác
    if(p!=NULL)//p la con tro p ko có địa chỉ hay là nội dung thì p==NULL
    {
        // phan tu dau tien la so phan tu cua mang đọc cho n
        fscanf(p,"%d ",&m);
        fscanf(p,"%d ",&n);
        //đọc các phần tử của mảng
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            fscanf(p,"%d ",&a[i][j]);
        fclose(p);
    }
    else cout<<"Khong ton tai tap tin";
}
void xuatmang(int a[max], int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int tinhTong(int a[max], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum=sum+a[i];
    return sum;
}

int timMax(int a[max], int n)
{
    int maxi=a[0];
    for(int i=1;i<n;i++)
        if(maxi<a[i])
            maxi=a[i];
    return maxi;
}

void ghiKetqua(int a[max], int n)
{
    FILE*p= fopen(fo,"wt");
    fprintf(p,"cau a %d \n", tinhTong(a,n));
    fprintf(p,"cau b %d \n", timMax(a,n));

    fclose(p);
}
void ghi_bosung(int n)
{
    FILE*p= fopen(fo,"a"); //a: append
    fprintf(p,"%d \n", n);

    fclose(p);
}
void sapxeptangdan(int a[max], int n)//O(N2)
{
    for(int i=0; i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i] >a[j])
                swap(a[i],a[j]);
}
void sapxepgiamdan(int a[max], int n) //sort
{
    for(int i=0; i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i] <a[j])
                swap(a[i],a[j]);
}
void ghiketqua2(int a[max], int n) //ghi mảng lên tập tin sort
{
    FILE* p=fopen("D:\\sort.out","wt");
    for (int i=0;i<n;i++)
        fprintf(p,"%d ",a[i]);
    fclose(p);

}
void ghiketqua3(int a[max], int n) //ghi mang da sap xep len tap tin day so dang bo sung
{
    FILE* p=fopen(fo,"a");
    //fprintf(p,"%d ",n);
    for (int i=0;i<n;i++)
        fprintf(p,"%d ",a[i]);
    fclose(p);

}

void docMang2 (int a[max], int &n)//doc 1 day so va gan vao mang, khong biet truoc so phan tu
{
    int i=0;

    FILE* p=fopen("D://sort.out","rt");
    if(p!=NULL)
    {
        while(!feof(p))
            {
                fscanf(p,"%d ",&a[i]);
                i++;
            }
        fclose(p);
        n=i;
    }
    else cout<<"Khong ton tai tap tin";
}

//void timGTlonthu2 (int a[max], int n, int&max1, int& max2)
void timGTlonthu2 (int a[max], int n) //sau khi co gia tri thi ghi len tap tin
{
    int max1, max2;
    if(a[0]>a[1])
    {
        max1=a[0];
        max2=a[1];
    }
    else
    {
        max2=a[0];
        max1=a[1];
    }

    for(int i=2;i<n;i++)
    {
        if(a[i]>max1)
        {
            max1=a[i];
            max2=max1;
        }
        else if(a[i]>max2)
        {
            max2=a[i];
        }
    }
    FILE*p= fopen(fo,"w"); //a: append a,w deu duoc, a khong ro y nghia
    fprintf(p,"%d \n", max1);
    fprintf(p,"%d \n", max2);
    fclose(p);


}
//de cuat cua ban nghia

void ghifile(int a[], int n)
{
	g = fopen("D:\\BT1.txt","wt");
	solonnhat(a,n);
	fclose(g);
}
//het phan bai cua ban Nghia
int timGTLonthuK (int a[max], int n, int rank)// da co thu tu roi
{
    int count=1;
    if(rank==1)
        //ghi ket qua
        return a[0];
    for(int i=0;i<n-1;i++)   //20 20 19 19 18 9 8 6
    {
        if(a[i]!=a[i+1])
            count++;
            if(count==rank)
            {
                //hoac ghi tai day
                return a[i+1];
            }
    }
    //ghi nhan ket qua ?
    //return rồi nên không ghi được


    return 0; //khong ton tai hang theo yeu cau
}
void GhifileVB()
{
	FILE* p=fopen("Baitho.txt","wt");
	fputs("Em oi doi anh ve",p); //con tro se nam tai cuoi dong hien tai
	fputs("\n",p);
	fputs("Doi anh hoai em nhe",p);
	fputs("\n",p);
	fputs("Mua co roi dam de",p);
	fputs("\n",p);
	fputs("Ngay co dai le the",p);
	fclose(p);
}
