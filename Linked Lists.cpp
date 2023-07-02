#include<iostream>

using namespace std;
struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void create();
void view();
void insert();

int main()
{
    int ch;
    while(ch != 0)
    {
        cout << "1 to create a node:" << endl;
        cout << "2 to view a node:" << endl;
        cout << "3 to insert a node:" << endl;
        cout << "0 to end:" << endl;
        cin >> ch;
        if (ch == 1)
        {
            create();
        }
        else if (ch == 2)
        {
            view();
        }
        else if (ch == 3)
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

void create()
{
    int n,i;
    struct node *temp;
    cout << "Enter the number of nodes:" << endl;
    cin >> n;
    
    for (i=0;i<n;i++)
    { 
        temp = new(struct node[sizeof(struct node)]);
        cout << "Enter data:" << endl;
        cin >> temp->data;
        temp->next = NULL;
        
        if(head == NULL)
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

void insert()
{
    struct node *a = head;
    int element, index;
    cout << "Enter the element you want to insert: ";
    cin >> element;

    cout << "Enter the place you want to insert: ";
    cin >> index;

    
}