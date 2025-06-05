#include <iostream>
#include <stack>
#include "../../linked-list/LinkedList.h"
using namespace std;

// Q1) Given a singly linked list, print the elements in reverse (without modifying the list).

Node* print_reverse(Node* head)
{
    stack<int> st;
    Node* temp = head;
    while (temp)
    {
        st.push(temp->value);
        temp = temp->next;
    }
    temp = head;
    Node* newhead = head;
    while (temp)
    {
        newhead->value = st.top();
        temp = temp->next;
    }
    return newhead;
}

int main()
{
    LinkedList* list = new LinkedList(5);
    list->prepend(1);
    list->append(10);
    Node* head = list->getHead();
    print_reverse(head);
    list->printList();
    return 0;
}