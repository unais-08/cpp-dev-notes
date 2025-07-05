#include <iostream>

using namespace std;

/**
 * Node structure for the linked list
 * Each node contains an integer data and a pointer to the next node.
 */
struct Node
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

/**
 * Stack class implemented using a singly linked list
 */
class Stack
{
   private:
    Node* topNode;  // Pointer to the top of the stack

   public:
    // Constructor initializes an empty stack.

    Stack() : topNode(nullptr) {}

    // Destructor to clean up memory by popping all elements.

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    /**
     * Push a value onto the stack.
     * @param value Integer to push.
     */
    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    /**
     * Remove the top element from the stack.
     * Prints an error if the stack is empty.
     */
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return;
        }
        Node* temp = topNode;
        cout << "Popped " << temp->data << " from the stack.\n";
        topNode = topNode->next;
        delete temp;
    }

    /**
     * Get the value at the top of the stack.
     * @return Top value, or -1 if empty (could also throw an exception).
     */
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No top element.\n";
            return -1;
        }
        return topNode->data;
    }

    /**
     * Check if the stack is empty
     * @return true if empty, false otherwise.
     */
    bool isEmpty() { return topNode == nullptr; }

    /**
     * Display all elements in the stack from top to bottom.
     */
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack contents (top to bottom): ";
        Node* current = topNode;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

/**
 * Main function to demonstrate stack operations.
 */
int main()
{
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.display();

    cout << "Current top: " << myStack.top() << endl;

    myStack.pop();
    myStack.display();

    myStack.pop();
    myStack.pop();

    // Try popping from empty stack
    myStack.pop();

    return 0;
}
