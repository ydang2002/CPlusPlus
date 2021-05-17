
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void Doc(int*& a, int& dong, int& cot)
{
    FILE* p = fopen("inp.txt", "r");
	if (p==NULL)
	{
		cout << "khong co tap tin";
	}
	fscanf(p, "%d", &dong);
	fscanf(p, "%d", &cot);
	a = new int[dong * cot];
	for (size_t i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			fscanf(p, "%d", *(a + cot * i + j));
		}
	}
	fclose(p);
}

int TinhTong(int* a, int cot, int k)
{
	int s = 0;
	for (int j = 0; j < cot; j++)
	{
		if (*(a+k*cot+j)%2!=0)
		{
			s = s + *(a + k * cot + j);
		}
	}
	return s;
}



int main()
{
	int dong, cot, * a,k;
	cout << "\n nhap k";
	cin >> k;
	Doc(a, dong, cot);
	FILE* p = fopen("inp.txt", "w");
	cout<<TinhTong(a, cot,k);
	fclose(p);
}



