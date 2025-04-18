#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        data=0;
        next=NULL;
        prev=NULL;
    }
};

class Doublylinkedlist
{
    private:
    Node * head;
    public:
    Doublylinkedlist()
    {
        head=NULL;
    }

    void insertion(int val)
    {
        Node* newnode=new Node();
        newnode->data=val;
        if(head==NULL)
        {
            newnode->next=NULL;
            newnode->prev=NULL;
            head=newnode;
        }
        else
        {
            Node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=NULL;
        }
    }

    void deletion(int val)
    {
         Node* temp=head;
         
         if(head->next==NULL && temp->data==val)
         {
            free(head);
            head=NULL;
         }
         else if(temp->next==NULL && temp->data==val)
         {

         }
    }
    void display()
    {
        Node* temp=head;

        if(temp==NULL)
        {
             cout<<"Linked list is empty"<<endl;
        }

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

     
};

int main()
{
    Doublylinkedlist dll;
    dll.insertion(1);
    dll.insertion(2);
    dll.insertion(3);
    dll.display(); 
    return 0;
}