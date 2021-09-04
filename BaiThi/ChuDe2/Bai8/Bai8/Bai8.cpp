#include <iostream>
using namespace std;
#include <string>


char* XoaKiTu(char* s)
{
    int l, p;
    cout << "\nNhap l ki tu can xoa: ";
    cin >> l;
    cout << "\nNhap vi tri p băt dau xoa:";
    cin >> p;
    for (int i = p; i < strlen(s); i++)
    {
        s[i] = s[i + l];
    }
    return s;
}

int main()
{
    char* s = new char[100];
    puts("Moi ban nhap");
    fgets(s, 100, stdin);
    XoaKiTu(s);
    puts(s);
}

