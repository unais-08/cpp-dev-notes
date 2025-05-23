/**
 * File: 01-cpp-pointers.cpp
 * Description: A comprehensive and beginner-friendly tutorial on pointers in C++,
 * covering their fundamental concepts, declaration, dereferencing, arithmetic,
 * relationship with arrays and functions, const correctness, dynamic memory
 * allocation, common pitfalls, and an introduction to smart pointers.
 * Date: 2025-05-23
 */

#include <iostream> // For std::cout, std::endl
#include <string>   // For std::string
#include <vector>   // For std::vector (for smart pointer context)
#include <memory>   // For std::unique_ptr, std::shared_ptr (smart pointers)

// =========================================================================
// 1. Introduction: What are Pointers?
// =========================================================================

/**
 * **1. Introduction: What are Pointers?**
 * -   In C++, a **pointer** is a variable that stores the **memory address** of another variable.
 * -   Instead of holding a direct value (like an `int` or `char`), it holds the location
 * (address) in computer memory where that value is stored.
 * -   Think of a pointer as a street address. It doesn't contain the house itself,
 * but it tells you exactly where to find the house.
 * -   **Why use pointers?**
 * -   **Dynamic Memory Allocation:** To allocate memory at runtime (on the heap).
 * -   **Efficient Array/Data Structure Handling:** To pass large data structures to functions
 * without copying them, improving performance.
 * -   **Direct Memory Access:** For low-level programming, hardware interaction, etc.
 * -   **Implementing Data Structures:** Like linked lists, trees, graphs.
 * -   **Polymorphism:** A core concept in Object-Oriented Programming (OOP) in C++.
 */

// =========================================================================
// 2. Memory Addresses: The Foundation of Pointers
// =========================================================================

/**
 * **2. Memory Addresses: The Foundation of Pointers**
 * -   Every variable in your program occupies a specific location in the computer's RAM (Random Access Memory).
 * -   This location has a unique numerical address.
 * -   The **address-of operator (`&`)** is used to get the memory address of a variable.
 */

// Example 2.1: Getting the address of a variable
void demonstrateAddresses()
{
    int age = 30;
    double price = 99.99;
    char grade = 'A';

    std::cout << "--- 2. Memory Addresses Example ---" << std::endl;
    std::cout << "Address of age: " << &age << std::endl;     // Output: A hexadecimal memory address (e.g., 0x7ffee...)
    std::cout << "Address of price: " << &price << std::endl; // Output: Another hexadecimal memory address
    std::cout << "Address of grade: " << &grade << std::endl; // Output: Another hexadecimal memory address
    std::cout << "Value of age: " << age << std::endl;
}

// =========================================================================
// 3. Pointer Declaration and Initialization
// =========================================================================

/**
 * **3. Pointer Declaration and Initialization**
 * -   **Declaration Syntax:** `dataType* pointerName;`
 * -   The `dataType` specifies the type of data the pointer *points to*, not the type of the pointer itself.
 * -   The `*` indicates that it's a pointer variable. It can be placed next to the type, the name, or in between.
 * Conventionally, `dataType* pointerName` or `dataType *pointerName` are common.
 * -   **Initialization:**
 * -   A pointer should always be initialized to either a valid memory address or `nullptr` (C++11 onwards, preferred over `NULL` or `0`).
 * -   An uninitialized pointer is called a **wild pointer** and can lead to crashes.
 */

// Example 3.1: Declaring and initializing pointers
void demonstratePointerDeclaration()
{
    int value = 42;
    int *ptr_value; // Declares a pointer to an integer (uninitialized - DANGER!)

    ptr_value = &value; // Initializes ptr_value with the address of 'value'

    double pi = 3.14;
    double *ptr_pi = &pi; // Declares and initializes a pointer to a double

    std::string message = "Hello";
    std::string *ptr_message = &message; // Pointer to a string

    int *null_ptr = nullptr; // Modern C++ way to declare a null pointer (points to nothing)

    std::cout << "\n--- 3. Pointer Declaration & Initialization Example ---" << std::endl;
    std::cout << "Value: " << value << ", Address: " << &value << ", Pointer holds: " << ptr_value << std::endl;
    std::cout << "Pi: " << pi << ", Address: " << &pi << ", Pointer holds: " << ptr_pi << std::endl;
    std::cout << "Message: " << message << ", Address: " << &message << ", Pointer holds: " << ptr_message << std::endl;
    std::cout << "Null pointer holds: " << null_ptr << std::endl;
}

// =========================================================================
// 4. Dereferencing Pointers (The `*` Operator)
// =========================================================================

/**
 * **4. Dereferencing Pointers (The `*` Operator)**
 * -   The `*` operator (when used with a pointer variable) is called the **dereference operator**.
 * -   It allows you to access the *value* stored at the memory address that the pointer holds.
 * -   Think of it as "go to this address and give me what's there."
 * -   **Caution:** Dereferencing a `nullptr` or a wild pointer will lead to **undefined behavior** (e.g., segmentation fault, crash).
 */

// Example 4.1: Dereferencing a pointer
void demonstrateDereferencing()
{
    int data = 100;
    int *ptr_data = &data; // ptr_data holds the address of 'data'

    std::cout << "\n--- 4. Dereferencing Pointers Example ---" << std::endl;
    std::cout << "Value of data: " << data << std::endl;
    std::cout << "Address held by ptr_data: " << ptr_data << std::endl;
    std::cout << "Value at address held by ptr_data (*ptr_data): " << *ptr_data << std::endl; // Dereferencing!

    // Modifying the value through the pointer
    *ptr_data = 200;                                                                    // Changes the value of 'data'
    std::cout << "Value of data after modification via pointer: " << data << std::endl; // Output: 200
}

// =========================================================================
// 5. Pointers and Arrays: A Close Relationship
// =========================================================================

/**
 * **5. Pointers and Arrays: A Close Relationship**
 * -   In C++, an array's name can often be treated as a **constant pointer** to its first element.
 * -   This means the array name itself holds the memory address of its first element.
 * -   **Array Decay:** When an array is passed to a function, it "decays" into a pointer
 * to its first element. The function loses information about the array's size.
 */

// Example 5.1: Array name as a pointer
void demonstratePointersAndArrays()
{
    int numbers[] = {10, 20, 30, 40, 50}; // An array of 5 integers
    int size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "\n--- 5. Pointers and Arrays Example ---" << std::endl;
    std::cout << "Address of numbers[0]: " << &numbers[0] << std::endl;
    std::cout << "Value of array name 'numbers' (address of first element): " << numbers << std::endl; // Array name decays to pointer

    // Accessing elements using pointer arithmetic (see next section)
    std::cout << "Value of numbers[0] using pointer: " << *numbers << std::endl;
    std::cout << "Value of numbers[1] using pointer: " << *(numbers + 1) << std::endl; // Same as numbers[1]
}

// Example 5.2: Array decay when passing to a function
void printArray(int *arr, int size)
{ // 'arr' is a pointer, not an array
    std::cout << "5.2 Inside printArray: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " "; // Can use array-like syntax with pointers
    }
    std::cout << std::endl;
    // std::cout << sizeof(arr) << std::endl; // This would be size of pointer (e.g., 8 bytes), not the array
}

// =========================================================================
// 6. Pointer Arithmetic
// =========================================================================

/**
 * **6. Pointer Arithmetic**
 * -   You can perform arithmetic operations on pointers, but only certain ones make sense:
 * -   **Increment (`++`):** Moves the pointer to the next memory location of the *same data type*.
 * If `ptr` points to an `int`, `ptr++` moves it `sizeof(int)` bytes forward.
 * -   **Decrement (`--`):** Moves the pointer to the previous memory location.
 * -   **Addition (`+`):** `ptr + N` moves the pointer `N * sizeof(dataType)` bytes forward.
 * -   **Subtraction (`-`):** `ptr - N` moves the pointer `N * sizeof(dataType)` bytes backward.
 * -   **Subtraction of two pointers:** `ptr1 - ptr2` gives the number of elements between them (of the pointer's type).
 * -   **Caution:** Pointer arithmetic is typically only meaningful within the bounds of an array.
 * Going out of bounds leads to undefined behavior.
 */

// Example 6.1: Pointer arithmetic
void demonstratePointerArithmetic()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr; // p points to arr[0]

    std::cout << "\n--- 6. Pointer Arithmetic Example ---" << std::endl;
    std::cout << "p points to: " << *p << " (address: " << p << ")" << std::endl;

    p++; // Move to the next integer (arr[1])
    std::cout << "p++ points to: " << *p << " (address: " << p << ")" << std::endl;

    p += 2; // Move two integers forward (arr[3])
    std::cout << "p += 2 points to: " << *p << " (address: " << p << ")" << std::endl;

    int *q = &arr[4]; // q points to arr[4]
    std::cout << "q points to: " << *q << " (address: " << q << ")" << std::endl;

    // Difference between two pointers (number of elements between them)
    std::ptrdiff_t diff = q - p; // q (arr[4]) - p (arr[3]) = 1
    std::cout << "Difference q - p: " << diff << std::endl;
}

// =========================================================================
// 7. Pointers and Functions
// =========================================================================

/**
 * **7. Pointers and Functions:**
 *
 * **7.1. Passing by Pointer (Simulating Pass by Reference):**
 * -   Similar to pass by reference (`&`), but you explicitly pass the address (`&variable`)
 * and work with the pointer (`*pointer`) inside the function.
 * -   Allows a function to modify the original variable passed from the caller.
 */

// Example 7.1.1: Pass by Pointer to modify value
void swapValues(int *a, int *b)
{
    int temp = *a; // Dereference to get value
    *a = *b;       // Modify value at address 'a'
    *b = temp;     // Modify value at address 'b'
}

/**
 * **7.2. Returning Pointers from Functions:**
 * -   A function can return a pointer.
 * -   **CRITICAL CAUTION:** Never return a pointer to a **local variable** declared inside the function.
 * Local variables are destroyed when the function exits, making the returned pointer a **dangling pointer**
 * (it points to invalid memory).
 * -   It's safe to return pointers to:
 * -   Dynamically allocated memory (allocated with `new`).
 * -   Global or static variables.
 * -   Memory passed into the function as an argument.
 */

// Example 7.2.1: DANGEROUS - Returning pointer to local variable
// int* createLocalInt() {
//     int localVal = 10;
//     return &localVal; // DANGER! localVal will be destroyed after return.
// }

// Example 7.2.2: Safe - Returning pointer to dynamically allocated memory
int *createDynamicInt(int value)
{
    int *ptr = new int(value); // Allocate on heap
    return ptr;                // Safe to return, caller must delete
}

// =========================================================================
// 8. Pointers to Pointers (Double Pointers)
// =========================================================================

/**
 * **8. Pointers to Pointers (Double Pointers)**
 * -   A pointer to a pointer is a variable that stores the memory address of another pointer.
 * -   Syntax: `dataType** pointerToPointerName;`
 * -   Used in scenarios like:
 * -   Passing a pointer by reference to a function (so the function can modify which memory the original pointer points to).
 * -   Working with arrays of pointers (e.g., C-style dynamic 2D arrays).
 */

// Example 8.1: Double pointer usage
void demonstrateDoublePointer()
{
    int val = 10;
    int *ptr = &val;         // ptr points to val
    int **ptr_to_ptr = &ptr; // ptr_to_ptr points to ptr

    std::cout << "\n--- 8. Pointers to Pointers Example ---" << std::endl;
    std::cout << "Value of val: " << val << std::endl;
    std::cout << "Address of val: " << &val << std::endl;
    std::cout << "Value of ptr (address of val): " << ptr << std::endl;
    std::cout << "Address of ptr: " << &ptr << std::endl;
    std::cout << "Value of ptr_to_ptr (address of ptr): " << ptr_to_ptr << std::endl;

    std::cout << "Dereferencing ptr_to_ptr once (*ptr_to_ptr): " << *ptr_to_ptr << " (which is the value of ptr)" << std::endl;
    std::cout << "Dereferencing ptr_to_ptr twice (**ptr_to_ptr): " << **ptr_to_ptr << " (which is the value of val)" << std::endl;

    // Modifying val through double pointer
    **ptr_to_ptr = 20;
    std::cout << "Value of val after modification via double pointer: " << val << std::endl; // Output: 20
}

// =========================================================================
// 9. `const` with Pointers (Const Correctness)
// =========================================================================

/**
 * **9. `const` with Pointers (Const Correctness)**
 * -   `const` can be used in different positions with pointers, affecting what can be modified.
 * -   This is crucial for writing safe and robust code.
 *
 * 9.1. **Pointer to `const` Data (`const int* ptr;`)**
 * -   The data pointed to cannot be modified through this pointer.
 * -   The pointer itself *can* be changed to point to another location.
 * -   Often used when a function receives a pointer to data it should only read.
 */

// Example 9.1.1: Pointer to const data
void printConstData(const int *p)
{
    // *p = 10; // ERROR: cannot assign to a variable that is const
    std::cout << "9.1.1 Value pointed to by const int*: " << *p << std::endl;
    p++; // OK: pointer itself can be changed
}

/**
 * 9.2. **`const` Pointer to Non-`const` Data (`int* const ptr;`)**
 * -   The pointer itself cannot be changed to point to another location.
 * -   The data pointed to *can* be modified through this pointer.
 */

// Example 9.2.1: Const pointer
void demonstrateConstPointer()
{
    int val = 50;
    int *const ptr = &val; // ptr is a constant pointer to val

    *ptr = 60; // OK: value can be modified through the pointer
    std::cout << "9.2.1 Value via const pointer: " << *ptr << std::endl;

    // ptr++; // ERROR: cannot increment a const pointer
    // ptr = &anotherVal; // ERROR: cannot reassign a const pointer
}

/**
 * 9.3. **`const` Pointer to `const` Data (`const int* const ptr;`)**
 * -   Neither the data pointed to nor the pointer itself can be modified.
 * -   The most restrictive form.
 */

// Example 9.3.1: Const pointer to const data
void demonstrateConstConstPointer()
{
    const int val = 70;          // val itself is const
    const int *const ptr = &val; // ptr is a const pointer to const data

    // *ptr = 80; // ERROR: cannot modify const data
    // ptr++; // ERROR: cannot modify const pointer
    std::cout << "9.3.1 Value via const int* const: " << *ptr << std::endl;
}

// =========================================================================
// 10. Dynamic Memory Allocation (`new` and `delete`)
// =========================================================================

/**
 * **10. Dynamic Memory Allocation (`new` and `delete`)**
 * -   Pointers are essential for dynamic memory allocation, which happens on the **heap**.
 * -   Memory allocated on the heap persists until explicitly deallocated or the program ends.
 * -   **`new` operator:** Allocates memory on the heap and returns a pointer to the allocated memory.
 * -   **`delete` operator:** Deallocates memory previously allocated with `new`.
 * -   **`delete[]` operator:** Deallocates memory for arrays allocated with `new[]`.
 * -   **CRITICAL:** Every `new` must have a corresponding `delete` (or `new[]` with `delete[]`)
 * to prevent **memory leaks**.
 */

// Example 10.1: Allocating a single variable dynamically
void allocateSingleInt()
{
    int *dynamicInt = new int; // Allocate memory for one int on the heap
    *dynamicInt = 123;         // Store a value in the allocated memory
    std::cout << "\n--- 10. Dynamic Memory Allocation Example ---" << std::endl;
    std::cout << "10.1 Dynamically allocated int: " << *dynamicInt << std::endl;
    delete dynamicInt;    // Deallocate the memory
    dynamicInt = nullptr; // Best practice: set pointer to nullptr after deletion
    std::cout << "10.1 Memory for dynamicInt deallocated." << std::endl;
}

// Example 10.2: Allocating an array dynamically
void allocateDynamicArray()
{
    int size = 5;
    int *dynamicArray = new int[size]; // Allocate memory for 5 ints on the heap

    for (int i = 0; i < size; ++i)
    {
        dynamicArray[i] = (i + 1) * 10;
    }

    std::cout << "10.2 Dynamically allocated array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] dynamicArray; // Deallocate the entire array
    dynamicArray = nullptr;
    std::cout << "10.2 Memory for dynamicArray deallocated." << std::endl;
}

// =========================================================================
// 11. Null Pointers (`nullptr`)
// =========================================================================

/**
 * **11. Null Pointers (`nullptr`)**
 * -   `nullptr` (introduced in C++11) is a keyword that represents a null pointer constant.
 * -   It is the preferred way to indicate that a pointer does not point to any valid memory location.
 * -   It is type-safe, unlike `NULL` (which is often defined as `0` or `(void*)0`).
 * -   Always check if a pointer is `nullptr` before dereferencing it to prevent crashes.
 */

// Example 11.1: Using nullptr
void demonstrateNullptr()
{
    int *safePtr = nullptr; // Initialize to null
    // int* unsafePtr; // Wild pointer - DANGER!

    std::cout << "\n--- 11. Null Pointers Example ---" << std::endl;
    if (safePtr == nullptr)
    {
        std::cout << "11.1 safePtr is a null pointer." << std::endl;
    }

    // if (unsafePtr == nullptr) { ... } // This check is unreliable for uninitialized pointers

    // Attempting to dereference a null pointer will cause a runtime error (segmentation fault)
    // std::cout << *safePtr << std::endl; // DANGER!
}

// =========================================================================
// 12. Dangling Pointers and Wild Pointers (Common Pitfalls)
// =========================================================================

/**
 * **12. Dangling Pointers and Wild Pointers (Common Pitfalls)**
 *
 * 12.1. **Wild Pointers:**
 * -   An uninitialized pointer. It contains a garbage memory address.
 * -   Dereferencing a wild pointer leads to immediate undefined behavior.
 * -   **Prevention:** Always initialize pointers to a valid address or `nullptr`.
 *
 * 12.2. **Dangling Pointers:**
 * -   A pointer that points to a memory location that has been deallocated or no longer exists.
 * -   This happens when the memory a pointer points to is freed, but the pointer itself is not set to `nullptr`.
 * -   Dereferencing a dangling pointer leads to undefined behavior.
 * -   **Prevention:** After `delete`ing memory, set the pointer to `nullptr`.
 */

// Example 12.1: Dangling pointer
void demonstrateDanglingPointer()
{
    int *ptr = new int(10);
    std::cout << "\n--- 12. Dangling Pointers Example ---" << std::endl;
    std::cout << "12.1 Value before delete: " << *ptr << std::endl;
    delete ptr; // Memory is freed, but ptr still holds the old address
    // ptr = nullptr; // If this line is uncommented, it prevents dangling pointer
    std::cout << "12.1 After delete, ptr points to: " << ptr << std::endl;
    // std::cout << "12.1 Value after delete (DANGER!): " << *ptr << std::endl; // DANGER! Dereferencing dangling pointer
}

// =========================================================================
// 13. Smart Pointers (Modern C++ Alternatives - Brief Introduction)
// =========================================================================

/**
 * **13. Smart Pointers (Modern C++ Alternatives - Brief Introduction)**
 * -   Modern C++ (C++11 onwards) provides **smart pointers** (`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`)
 * to automate memory management and prevent memory leaks and dangling pointers.
 * -   They are wrapper classes around raw pointers that automatically call `delete` when the
 * object goes out of scope or is no longer needed.
 * -   **Rule of Thumb:** Prefer smart pointers over raw `new`/`delete` whenever possible.
 */

// Example 13.1: std::unique_ptr (exclusive ownership)
void demonstrateUniquePtr()
{
    // std::unique_ptr takes ownership of the dynamically allocated memory
    std::unique_ptr<int> uPtr(new int(25));
    std::cout << "\n--- 13. Smart Pointers Example ---" << std::endl;
    std::cout << "13.1 unique_ptr value: " << *uPtr << std::endl;
    // Memory is automatically deallocated when uPtr goes out of scope
}

// Example 13.2: std::shared_ptr (shared ownership)
void demonstrateSharedPtr()
{
    std::shared_ptr<std::string> sPtr1(new std::string("Shared Data"));
    std::cout << "13.2 shared_ptr1 value: " << *sPtr1 << ", use count: " << sPtr1.use_count() << std::endl;

    std::shared_ptr<std::string> sPtr2 = sPtr1; // sPtr2 now shares ownership
    std::cout << "13.2 shared_ptr2 value: " << *sPtr2 << ", use count: " << sPtr1.use_count() << std::endl;

    // Memory is deallocated only when the last shared_ptr owning it is destroyed
}

// =========================================================================
// 14. Best Practices for Pointers
// =========================================================================

/**
 * **14. Best Practices for Pointers:**
 *
 * 14.1. **Prefer Smart Pointers:** For dynamic memory management, always use `std::unique_ptr`
 * or `std::shared_ptr` over raw `new`/`delete` unless there's a strong reason not to.
 *
 * 14.2. **Initialize Pointers:** Always initialize raw pointers to `nullptr` or a valid address.
 * Never leave them uninitialized.
 *
 * 14.3. **Check for `nullptr`:** Before dereferencing a raw pointer, always check if it's `nullptr`
 * to avoid runtime crashes.
 *
 * 14.4. **Pair `new` with `delete` (and `new[]` with `delete[]`):** If you must use raw pointers
 * and dynamic allocation, ensure every allocation has a corresponding deallocation.
 *
 * 14.5. **Set to `nullptr` After `delete`:** After `delete`ing memory pointed to by a raw pointer,
 * set the pointer to `nullptr` to prevent it from becoming a dangling pointer.
 *
 * 14.6. **Use `const` Correctly:** Apply `const` to pointers to enforce read-only access where appropriate,
 * improving safety and clarity.
 *
 * 14.7. **Avoid Returning Pointers to Local Variables:** Never return the address of a local stack variable.
 *
 * 14.8. **Pass by Reference (`&`) for Value Modification:** For modifying simple variables in functions,
 * prefer pass by reference (`int&`) over pass by pointer (`int*`) for cleaner syntax and safety,
 * unless pointer semantics are specifically needed (e.g., optional parameters, dynamic arrays).
 */

// =========================================================================
// Main Function (Entry Point of the Program)
// =========================================================================

int main()
{
    demonstrateAddresses();
    demonstratePointerDeclaration();
    demonstrateDereferencing();
    demonstratePointersAndArrays();
    printArray(new int[3]{10, 20, 30}, 3); // Example of passing dynamic array to function
    delete[] new int[3];                   // Clean up temp array
    demonstratePointerArithmetic();

    std::cout << "\n--- 7. Pointers and Functions Example ---" << std::endl;
    int val1 = 5, val2 = 10;
    std::cout << "Before swap: val1 = " << val1 << ", val2 = " << val2 << std::endl;
    swapValues(&val1, &val2); // Pass addresses
    std::cout << "After swap: val1 = " << val1 << ", val2 = " << val2 << std::endl;

    int *dynamicValPtr = createDynamicInt(99);
    std::cout << "Value from createDynamicInt: " << *dynamicValPtr << std::endl;
    delete dynamicValPtr; // Clean up dynamically allocated memory
    dynamicValPtr = nullptr;

    demonstrateDoublePointer();
    printConstData(new int(123)); // Example with pointer to const data
    demonstrateConstPointer();
    demonstrateConstConstPointer();

    allocateSingleInt();
    allocateDynamicArray();
    demonstrateNullptr();
    demonstrateDanglingPointer(); // Be aware of potential crash if dereferenced after delete

    demonstrateUniquePtr();
    demonstrateSharedPtr();

    std::cout << "\n--- End of Tutorial ---" << std::endl;

    return 0;
}
