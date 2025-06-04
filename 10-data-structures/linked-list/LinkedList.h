#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node
{
   public:
    int value;   // The data stored in the node
    Node* next;  // Pointer to the next node in the list

    Node(int val);
};

class LinkedList
{
   private:
    Node* head;  // Pointer to the first node in the list
    Node* tail;  // Pointer to the last node in the list
    int length;  // Current number of nodes in the list
   public:
    LinkedList(int value);

    ~LinkedList();
    void append(int value);
    void prepend(int value);
    void printList() const;

    void deleteLast();
    void deleteFirst();

    int getLength() const;

    bool insert(int value, int index);

    bool deletePosition(int index);

    void reverseLinkedList();
};
#endif
