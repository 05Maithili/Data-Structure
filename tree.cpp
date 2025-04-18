#include <iostream>
#include<stack>
using namespace std;

class BT
{
public:
    int data;
    BT *left;
    BT *right;

    BT(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a node into the binary tree
void Insert(BT*& root, int val)
{
    if (root == NULL)
    {
        root = new BT(val);
        return;
    }
    char ch1;
    cout << "\nEnter where do you want to enter (left[l]/right[r]) of " << root->data << " : ";
    cin >> ch1;
    if (ch1 == 'l' || ch1 == 'L')
    {
        if (root->left == NULL)
            root->left = new BT(val);
        else
            Insert(root->left, val);
    }
    else
    {
        if (root->right == NULL)
            root->right = new BT(val);
        else
            Insert(root->right, val);
    }
}

// Function to display the tree in pre-order
void Displaypreorder(BT *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Displaypreorder(root->left);
    Displaypreorder(root->right);
}

void Displayinorder(BT *root)
{
     if(root==NULL)
     {
        return;
     }
    Displayinorder(root->left);
    cout << root->data << " ";
    Displayinorder(root->right);
}

void Displaypostorder(BT *root)
{
     if(root==NULL)
     {
        return;
     }
    Displaypostorder(root->left); 
    Displaypostorder(root->right);
    cout << root->data << " ";
}

void leafnode(BT *root)
{
     if(root==NULL)
     {
        return;
     }
     if(root->left==NULL && root->right==NULL)
     {
        cout << root->data << " ";
        return; 
     }
     leafnode(root->left);
     leafnode(root->right); 
}

int count(BT * root)
{
     if(root==NULL)
     {
        return 0;
     }
     return 1+count(root->left)+count(root->right);
}

int heightOfTree(BT* root)
{
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool findAncestors(BT* root, int target) {
    if (root == NULL) {
        return false;
    }
    if (root->data == target) {
        return true;
    }
    if (findAncestors(root->left, target) || findAncestors(root->right, target)) {
        cout << root->data << " ";
        return true;
    }
    return false;
}

void iterativePreorder(BT* root)
{
    if (root == NULL) {
        return;
    }

    stack<BT*> s;
    s.push(root);

    while (!s.empty()) {
        BT* currentNODE = s.top();
        s.pop();

        cout << currentNODE->data << " ";

        // Push right child first so that left is processed first
        if (currentNODE->right) {
            s.push(currentNODE->right);
        }
        if (currentNODE->left) {
            s.push(currentNODE->left);
        }
    }
}

void iterativeInorder(BT* root)
{
    if (root == NULL) {
        return;
    }

    stack<BT*> s;
    BT* Node;
    while(root!=NULL || !s.empty())
    {
        while(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
        Node=s.top();
        s.pop();
        cout << Node->data << " ";
    }
}


int main()
{
    BT *root = NULL;
    int choice, val, n, target;

    do
    {
        cout << "\nEnter your choice\n1.Create Root\n2.Insert Node\n3.Pre-order Tree\n4.In-order\n5.Post-order\n6.Leaf Node\n7.Total Nodes\n8.Height of Tree\n9.Find Ancestors\n10.Iterative Pre-order\n11.Exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (root == NULL)
            {
                cout << "\nEnter root node value: ";
                cin >> val;
                root = new BT(val);
            }
            else
            {
                cout << "\nRoot already exists!";
            }
            break;

        case 2:
            if (root == NULL)
            {
                cout << "\nCreate a root first!";
            }
            else
            {
                cout << "\nEnter node value: ";
                cin >> val;
                Insert(root, val);
            }
            break;

        case 3:
            cout << "\nPre-order Traversal: ";
            Displaypreorder(root);
            cout << endl;
            break;

        case 4:
            cout << "\nIn-order Traversal: ";
            Displayinorder(root);
            cout << endl;
            break;

        case 5:
            cout << "\nPost-order Traversal: ";
            Displaypostorder(root);
            cout << endl;
            break;

        case 6:
            cout << "\nLeaf Nodes: ";
            leafnode(root);
            cout << endl;
            break;

        case 7:
            n = count(root);
            cout << "\nTotal Nodes: " << n;
            cout << endl;
            break;

        case 8:
            n = heightOfTree(root);
            cout << "\nHeight of Tree: " << n;
            cout << endl;
            break;

        case 9:
            cout << "\nEnter the target node value to find its ancestors: ";
            cin >> target;
            cout << "\nAncestors of " << target << ": ";
            if (!findAncestors(root, target)) {
                cout << "Node not found";
            }
            cout << endl;
            break;

        case 10:
            cout << "\nIterative Pre-order Traversal: ";
            iterativePreorder(root);
            cout << endl;
            break;

        case 11:
            cout << "\nExiting program....!!\n";
            break;

        default:
            cout << "\nInvalid input!!";
            break;
        }
    } while (choice != 11);

    return 0;
}
