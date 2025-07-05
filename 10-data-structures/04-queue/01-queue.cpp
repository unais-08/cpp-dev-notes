#include <iostream>
using namespace std;

/**
 * Node structure for the linked list
 */
class Node
{
   public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

/**
 * Queue class implemented using a singly linked list
 */
class Queue
{
   private:
    Node* frontNode;
    Node* backNode;
    int length;

   public:
    /**
     * Constructor initializes an empty queue.
     */
    Queue() : frontNode(nullptr), backNode(nullptr), length(0) {}

    /**
     * Destructor to free all nodes in the queue.
     */
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    /**
     * Add element to the back of the queue.
     */
    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            frontNode = backNode = newNode;
        }
        else
        {
            backNode->next = newNode;
            backNode = newNode;
        }
        length++;
        cout << "Enqueued: " << value << endl;
    }

    /**
     * Remove element from the front of the queue.
     */
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
        length--;

        if (frontNode == nullptr)
        {
            backNode = nullptr;
            cout << "Queue is now empty.\n";
        }
    }

    /**
     * Return the size of the queue.
     */
    int size() const { return length; }

    /**
     * Check if the queue is empty.
     */
    bool isEmpty() const { return length == 0; }

    /**
     * Print all elements of the queue from front to back.
     */
    void print_queue() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node* current = frontNode;
        cout << "Queue contents (front to back): ";
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

/**
 * Main function to demonstrate queue operations.
 */
int main()
{
    Queue queue;

    // Demonstrate enqueue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.print_queue();

    // Demonstrate dequeue
    queue.dequeue();
    queue.print_queue();

    queue.dequeue();
    queue.dequeue();

    // Try to dequeue from empty queue
    queue.dequeue();

    // Show final state
    queue.print_queue();

    return 0;
}
