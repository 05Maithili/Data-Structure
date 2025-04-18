#include<iostream>
using namespace std;

class Employee {
public:
    int Emp_id;
    int salary;
    string name;
    Employee* left;
    Employee* right;

    Employee(int id, int sal, string Name) {
        Emp_id = id;
        salary = sal;
        name = Name;
        left = right = NULL;
    }
};

class Operation {
public:
    Employee* insert(Employee* root, int id, int sal, string Name) {
        if (root == NULL) {
            return new Employee(id, sal, Name);
        }
        if (id < root->Emp_id) {
            root->left = insert(root->left, id, sal, Name);
        } else {
            root->right = insert(root->right, id, sal, Name);
        }
        return root;
    }

    void display(Employee* root) {
        if (root == NULL) {
            return;
        }
        display(root->left);
        cout << "\nID: " << root->Emp_id << "\tName: " << root->name << "\tSalary: " << root->salary;
        display(root->right);
    }

    void search(Employee* root, int key_id) {
        if (root == NULL) {
            cout << "\nEmployee not found!";
            return;
        }
        if (root->Emp_id == key_id) {
            cout << "\nEmployee found: ID: " << root->Emp_id << "\tName: " << root->name << "\tSalary: " << root->salary;
            return;
        }
        if (key_id < root->Emp_id) {
            search(root->left, key_id);
        } else {
            search(root->right, key_id);
        }
    }

    Employee* minValueNode(Employee* node) {
        Employee* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    Employee* deleteNode(Employee* root, int key_id) {
        if (root == NULL) return root;
        if (key_id < root->Emp_id) {
            root->left = deleteNode(root->left, key_id);
        } else if (key_id > root->Emp_id) {
            root->right = deleteNode(root->right, key_id);
        } else {
            if (root->left == NULL) {
                Employee* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Employee* temp = root->left;
                delete root;
                return temp;
            }
            Employee* temp = minValueNode(root->right);
            root->Emp_id = temp->Emp_id;
            root->name = temp->name;
            root->salary = temp->salary;
            root->right = deleteNode(root->right, temp->Emp_id);
        }
        return root;
    }

    void update(Employee* root, int key_id, int new_sal, string new_name) {
        if (root == NULL) {
            cout << "\nEmployee not found!";
            return;
        }
        if (root->Emp_id == key_id) {
            root->salary = new_sal;
            root->name = new_name;
            cout << "\nEmployee updated: ID: " << root->Emp_id << "\tName: " << root->name << "\tSalary: " << root->salary;
            return;
        }
        if (key_id < root->Emp_id) {
            update(root->left, key_id, new_sal, new_name);
        } else {
            update(root->right, key_id, new_sal, new_name);
        }
    }
};

int main() {
    Employee* root = NULL;
    Operation op;
    int ch, choice, id, sal, key_id, new_sal;
    string Name, new_name;
    do {
        cout << "\n1. Insert\n2. Display\n3. Search\n4. Delete\n5. Update\n6. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter Employee ID: ";
                cin >> id;
                cout << "\nEnter Name of Employee: ";
                cin >> Name;
                cout << "\nEnter Salary of Employee: ";
                cin >> sal;
                root = op.insert(root, id, sal, Name);
                break;
            case 2:
                op.display(root);
                break;
            case 3:
                cout << "\nEnter Employee ID to search: ";
                cin >> key_id;
                op.search(root, key_id);
                break;
            case 4:
                cout << "\nEnter Employee ID to delete: ";
                cin >> key_id;
                root = op.deleteNode(root, key_id);
                break;
            case 5:
                cout << "\nEnter Employee ID to update: ";
                cin >> key_id;
                cout << "\nEnter new Name of Employee: ";
                cin >> new_name;
                cout << "\nEnter new Salary of Employee: ";
                cin >> new_sal;
                op.update(root, key_id, new_sal, new_name);
                break;
            case 6:
                cout << "\nExiting....!!";
                break;
            default:
                cout << "\nInvalid choice...!!";
        }
        cout << "\nDo you want to continue(1/0): ";
        cin >> choice;
    } while (choice != 0);
    return 0;
}