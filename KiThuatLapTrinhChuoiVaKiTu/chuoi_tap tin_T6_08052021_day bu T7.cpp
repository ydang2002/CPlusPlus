#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>

void doctaptin (char* tentaptin)
{
    //bien s nhan 1 chuoi co kich thuoc toi da 100 ki tu tu tap tin
    //hoac 1 dong trong tap tin (den khi xuong hang)
    char* s=new char[300];
    FILE* f=fopen (tentaptin,"rt");
    if(f!=NULL)
    {
        while(!feof(f))// khi tap tin chua ket thuc
        {
            fgets(s,300,f);
            puts("===het 1 lan fgets ===xuong hang");
            puts(s);
        }

        fclose(f);
    }
    else{
        cout<<"khong tim thay tap tin";
    }

}
//trong truong hop có 1 đoan trong vb, sau khi đọc chúng ta nhận được chuỗi đó
char* doctaptin2 (char* tentaptin)
{
    //bien s nhan 1 chuoi co kich thuoc toi da 100 ki tu tu tap tin
    //hoac 1 dong trong tap tin (den khi xuong hang)
    char* s=new char[300];
    FILE* f=fopen (tentaptin,"rt");
    if(f!=NULL)
    {
        while(!feof(f))// khi tap tin chua ket thuc
        {
            fgets(s,300,f);
            puts("===het 1 lan fgets ===xuong hang");
            puts(s);
        }
    }
    else{
        cout<<"khong tim thay tap tin";
    }

    return s;
}
int demSodoan (char* tentaptin)
{
    //bien s nhan 1 chuoi co kich thuoc toi da 100 ki tu tu tap tin
    //hoac 1 dong trong tap tin (den khi xuong hang)
    int sodoan=0;
    char* s=new char[300];
    FILE* f=fopen (tentaptin,"rt");
    if(f!=NULL)
    {
        while(!feof(f))// khi tap tin chua ket thuc
        {
           fgets(s,300,f);
           sodoan++;
        }
    }
    else{
        cout<<"khong tim thay tap tin";
    }
    return sodoan;
}
int demSotu (char* tentaptin)
{
    //bien s nhan 1 chuoi co kich thuoc toi da 100 ki tu tu tap tin
    //hoac 1 dong trong tap tin (den khi xuong hang)
    int soTu=0;
    char* s=new char[300];
    FILE* f=fopen (tentaptin,"rt");
    if(f!=NULL)
    {
        while(!feof(f))// khi tap tin chua ket thuc
        {
           fgets(s,300,f);
           for(int i=0;i<strlen(s);i++)
           {
              if(s[i]==' ')
                soTu++;
           }
            soTu++; //từ cuối cùng của s;
        }
    }
    else{
        cout<<"khong tim thay tap tin";
    }
    return soTu;
}
//dem xem co bao nhieu từ, câu, bao nhiêu đoạn

//ví dụ đếm có bao nhiêu từ có k kí tự
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
    cout<<"gia tri ki tu cuoi" <<vtdau[strlen(vtdau)-1]<<"\n";
    if(vtdau[strlen(vtdau)-1]==10)
    {
        cout<<"aaa";
        if(strlen(vtdau)-1==k)
        dem++;
    }

    else{
        if(strlen(vtdau)==k)
        dem++;
    }

    return dem;
}
int demSotuKkt (char* tentaptin, int k)
{
    char* s=new char[300];
    FILE* f=fopen (tentaptin,"rt");
    int dem=0;
    if(f!=NULL)
    {
        while(!feof(f))// khi tap tin chua ket thuc
        {
           fgets(s,300,f);
           //what to do
           dem=dem+sotucoKkt(s,k);
        }
    }
    else{
        cout<<"khong tim thay tap tin";
    }
    return dem;
}

struct Cau
{
    char*s;
};
struct sinhvien
{
    char*hoten;
    char* diachi;
};
void doctaptin3 (char* tentaptin, Cau sentence[], int& socau)

{
    //bien s nhan 1 chuoi co kich thuoc toi da 100 ki tu tu tap tin
    //hoac 1 dong trong tap tin (den khi xuong hang)
    socau=0;
    char* s1=new char[300];
    FILE* f=fopen (tentaptin,"rt");
    if(f!=NULL)
    {
        while(!feof(f))// khi tap tin chua ket thuc
        {
            fgets(s1,300,f);
            sentence[socau].s=new char[100];
            //gán chuỗi s1 được nhận từ fgets
            //sentence[socau].s = s1 sai vì ko gán trực tiếp chuỗi cho chuỗi
            strcpy(sentence[socau].s,s1);//câu thứ socau có thành phần s bằng s1
            socau++;
        }
    }
    else{
        cout<<"khong tim thay tap tin";
    }
}
int main()
{
   // cout<<strlen("Que huong la chum khe ngot cho con treo hai moi ngay que huong la duong di hoc con ve rop buom vang bay. Que huong la con dieu biec, tuoi tho con tha tren dong, que huong la con do nho, em dem khua nuoc ven song Que huong moi nguoi chi mot, nhu la chi mot me thoi ");
 //   doctaptin ("que huong.txt");
 //   cout<<"so tu co 3 ki tu la "<<sotucoKkt("que huong.txt abc ckh",3);
   cout<<"so tu co 3 ki tu trong vb = "<<demSotuKkt("que huong2.txt",3);
    Cau sentence[100];
    int socau=0;
    doctaptin3("que huong.txt",sentence,socau);
    for(int i=0;i<socau;i++)
        puts(sentence[i].s);
    return 0;
}

/*
while(f!=feof(f))
        {
            fgets(s,100,f);
            for(int i=0;i<strlen(s);i++)
            {
                if(s[i]==' ')
                {
                    if(sokt==k)
                    {
                        dem++;
                    }
                    sokt=0;
                }
                else
                {
                    sokt++;
                }
            }
            if(sokt==k)
            {
                dem++;
            }
        */
