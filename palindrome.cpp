#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Function to push an element onto the stack
void push(char stack[], int &top, char value) {
    top++;
    stack[top] = value;
}

// Function to pop an element from the stack
char pop(char stack[], int &top) {
    char value = stack[top];
    top--;
    return value;
}

// Function to check if a given string is a palindrome using stack concept
int isPalindrome(string str) {
    string cleanedStr = "";
    char stack[1000]; // Array to simulate stack
    int top = -1; // Stack pointer

    // Clean the string: remove non-alphanumeric characters and convert to lowercase
    for (int i = 0; i < str.length(); i++) {
        if (isalnum(str[i])) {
            cleanedStr += tolower(str[i]);
        }
    }

    // Push all characters of cleanedStr onto the stack
    for (int i = 0; i < cleanedStr.length(); i++) {
        push(stack, top, cleanedStr[i]);
    }

    // Check if the cleaned string is a palindrome
    for (int i = 0; i < cleanedStr.length(); i++) {
        if (cleanedStr[i] != pop(stack, top)) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Is a palindrome
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    if (isPalindrome(str)) {
        cout << "\"" << str << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << str << "\" is not a palindrome." << endl;
    }

    return 0;
}
