/*) Cho dãy số xn được định nghĩa như sau:
𝑥1 = 19;
𝑥𝑛 = 𝑥1 + 𝑥2 + 𝑥3+. . . +𝑥𝑛−1 + 5𝑛 + 2019 với mọi số nguyên dương 𝑛 > 1.
a. Hãy cho biết giá trị của x5.
b. Hãy viết hàm đệ qui tính xn với mọi số nguyên dương n.*/
#include <iostream>
using namespace std;

double X(int n)
{
	int s = 0;
	if (n==1)
	{
		return 19;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			s = s + X(i);
		}
	}
	return s + 5 * n + 2019;
}

void xoa1vitrik(int a[], int n)

{

	int k;

	printf("nhap vi tri can xoa: ");

	scanf("%d", &k);

	for (int i = 0; i < n; i++)

		a[k] = a[k + 1];

	n = n - 1;
int main()
{
	int n;
	cout<<"\nnhap n: ";
	cin >> n;
	cout << "\nXn la: " << X(n);
}

