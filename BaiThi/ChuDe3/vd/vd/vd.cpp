
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<cstring>

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
	cout << sokitumoitu;
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
void TimTuMax(char* s)
{
	char b[30];		// temporary
	char c[30];		// result
	int j = 0, maxlength = 0;


	for (int i = 0; i <= strlen(s); i++) {
		if (s[i] != ' ' && s[i] != '\0') {
			b[j++] = s[i];
		}
		else {
			b[j] = '\0';
			if (strlen(b) > maxlength) {
				strcpy(c, b);		// b -> c
				maxlength = strlen(b);	// update maxLength
			}
			j = 0;
		}
	}
	cout << "Ket qua bai 12: ";
	puts(c); // output - result

}

//void  cau13(char* s)
//{
// int j = 0;
//	char* x = new char[100];
//	cout << "\n Nhap chuoi: ";
//	fgets(x, 100, stdin);
//	char* first;
//	first = strstr(s, x);
//	for (int i = 0; i < strlen(s); i++)
//	{
//		if (first != NULL)
//		{
//			if (x[j]==s[i])
//			{
//				return (i-j);
//			}
//			else
//			{
//				return -1;
//			}
//		}
//		/*else
//		{
//			return -1;
//		}*/
//	}
//	
//}

int cau13(char* s)
{
	char* x = new char[100];
	cout << "\n nhap chuoi: ";
	fgets(x, 100, stdin);
	int j = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i]!=x[j])
		{
			j = 0; continue;
		}
		else
		{
			if (j=strlen(x)-1)
			{
				return i - j;
			}
			j++;
		}
	}
	return-1;
}


int main()
{
	char* s = new char[100];
	cout << "\n Nhap chuoi: ";
	fgets(s, 100, stdin);
	//cout << "\nKet qua bai 9: " << DemSoTu(s) << endl;//so kí lương từ chuoi s
	//cout << "Ket qua bai 10: "; DemSoKiTuMoiTu(s);//số lượng kí tự mỗi từ chuoi s
	//cout << "Ket qua bai 11: " << TachTrai(s);
	cau13(s);
	//cout << "Ket qua bai 13: " << cau13(s);
	//puts(s);
}



