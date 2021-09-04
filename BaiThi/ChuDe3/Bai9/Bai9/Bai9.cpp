//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
//#include<cstring>

using namespace std;

//bai 9
int  DemSoTu(char* s)
{
	int dem = 1;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')
		{
			dem++;
		}
	}
	return dem;
}

//bai 10
void DemSoKiTuMoiTu(char* s)
{
	int sokitumoitu = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != ' ')
		{
			sokitumoitu++;
		}
		else
		{
			cout << sokitumoitu << " ";
			sokitumoitu = 0;
		}
	}
	cout<< sokitumoitu;
}

//Bai 11
char* TachTrai(char* s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')
		{
			s[i] = '\0';
		}
	}
	return s;
}

//bai 12
char* TimTuMax(char* s)
{
	char b[30];		// temporary
	char c[30];		// result
	int j = 0, maxlength = 0;


	for (int i = 0; i <= strlen(s); i++) {
		if (s[i] != 32 && s[i] != '\0') {
			b[j++] = s[i];
		}
		else {
			b[j] = '\0';
			if (strlen(b) > maxlength) {
				//strcpy(c, b);		// b -> c
				//maxlength = strlen(b);	// update maxLength
			}
			j = 0;
		}
	}
	puts(c); // output - result
	return 0;

}/*char string[55] = "Deviot.vn Cung nhau hoc lap trinh";
   char *first;
   first = strstr(string, "lap trinh");
   if (first != NULL)
   {
       printf("Chuoi con la: %s\r\n",first);
   }else
   {
       printf("Khong tim thay!\n");
   }
}*/
int  cau13(char* s)
{
	char* x = new char[100];
	cout << "\n Nhap chuoi: ";
	fgets(x, 100, stdin);
	char* first;
	first = strstr(s,x);
	for (int i = 0; i < strlen(s); i++)
	{
		if (first != NULL)
		{
			//cout << "\nVi tri: " << s[i];
			return s[i];
		}
	}
	return -1;
}


int main()
{
	char* s = new char[100];
	cout << "\n Nhap chuoi: ";
	fgets(s, 100, stdin);
	cout << "\nKet qua bai 9: " << DemSoTu(s) << endl;//so kí lương từ chuoi s
	cout << "Ket qua bai 10: "; DemSoKiTuMoiTu(s);//số lượng kí tự mỗi từ chuoi s
	cout << "Ket qua bai 11: "<<TachTrai(s);
	//cout << "Ket qua bai 12: " << TimTuMax(s);
	//cout << "Ket qua bai 13: " << cau13(s);
	puts(s);
}

