#include <iostream>
#include <stdlib.h>

using namespace std;

// node templete
struct node
{
    int data;
    struct node *next;
};

// Global Head and tail pointer
struct node *head = NULL;
struct node *tail = NULL;

// forward declaration of functions
void create();
void view();
void insertByIndex();
void insertByElement();
void deletion();
void average();
void bubbleSort();

// main function
int main()
{
    int ch;
    cout << "Create a node:" << endl;
    create();
    while (ch != 0)
    {
        cout << "1 to view a node:" << endl;
        cout << "2 to insert a node by index:" << endl;
        cout << "3 to insert a node by Element:" << endl;
        cout << "4 to delete a node:" << endl;
        cout << "5 to find average of the list:" << endl;
        cout << "6 to sort the list:" << endl;
        cout << "0 to end:" << endl;
        cin >> ch;

        if (ch == 1)
        {
            view();
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

        else
        {
            break;
        }
    }

    return 0;
}

// function definations

void create()
{
    int n;
    struct node *temp;
    cout << "Enter the number of nodes:" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        temp = new (struct node[sizeof(struct node)]);
        cout << "Enter data:" << endl;
        cin >> temp->data;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
}

void view()
{
    struct node *traverse = head;
    while (traverse != NULL)
    {
        cout << "Data = " << traverse->data << endl;
        traverse = traverse->next;
    }
}

void insertByIndex() // inserstion using index
{
    struct node *a, *temp;
    a = new (struct node[sizeof(struct node)]);

    int element, index;

    cout << "Enter the element you want to insert: ";
    cin >> element;

    cout << "Enter the place you want to insert: ";
    cin >> index;

    cout << "Inserting " << element << " at " << index << " index!!" << endl;

    if (index == 1)
    {
        a->next = head;
        a->data = element;
        head = a;
    }
    else
    {
        temp = head;
        for (int i = 0; i < index - 2; i++)
        {
            temp = temp->next;
        }
        a->next = temp->next;
        temp->next = a;
        a->data = element;
        if (temp == tail)
        {
            tail = a;
        }
    }
}

void insertByElement()
{
    struct node *ptr = head, *a;

    cout << "Enter the element after you want to insert:" << endl;
    int element;
    cin >> element;

    while (ptr != NULL && ptr->data != element)
    {
        ptr = ptr->next;
    }

    a = new (struct node[sizeof(struct node)]);

    cout << "Enter the element you want to insert:" << endl;
    cin >> a->data;
    a->next = ptr->next;
    ptr->next = a;
    if (ptr == tail)
    {
        tail = ptr;
    }
}

void deletion()
{
    struct node *ptr, *temp;
    ptr = head;

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

void average()
{
    struct node *ptr = head;
    float average = 0, sum = 0, number = 0;
    while (ptr != NULL)
    {
        sum = sum + ptr->data;
        number++;
        ptr = ptr->next;
    }
    average = sum / number;
    cout << "The average of the linked list = " << average << endl;
}

void bubbleSort()
{
    struct node *current = head, *nextt = NULL;
    int temp;

    cout << "Sorting the list....." << endl;
    
    while(current != NULL) 
    {  
        //Node nextt will point to node next to current  
        nextt = current->next;  
            
        while(nextt != NULL) 
        {  
            //swapping coding   
            if(current->data > nextt->data) 
            {  
                temp = current->data;  
                current->data = nextt->data;  
                nextt->data = temp;  
            }  
            nextt = nextt->next;  
        }  
        current = current->next;  
    }      
}
