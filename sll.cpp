#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertathead(node* &head,int val)
{
    node* new_node=new node(val);
    new_node->next=head;
    head=new_node;
    
}
void insertattail(node* &head,int val)
{
    node* new_node=new node(val);
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}
void insertatposition(node* &head,int pos,int val)
{
    node* new_node=new node(val);
    node* temp=head;
    int current_pos=0;
    while(current_pos!=pos-1)
    {
           temp=temp->next;
           current_pos++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void deleteathead(node* &head)
{
    node* temp=head;
    head=head->next;
    free(temp);
}
void deleteattail(node* &head)
{
    if (head == NULL) return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteatpos(node* &head,int pos)
{
    int current_pos=0;
    node* temp=head;
    while(current_pos!=pos-1)
    {
        temp=temp->next;
        current_pos++;
    }
    node* temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
}

void searching(node* &head,int val)
{
    node* temp=head;
    int flag=0;
    while(temp!=NULL)
    {
        if(val==temp->data)
        {
            flag=1;
            cout<<"\nElement founded ";
            break;
        }
        temp=temp->next;
    }
    if(flag!=1)
    {
        cout<<"\nElement not found";
    }
}

void updatedata(node* &head,int pos,int val)
{
    node* temp=head;
    int current_pos=0;
    while(current_pos!=pos)
    {
         temp=temp->next;
         current_pos++;
    }
    temp->data=val;
}

void display(node* head)
{
    node* temp=head;
    if(temp==NULL)
    {
        cout<<"\nLinked list is empty";
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL\n ";
}
int main()
{
    node *head=NULL ;
    insertathead(head,3);
    display(head);
    insertathead(head,4);
    display(head);
    insertattail(head,7);
    display(head);
    insertatposition(head,1,9);
    display(head);
    /*deleteathead(head);
    display(head);
    deleteattail(head);
    display(head);*/
    deleteatpos(head,2);
    display(head);
    searching(head,9);
    searching(head,0);
    updatedata(head,1,5);
    display(head);
     return 0;
}