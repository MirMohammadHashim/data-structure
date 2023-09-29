#include <iostream>
using namespace std;

struct doubleLink
{
    int marks;
    int rollNumber;
    string name;
    char grade;
    struct doubleLink *next;
    struct doubleLink *previous;
};

struct doubleLink *head = NULL;
struct doubleLink *tail = NULL;

void create()
{
    struct doubleLink *ptr;
    int number;

    cout << "Enter number of nodes:" << endl;
    cin >> number;

    for (int i = 0; i < number; i++)
    {
        ptr = new (struct doubleLink[sizeof(struct doubleLink)]);
        cout << "Enter roll number: " << endl;
        cin >> ptr->rollNumber;
        cout << "Enter name: " << endl;
        cin >> ptr->name;
        cout << "Enter grade: " << endl;
        cin >> ptr->grade;
        ptr->next = NULL;

        if (head == NULL)
        {
            ptr->previous = NULL;
            head = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            ptr->previous = tail;
            tail = ptr;
        }
    }
}

void print()
{
    struct doubleLink *ptr;
    int inp;
    cout << "Type 1 to print the list in straight:" << endl
         << "Type 2 to print the list in reverse:" << endl;
    cin >> inp;

    if (inp == 1)
    {
        ptr = head;
        while (ptr != NULL)
        {
            cout << "The data is " << ptr->rollNumber << endl;
            ptr = ptr->next;
        }
    }
    else if (inp == 2)
    {
        ptr = tail;
        while (ptr != NULL)
        {
            cout << "The data is " << ptr->rollNumber << endl;
            ptr = ptr->previous;
        }
    }
    else
        cout << "Error:(";
}

void insert()
{
    struct doubleLink *ptr = head, *temp;
    int index;

    cout << "Enter the index where you want to insert:" << endl;
    cin >> index;
    cout << "Enter node " << endl;
    cin >> temp->rollNumber;
    cout << "Enter roll number: " << endl;
    cin >> temp->rollNumber;
    cout << "Enter name: " << endl;
    cin >> temp->name;
    cout << "Enter grade: " << endl;
    cin >> temp->grade;

    if (index == 1)
    {
        head->previous = ptr;
        ptr->next = head;
        head = ptr;
        ptr->previous = NULL;
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            temp->next = ptr;
            ptr->previous = temp;
            tail = ptr;
            ptr->next = NULL;
        }
        ptr->next = temp->next;
        ptr->previous = temp;
        temp->next = ptr;
        temp = ptr->next;
        temp->previous = ptr;
    }
}

int main()
{
    int inp;
    cout << "Create node.....!" << endl;
    create();
    while (inp != 0)
    {
        cout << "Enter your choice:" << endl
             << "1 to print the list:" << endl
             << "2 to insert a node in list:" << endl;

        cin >> inp;

        if (inp == 1)
        {
            print();
        }
        else if (inp == 2)
        {
            insert();
        }
        else
        {
            break;
        }
    }

    return 0;
}