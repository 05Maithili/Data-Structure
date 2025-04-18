#include<iostream>
#include<cstring>

using namespace std;

class Bst
{   
    public:
    int id;
    string name;

    Bst* left;
    Bst* right;

    Bst(int id1, string name1)
    {
        id=id1;
        name= name1;
        left=NULL;
        right=NULL;
    }

};

class Bstoperation{
    public:

    Bst* insert(Bst* root,int id1, string name1)
    {
        if(root == NULL)
        {
            root= new Bst(id1,name1);
            return root;
        }

        if(id1 >root->id)
        {
            root->right=insert(root->right,id1,name1);
        }
        if(id1 <root->id)
        {
            root->left=insert(root->left,id1,name1);
        }
        return root;
    }

    void display(Bst* root)
    {
        if (root==NULL)
        {
            return;
        }

        display(root->left);
        cout<<"ID: "<<root->id<<"Name: "<<root->name;
        display(root->right);
    }

    void 
};

int main()
{
    Bst * root=NULL;
    Bstoperation a;
    root=a.insert(root,1,"a");
    root=a.insert(root,3,"b");
    root=a.insert(root,2,"d");
    root=a.insert(root,0,"c");
    a.display(root);
    return 0;
}