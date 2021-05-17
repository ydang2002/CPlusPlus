#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct list
{
    node* head;
};

struct list2
{
    node* head;
    node* tail;
};

void KhoiTao(list2& l)
{
    l.head = NULL;
    l.tail = NULL;
}

node* TaoNode(int x)
{
    node* p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}

void ThemNodeVaoDau(node*& head, node* p)
{
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}

void ThemDau(list2*& l, int k)
{
    node* p = TaoNode(k);
    if (l->head=NULL)
    {
        l->head = l->tail = p;
    }
    else
    {
        p->next = l->head;
        l->head = p;
    }
}
void ThemVaoCuoi(node* &head, node* p)
{
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void Xuat(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << "\t" << temp->data;
        temp = temp->next;
    }
}

void xuat(node* head)
{
    for (node* i = head; i != NULL; i = i->next)
    {
        cout << i->data << "\t";
    }
}

int TinhTong(node* head)
{
    int sum = 0;
    if (head==NULL)
    {
        cout << "danh sach rong";
    }
    else
    {
        while (head!=NULL)
        {
            sum = sum + head->data;
            head = head->next;
        }
    }
    return sum;
}

int TimX(node* head,int k)
{
    bool timthay = false;
    if (head == NULL)
    {
        cout << "danh sach rong";
    }
    else
    {
        while (head != NULL &&timthay==false)
        {
            if (head->data == k)
            {
                timthay = true;
                head = head->next;//kiem tra
            }
        }

    }
    return timthay;
}

void insAfter(node* head, int k, int key)
{
    /*int k;
    cout << "\n nhap gia tri k: ";
    cin >> k;*/
    node* temp = head;
    while (temp!=NULL&&temp->data!=k)
    {
        if (temp=NULL)
        {
            cout << "khong tim thay phan tu co gia tri= " << k;
        }
        else
        {
            node* t = TaoNode(key);
            t->next = temp->next;
            temp->next = t;
        }
    }

}

void insBefor(node *head, int k, int key)
{
    node*temp = head;
    while (temp!=NULL&&temp->data!=k)
    {
        temp = temp->next;
    }

}

void XoaDau(node* &head)
{
    node* temp = head;
    head = head->next;
    free(temp);
}

void XoaCuoi(list2*& l)
{
    if (l->head==l->tail)
    {
        node* p = l->head;

    }
}

int main()
{
    list2(l);
    KhoiTao(l);
    int n;
    cout << "\n nhap so luong node can them: ";
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {

        cout << "\n nhap gia tri so nguyen: ";
        cin >> x;
        node* p = TaoNode(x);
        cout << p->data;
        ThemDau(l, x);
    }
    /*//node* head = NULL;
    int n, k;
    cout << "\n nhap so luong node can them: ";
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {

        cout << "\n nhap gia tri so nguyen: ";
        cin >> x;
        node* p = TaoNode(x);
        cout << p->data;
        //ThemNodeVaoDau(head, p);
        //ThemVaoCuoi(head, p);
        //TinhTong(head);
        //TimX(head, k);
        ThemDau(l, x);
    }
    
    
    cout << "\ndanh sach lien ket don";
    Xuat(head);
    return 0;*/
}

