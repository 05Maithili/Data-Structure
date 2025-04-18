#include <iostream>
#include <cstring>
using namespace std;

#define MAX 5  

 
class Order {
public:
    char customerName[50];
    int pizzatype;
    int pizzaSize;    
    int quantity;

     
    void takeOrder() {
        cout << "Enter customer name: ";
        cin.ignore();  
        cin.getline(customerName, 50);

        cout << "Enter pizza name (1 for Paneer pizza, 2 for Pineapple pizza, 3 Extra chees pizza): ";
        cin>>pizzatype;

        cout << "Enter pizza size (1 for Small, 2 for Medium, 3 for Large): ";
        cin >> pizzaSize;

        cout << "Enter pizza quantity: ";
        cin >> quantity;
    }

     
    void displayOrder() {
        cout << "Customer Name: " << customerName << endl;
        cout << "Pizza Name: " << pizzatype << endl;
        switch (pizzatype) {
            case 1: cout << "Paneer Pizza"; break;
            case 2: cout << "Pineapple Pizza"; break;
            case 3: cout << "Extra chees Pizza"; break;
            default: cout << "Unknown Pizza"; break;
        }
        cout << "Pizza Size: ";
        switch (pizzaSize) {
            case 1: cout << "Small"; break;
            case 2: cout << "Medium"; break;
            case 3: cout << "Large"; break;
            default: cout << "Unknown size"; break;
        }
        cout << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

 
class PizzaParlor {
    int front, rear;
    Order orders[MAX];  

public:
    PizzaParlor() {
        front = -1;
        rear = -1;
    }
 
    void placeOrder() {
        if (rear == MAX - 1) {
            cout << "Sorry, the parlor cannot accept more orders at the moment.\n";
        } else {
            if (front == -1) front = 0;  
            rear++;
            orders[rear].takeOrder(); 
            cout << "Order placed successfully.\n";
        }
    }

     
    void serveOrder() {
        if (rear == -1 || front > rear) {
            cout << "No orders to serve.\n";
        } else {
            cout << "Serving order for:\n";
            orders[front].displayOrder(); 
            front++;
            if (front > rear) {  
                front = rear = -1;
            }
        }
    }

     
    void displayOrders() {
        if (front == -1 || front > rear) {
            cout << "No current orders.\n";
        } else {
            cout << "Current orders in queue:\n";
            for (int i = front; i <= rear; i++) {
                cout << "\nOrder " << (i - front + 1) << ":\n";
                orders[i].displayOrder();
            }
            cout << endl;
        }
    }
};

int main() {
    PizzaParlor parlor;
    int choice;

    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                parlor.placeOrder();
                break;

            case 2:
                parlor.serveOrder();
                break;

            case 3:
                parlor.displayOrders();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
