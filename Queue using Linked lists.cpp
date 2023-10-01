// Queue is an abstract linear data structure, it is an ordered listed which works on the principle of first in first out FIFO
// here insertion would be done on the last node (rear or tail) we use term enqueue for insertion
// and deletion would be done on first node (front or head) we use dequeue for delete operation

#include <iostream>
using namespace std;

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *FRONT = NULL;
struct Queue *REAR = NULL;

void Enqueue()
{
    struct Queue *temp;
    temp = new(struct Queue[sizeof(struct Queue)]);
    cout << "Enter data: ";
    cin >> temp->data;

    if (FRONT == NULL)
    {
        FRONT = temp;
        REAR = temp;
        FRONT->next = NULL;
    }
    else
    {
        temp->next = REAR;
        
    }
    
    
    
}

void Dequeue()
{

}

void front()
{

}

void isEmpty()
{

}

void display()
{

}

int main()
{
    int choice;
    while (choice != 0)
    {
        cout << "\nEnter choice--> " << endl
             << "1 to Enqueue " << endl
             << "2 to Dequeue " << endl
             << "3 to peak " << endl
             << "4 to display " << endl
             << "5 to check is Queue is empty " << endl
             << "0 to end " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            front();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
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