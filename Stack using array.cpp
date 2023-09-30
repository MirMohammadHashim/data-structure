#include <iostream>
using namespace std;

#define N 5
int top = -1;
int stack[N];

void push()
{
    int x;
    cout << "Enter data: ";
    cin >> x;
    if (top == N - 1)
    {
        cout << "Stack is full:(" << endl;
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop() // printing and deleting the top element
{
    if (top == -1)
    {
        cout << "Stack is empty:(" << endl;
    }
    else
    {
        cout << "Deleting " << stack[top] << " at " << top + 1 << "th position!! " << endl;
        top--;
    }
}

void peak() // printing the top element without deleting it
{
    if (top == -1)
    {
        cout << "Stack is empty:(" << endl;
    }
    else
    {
        cout << "The element at " << top + 1 << "th position is " << stack[top] << endl;
    }
}
void dispaly() // display all the elements
{
    if (top == -1)
    {
        cout << "stack is empty try pushing elements to it" << endl;
    }

    for (int i = top; i >= 0; i--)
    {
        cout << "The element at " << i + 1 << " is " << stack[i] << endl;
    }
}
int main()
{
    int choice;
    while (choice != 0)
    {
        cout << "\nEnter choice--> " << endl
             << "1 to push " << endl
             << "2 to pop " << endl
             << "3 to peak " << endl
             << "4 to display " << endl
             << "0 to end " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peak();
            break;
        case 4:
            dispaly();
            break;
        case 0:
            cout << "Ending program bye";
            break;
        default:
            cout << "Invalid input try again!!!!";
            break;
        }
    }

    return 0;
}
