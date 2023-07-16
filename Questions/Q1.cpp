// create a node where it can store information like name age grade, and write a function that displays only the name of
// those students that have scored A grade.

#include <iostream>
using namespace std;

struct node
{
    int age;
    char grade;
    string name;
    struct node *next;
};
struct node *HEAD = NULL;
struct node *TAIL = NULL;

void create()
{
    int n;
    struct node *ptr;
    cout << "Enter the number of students:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ptr = new (struct node[sizeof(struct node)]);
        cout << "Enter name: " << endl;
        cin >> ptr->name;
        cout << "Enter age: " << endl;
        cin >> ptr->age;
        cout << "Enter grade: " << endl;
        cin >> ptr->grade;

        ptr->next = NULL;

        if (HEAD == NULL)
        {
            HEAD = ptr;
            TAIL = ptr;
        }
        else
        {
            TAIL->next = ptr;
            TAIL = ptr;
        }
    }
}

void scoreCheck()
{
    struct node *ptr = HEAD;

    while (ptr != NULL)
    {
        if (ptr->grade == 'A')
        {
            cout << ptr->name <<" has scored A grade!!!" << endl;
        }
        ptr = ptr->next;
    }
}

int main()
{
    create();
    scoreCheck();
    return 0;
}