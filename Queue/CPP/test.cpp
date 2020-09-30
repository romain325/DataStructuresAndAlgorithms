#include "Queue.h"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    push(7);
    push(6);
    push(6);
    printAll();
    pop();
    cout<<"\nAfter delete first element \n";
    printAll();
    return 0;
}
