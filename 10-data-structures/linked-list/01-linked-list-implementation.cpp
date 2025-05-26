#include <iostream>  // Required for input/output operations, like std::cout

/**
 * @brief Represents a single node in the linked list.
 *
 * Each Node holds an integer value and a pointer to the next Node in the sequence.
 */
class Node
{
   public:
    int value;   // The data stored in the node
    Node* next;  // Pointer to the next node in the list

    /**
     * @brief Constructs a new Node with the given value.
     * @param val The integer value to store in the node.
     */
    Node(int val) : value(val), next(nullptr) {}
};

/**
 * @brief Implements a singly linked list data structure.
 *
 * This class provides methods for common linked list operations such as
 * appending, prepending, deleting nodes, and printing the list.
 */
class LinkedList
{
   private:
    Node* head;  // Pointer to the first node in the list
    Node* tail;  // Pointer to the last node in the list
    int length;  // Current number of nodes in the list

   public:
    /**
     * @brief Constructs a new LinkedList with an initial node.
     * @param value The value for the first node of the list.
     */
    LinkedList(int value)
    {
        // Create the first node and set it as both head and tail
        head = new Node(value);
        tail = head;
        length = 1;
    }

    /**
     * @brief Destroys the LinkedList, deallocating all nodes.
     *
     * This destructor iterates through the list and frees the memory
     * occupied by each node to prevent memory leaks.
     */
    ~LinkedList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* nextNode = current->next;  // Store next node before deleting current
            delete current;                  // Deallocate current node
            current = nextNode;              // Move to the next node
        }
        head = nullptr;  // Ensure head and tail are null after deletion
        tail = nullptr;
        length = 0;  // Reset length
    }

    /**
     * @brief Adds a new node with the given value to the end of the list.
     * @param value The value to append.
     */
    void append(int value)
    {
        Node* newNode = new Node(value);
        // If the list is empty, the new node becomes both head and tail
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;  // Link the current tail to the new node
            tail = newNode;        // Update tail to the new node
        }
        length++;
    }

    /**
     * @brief Adds a new node with the given value to the beginning of the list.
     * @param value The value to prepend.
     */
    void prepend(int value)
    {
        Node* newNode = new Node(value);
        // If the list is empty, the new node becomes both head and tail
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;  // Link the new node to the current head
            head = newNode;        // Update head to the new node
        }
        length++;
    }

    /**
     * @brief Prints all the values in the linked list from head to tail.
     *
     * Displays the list in the format: value1 --> value2 --> ... --> nullptr
     */
    void printList() const
    {
        Node* temp = head;  // Start from the head
        while (temp != nullptr)
        {
            std::cout << temp->value << " --> ";  // Print current node's value
            temp = temp->next;                    // Move to the next node
        }
        std::cout << "nullptr" << std::endl;  // Indicate the end of the list
    }

    /**
     * @brief Deletes the last node from the linked list.
     *
     * Handles cases for empty lists, single-node lists, and multi-node lists.
     */
    void deleteLast()
    {
        if (head == nullptr)
        {  // Check if the list is empty
            std::cout << "Error: Cannot delete from an empty list." << std::endl;
            return;
        }

        if (head == tail)
        {                    // If there's only one node in the list
            delete head;     // Deallocate the single node
            head = nullptr;  // Reset head and tail
            tail = nullptr;
        }
        else
        {
            Node* temp = head;
            // Traverse until 'temp' is the node *before* the tail
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;           // Deallocate the tail node
            tail = temp;           // Update tail to the new last node
            tail->next = nullptr;  // The new tail points to nullptr
        }
        length--;  // Decrement the list length
    }

    /**
     * @brief Deletes the first node (head) from the linked list.
     *
     * Handles cases for empty lists and single-node lists.
     */
    void deleteFirst()
    {
        if (head == nullptr)
        {  // Check if the list is empty
            std::cout << "Error: Cannot delete from an empty list." << std::endl;
            return;
        }

        Node* temp = head;  // Store the current head
        if (head->next == nullptr)
        {                    // If there's only one node (head is also tail)
            head = nullptr;  // Reset head and tail
            tail = nullptr;
        }
        else
        {
            head = head->next;  // Move head to the next node
        }
        delete temp;  // Deallocate the original head node
        length--;     // Decrement the list length
    }

    /**
     * @brief Gets the current number of nodes in the linked list.
     * @return The length of the linked list.
     */
    int getLength() const { return length; }

    bool insert(int value, int index)
    {
        if (head == nullptr)
        {
            prepend(value);
            return true;
        }
        if (index == length - 1)
        {
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* prev = head;
        for (int i = 0; i < index; i++)
        {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
        length++;
        return true;
    }

    bool deletePosition(int index)
    {
        if (head == nullptr)
        {
            std::cout << "Empty List" << std::endl;
            return false;
        }

        if (index < 0 || index >= length)
        {
            std::cout << "Index out of bounds" << std::endl;
            return false;
        }

        Node* toDelete = nullptr;

        if (index == 0)
        {
            toDelete = head;
            head = head->next;
        }
        else
        {
            Node* prev = head;
            for (int i = 0; i < index - 1; i++)
            {
                prev = prev->next;
            }

            toDelete = prev->next;
            prev->next = toDelete->next;
        }

        delete toDelete;
        length--;
        return true;
    }

    // 1->2->3->4->5
    // 5->2->3->4->1
    void reverseLinkedList()
    {
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* before = nullptr;
        Node* after = temp->next;
        for (int i = 0; i < length; i++)
        {
            after = temp->next;
            temp->next = before;
            before=temp;
            temp = after;
            // temp = after;
        }
    }
};

// --- Main function for demonstration ---
int main()
{
    // Create a new linked list with an initial value of 10
    LinkedList my_list(10);
    my_list.printList();  // Output: 10 --> nullptr

    // Append a value to the list
    my_list.append(20);
    my_list.append(30);
    my_list.printList();  // Output: 10 --> 20 --> 30 --> nullptr

    // Prepend a value to the list
    my_list.prepend(5);
    my_list.printList();  // Output: 5 --> 10 --> 20 --> 30 --> nullptr

    // Delete the first node
    my_list.deleteFirst();
    my_list.printList();  // Output: 10 --> 20 --> 30 --> nullptr

    // Delete the last node
    my_list.deleteLast();
    my_list.printList();  // Output: 10 --> 20 --> nullptr

    // Demonstrate deleting all nodes
    my_list.deleteFirst();  // Delete 10
    my_list.printList();    // Output: 20 --> nullptr
    my_list.deleteLast();   // Delete 20
    my_list.printList();    // Output: nullptr

    // Attempt to delete from an empty list
    my_list.deleteFirst();  // Output: Error: Cannot delete from an empty list.
    LinkedList* myll = new LinkedList(10);
    myll->append(20);
    myll->append(30);
    myll->append(40);
    myll->append(50);

    myll->printList();
    myll->reverseLinkedList();
    myll->printList();
    return 0;  // Indicate successful execution
}