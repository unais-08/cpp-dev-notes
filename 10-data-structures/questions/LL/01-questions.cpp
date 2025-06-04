#include <iostream>
#include "../../linked-list/LinkedList.h"
using namespace std;
int main()
{
    LinkedList* list = new LinkedList(5);
    list->printList();
    return 0;
}