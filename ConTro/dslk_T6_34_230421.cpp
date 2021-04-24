//@dinh khai
//danh sach lien ket cac node
//su dung con tro head tro den node dau tien
#include <iostream>
using namespace std;
struct node
{
    int x;
    struct node* pnext;
};
struct linklist
{
    node* head;
    node* tail;
};

void taoNode1 (node &p)
{
    cin>>p.x;
    p.pnext=NULL;
}
void taoNode2 (node* &p)
{
    p=new node;
    cin>>p->x;
    p->pnext=NULL;
}
node* taoNode3 (int n)
{
    node* p=new node;
    p->x=n;
    p->pnext=NULL;
    return p;
}

void duyet (node* head)
{
    if(head==NULL)
        cout<<"Danh sach rong !\n";
    else{
      while (head!=NULL)
    {
        cout<<"gia tri cua node = "<< head->x <<"\n";
        head=head->pnext;
    }
    }

}
//thu 6 ngay 23/04
int tinhTong (node* head)
{
    int sum=0;
    if(head==NULL)
        {
            cout<<"Danh sach rong !\n";
        }
    else{
      while (head!=NULL)
        {
            sum=sum+ head->x ;
            head=head->pnext;
        }
    }
    return sum;
}
bool timK (node* head, int k)
{

    if(head==NULL)
    {
            cout<<"Danh sach rong !\n";
            return false;
    }
    else
    {
      while (head!=NULL&&head->x!=k)
      {

            head=head->pnext;
      }
        if(head->x==k)
            return true;

    }
    return false;
}

bool timK (node* head, int k)
{
    bool timthay=false;
    if(head==NULL)
    {
            cout<<"Danh sach rong !\n";
    }
    else
    {
      while (head!=NULL&&timthay==false)
      {
            if(head->x==k)
                timthay=true;
            head=head->pnext;
      }

    }
    return timthay;
}
void insertFirst (node* &head, node* t)
{
    if (head==NULL)
    {
        head=t;
    }
    else
    {
        t->pnext=head;
        head=t;
    }
}

void insertFirst_2 (node* &head, int n)
{
    node* t=taoNode3(n);
    if (head==NULL)
    {
        head=t;
    }
    else
    {
        t->pnext=head;
        head=t;
    }
}


void insertLast (node* &head, node* t)
{
    if (head==NULL)
    {
        head=t;
    }
    else
    {
        node* temp = head;
        while (temp->pnext!=NULL)
            temp=temp->pnext;
        // kết thúc vòng lặp thì temp là node cuối
        temp->pnext = t;
    }
}
void insertLast_2 (node* &head, int key)
{
    node* t=taoNode3(key);
    if (head==NULL)
    {
        head=t;
    }
    else
    {
        node* temp = head;
        while (temp->pnext!=NULL)
            temp=temp->pnext;
        // kết thúc vòng lặp thì temp là node cuối

        temp->pnext = t;
    }
}

void insAfter (node* head, int k, int key)
{
    node*temp=head;
    while(temp!=NULL&&temp->x!=k)
        temp=temp->pnext;
    //vong lap dừng
    if(temp==NULL)
    {
        cout<<"KHong tim thay phan tu co gia tri = "<<k;
    }
    //temp la node co gia tri bang k
    else{
        node* t= taoNode3(key);
        t->pnext=temp->pnext;
        temp->pnext=t;
    }
}

void insBefore (node* & head, int k, int key)
{
    node*temp=head;
    while(temp!=NULL&&temp->x!=k)
        temp=temp->pnext;
    //vong lap dừng
    if(temp==NULL)
    {
        cout<<"KHong tim thay phan tu co gia tri = "<<k;
    }
    //temp la node co gia tri temp->x bang k
    else{
        node* t= new node;
        *t=*temp;
        //sau khi gán thì t->x== k==temp->x;
        //t->pnext==temp->next
        temp->next=t;
        temp->x=key;
    }
}

void taoDanhsach (node* &head, int n)
{
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        insertFirst_2(head,temp);
    }
}
void xoaDau (node* &head)
{
        //xet them dieu kien co 1 node hoac ds rong
        node*temp =head;
        head=head->next;
        free(temp);
}

void themDau (linklist* &list, int k)
{
    node* p= taoNode3(k);
    if(list->head == NULL)
    {
        list->head=list->tail=p;
    }
    else{
        p->pnext=list->head;
        list->head=p;
    }
}

void themDau_2 (node* &head, node*&tail, int k)
{
    node* p= taoNode3(k);
    if(head == NULL)
    {
        head=tail=p;
    }
    else{
        p->pnext=head;
        head=p;
    }
}
void themCuoi_2 (node* &head, node*&tail, int k)
{
    node* p= taoNode3(k);
    if(head == NULL)
    {
        head=tail=p;
    }
    else{
        tail->pnext=p;
        tail=p;
    }
}

int main()
{
    /*node p;
    taoNode1 (p);
    cout<< p.x;

    node* p;
    taoNode2 (p);
    cout<<"gia tri con tro tro den la = "<<p->x;
    */
    node*p=taoNode3 (20);
    cout<<"gia tri con tro tro den la = "<< p->x <<"\n";
    node*q=taoNode3 (50);
    cout<<"gia tri con tro tro den la = "<< q->x <<"\n";
    p->pnext=q;
    node*k=taoNode3 (90);
    cout<<"gia tri con tro tro den la = "<< k->x <<"\n";
    q->pnext=k;
    /*
    node*head=p;
    duyet(head);
    */
    //chen node t
    node* head= NULL;
    node* tail==NULL;
    node* t= taoNode3 (100);
    insertFirst(head, t);
    insertFirst_2 (head,8);
    insertFirst_2 (head,20);
    insertFirst_2 (head,99);
    insertLast_2(head,11);
    duyet(head);
}
