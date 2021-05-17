
#include <iostream>
#include <string>
//#include <stdio.h>
using namespace std;

//tach ki tu ben trai
void TachTrai(char* s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i]==' ')
		{
			s[i] = '\0';
		}
	}
}


void TachTrai2(char *s)
{
	char* p = strchr(s, ' ');
		s[p - s] = '\0';
}

void TachPhai(char* &s)
{
	int vitri = 0;
	for (int  i = 0; i < strlen(s); i++)
	{
		if (s[i]==' ')
		{
			vitri = i;
		}
	}
	s = s + vitri + 1;

}

char* TachPhai2(char* s)
{
	char* temp = s;
	char* p = strchr(s, ' ');
	while (p!=NULL)
	{
		temp = p + 1;
		p = strchr(p + 1, ' ');
	}
	return temp;
}

char* TachPhai3(char *s)
{
	char* p = strrchr(s, ' ');
	return p + 1;
}

char* VietHoaDauMoiTu(char* s)
{
	
	s = strlwr(s);// hàm dùng để viết thương tất cả các chữ có trong chuoi
	
	//s[0] = s[0]= ' ';
	for (int  i = 0; i < strlen(s); i++)
	{
		if (s[i]==' ' && s[i+1] !=' ')
		{
			
			s[i + 1] = toupper(s[i + 1]);// có thể thay ở duoi
			//s[i + 1] = s[i + 1] - 32;
		}
		if (s[0] != ' ')
		{
			s[0] = toupper(s[0]);
		}
	}
	return s;
}

void DemKhoangTrang(char* s)
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i]==' ')
		{
			dem++;
			cout << dem;
		}
	}
	
}

int  DemSoTu(char* s)
{
	int dem = 1;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i]==' ')
		{
			dem++;
		}
	}
	return dem;
}

void DemNguyenAm(char* s)
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] =='u'||s[i]=='e'||s[i]=='o'||s[i]=='a'||s[i]=='i')
		{
			dem++;
		}
	}
	cout << "\nnguyen am la:" << dem;
}

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

void SapXepKiTuTangDan(char* s)
{
	for (int i = 0; i < strlen(s)-1; i++)
	{
		for (int j = i+1; j < strlen(s); j++)
		{
			if (*(s+i)>*(s+j))
			{
				char temp = *(s + i);
				*(s + i) = *(s + j);
				*(s + j) = temp;
			}
		}
	}
}

void XoaKhoangTrangDau(char* &s)
{
	while (s[0]==' ')
	{
		s = s + 1;
	}
}

void XoaKhoangTrangCuoi(char*& s)
{
	while (s[strlen(s)-1] == ' ')
	{
		
	}
}

int main()
{
	char* s = new char[100];
	//cout << "\n Nhap chuoi: ";
	fgets(s, 100, stdin);
	XoaKhoangTrangDau(s);
	cout << s;
}
