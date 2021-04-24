#include <iostream>
using namespace std;

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
    node *p=new node;
    p->data = x;
    p->next = NULL;
    return p;
}

void ThemNODEVaoDau(list& l, node* p)
{
    if (l.head == NULL)
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

//them node key sau node k;
void ThemNODE_p_sauNODE_k(list& l, node* p)
{
    int x;
    cout << "\n Nhap gia tri node k: ";
    cin >> x;
    node* k = TaoNODE(x);
   if (k->data == l.head->data && l.head == NULL)
    {
        ThemNODEVaoCuoi(l, p);
    }
    else
    {
        //duyet dau danh sach den cuoi danh
        for (node* i = l.head; i != NULL; i = i->next)
        {
            if (k->data == i->data)
            {
                node* temp2 = TaoNODE(p->data);
                node* temp = i->next;
                temp2->next = temp;
                i->next = temp2;
            }

        }
    }
}
//them node key sau node k
void insAfter(list&l, int &k, int &key)
{
    cout << "\n Nhap gia tri k: ";
    cin >> k;
    cout << "\nNhap gia tri KEY can them vao: ";
    cin >> key;
    node* temp = l.head;
    while (temp != NULL && temp->data != k)
        temp = temp->next;
    //vong lap dừng
    if (temp == NULL)
    {
        cout << "KHong tim thay phan tu co gia tri = " << k;
    }
    //temp la node co gia tri bang k
    else 
    {
        node* t = TaoNODE(key);
        t->next = temp->next;
        temp->next = t;
    }
}

//them node key truoc node k
void insBefore(list &l, int &k, int &key)
{
    cout << "\n Nhap gia tri k: ";
    cin >> k;
    cout << "\nNhap gia tri KEY can them vao: ";
    cin >> key;
    node* temp = l.head;
    while (temp != NULL && temp->data != k)
        temp = temp->next;
    //vong lap dừng
    if (temp == NULL)
    {
        cout << "KHong tim thay phan tu co gia tri = " << k;
    }
    //temp la node co gia tri temp->x bang k
    else {
        node* t = new node;
        *t = *temp;
        //sau khi gán thì t->x== k==temp->x;
        //t->pnext==temp->next
        temp->next = t;
        temp->data = key;
    }
}

//tìm node k có return true,khong co return false,cách nay cua thầy
//cach 1
bool TimK1(list &l, int &k)
{
    cout << "\nNhap gia tri k: ";
    cin >> k;
    bool timthay = false;
    if (l.head == NULL)
    {
        cout << "Danh sach rong !\n";
    }
    else
    {
        while (l.head != NULL && timthay == false)
        {
            if (l.head->data == k)
                timthay = true;
            l.head = l.head->next;
        }

    }
    return timthay;
}

//cách cua mình
//tim gia tri k 
int TimK(list l)
{
    //nhap gia tri k can tim
    int k;
    cout << "\nNhap gia tri k can tim:";
    cin >> k;
    if (l.head == NULL)
    {
        cout << "Danh sach rong !\n";
    }
    for (node* i = l.head; i != NULL; i = i->next)
    {
        if (k == i->data)
        {
            return 1;
        }
    }
    return 0;
}

void Xuat(list l)
{
    node* temp = l.head;
    while (temp != NULL)
    {
        cout << "\t" << temp->data;
        temp = temp->next;
    }
}

void NhapNODE(list &l)
{
    int x, n;
    cout << " \n nhap so luong node vao danh sach: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\n nhap gia tri x: ";
        cin >> x;
        node* p = TaoNODE(x);
        cout << p->data << endl;
        ThemNODEVaoCuoi(l, p);
    }
}

//kiem tra so nguyen to
bool check(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

//dem so nguyen to trong danh sach lien ket
void DemSoNguyenTo(list& l)
{
    int dem = 0;
    for (node* i = l.head; i != NULL; i = i->next)
    {
        if (check(i->data) == true)
        {
            dem++;
        }
    }
    cout << "\n Co " << dem << " so nguyen to" << endl;
}

/*int main()
{
    list(l);
    KhoiTao(l);
    NhapNODE(l);
    //them node vao dau them node vao cuoi cách của thầy
    int k, key;
    insAfter(l,k,key);
    //insBefore(l, k, key);
    //cout<<TimK1(l, k);
    //cout << TimK(l);

    /*int x;
    cout << "\n nhap gia tri p: ";
    cin >> x;
    node* p = TaoNODE(x);
    cout << p->data << endl;
    ThemNODE_p_sauNODE_k(l, p);*/
    /*
    //them node vao dau va them node vao cuoi
    int x, n;
    cout << " \n nhap so luong node: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\n nhap gia tri x: ";
        cin >> x;
        node* p = TaoNODE(x);
        cout << p->data << endl;
        //ThemNODEVaoDau(l, p);
        //ThemNODEVaoCuoi(l,p);
        ThemNODE_h_sauNODE_k(l, p);
    }*/
    //Xuat(l);
    /*int x, n;
    cout << " \n nhap so luong node: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\n nhap node x: ";
        cin >> x;
        node* p = TaoNODE(x);
        cout << p->data << endl;
        ThemNODEVaoCuoi(l, p);
    }
    Xuat(l);
}*/

int main()
{
    list(l);
    KhoiTao(l);
    NhapNODE(l);
    int x, n, g;
    cout << " \n nhap so luong node vao dau danh sach: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\n nhap node x can them dau: ";
        cin >> x;
        node* p = TaoNODE(x);
        ThemNODEVaoDau(l, p);
    }
    cout << " \n nhap so luong node vao cuoi danh sach: ";
    cin >> g;
    for (int i = 0; i < g; i++)
    {
        cout << "\n nhap node x can them vao cuoi: ";
        cin >> x;
        node* p = TaoNODE(x);
        ThemNODEVaoCuoi(l, p);
    }
    Xuat(l);
    /*int x;
    cout << "\n them node p vao sau node k";
    cout << "\n nhap gia tri p: ";
    cin >> x;
    node* p = TaoNODE(x);
    cout << p->data << endl;
    ThemNODE_p_sauNODE_k(l, p);*/
    int k, key;
    insAfter(l, k, key);
    insBefore(l, k, key);
    Xuat(l);
    cout << "\nTim node k roi return ve 0 || 1";
    cout << TimK(l);
    cout << "\nSo luong so nguyn to:";
    DemSoNguyenTo(l);
}

