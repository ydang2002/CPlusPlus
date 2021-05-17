#include<iostream>
#include <string.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
char* nhap()
{
    char* s= new char[100];
    puts ("Moi ban nhap");
    gets(s);
    return s;
}

void nhap2 (char* s)
{
    puts ("Moi ban nhap");
    gets(s);
}
void nhap3 (char* &s)
{
    s=new char[100];
    puts ("Moi ban nhap");
    gets(s);
}
int dem (char* s)
{
    int dem=1;
    char*p=strchr(s,' ');
    while(p!=NULL)
    {
        dem++;
        p=p+1;
        p=strchr(p,' ');
    }
    return dem;
}

void vd_strchr ()
{
    //char * strchr (char * str, int character );
    char s1[100]="this is s1";
    printf("dia chi s1 khi cap phat %p \n",s1);
    puts(s1);
    char* vitri=strchr(s1,' ');
    cout<<"sau vi tri khoang trang "<<*(vitri+1);
    printf("dia chi cua vitri %p \n",vitri);
    printf("dia chi cua s1 + 4 %p \n",s1+4);
    vitri=strchr(vitri+1,' ');//làm lần 2
    cout<<"sau vi tri khoang trang thu 2 "<<*(vitri+1);

}
void vd_strchr_demNguyenAm ()
{
  char str[] = "ai roi cung tim duoc am em sau kho dau, chi la khong cung nhau";
  char * pch;
  printf ("Tim nguyen am 'a' trong \"%s\"...\n",str);
  pch=strchr(str,'a');
  while (pch!=NULL)
  {
    printf ("Tim thay a tai %d\n",pch-str);
    pch=strchr(pch+1,'a');
  }

}
void vd_strcpy()
{
    //char * strcpy ( char * destination, const char * source );
    char* s=new char[100];
    printf("dia chi s khi cap phat %p \n",s);
    //gan chuỗi cho mảng s1
    char s1[100]="hello everyone";
    puts(s1);

    printf("dia chi s1 khi cap phat %p \n",s1);
    char s2[100]="How are you";
    puts(s1);
    strcpy(s,s1);
    printf("dia chi s khi cap phat %p \n",s);
    puts(s);
    //gán chuỗi tĩnh cho s
    strcpy(s,"how are you");
    puts(s);
    char* temp ;
    strcpy(temp,s);
    printf("dia chi temp la %p \n",temp);
    puts(temp);
  //  strcpy(s1,s2);
   // puts(s1);

}
void tachtrai ()
{
    char* s=new char[100];
    s=nhap();
    char* temp=new char[100];
    temp= strcpy(temp,s);
    for(int i=0;i<strlen(temp);i++)
    {
        if(temp[i]==' ')
            temp[i]='\0';
    }
    puts(" s la ");
    puts(s);
    puts("tu dau tien ben trai la ");
    puts(temp);
}


void vd_strcat ()
{
    //char * strcat ( char * destination, const char * source );
    char* s=new char[100];
    printf("dia chi s khi cap phat %p \n",s);
    //gan chuỗi cho mảng s1
    char s1[100]="this is s1";
    printf("dia chi s1 khi cap phat %p \n",s1);
    puts(s1);

    //gán chuỗi tĩnh cho s
    strcat(s,s1);
    puts("strcat s va s1 ");
    puts(s);

    strcpy(s, "this is s ");
    strcat(s,s1);
    puts(s);
}



void vd_strstr ()
{//char *strstr (const char *s1, const char *s2);
    char s1[] = "Roi xa nhau dau tim van con mang ten nhau";
    char s2[] = "nhau";
    char* p;

    // tìm s2 trong s1
    p = strstr(s1, s2);

    // Prints the result
    if (p) {
        printf("tim thay roi\n");
        printf("s2 xuat hien dau tien '%s' trong '%s' la '%s'", s2, s1, p);
    } else
        printf("Khong tim thay\n");
}
void vd_strstr_timvathaythe ()
{
    char s1[] = "Xin chao Nguyen";
    char s2[] = "Nguyen";
    char* p;
    puts(s1);
    // Tìm vị trí s2 xuất hiện đầu tiên trong s1
    p = strstr(s1, s2);

    // thay thế
    if (p) {
        strcpy(p, "Minh");
        puts (s1);
    } else
        cout<<"Khong tim thay " << s2;
}
void vd_strcmp()
{
    //int strcmp(const char *str1, const char *str2)
    char str1[15];
   char str2[15];
   int ret;


   strcpy(str1, "abcde");
   strcpy(str2, "bBCDEFdddddd");

   ret = strcmp(str1, str2);

   if(ret < 0) {
      printf("str1 nho hon str2");
   } else if(ret > 0) {
      printf("str2 nho hon str1");
   } else {
      printf("str1 bang str2");
   }
}void vd_strrev()
{
    //char *strrev(char *str);
    char str[50] = "Chi la khong cung nhau";

   puts(str);
   char* str2=strrev(str);
   printf("Sau khi dao mang %s",str2);
}


void XoaKhoangTrangDau1(char s[])
{

	while (s[0]==' ')
	{
		strcpy(s, s+1);
	}
}
void XoaKhoangTrangDau2(char*& s)
{

	while (s[0]==' ')
	{
		s=s+1;
	}
}
void XoaKhoangTrangCuoi(char *s)
{

	while (s[strlen(s)-1] == ' ')
	{
		s[strlen(s) - 1] = '\0';
	}
}
void xoakhoangtranggiua(char* s)
{
	// tim chuoi 2 khoang trang "  "
	//
	char* p;
	p = strstr(s, "  ");
	while (p != NULL)//khi chuoi chua ket thuc
	{
			strcpy(p, p + 1);
			p = strstr(s, "  ");
	}
}

void demtuBDbangNA ()
{
    int dem=0;
    char* str =new char[100];
    strcpy(str,"ai roi cung tim duoc am em sau kho dau, chi la khong cung nhau uhm uhm" );
    char* s=new char[2];
    strcpy(s," ");
    str=strcat(s,str );
    char* p=strchr(str,' ');
    while(p!=NULL)
    {
        if(*(p+1)=='a'||*(p+1)=='u'||*(p+1)=='i'||*(p+1)=='e')
            dem++;
        p=strchr(p+1,' ');//tìm khoảng trắng kế tiếp
    }
    cout<<dem;
}
int main()
{
	  demtuBDbangNA ();
	/*ví dụ 1
	char *s1=new char[100];
	fflush(stdin);
	gets(s1); //nhap 1 chuoi
	puts(s1);
	char s2[100]="aaaaaa";
//	puts(s1);
	puts(s2);
	//s2=s1;

	char* s3;
	s3=s1;
	s3=s2;
	cout<<"chuoi S3 = ";
	puts(s3);
//	s1=s2;
//	puts(s2);
//	puts(s1);
*/
/*
char *s1=new char[100];
	fflush(stdin);
	gets(s1); //nhap 1 chuoi
	puts(s1);
	s1=s1+5;
	cout<<"Gia tri moi la ";
	puts(s1);
*/
//char* s1=new char[100];
/*char* s3;
nhap3(s3);
puts(s3);
cout<<dem(s3);
ví dụ 2 hàm nhập chuỗi
	char* s1;
	s1=nhap();
	puts(s1);

printf("dia chi %p",&s3);
printf("dia chi %p",s3);
char*s = s3;
printf("dia chi s %p",s);
s=new char[100];
printf("dia chi s khi cap phat %p",s);
s=strcpy(s,"abc");
puts(s);
printf("dia chi s khi nhan gtri %p",s);
//s='hello';
*/

	return 1;
}

