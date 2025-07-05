#include <iostream>
#include "02-linked-list-header-file.h"
using namespace std;

int main()
{
    LinkedList* l1 = new LinkedList(10);
    l1->append(20);
    l1->printList();
    return 0;
}