// tìm giá trị lón nhất bằng cấp phát động
#include <iostream>
using namespace std;

void NhapMang(int &n, int *&a)
{
    cout << " \n nhap so phan tu: ";
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << " \n phan tu thu a[" << i << "]: ";
        cin >> *(a + i);
    }

}

void XuatMang(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}

int GiaTriLonNhat(int n, int* a)
{
    int MAX = *a;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) > MAX)
        {
            MAX = *(a + i);
            return MAX;
        }
    }
}
int main()
{
    int n, * a;
    NhapMang(n, a);
    XuatMang(n, a);
    cout << " gia  tri lon nhat: " << GiaTriLonNhat(n, a);
}

