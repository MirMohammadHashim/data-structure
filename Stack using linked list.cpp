#include <iostream>
using namespace std;

struct stack
{
    int data;
    struct stack *previous;
};

struct stack *TOP = NULL;

void push()
{
    struct stack *newNode;                              // initialize
    newNode = new (struct stack[sizeof(struct stack)]); // memory allocation
    cout << "Enter data:--> " << endl;
    cin >> newNode->data;

    if (TOP == NULL)
    {
        TOP = newNode;
        TOP->previous = NULL;
    }
    else
    {
        newNode->previous = TOP;
        TOP = newNode;
    }
}
void pop() // delete and print top node
{
    if (TOP == NULL)
    {
        cout << "Stack is empty:(\nTry pushing some elements to it:)" << endl;
    }
    else
    {
        cout << "The deleting data at top which is " << TOP->data << endl;
        TOP = TOP->previous;
    }
}
void peak()
{
    if (TOP == NULL)
    {
        cout << "Stack is empty:(\nTry pushing some elements to it:)" << endl;
    }
    else
    {
        cout << "The data at top is " << TOP->data << endl;
    }
}
void display()
{
    struct stack *temp = TOP;
    if (TOP == NULL)
    {
        cout << "Stack is empty:(\nTry pushing some elements to it:)" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << "The data is = " << temp->data << endl;
            temp = temp->previous;
        }
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
             << "NULL to end " << endl;
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
            display();
            break;
        case 0:
            cout << "Ending program bye";
            break;
        default:
            cout << "Invalid input try again!!!!";
        }
    }

    return 0;
}