#include <iostream>
#include <string>
using namespace std;
struct node
{
    string words;
    int degree;
    node *prior;
    node *next;
    node()
    {
        degree = 1;
        prior = NULL;
        next = NULL;
    }
    node(string str, node* p =NULL, node* n=NULL)
    {
        words = str; prior = p; next = n;
    }

};

class DbLinkList
{
protected:
    node *head;
    int length;
public:
    DbLinkList();
    DbLinkList(string str[],int len);
    virtual ~DbLinkList();
    bool Empty() const;
    void Clear();
    void Show() const;
    void Find(string W);
    void Delete(string W);
    void Sort();
    void insert(string g);
};
DbLinkList::DbLinkList()
{
    head = new node;
    head->prior = head->next = head;
    length = 0;
}
DbLinkList::DbLinkList(string str[],int len)
{

    head = new node;
    node *p = head;
    for(int i=0;i<len;i++)
    {
        p->next = new node(str[i], p);
        p->next->degree = 1;
        p = p->next;
    }
    length = len;
    head->prior = p;
    p->next = head;
    Sort();
}
DbLinkList::~DbLinkList()
{
    Clear();
    delete head;
}
bool DbLinkList::Empty() const
{
    return head->next = head;
}
void DbLinkList::Clear()
{
    node* p;
    p = head->next;
    while(p!=head)
    {
        head->next = head->next->next;
        head->next->prior = head;
        delete p;
        p = head->next;
    }
}
void DbLinkList::Show() const
{
    node *p ;
    int t = 0;
    p=head->next;
    if(p == head)
    {
        cout<<"It's Empty\n";
        return;
    }
    while(p != head)
    {
        cout<<p->degree<<" "<<p->words<<endl;
        p=p->next;
    }

}
void DbLinkList::insert(string g)
{
    node *p = new node;
    p->words = g;
    p->degree = 1;
    head->prior->next = p;
    p->next = head;
    head->prior = p;
    cout<<p->words<<" was appended\n";
}
void DbLinkList::Find(string W)
{
    bool flag = false;
    node *p = head;
    p = p->next;
    while(p != head)
    {
        if(p->words ==  W)
        {
            ++(p->degree);
            cout<<"Find "<<p->words<<endl;
            flag = true;

            break;
        }
        p=p->next;
    }Sort();
    if(!flag)
    {
        insert(W);
        cout<<"Not Found\n";
    }
}
void DbLinkList::Delete(string W)
{
    node* p = head;
    p = p->next;
    while(p != head)
    {
        if(p->words == W)
        {
            p->prior->next = p->next;
            p->next->prior = p->prior;
            cout<<p->words<<" was Deleted\n";
            delete p;

            break;
        }
        p=p->next;
    }
}
void DbLinkList::Sort()
{
    node* p0;
    node* p;
    node* p1;
    node* p2;
    p1 = head->next;//oldLink

    head->next = head;
    head->prior = head;
    p0 = head->next;
    while(p1!=head)
    {
        p = p1;
        p1 = p1->next;
        while(p->degree < p0->degree && p0!=head)
            p0 = p0->next;

        p0->prior->next = p;
        p->prior = p0->prior;
        p->next = p0;
        p0->prior = p;
        p0 = head->next;
    }

}

int main()
{
    /**********TEST***********/
    string str[5]={"AC","aA","bc","dd","tttt"};

    DbLinkList t(str,5);
    t.Show();
    t.Delete("AC");
    t.Show();
    t.insert("pp");
    t.Find("dd");
    t.Show();
    t.Clear();

    t.Show();
    if(t.Empty())
        cout<<0<<endl;
    /**********TEST************/
    return 0;
}
