/**
 * @class Node
 * @description Represents a single node in the linked list.
 *
 * Each Node holds a value and a reference (pointer) to the next Node in the sequence.
 */
class Node {
  /**
   * @constructor
   * @param {*} value The data to store in the node. Can be of any type.
   */
  constructor(value) {
    this.value = value; // The data stored in the node
    this.next = null; // Reference to the next node in the list
  }
}

/**
 * @class LinkedList
 * @description Implements a singly linked list data structure.
 *
 * This class provides methods for common linked list operations such as
 * appending, prepending, deleting nodes, and printing the list.
 */
class LinkedList {
  /**
   * @constructor
   * @param {*} value The value for the first node of the list.
   */
  constructor(value) {
    // Create the first node and set it as both head and tail
    this.head = new Node(value);
    this.tail = this.head;
    this.length = 1;
  }

  /**
   * @method append
   * @description Adds a new node with the given value to the end of the list.
   * @param {*} value The value to append.
   * @returns {LinkedList} The current LinkedList instance for chaining.
   */
  append(value) {
    const newNode = new Node(value);
    // If the list is empty (shouldn't happen with initial constructor, but good for robustness)
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode; // Link the current tail to the new node
      this.tail = newNode; // Update tail to the new node
    }
    this.length++;
    return this; // Allow method chaining
  }

  /**
   * @method prepend
   * @description Adds a new node with the given value to the beginning of the list.
   * @param {*} value The value to prepend.
   * @returns {LinkedList} The current LinkedList instance for chaining.
   */
  prepend(value) {
    const newNode = new Node(value);
    // If the list is empty
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      newNode.next = this.head; // Link the new node to the current head
      this.head = newNode; // Update head to the new node
    }
    this.length++;
    return this; // Allow method chaining
  }

  /**
   * @method printList
   * @description Prints all the values in the linked list from head to tail to the console.
   *
   * Displays the list in the format: value1 --> value2 --> ... --> null
   */
  printList(head = this.head) {
    let temp = this.head; // Start from the head
    let listString = "";
    while (temp !== null) {
      listString += `${temp.value} --> `; // Append current node's value
      temp = temp.next; // Move to the next node
    }
    listString += "null"; // Indicate the end of the list
    console.log(listString);
  }

  /**
   * @method deleteLast
   * @description Deletes the last node from the linked list.
   *
   * Handles cases for empty lists, single-node lists, and multi-node lists.
   * @returns {*} The value of the deleted node, or null if the list was empty.
   */
  deleteLast() {
    if (!this.head) {
      // Check if the list is empty
      console.warn("Warning: Cannot delete from an empty list.");
      return null;
    }

    let deletedValue = null;

    if (this.head === this.tail) {
      // If there's only one node in the list
      deletedValue = this.head.value;
      this.head = null; // Reset head and tail
      this.tail = null;
    } else {
      let temp = this.head;
      // Traverse until 'temp' is the node *before* the tail
      while (temp.next !== this.tail) {
        temp = temp.next;
      }
      deletedValue = this.tail.value;
      this.tail = temp; // Update tail to the new last node
      this.tail.next = null; // The new tail points to null
    }
    this.length--; // Decrement the list length
    return deletedValue;
  }

  /**
   * @method deleteFirst
   * @description Deletes the first node (head) from the linked list.
   *
   * Handles cases for empty lists and single-node lists.
   * @returns {*} The value of the deleted node, or null if the list was empty.
   */
  deleteFirst() {
    if (!this.head) {
      // Check if the list is empty
      console.warn("Warning: Cannot delete from an empty list.");
      return null;
    }

    const deletedValue = this.head.value;
    const temp = this.head; // Store the current head for potential return value

    if (this.head.next === null) {
      // If there's only one node (head is also tail)
      this.head = null; // Reset head and tail
      this.tail = null;
    } else {
      this.head = this.head.next; // Move head to the next node
    }
    // In JavaScript, temp (the old head) will be garbage collected if no other references exist.
    // We don't need to 'delete' it explicitly.
    this.length--; // Decrement the list length
    return deletedValue;
  }

  /**
   * @method getLength
   * @description Gets the current number of nodes in the linked list.
   * @returns {number} The length of the linked list.
   */
  getLength() {
    return this.length;
  }

  /**
   * @method isEmpty
   * @description Checks if the linked list is empty.
   * @returns {boolean} True if the list is empty, false otherwise.
   */
  isEmpty() {
    return this.length === 0;
  }
  /**
   * @method reverse
   * @description Reverse the linked list
   * @returns {newHead} True if the list is empty, false otherwise.
   */

  reverseLinkedListBruteForce() {
    const st = [];
    let temp = this.head;
    while (temp) {
      st.push(temp.value);
      temp = temp.next;
    }
    temp = this.head;
    while (temp) {
      temp.value = st.pop();
      temp = temp.next;
    }
  }

  reverseLinkedListOptimal() {
    let temp = this.head;
    let prev = null;
    while (temp !== null) {
      let front = temp.next; // Store next node
      temp.next = prev; // Reverse the link
      prev = temp; // Move prev forward
      temp = front; // Move temp forward
    }
    this.tail = this.head; // Update tail to old head
    this.head = prev; // Update head to new head
    return this.head;
  }
}

// --- Main execution block for demonstration ---
console.log("--- Initializing List ---");
const my_list = new LinkedList(10);

my_list.printList(); // Output: 10 --> null
console.log("Length:", my_list.getLength()); // Output: Length: 1

console.log("\n--- Appending Values ---");
my_list.append(20).append(30); // Chaining append calls
my_list.printList(); // Output: 10 --> 20 --> 30 --> null
console.log("Length:", my_list.getLength()); // Output: Length: 3

console.log("\n--- Prepending Value ---");
my_list.prepend(5);
my_list.printList(); // Output: 5 --> 10 --> 20 --> 30 --> null
console.log("Length:", my_list.getLength()); // Output: Length: 4

console.log("\n--- Deleting First Node ---");
const deletedFirst = my_list.deleteFirst();
console.log("Deleted first node value:", deletedFirst); // Output: Deleted first node value: 5
my_list.printList(); // Output: 10 --> 20 --> 30 --> null
console.log("Length:", my_list.getLength()); // Output: Length: 3

console.log("\n--- Deleting Last Node ---");
const deletedLast = my_list.deleteLast();
console.log("Deleted last node value:", deletedLast); // Output: Deleted last node value: 30
my_list.printList(); // Output: 10 --> 20 --> null
console.log("Length:", my_list.getLength()); // Output: Length: 2

console.log("\n--- Deleting Remaining Nodes ---");
my_list.deleteFirst(); // Delete 10
my_list.printList(); // Output: 20 --> null
my_list.deleteLast(); // Delete 20
my_list.printList(); // Output: null
console.log("Length:", my_list.getLength()); // Output: Length: 0
console.log("Is empty?", my_list.isEmpty()); // Output: Is empty? true

console.log("\n--- Attempting to Delete from Empty List ---");
my_list.deleteFirst(); // Output: Warning: Cannot delete from an empty list.
my_list.deleteLast(); // Output: Warning: Cannot delete from an empty list.

my_list.append(50);
my_list.append(60);
my_list.append(70);
my_list.append(80);
my_list.printList();
// my_list.reverseLinkedListBruteForce();
const newHead = my_list.reverseLinkedListOptimal();
// console.log(newHead);
my_list.printList();
