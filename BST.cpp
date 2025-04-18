#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int id;
    string name;
    float salary;
    Employee* left;
    Employee* right;

    Employee(int empID, string empName, float empSalary) {
        id = empID;
        name = empName;
        salary = empSalary;
        left = right = NULL;
    }
};

// Insert Employee (Sorted by ID)
Employee* insert(Employee* root, int id, string name, float salary) {
    if (root == NULL) {
        return new Employee(id, name, salary);
    }
    if (id < root->id) {
        root->left = insert(root->left, id, name, salary);
    } else {
        root->right = insert(root->right, id, name, salary);
    }
    return root;
}

// Search Employee by ID
Employee* search(Employee* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }
    if (id < root->id) {
        return search(root->left, id);
    }
    return search(root->right, id);
}

// Find Minimum Employee by ID
Employee* findMin(Employee* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Find Maximum Employee by ID
Employee* findMax(Employee* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Delete Employee by ID
 

// Update Employee Name (ID and Salary remain unchanged)
Employee* updateEmployee(Employee* root, int id, string newName) {
    Employee* emp = search(root, id);
    if (emp != NULL) {
        emp->name = newName;
    }
    return root;
}

// Inorder Traversal (Sorted Order of Employees)
void inorder(Employee* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << "ID: " << root->id << ", Name: " << root->name << ", Salary: " << root->salary << endl;
        inorder(root->right);
    }
}

 
// Function to calculate total employees and total salary
void calculateTotal(Employee* root, int& count, float& totalSalary) {
    if (root == NULL) return;
    count++;
    totalSalary += root->salary;
    calculateTotal(root->left, count, totalSalary);
    calculateTotal(root->right, count, totalSalary);
}

// Compute Average Salary
float averageSalary(Employee* root) {
    int count = 0;
    float totalSalary = 0.0;
    calculateTotal(root, count, totalSalary);
    return (count == 0) ? 0 : totalSalary / count;
}

// Main Function
int main() {
    Employee* root = NULL;
    int choice, id;
    string name;
    float salary;

    do {
        cout << "\n1. Insert Employee\n2. Search Employee \n3. Update Employee Name\n4. Inorder Traversal";
        cout << " \n5. Find Min Employee\n6. Find Max Employee";
        cout << "\n7. Average Salary\n0. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID, Name, Salary: ";
                cin >> id;
                cin.ignore();
                getline(cin, name);
                cin >> salary;
                root = insert(root, id, name, salary);
                break;

            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                if (search(root, id)) cout << "Employee found!\n";
                else cout << "Employee not found!\n";
                break;

            case 3:
                cout << "Enter Employee ID and new Name: ";
                cin >> id;
                cin.ignore();
                getline(cin, name);
                root = updateEmployee(root, id, name);
                break;

            case 4:
                inorder(root);
                break;

            case 5:
                cout << "Minimum Employee ID: " << findMin(root)->id << endl;
                break;

            case 6:
                cout << "Maximum Employee ID: " << findMax(root)->id << endl;
                break;

            case 7:
                cout << "Average Salary: " << averageSalary(root) << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}