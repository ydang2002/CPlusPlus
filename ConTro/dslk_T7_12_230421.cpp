#include <iostream>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
//tạo node
node* taoNode3 (int key)
{
    node* p=new node;
    p->key=key;
    p->next=NULL;
    return p;
}
// chèn 1 node vào đầu danh sách
//overloading
void insFirst (node* &head, node* p)
{
    //2 trường hợp
    //trường hợp danh sách rỗng, nghĩa là p là node đầu tiên
    //điều kiện danh sách rỗng head==NULL
    if(head==NULL)
    {
        head=p;
    }
    else{
        p->next = head;
        head=p;
    }
}
void insFirst_2 (node* &head, int key)
{
    node*p = taoNode3 (key);
    if(head==NULL)
    {
        head=p;
    }
    else{
        p->next = head;
        head=p;
    }
}
//chèn vào cuối danh sách
void insertLast (node* &head, node* t)
{
    if (head==NULL)//danh sách rỗng
    {
        head=t;
    }
    else
    {
        node* temp = head;
        while (temp->next!=NULL)
            temp=temp->next;
        // kết thúc vòng lặp thì temp là node cuối
        temp->next = t;
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
        while (temp->next!=NULL)
            temp=temp->next;
        // kết thúc vòng lặp thì temp là node cuối

        temp->next = t;
    }
}
void insAfter (node* &head, int data, int k)
{

        node* temp = head;
        //tìm vị trí node có giá trị k
        while (temp!=NULL && temp->key!=k)
            temp=temp->next;
        // kết thúc vòng lặp thì temp =NULL nghĩa là ko tìm thấy node =k
        if(temp==NULL)
            cout<<"khong ton tai node co gia tri = "<<k;
        else{
          // kết thúc vòng lặp thì temp !=NULL nghĩa là
          //temp đang trỏ tới node có giá trị bằng k
          node*p =taoNode3(data);
          p->next= temp->next;
          temp->next=p;
        }

}

void insBefore (node* &head, int data, int k)
{

        node* temp = head;
        //tìm vị trí node có giá trị k
        while (temp!=NULL && temp->key!=k)
            temp=temp->next;
        // kết thúc vòng lặp thì temp =NULL nghĩa là ko tìm thấy node =k
        if(temp==NULL)
            cout<<"khong ton tai node co gia tri = "<<k;
        else{
          // kết thúc vòng lặp thì temp !=NULL nghĩa là
          //temp đang trỏ tới node có giá trị bằng k

          node* q=new node;
          *q=*temp;
          temp->next = q;
          temp->key = data;
        }

}

void duyet (node* head)
{
    node* temp=head;
    while(temp !=NULL)
    {
        //làm gì
        cout<<"Node co gia tri = "<<temp->key<<"\n";
        // di chuyển qua node kế tiếp
        temp=temp->next;

    }
}

//tim tổng các node
int tinhTong (node* head)
{
    node* temp=head;
    int sum=0;
    while(temp !=NULL)
    {
        //làm gì
        sum=sum+temp->key;
        // di chuyển qua node kế tiếp
        temp=temp->next;

    }
    return sum;
}

void insFisrt_3 (node* &head, node*& tail, int data)
{
    //xét danh sách rỗng
    node* p =taoNode3(data);
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else{
        p->next=head;
        head=p;
    }
}
void insLast_3 (node* &head, node*& tail, int data)
{
    //xét danh sách rỗng
    node* p =taoNode3(data);
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else{
        tail->next=p;
        tail=p;
    }
}

void delFirst (node* &head, node*& tail)
{
    //xét trường hợp danh sách có 1 node
    if(head==tail)
    {
        node* temp=head;
        head=tail=NULL;
        free(temp);
    }
    else{
        node* temp=head;
        head =head ->next;
        free(temp);
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
    node* t= taoNode3 (100);
    insertFirst(head, t);
    insertFirst_2 (head,8);
    insertFirst_2 (head,20);
    insertFirst_2 (head,99);
    insertLast_2(head,11);
    duyet(head);
}
