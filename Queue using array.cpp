#include <iostream>
using namespace std;

#define size 5
int Queue[size];
int front = -1, rear = -1;

void Enqueue() // inserting an element from rear
{
    if (rear == size - 1)
    {
        cout << "Oops queue is full\nTry dequeuing some elements!!" << endl;
    }
    else
    {
        int data;
        cout << "Enter data: ";
        cin >> data;
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            Queue[rear] = data;
        }
        else
        {
            rear++;
            Queue[rear] = data;
        }
    }
}

void Dequeue() // deleting front element from Queue
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty:(\nTry enqueuing some elements" << endl;
    }
    else
    {
        cout << "The dequed element is " << Queue[front] << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void peek() // printing front element
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty:(\nTry enqueuing some elements" << endl;
    }
    else
    {
        cout << "The data at front is --> " << Queue[front] << endl;
    }
}

void isEmpty() // checking if queue is empty
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty:(\nTry enqueuing some elements" << endl;
    }
    else
    {
        cout << "The Queue is not empty" << endl;
    }
}

void isFull() // checking if queue is full
{
    if (rear == size - 1)
    {
        cout << "The Queue is full" << endl;
    }
    else
    {
        cout << "The Queue is not full" << endl;
    }
}

void display() // printing all the elements of queue
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty:(\nTry enqueuing some elements" << endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << "The data is --> " << Queue[i] << endl;
        }
    }
}
int main()
{
    int choice;
    while (choice != 0)
    {
        cout << "\nEnter choice--> " << endl
             << "1 to Enqueue " << endl
             << "2 to Dequeue " << endl
             << "3 to peek " << endl
             << "4 to display " << endl
             << "5 to check if Queue is full" << endl
             << "6 to check if Queue is empty " << endl
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
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            isFull();
            break;
        case 6:
            isEmpty();
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