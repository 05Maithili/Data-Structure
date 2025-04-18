#include<iostream>
#include<stack>
#include<string>
using namespace std;

class FT
{
    public:
    string name;
    FT* left;
    FT* right;

    FT(string Name)
    {
        name=Name;
        left=NULL;
        right=NULL;
    }
};

class family
{
    public:
    FT* node;

    void Insert(FT* node,string Name )
    {
        if (node == NULL)
        {
            node = new FT(Name);
            return;
        }
        char ch1;
        cout << "\nEnter where do you want to Insert member (left[l]/right[r]) of " << node->name << " : ";
        cin >> ch1;
        if (ch1 == 'l' || ch1 == 'L')
        {
            if (node->left == NULL)
                node->left = new FT(Name);
            else
                Insert(node->left, Name);
        }
        else
        {
            if (node->right == NULL)
                node->right = new FT(Name);
            else
                Insert(node->right, Name);
        }
    }

 

    



    void Displaypostorder(FT *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->name<< " ";
        Displaypostorder(root->left);
        Displaypostorder(root->right);
         
    }
};

int main()
{
    int ch,n;
    FT* root = NULL;
    family f;
    string Name;

    FT* oldestMember = NULL; // Declare outside switch
    do
    {
        cout<<"\nEnter your choice:\n1.Insert New member\n2.Search member\n3.Update information\n4.Find ancestors\n5.Find descendants\n6.Find Sibling\n7.Find oldest member\n8.Count Family member\n9.Display\n10.Exit:";
        cin>>ch;
        switch(ch)
        {
            case 1://Insert New member
                if (root == NULL)
                {
                    cout << "\nEnter Name of member: ";
                    cin >> Name;
                    root = new FT(Name);
                }
                else
                {
                    cout << "\nEnter Name of member: ";
                    cin >> Name;
                    f.Insert(root,Name);
                }
                break;
               
            case 3://Display
                cout << "\nDisplaying Family Tree in postorder: ";
                f.Displaypostorder(root);
                cout << endl;
                break;
            case 10://Exit
                break;                                
        }
         
    } while (ch != 4);
    
    return 0;
}