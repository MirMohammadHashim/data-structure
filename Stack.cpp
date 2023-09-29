#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int topValue;
    int *arr;
};

int main()
{
    struct Stack s1;
    s1.size = 80;
    s1.topValue = -1;
    s1.arr = new(int [sizeof(int )]);
    
    
    return 0;
}