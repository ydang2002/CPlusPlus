
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
using namespace std;

int dem(char* s)
{
	int dem = 1;
	char* p = strchr(s, ' ');
	while (p != NULL)
	{
		dem++;
		p = p + 1;
		p = strchr(p, ' ');
	}
	return dem;
}

//int Dem(char* s)
//{
//	int dem = 0;
//	char* k = new char[2];
//	strcpy(k, " ");
//	s = strcat(k,s );
//	for (int i = 0; i< strlen(s); i++)
//	{
//		if (s[i]=' ' && s[i +1]=='u' || s[i+1 ] == 'e' || s[i+1 ] == 'o' || s[i+1 ] == 'a' || s[i +1] == 'i')
//		{
//			dem++;
//		}
//		/*if ( s[0] == 'u' || s[0] == 'e' || s[0] == 'o' || s[0] == 'a' || s[0] == 'i')
//		{
//			dem++;
//		}*/
//	}
//	return dem;
//}

void demtuBDbangNA()
{
	int dem = 0;
	char* str = new char[100];
 strcpy(str,"ai roi cung tim duoc am em sau kho dau, chi la khong cung nhau uhm uhm" );
	char* s = new char[2];
	strcpy(s, " ");
	str = strcat(s, str);
	char* p = strchr(str, ' ');
	while (p != NULL)
	{
		if (*(p + 1) == 'a' || *(p + 1) == 'u' || *(p + 1) == 'i' || *(p + 1) == 'e')
			dem++;
		p = strchr(p + 1, ' ');//tìm khoảng trắng kế tiếp
	}
	cout << dem;
}

int demtuBDbangNA(char*str)
{
	int dem = 0;
	char* s = new char[2];
	strcpy(s, " ");
	str = strcat(s, str);
	char* p = strchr(str, ' ');
	while (p != NULL)
	{
		if (*(p + 1) == 'a' || *(p + 1) == 'u' || *(p + 1) == 'i' || *(p + 1) == 'e' || *(p + 1) == 'o')
			dem++;
		p = strchr(p + 1, ' ');//tìm khoảng trắng kế tiếp
	}
	return dem;
}

int main()
{
	char* str = new char[100];
	//puts("moi nhap chuoi:");
	fgets(str, 100, stdin);
	cout << "\nso luong tu bat dau bang nguyen am: "<< demtuBDbangNA(str);
	
		
}

