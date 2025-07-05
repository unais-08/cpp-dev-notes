#include <iostream>
#include "02-linked-list-header-file.h"

Node::Node(int val) : value(val), next(nullptr) {}

LinkedList::LinkedList(int value)
{
    head = new Node(value);
    tail = head;
    length = 1;
}

LinkedList::~LinkedList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void LinkedList::append(int value)
{
    Node* newNode = new Node(value);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::prepend(int value)
{
    Node* newNode = new Node(value);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void LinkedList::printList() const
{
    Node* temp = head;
    while (temp)
    {
        std::cout << temp->value << " --> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

void LinkedList::deleteLast()
{
    if (!head) return;
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node* temp = head;
        while (temp->next != tail) temp = temp->next;
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    length--;
}

void LinkedList::deleteFirst()
{
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    if (!head) tail = nullptr;
    length--;
}

int LinkedList::getLength() const
{
    return length;
}

bool LinkedList::insert(int value, int index)
{
    if (index < 0 || index > length) return false;
    if (index == 0)
    {
        prepend(value);
        return true;
    }
    if (index == length)
    {
        append(value);
        return true;
    }

    Node* newNode = new Node(value);
    Node* prev = head;
    for (int i = 0; i < index - 1; i++)
    {
        prev = prev->next;
    }
    newNode->next = prev->next;
    prev->next = newNode;
    length++;
    return true;
}

bool LinkedList::deletePosition(int index)
{
    if (index < 0 || index >= length) return false;
    if (index == 0)
    {
        deleteFirst();
        return true;
    }

    Node* prev = head;
    for (int i = 0; i < index - 1; i++)
    {
        prev = prev->next;
    }
    Node* toDelete = prev->next;
    prev->next = toDelete->next;
    if (toDelete == tail) tail = prev;
    delete toDelete;
    length--;
    return true;
}

void LinkedList::reverseLinkedList()
{
    Node* prev = nullptr;
    Node* curr = head;
    tail = head;

    while (curr)
    {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}
