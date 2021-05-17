#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void DocFile(int a[], int& n)
{
	n = 0;
	FILE* p = fopen("inp.txt", "r");
		if (p==NULL)
		{
			cout << " khong tim thay file";
		}
		while (!feof(p))
		{
			fscanf(p, "%d", &a[n]);
			n++;
		}
		fclose(p);
}

void SapXep(FILE* p,int a[], int n)
{
	int k;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i]>a[j])
			{
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		fprintf(p, "%d\t", a[i]);
	}
}

int main()
{
	int a[100], n;
	DocFile(a, n);
	FILE* p = fopen("mang.out", "w");
	SapXep(p,a, n);
	fclose(p);
}

