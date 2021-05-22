/*Văn phòng Khoa ghi nhận danh sách sinh viên. Họ và tên sinh viên được đặt trên mỗi dòng trong
một tập tin có tên “danhsach.inp”, đầu và cuối họ tên không có khoảng trắng, ở giữa mỗi từ có một
khoảng trắng. Hãy viết chương trình thực hiện:Sắp xếp danh sách sinh viên theo thứ tự tăng dần của
phần tên sinh viên. Danh sách được in lên tập tin có tên “DS_Sort.out”.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

struct list
{
    char* s;
};

void DocDanhSachSV(list sv[], int& n)
{
    n = 0;
    char* p = new char[200];
    FILE* F = fopen("danhsach.inp", "r");
    if (F==NULL)
    {
        cout << "khong ton tai danh sach sinh vien ";
    }
    else
    {
        while (!feof(F))
        {
            fgets(p, 200, F);
            sv[n].s = new char[200];
            strcpy(sv[n].s, p);
                n++;
                
        }
    }
}

void swap(char x, char y)
{
    char temp = x;
    x = y;
    y = temp;
}

void Sapxep(list sv[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(sv[i].s, sv[j].s) < 0)
            {
                swap(sv[i].s, sv[j].s);
            }
        }
    }
}
void Xuat(list sv[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << sv[i].s << " \n";
    }
}

int main()
{
    int n;
    list sv[200];
    DocDanhSachSV(sv, n);
    Sapxep(sv, n);
    Xuat(sv, n);
}

