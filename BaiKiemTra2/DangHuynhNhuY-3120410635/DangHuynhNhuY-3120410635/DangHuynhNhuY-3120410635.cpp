//Họ và tên: Đặng Huỳnh Như y - 3120410635
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//bài 1
int TinhXn(int n)
{
	int s = 0;
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
	for (int i = 0; i < n; i++)
		s = s + (n - i) * TinhXn(i);
	}
	return s;
	
}

//bai 2
//cau a
//dọc tập tin true label.inp
void DocFILE(int a[], int& n)
{
	n = 0;
	FILE* F = fopen("true label.inp", "r");
	if (F != NULL)
	{
		int* a = new int[1000];
		for (int i = 0; i!=feof(F); i++)
		{
			fscanf(F, "%d\t", &a[i]);
			cout << a[i] << " ";
			n++;
		}
		fclose(F);
	}
	else
	{
		cout << "khong ton tai tap tin";
	}
}


////dọc tập tin "predicted label.inp"
//void DocFILE(int b[], int& m)
//{
//	m = 0;
//	FILE* F = fopen("true label.inp", "r");
//	if (F != NULL)
//	{
//		int* b = new int[1000];
//		for (int i = 0; i < 1000; i++)
//		{
//			fscanf(F, "%d\t", &b[i]);
//			m++;
//		}
//		fclose(F);
//	}
//	else
//	{
//		cout << "khong ton tai tap tin";
//	}
//}
//cau b
//tin giá tri TP,FP,TN,FN

void doc(FILE* f, int* &a, int& n)
{
	if (f != NULL)
	{
		n = 0;
		while (!feof(f))
		{
			fscanf(f, "%d", &a[n]);
			cout << a[n];
			n++;
		}
		fclose(f);
	}
	else
		cout << "khong ton tai tap tin " << endl;
}
void doc2(FILE* f, int* &b, int& m)
{
	if (f != NULL)
	{
		m = 0;
		while (!feof(f))
		{
			fscanf(f, "%d", &b[m]);
			cout << b[m];
			m++;
		}
		fclose(f);
	}
	else
		cout << "khong ton tai tap tin " << endl;
}



void giatri(int a[], int b[], int n,int m, float& Precision, float& Recall, int& TN, int& FP, int& TP, int& FN)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] == 0 && b[j] == 0)
			{
				TN++;
			}
			else if (a[i] == 0 && b[j] == 1)
			{
				FP++;
			}
			else if (a[i] == 1 && b[j] == 1)
			{
				TP++;
			}
			else
			{
				FN++;
			}
		}
	}
	Precision = TP / (TP + FP);
	Recall = TP / (TP + FN);
}

int Tinh(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong = tong + a[i];
	}
	return tong;
}

//Cau c trong ham main
void GhiGiatri(FILE*F,int* a, int* b, int n,int m, float& Precision, float& Recall, int& TN, int& FP, int& TP, int& FN)
{
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (a[i] == 0 && b[j] == 0)
			{
				TN++;
			}
			else if (a[i] == 0 && b[j] == 1)
			{
				FP++;
			}
			else if (a[i] == 1 && b[j] == 1)
			{
				TP++;
			}
			else
			{
				FN++;
			}
		}
	}
	cout << TN << endl;
	cout << FP << endl;
	cout << TP << endl;
	cout << FN << endl;
	fprintf(F, "%d  ", TN);
	fprintf(F, "%d  ", FP);
	fprintf(F, "%d  ", TP);
	Precision = TP / (TP + FP);
	fprintf(F, "%d  ", FN);
	fprintf(F, "%d Precision=TP/ (TP+FP) = 2/(2+2) = ", Precision);
	Recall = TP / (TP + FN);
	fprintf(F, "%dRecal = TP/(TP+FN) = 2/(2+1)=  ", Recall);

}


int main()
{
	/*Phần kiểm tra bài 1
	int n;
	cout << "\n Nhap n:";
	cin >> n;
	cout << "\n Gia tri Xn :" << TinhXn(n);*/

	//Phần kiểm tra bài 2
	/*int  a[1000], b[1000], n,m;
	int  TN, FP, TP, FN;
	float Precision, Recall;
	DocFILE(a, n);*/
	//DocFILE(a, m);
	////cau c
	//FILE* F = fopen("result.out", "w");
	//GhiGiatri(F, a, b, n, Precision, Recall, TN, FP, TP, FN);
	//fclose(F);
	int* a = new int[1000];
	int* b = new int[1000];
	int gt[100][100];
	int n, m, TN, FP, TP, FN;
	float precision, recall;
	FILE* f = fopen("true label.inp", "rt");
	doc(f, a, n);
	fclose(f);
	cout << endl;
	FILE* p = fopen("predicted label.inp", "rt");
	doc2(f, a, m);
	fclose(p);
	cout << endl;
	FILE* F = fopen("result.out", "wt");
	GhiGiatri(F, a, b, n,m, precision, recall, TN, FP, TP, FN);
	fclose(F);
	//giatri( a, b, n,m, precision, recall, TN, FP, TP, FN);
	/*FILE* F = fopen("result.out", "w");
	GhiGiatri(F, a, b, n, precision, recall, TN, FP, TP, FN);
	fclose(F);*/
	//giatri(a[], b[], n, Precision, Recall, TN, FP, TP, FN);

}