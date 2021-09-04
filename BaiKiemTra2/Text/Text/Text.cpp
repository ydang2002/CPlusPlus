//Nguyen Thi Thanh Huyen mssv: 3120560035
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
struct List
{
    char* s;
};

//bai 1
int X(int n);

//bai 2
void Read_TrueLabel(int* a, int& n);
void Read_PredictedLabel(int* b, int& n);
void GhiGiatri(FILE* F, int* a, int* b, int n, int m, float& Precision, float& Recall, int& TN, int& FP, int& TP, int& FN);

//void TaoMang(int result[][10]);
//void Tinh_Gia_Tri(int* a, int* b, int n, int result[][10]);
//double Precision(int result[][10]);
//double Recall(int result[][10]);
//void Write_Result(int result[][10], int n);

//bai 3
//void Read_List(List sv[], int& n);
//char* VietHoa(char* s);
//void Chuan_Hoa_Ghi_File(List sv[], int n);
//char* Find_Max(List sv[], int n);
//void Taomang_TanSuatChu(int a[], int sochucai);
//void TanSuat(List sv[], int n, int a[]);
//void Xuat_TanSuat(int a[], int sochucai);
int main()
{
    //bai 1
   /* cout << "cau 1:" << endl;
    cout << X(4);*/
    //bai 2
    cout << endl << "cau 2:" << endl;
    int* a = new int[100];
    int* b = new int[100];
    int n,m;
    int TN, FP, TP, FN;
    float precision, recall;
    int result[10][10];
    Read_TrueLabel(a, m);
    Read_PredictedLabel(b, n);
    FILE* F = fopen("result.out", "wt");
    GhiGiatri(F, a, b, n, m, precision, recall, TN, FP, TP, FN);
    fclose(F);
    /*TaoMang(result);
    Tinh_Gia_Tri(a, b, n, result);
    Write_Result(result, n);*/
    //bai 3
    //cout << endl << "cau 3:" << endl;
    //List sv[100];
    //int m;
    //Read_List(sv, m);
    //cout << "So luong sinh vien trong danh sach la: " << m;
    //Chuan_Hoa_Ghi_File(sv, m);
    //char* s = Find_Max(sv, m);
    //cout << endl << "Sinh vien co ho ten dai nhat la: ";
    //puts(s);
    //int a1[50];
    //Taomang_TanSuatChu(a1, 26); //tao mang chu cai
    //TanSuat(sv, m, a1);
    //Xuat_TanSuat(a1, 26);
    //return 0;
}

//bai 1
int X(int n)
{
    int s = 0;
    if (n == 0 || n == 1)
        return 1;
    else
    {
        for (int i = 0; i < n; i++)
            s = s + (n - i) * X(i);
    }
    return s;
}

//bai 2
void Read_TrueLabel(int* a, int& m)
{
    m = 0;
    FILE* p = fopen("truelabel.inp", "rt");
    if (p == NULL)
        cout << "ko tim thay file truelabel.inp";
    else
    {
        while (!feof(p))
        {
            fscanf(p, "%d", &a[m]);
            m++;
        }
    }
    fclose(p);
}

void Read_PredictedLabel(int* b, int& n)
{
    n = 0;
    FILE* p = fopen("predictedlabel.inp", "rt");
    if (p == NULL)
        cout << "ko tim thay file pridictedlabel.inp";
    else
    {
        while (!feof(p))
        {
            fscanf(p, "%d", &b[n]);
            n++;
        }
    }
    fclose(p);
}

void GhiGiatri(FILE* F, int* a, int* b, int n, int m, float& Precision, float& Recall, int& TN, int& FP, int& TP, int& FN)
{
    TN = FP = TP = FN = Precision = Recall = 0;
    for (int i = 0; i < n; i++)
    {

            if (a[i] == 0 && b[i] == 0)
            {
                TN++;
            }
            else if (a[i] == 0 && b[i] == 1)
            {
                FP++;
            }
            else if (a[i] == 1 && b[i] == 1)
            {
                TP++;
            }
            else
            {
                FN++;
            }
        
    }
    Precision = TP * 1.0 / (TP + FP);
    Recall = TP * 1.0 / (TP + FN);
    cout << TN << endl;
    cout << FP << endl;
    cout << TP << endl;
    cout << FN << endl;
    fprintf(F, "%d  ", TN);
    fprintf(F, "%d  ", FP);
    fprintf(F, "\n%d  ", TP);
    fprintf(F, "%d  ", FN);
    fprintf(F, "\n%f ", Precision);
    fprintf(F, "\n%f ", Recall);
}

//tao mang de luu 4 gia tri tp, fp, tn, fn
void TaoMang(int result[][10])
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = 0;
}

//result[0][0] = tn     result[0][1] = fp       result[1][0] = fn       result[1][1] = tp
//ham tinh gia tri tp, fp, tn,fn
// a la con tro mang truelabel, b la con tro mang predicted label
void Tinh_Gia_Tri(int* a, int* b, int n, int result[][10])
{
    for (int i = 0; i < n; i++)
    {
        int x = *(a + i);
        int y = *(b + i);
        cout<<"\n gia tri"<<result[x][y]++;
    }
}

//tinh precision
double Precision(int result[][10])
{
    //int temp = result[1][1] + result[0][1];
    double pre = (result[1][1] * 1.0) / (result[1][1] + result[0][1]);
    return pre;
}

//Tinh Recall
double Recall(int result[][10])
{
    int temp = result[1][1] + result[1][0];
    double rec = result[1][1] * 1.0 / temp;
    return rec;
}

//In ket qua len tap tin result.out
void Write_Result(int result[][10], int n)
{
    FILE* p = fopen("result.out", "wt");
    fprintf(p, "So luong mau xet nghiem la: %d\n", n);
    fprintf(p, "Ma tran Confusion Matrix\n");
    fprintf(p, "TP = %d ", result[1][1]);
    fprintf(p, "FN = %d", result[1][0]);
    fprintf(p, "\n");
    fprintf(p, "FP = %d ", result[0][1]);
    fprintf(p, "TN = %d", result[0][0]);
    double pre = Precision(result);
    double rec = Recall(result);
    fprintf(p, "\n");
    fprintf(p, "Precision = %fl\n", pre);
    fprintf(p, "Recall = %fl", rec);
    fclose(p);
}

//bai 3
//ham doc file vao luu vao list
//void Read_List(List sv[], int& n)
//{
//    n = 0;
//    char* p = new char[200];
//    FILE* fp = fopen("danhsach.inp", "rt");
//    if (fp == NULL)
//        cout << "ko tim thay danh sach";
//    else
//    {
//        while (!feof(fp))
//        {
//            fgets(p, 200, fp);
//            sv[n].s = new char[200];
//            strcpy(sv[n].s, p);
//            n++;
//        }
//    }
//    fclose(fp);
//}
//
//char* VietHoa(char* s)
//{
//    strlwr(s);
//    int i = 0;
//    while (i < strlen(s))
//    {
//        if (s[i] == ' ')
//            s[i + 1] = toupper(s[i + 1]);
//        i++;
//    }
//    s[0] = toupper(s[0]);
//    return s;
//}
//
//void Chuan_Hoa_Ghi_File(List sv[], int n)
//{
//    FILE* fp = fopen("DS_new.out", "wt");
//    for (int i = 0; i < n; i++)
//    {
//        char* p = new char[200];
//        p = VietHoa(sv[i].s);
//        fputs(p, fp);
//        fputs("\n", fp);
//    }
//    fclose(fp);
//}
//
////tim va in ra ho ten sinh vien dai nhat
//char* Find_Max(List sv[], int n)
//{
//    int max = strlen(sv[0].s);
//    char* p = sv[0].s;
//    for (int i = 0; i < n; i++)
//    {
//        if (max < strlen(sv[i].s))
//        {
//            max = strlen(sv[i].s);
//            strcpy(p, sv[i].s);
//        }
//    }
//    return p;
//}
//
////chon cau 3.4
////tao mang tan suat cho chu cai
//void Taomang_TanSuatChu(int a[], int sochucai)
//{
//    for (int i = 0; i < sochucai; i++)
//    {
//        a[i] = 0;
//    }
//}
//
//void TanSuat(List sv[], int n, int a[])
//{
//    for (int i = 0; i < n; i++)
//    {
//        char* p = strrchr(sv[i].s, ' ');
//        int x = *(p + 1) - 65;
//        a[x]++;
//    }
//}
//
//void Xuat_TanSuat(int a[], int sochucai)
//{
//    for (int i = 0; i < sochucai; i++)
//    {
//        cout << i + 65 << " co " << a[i] << " lan xuat hien";
//        cout << endl;
//    }
//}
//
