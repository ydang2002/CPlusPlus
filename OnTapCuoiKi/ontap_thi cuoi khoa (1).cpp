#include <iostream>
using namespace std;
//Y Đặng Huỳnh Như1:10 PM
struct node
{
    int data;
    node* next;
};

struct list
{
    node* head;
    node* tail;
};

void KhoiTao(list& l)
{
    l.head = NULL;
    l.tail = NULL;
}

node* TaoNODE(int x)
{
    node* p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}

void ThemNODEVaoDau(list& l, node* p)
{
    if (l.head == NULL)//ds rỗng
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void ThemNODEVaoDau(list& l, int k)
{
    node*p =new node;
    p=TaoNODE(k);
    if (l.head == NULL)//ds rỗng
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void ThemNODEVaoCuoi(list& l, node* p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

int TimMax(list l)
{
    int max = -1;
    for (node* i = l.head; i != NULL; i = i->next)
    {
        if (i->data>max)
        {
            max = i->data;
        }
    }
    return max;
}

void TimMaxChan(list l)
{
    for (node* i = l.head; i != NULL; i = i->next)
    {
        if (i->data==TimMax(l) && i->data % 2 == 0)
        {
            cout << "\n phan tu chan va lon nhat: " << i->data;
        }
    }
}

node* Find_maxNode (node* head)
{
    int max = head->data;
    node* maxNode = head;
    node* temp = head;
    while(temp != NULL)
    {
        if(temp->data > max)
        {
            max = temp->data;
            maxNode = temp;
        }
        temp = temp->next;
    }
    return maxNode;
}

//ngo hau Le1:41 PM
node* timmaxchan(linkedlist* l)
{
    node* maxNode=new node;
    node* f=l->head;
    int max=-1;
    while(f!=NULL)
    {
        if(f->data%2==0)
        {
            if(f->data>max)
            {
                max=f->data;
                maxNode->data=f->data;
              //  maxNode = f;
            }
        }
        f=f->next;
    }
    return maxNode;
}

int TimMinVaLonHonK(list l,int k)
{
    int min = INTMAX;
    for (node* i = l.head; i != NULL; i = i->next)
    {
        if (i->data <min&&i->data>k)
        {
            min = i->data;
        }
    }
    return min;
}

/*
node* temp = head;
while(temp != NULL)
    {
        if(điều kiện bài toán)
        {
            xử lý;
        }
        temp = temp->next;
    }
*/
    //Nhập vào số n và cho biết n có bao nhiêu chữ số.
int Dem (int n)
{
    if(n < 10)
        return 1;
    else
        return 1 + Dem(n/10);
}

//Tính tổng của các chữ số của một số tự nhiên n.
int tongchuso(int n)
{
    if(n>0)
        return n%10+tongchuso(n/10);
    return 0;
}
//Khắc Vượng
int Tinh(int n)
{
if (n<10)
{
    return n;
}
else
{
    return Tinh(n / 10) + n % 10;
}
}

//tìm chữ số nhỏ nhất trong số n
//Tạ Hà Anh Tú2:30 PM
int min(int n)
{
    if(n<10)
        return n;
    if((n%10)<min(n/10))
        return n%10;
    else
        return min(n/10);
}
int check(int n,int *min)
{
	if(n<10 ) return n;
	else {
		if(*min>(n%10)) *min=(n%10);
			check(n/10);
	}
}

//ngo hau Le2:36 PM
int timchusonhonhat(int n)
{
    int min=n%10;
    if(n<10)
    {
        return min;
    }
    else
    {
        if(min<timchusonhonhat(n/10))
        {
            return min;
        }
        else
        {
            return timchusonhonhat(n/10);
        }
    }
}

//Dảy số
/*
S = S(n-1) + phần tử thứ n

S=1 + 2^2 + 3^2 +...+ n^2
*/
int tong (int n)
{
    if(n==1)
        return 1;
    else {
        return tong(n-1) + n*n;
    }
}
// S=1 + 1x2 + 1x2x3+ ... +1x2x...x n 

int tong2 (int n)
{
    if(n==1)
        return 1;
    else {
        return tong2(n-1) + giaithua(n);
    }
}


int X (int n)
{
    int s = 0;
    if(n == 0 || n == 1)
        return 1;
    else
    {
        for(int i = 0; i < n; i++)
            s = s + (n-i)*X(i);
    }
    return s;
}

//Tập tin chứa mảng số (cấp phát động hoặc không)
/*
2.1 Đọc tập tin
có cấu trúc dòng 1 ghi số phần tử, dòng 2 liệt kê các giá trị của từng phần tử
*/
void Read_File(int a[100], int &n)
{
    n = 0;
    FILE* f = fopen("mangso.inp", "rt");
    if(f == NULL)
        cout<<"ko tim thay file mangso.inp";
    else
    {
        fscanf(f, "%d", &n);
        for(int i=0;i<n;i++)
        {
            fscanf(f, "%d", &a[i]);
        }
    }
    fclose(p);
}
//cấp phát động
void Read_File(int*& a, int &n)
{
    n = 0;
    FILE* f = fopen("mangso.inp", "rt");

    if(f == NULL)
        cout<<"ko tim thay file mangso.inp";
    else
    {
        fscanf(f, "%d", &n);
        a=new int[n];
        for(int i=0;i<n;i++)
        {
            fscanf(f, "%d", &a[i]);
        }
    }
    fclose(f);
}

//xử lý mảng
//Tìm phần tử lớn nhất, phần tử chẵn
int timMax (int* a, int n)
{
    int max= *(a+0);
    //max= a[0];
    for (int i=1;i<n;i++)
    {
        if(*(a+i)>max)
            max=*(a+i);
    }
    return max;
}

// ghi kết quả
bool isPrime(int n)
{
    //Nếu là số NT
    return true;
    //Ngược lại
    return false;

}
void Ghi (int *a, int n)
{
    FILE* p = fopen("ketqua.out", "wt");
    fprintf(p, "gia tri lon nhat la: %d\n", timMax (a,  n));
    //ví dụ ghi các số chẵn trong mảng
    for (int i=0; i<n;i++)
        if(*(a+i)%2==0) //hoặc TH tìm số nguyên tố if(isPrime(*(a+i))==true)
        {
            fprintf(p, " %d\n", *(a+1));
        }

    fclose(p);
}

//Chuỗi
//viết hoa, viết thường
//tách trái, phải
//đếm số từ
//từ có k kí tự
//từ dài nhất
// số từ bắt đầu bằng nguyên âm
//đếm số kí tự là nguyên âm
//Một số hàm cần nhớ
//strlen(s): độ dài của s
//temp= strcpy(temp,s);// copy nội dung của s cho temp
void tachtrai (char* s)
{
    s=new char[100];
    s=nhap();
    char* temp=new char[100];
    temp= strcpy(temp,s);
    for(int i=0;i<strlen(temp);i++)
    {
        if(temp[i]==' ')
            temp[i]='\0';
    }

    puts("tu dau tien ben trai la ");
    puts(temp);
}
void tachphai (char* s)
{
    s=new char[100];
    s=nhap();
    int vitri=0;
    char* temp=new char[100];
    temp= strcpy(temp,s);
    for(int i=0;i<strlen(temp);i++)
    {
        if(temp[i]==' ')
            vitri=i;
    }
    temp= s+vitri+1; //vitri là vị trí khoảng trắng cuối cùng, vitri+1 bắt đầu từ cuối
    puts("tu dau tien ben phai la ");
    puts(temp);
}

//viết hoa, viết thường
char* vietthuong (char* s)
{
    strlwr(s);
    return s;
}
char* VietHoa(char* s) //kí tự đầu
{
    strlwr(s);
    int i = 0;
    while(i < strlen(s))
    {
        if(s[i] == ' ')
            s[i+1] = toupper(s[i+1]);// hoặc s[i+1] =s[i+1] -32;
            // ham toupper can include <ctype.h>
        i++;
    }
    s[0] = toupper(s[0]);//viết hoa kí tự đầu
    return s;
}

//đếm số từ **

int demSotu (char* s)
{
    //khong xet truong hop chuoi s rong
    int dem=1;
    for(int i=0;i<strlen(s);i++)
    {
        if(temp[i]==' ')
            dem++; //đếm thêm 1 từ khi xác định 1 khoảng trắng
    }
    return dem;
}
// cách 2 dùng strchr
int demSotu_S (char* s)
{
    //khong xet truong hop chuoi s rong
    char*s1= new char[100];
    strcpy(s1,s);
    strcat(s1," ");
    char* p =strchr(s,' ');
    int dem=1;
    while(p!=NULL)
    {
        dem++;
        p=strchr(p+1,' '); //tìm từ kế tiếp
    }
   return dem;
}
//từ có k kí tự
int demSoTucoKkitu (char*s , int k)
{
    int sokt1tu = 0;//số kí tự trong 1 từ
    int sotukKitu=0;
    //vd : Que huong la chum khe ngot
    strcat(s," "); //thêm khoảng trắng vào chuỗi s
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]!=' ')
        {
            sokt1tu ++;
        }
        else{
            if(sokt1tu ==k)
            {
                sotukKitu++;
            }
            sokt1tu=0;
        }
    }

    return sotukKitu;

}

//tìm từ dài nhất

void* timtudainhat (char* s)
{
    int sokt1tu = 0;
    int sotukKitu=0;
    int vitriBD= 0;// của từ dài nhất

    int maxLength = 0;
    //vd : Que huong la chum khe ngot
    strcat(s,' '); //thêm khoảng trắng vào chuỗi s
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]!=' ')
        {
            sokt1tu ++;
        }
        else{
            if(sokt1tu > maxLength)
            {
                maxLength= sokt1tu;

                vitriBD= i- maxLength;
            }
            sokt1tu=0;
        }
    }
    char* temp=new char[100];
    strcpy(temp, s);
    temp= temp+ vitriBD;
    *(temp + maxLength)='\0';

   puts("Tu dai nhat la");
   puts(temp) ;
}

//đếm số từ bắt đầu bằng nguyên âm
int demtuNguyenAm(char* s)
{
    strlwr(s);
    int dem=0;

    For (int i=0;i<strlen(s);i++)
    {
        if(s[i] == ' ')
            if(s[i+1] ='a' || s[i+1] ='o'||s[i+1] ='i' ||s[i+1] ='e'||s[i+1] ='u';// hoặc s[i+1] =s[i+1] -32;
                dem++;
    }
    if(s[0] ='a' || s[0] ='o'||s[0] ='i' ||s[0] ='e'||s[0] ='u';// xét trường hợp từ đầu tiên
                dem++;
    return dem;
}
//vì dụ

void test()
{
    int* p=new int ;
    *p=10;
    *p++;
    int* q=new int ;
    q=p;
    cout<< *p;
    cout<<*q;
}


