#include <iostream>
#include <vector>

using namespace std;

/**
 * Stack class implemented using std::vector
 */
class Stack
{
   private:
    vector<int> elements;  // Dynamic array to store stack elements

   public:
    /**
     * Push a value onto the stack.
     * @param value Integer to push.
     */
    void push(int value)
    {
        elements.push_back(value);
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
        cout << "Popped " << elements.back() << " from the stack.\n";
        elements.pop_back();
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
        return elements.back();
    }

    /**
     * Check if the stack is empty.
     * @return true if empty, false otherwise.
     */
    bool isEmpty() { return elements.empty(); }

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
        for (int i = elements.size() - 1; i >= 0; --i)
        {
            cout << elements[i] << " ";
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
