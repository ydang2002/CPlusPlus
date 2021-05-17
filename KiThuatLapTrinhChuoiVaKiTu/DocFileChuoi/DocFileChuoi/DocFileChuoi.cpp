#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void doctaptin(char*& tentaptin)
{
    //bien s nhan 1 chuoi co kich thuoc toi da 100 ki tu tu tap tin
    //hoac 1 dong trong tap tin (den khi xuong hang)
    char* s = new char[300];
    FILE* f = fopen("que huong.txt", "rt");
    if (f != NULL)
    {
        while (!feof(f))// khi tap tin chua ket thuc
        {
            fgets(s, 300, f);
            puts("===het 1 lan fgets ===xuong hang");
            puts(s);
        }

        fclose(f);
    }
    else {
        cout << "khong tim thay tap tin";
    }

}

int demSotu(char* tentaptin)
{
    //bien s nhan 1 chuoi co kich thuoc toi da 100 ki tu tu tap tin
    //hoac 1 dong trong tap tin (den khi xuong hang)
    int soTu = 0;
    char* s = new char[300];
    FILE* f = fopen("que huong.txt", "rt");
    if (f != NULL)
    {
        while (!feof(f))// khi tap tin chua ket thuc
        {
            fgets(s, 300, f);
            for (int i = 0; i < strlen(s); i++)
            {
                if (s[i] == ' ')
                    soTu++;
            }
            soTu++; //từ cuối cùng của s;
        }
    }
    else {
        cout << "khong tim thay tap tin";
    }
    return soTu;
}

//ví dụ đếm có bao nhiêu từ có k kí tự
int sotucoKkt(char* s, int k)
{
    int dem = 0;
    //strcat(s," "); //cách 1 xử lý thêm 1 khoảng trắng vào sau chuỗi s
    char* vtdau = s;
    char* vitriKT = strchr(s, ' ');//tim thay 1 tu được ghi lại là vị trí khảng trắng
    while (vitriKT != NULL)
    {
        int sokitu = vitriKT - vtdau;
        if (sokitu == k)
            dem++;
        vtdau = vitriKT + 1;//vị trí đầu cập nhật bằng vị trí khoảng trắng +1
        vitriKT = strchr(vitriKT + 1, ' ');//tìm khoảng trắng kế tiếp
    }
    //cout << "gia tri ki tu cuoi" << vtdau[strlen(vtdau) - 1] << "\n";
    if (vtdau[strlen(vtdau) - 1] == 10)
    {
        //cout << "aaa";
        if (strlen(vtdau) - 1 == k)
            dem++;
    }

    else {
        if (strlen(vtdau) == k)
            dem++;
    }

    return dem;
}

int demSotuKkt(char* tentaptin, int k)
{
    char* s = new char[300];
    FILE* f = fopen("que huong.txt", "rt");
    int dem = 0;
    if (f != NULL)
    {
        while (!feof(f))// khi tap tin chua ket thuc
        {
            fgets(s, 300, f);
            //what to do
            dem = dem + sotucoKkt(s, k);
        }
    }
    else {
        cout << "khong tim thay tap tin";
    }
    return dem;
}

int main()
{
    /*int k;
    char *tentaptin;
    doctaptin(tentaptin);
    cout<<"\nso tu: "<<demsotu(tentaptin);
    cout << "\nnhap k ki tu cua tu can dem: ";
    cin >> k;
    cout << "\nso tu co "<<k<<" ki tu: " << demsotukkt(tentaptin,k);*/
    char* s = new char[100];
    fgets(s, 100, stdin);
    puts(s);
    int k;
    cout << "\n nhap k: ";
    cin >> k;
    cout<<sotucoKkt(s,k);

}


