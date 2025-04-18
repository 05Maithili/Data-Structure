#include <iostream>
using namespace std;

#define Max 10
int queue[Max];
int front = -1;
int rear = -1;

void dequeue_insert_rear(int num) {
    if (rear == Max - 1) {
        cout << "\nQueue is overflow....";
    } else {
        if (front == -1)
        front = 0;  
        rear++;
        queue[rear] = num;
    }
}

void dequeue_delete_front() {
    if (front == -1 || front > rear) {
        cout << "\nQueue is empty";
    } else {
        int num = queue[front];
        front++;
        cout << "\n" << num << " deleted...";
         
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void dequeue_insert_front(int num) {
    if (front == 0 || front==-1) {
        cout << "\nElement could not be inserted.";
    } else {
        if (front == -1) 
        front = 0;  
        front--;
        queue[front] = num;
    }
}

void dequeue_delete_rear() {
    if (rear == -1 || rear < front) {
        cout << "\nQueue is empty.";
    } else {
        int num = queue[rear];
        rear--;
        cout << "\n" << num << " deleted...";
        
        if (rear < front) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        cout << "\nQueue is empty.";
        return;
    }
    cout << "\nQueue elements are: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout<<"\nRear index is:\t"<<rear;
    cout<<"\nFront index is:\t"<<front;
}

int main() {
    int num;
    int ch;
    do {
        cout << "\nEnter your choice:";
        cout << "\n1. Insert at rear";
        cout << "\n2. Insert at front";
        cout << "\n3. Delete at front";
        cout << "\n4. Delete at rear";
        cout << "\n5. Display";
        cout << "\n6. Exit:\t";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter element:\t";
                cin >> num;
                dequeue_insert_rear(num);
                break;
            case 2:
                cout << "\nEnter element:\t";
                cin >> num;
                dequeue_insert_front(num);
                break;
            case 3:
                dequeue_delete_front();
                break;
            case 4:
                dequeue_delete_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "\nExiting....!";
                break;
            default:
                cout << "\nInvalid choice! Please try again.";
                break;
        }
    } while (ch != 6);

    return 0;
}
