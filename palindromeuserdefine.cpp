#include <iostream>
#include <string>
using namespace std;

// User-defined function to calculate the length of a string
int stringLength(const string &str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// User-defined function to copy one string to another (unused but kept for learning)
void stringCopy(char dest[], const string &src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// User-defined function to check if a character is alphanumeric
bool isAlphanumeric(char s) {
    // Return true if the character is alphabetic or a digit, false otherwise
    return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9');
}

// User-defined function to convert a character to lowercase
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

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
    char cleanedStr[1000]; // Array to store cleaned string
    char stack[1000]; // Array to simulate stack
    int top = -1; // Stack pointer

    // Clean the string: remove non-alphanumeric characters and convert to lowercase
    int j = 0;
    for (int i = 0; i < stringLength(str); i++) {
        if (isAlphanumeric(str[i])) { // Check if the character is alphanumeric
            cleanedStr[j] = toLowerCase(str[i]); // Convert to lowercase and add to cleaned string
            j++;
        }
    }
    cleanedStr[j] = '\0'; // Null-terminate the cleaned string

    // Push all characters of cleanedStr onto the stack
    for (int i = 0; i < stringLength(cleanedStr); i++) {
        push(stack, top, cleanedStr[i]);
    }

    // Check if the cleaned string is a palindrome
    for (int i = 0; i < stringLength(cleanedStr); i++) {
        if (cleanedStr[i] != pop(stack, top)) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Is a palindrome
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); // Get user input

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        cout << "\"" << str << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << str << "\" is not a palindrome." << endl;
    }

    return 0;
}
