#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50  
char stack[MAX];
int top = -1;

void push(char x)
{
    if (top < MAX - 1)  
    {
        top++;
        stack[top] = x;
    }
    else
    {
        cout << "\nStack is overflow...!";
    }
}

char pop()
{
    if (top > -1)
    {
        return stack[top--];
    }
    else
    {
        cout << "\nStack is underflow...!";
        return '\0';
    }
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void infixToPostfix(const string &infix)  
{
    char c;
    int i = 0;
    while (i < infix.length())
    {
        c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            cout << c;
        }
        else if (c == '(')  
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                cout << pop();
            }
            if (top != -1)
            {
                pop();
            }
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
            {
                cout << pop();
            }
            push(c);
        }
        i++;
    }
    while (top != -1)
    {
        cout << pop();
    }
    cout << endl;
}

int main()
{
    string infix;
    cout << "\nEnter the infix expression:\t";
    cin >> infix;
    cout << "\nPostfix Expression is:\t";
    infixToPostfix(infix);
    return 0;
}
