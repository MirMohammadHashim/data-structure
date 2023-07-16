#include <iostream>
#include <cmath>
using namespace std;

struct CircleNode
{
    int data;
    struct CircleNode *next;
};
struct CircleNode *head = NULL;

void create() // creating nodes
{
    struct CircleNode *ptr, *temp;
    int num;

    cout << "Enter number of node:" << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        ptr = new (struct CircleNode[sizeof(struct CircleNode)]);

        cout << "Enter data = ";
        cin >> ptr->data;

        if (head == NULL)
        {
            temp = ptr;
            head = ptr;
        }
        else
        {
            head->next = ptr;
            head = ptr;
        }
    }
    head->next = temp;
}

void show() // printing nodes
{
    struct CircleNode *ptr = head;
    do
    {
        cout << "The data is " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

void insertByIndex() // insertion using index
{
    struct CircleNode *ptr, *current = head;
    ptr = new (struct CircleNode[sizeof(struct CircleNode)]);
    int index;

    cout << "Enter the element you want to insert: ";
    cin >> ptr->data;

    cout << "Enter the place you want to insert: ";
    cin >> index;

    cout << "Inserting " << ptr->data << " at " << index << " index!!" << endl;

    if (index == 1)
    {
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = ptr;
        ptr->next = head;
        head = ptr;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
}

void insertByElement() // insertion after element
{
    struct CircleNode *ptr = head, *temp;

    cout << "Enter the element after you want to insert:" << endl;
    int element;
    cin >> element;

    while (ptr != NULL && ptr->data != element)
    {
        ptr = ptr->next;
    }

    temp = new (struct CircleNode[sizeof(struct CircleNode)]);

    cout << "Enter the element you want to insert:" << endl;
    cin >> temp->data;

    temp->next = ptr->next;
    ptr->next = temp;
    if (ptr == head)
    {
        head = ptr;
    }
}

void deletion() // deleting elements from list
{
    struct CircleNode *ptr = head, *temp;

    cout << "Enter element to delete:" << endl;
    int element;
    cin >> element;

    while (ptr != NULL && ptr->data != element)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next; // this step unlinkes the element from linked list
    free(ptr);
}

void average() // finding average
{
    struct CircleNode *ptr = head;
    float average, sum = 0, number = 0;
    do
    {
        sum = sum + ptr->data;
        number++;
        ptr = ptr->next;
    } while (ptr != head);
    average = sum / number;
    cout << "The average of the linked list = " << average << endl;
}

void primeCheck() // check for prime numbers in list
{
    struct CircleNode *ptr = head;

    do
    {
        int flag = 0;

        if (ptr->data == 1)
        {
            cout << "1 is prime:)" << endl;
        }
        else if (ptr->data == 0)
        {
            cout << "0 is not a prime:(" << endl;
        }
        else
        {
            for (int i = 2; i < ptr->data; i++)
            {
                if (ptr->data % 2 == 0)
                {
                    flag++;
                }
            }
            if (flag == 0)
            {
                cout << ptr->data << " is a prime:)" << endl;
            }
            else
            {
                cout << ptr->data << " is not a prime:(" << endl;
            }
        }

        ptr = ptr->next;
    } while (ptr != head);
}

void bubbleSort() // bubble sorting the list
{
    struct CircleNode *current = head, *nextt = NULL;
    int temp;

    cout << "Sorting the list....." << endl;

    do
    {
        // Node nextt will point to node next to current
        nextt = current->next;

        while (nextt != NULL)
        {
            // swapping
            if (current->data > nextt->data)
            {
                temp = current->data;
                current->data = nextt->data;
                nextt->data = temp;
            }
            nextt = nextt->next;
        }
        current = current->next;
    } while (current != NULL);
}

void variance_StandardDeviation() // variance and standard de
{
    struct CircleNode *ptr = head;
    float standardDeviation, variance, temp, squaredSum = 0, mean, sum = 0, number = 0;

    // mean
    do{
        sum = sum + ptr->data;
        number++;
        ptr = ptr->next;
    }while (ptr != head);
    mean = sum / number;

    ptr = head;
     // variance
    do{
        temp = (ptr->data - mean);
        squaredSum = squaredSum + pow(temp, 2);
        ptr = ptr->next;
    }while (ptr != head);
    variance = squaredSum / number;

    cout << "The variance of the node = " << variance << endl;

    standardDeviation = sqrt(variance); // standard deviation
    cout << "The standard deviation of the node = " << standardDeviation << endl;
}

void bigAndSmall() // finding biggest and smallest element in the node
{
    struct CircleNode *ptr = head;
    int big = 0, small = 999999999;
    
    do{
        if (ptr->data > big)
        {
            big = ptr->data;
        }
        if (ptr->data < small)
        {
            small = ptr->data;
        }
        ptr = ptr->next;
    }while (ptr != head);
    cout << "The biggest node in the list is " << big << endl;
    cout << "The smallest node in the list is " << small << endl;
}

int main()
{
    int ch;
    cout << "Create a node......" << endl;
    create();
    while (ch != 0)
    {
        cout << "\nEnter your choice.....!" << endl
             << "1 to view a node:" << endl
             << "2 to insert a node by index:" << endl
             << "3 to insert a node by Element:" << endl
             << "4 to delete a node:" << endl
             << "5 to find average of the list:" << endl
             << "6 to sort the list:" << endl
             << "7 to check for primes:" << endl
             << "8 to find varaince and standard deviation:" << endl
             << "9 to find the biggest and smallest node:" << endl
             << "10 to find reverse the node:" << endl
             << "0 to end:" << endl;
        cin >> ch;

        if (ch == 1)
        {
            show();
        }
        else if (ch == 2)
        {
            insertByIndex();
        }
        else if (ch == 3)
        {
            insertByElement();
        }
        else if (ch == 4)
        {
            deletion();
        }
        else if (ch == 5)
        {
            average();
        }
        else if (ch == 6)
        {
            bubbleSort();
        }
        else if (ch == 7)
        {
            primeCheck();
        }
        else if (ch == 8)
        {
            variance_StandardDeviation();
        }
        else if (ch == 9)
        {
            bigAndSmall();
        }
        else
        {
            break;
        }
    }

    return 0;
}