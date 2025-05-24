/**
 * File: 02-cpp-static-dynamic-arrays.cpp
 * Description: A detailed tutorial differentiating between static and dynamic arrays in C++,
 * covering their memory allocation, advantages, disadvantages, and practical usage,
 * including C-style dynamic arrays with 'new'/'delete' and modern C++ std::vector.
 * Date: 2025-05-23
 */

#include <iostream>  // For std::cout, std::endl
#include <vector>    // For std::vector (dynamic array in C++)
#include <array>     // For std::array (fixed-size array wrapper in C++11)
#include <memory>    // For std::unique_ptr, std::shared_ptr (smart pointers for dynamic memory)

// =========================================================================
// 1. Introduction: Static vs. Dynamic Memory Allocation
// =========================================================================

/**
 * **1. Introduction: Static vs. Dynamic Memory Allocation**
 * -   In C++, memory for variables and data structures can be allocated in two primary ways:
 * -   **Static Memory Allocation (Stack):** Memory is allocated at compile time. Its size is fixed
 * and known before the program runs. This includes global variables, static variables, and local
 * variables (including fixed-size arrays) within functions. Memory is automatically managed
 * (allocated when scope is entered, deallocated when scope is exited).
 * -   **Dynamic Memory Allocation (Heap):** Memory is allocated at runtime. Its size can be
 * determined or changed during program execution. This memory must be explicitly managed by the
 * programmer (allocated with `new`, deallocated with `delete`).
 * -   The distinction between static and dynamic arrays directly relates to where and when their
 * memory is allocated.
 */

// =========================================================================
// 2. Static Arrays (Fixed-Size Arrays)
// =========================================================================

/**
 * **2. Static Arrays (Fixed-Size Arrays)**
 * -   These are the traditional C-style arrays where the size is fixed at compile time.
 * -   Their memory is typically allocated on the **stack** (for local arrays) or in the
 * **data segment** (for global/static arrays).
 * -   The compiler knows exactly how much memory to reserve for the array before the program runs.
 */

/**
 * **2.1. Characteristics:**
 * -   **Fixed Size:** Size must be a constant integer expression. Cannot be changed at runtime.
 * -   **Compile-Time Allocation:** Memory is set aside when the program is compiled or when the
 * function containing it is called (on the stack).
 * -   **Automatic Memory Management:** Memory is automatically deallocated when the array goes out
 * of scope (e.g., when the function returns).
 * -   **No Bounds Checking:** C++ does not perform runtime bounds checking for C-style arrays,
 * leading to undefined behavior if you access out-of-bounds indices.
 * -   **Array Decay:** When passed to functions, they decay into a pointer to their first element,
 * losing size information.
 */

// Example 2.1.1: Static array declaration and usage
void staticArrayExample()
{
    // Size must be a compile-time constant
    const int MAX_STUDENTS = 5;
    int studentScores[MAX_STUDENTS];  // Array of 5 integers on the stack

    // Initialize elements
    for (int i = 0; i < MAX_STUDENTS; ++i)
    {
        studentScores[i] = (i + 1) * 10;
    }

    std::cout << "2.1.1 Static Array Elements: ";
    for (int i = 0; i < MAX_STUDENTS; ++i)
    {
        std::cout << studentScores[i] << " ";
    }
    std::cout << std::endl;

    // Memory for studentScores is automatically deallocated when staticArrayExample() exits.
}

// Example 2.1.2: Multidimensional static array
void static2DArrayExample()
{
    int matrix[2][3] = {{10, 20, 30}, {40, 50, 60}};
    std::cout << "2.1.2 Static 2D Array Element [0][1]: " << matrix[0][1]
              << std::endl;  // Accesses 20
}

/**
 * **2.2. When to Use Static Arrays:**
 * -   When the exact size of the array is known at compile time and will not change.
 * -   For small, fixed-size collections where stack allocation is desired for performance.
 * -   When interacting with C APIs that expect raw arrays.
 * -   For lookup tables or fixed-size buffers.
 */

// =========================================================================
// 3. Dynamic Arrays (Runtime-Sized Arrays)
// =========================================================================

/**
 * **3. Dynamic Arrays (Runtime-Sized Arrays)**
 * -   These arrays have a size that can be determined or changed during program execution.
 * -   Their memory is allocated on the **heap** (also known as "free store").
 * -   Requires explicit memory management (allocation and deallocation).
 * -   Modern C++ strongly prefers `std::vector` for dynamic arrays due to its safety and automatic
 * memory management.
 */

/**
 * **3.1. C-style Dynamic Arrays (`new` and `delete`)**
 * -   Allocated using the `new` operator and deallocated using the `delete[]` operator.
 * -   `new dataType[size]` returns a pointer to the first element of the allocated memory block.
 * -   **Crucial:** You *must* use `delete[]` to free the allocated memory when it's no longer
 * needed, to prevent **memory leaks**.
 */

/**
 * **3.1.1. Characteristics of C-style Dynamic Arrays:**
 * -   **Runtime Size:** Size can be a variable determined during execution.
 * -   **Heap Allocation:** Memory is allocated from the heap.
 * -   **Manual Memory Management:** Programmer is responsible for `delete[]`.
 * -   **No Bounds Checking:** Similar to static C-style arrays, no runtime bounds checking.
 * -   **Pointer Semantics:** You work with a pointer to the first element.
 */

// Example 3.1.1: C-style dynamic array usage
void cStyleDynamicArrayExample(int size)
{
    if (size <= 0)
    {
        std::cout << "3.1.1 Invalid size for dynamic array." << std::endl;
        return;
    }

    int* dynamicArray = new int[size];  // Allocate memory for 'size' integers on the heap

    std::cout << "3.1.1 C-style Dynamic Array (size " << size << ") elements: ";
    for (int i = 0; i < size; ++i)
    {
        dynamicArray[i] = i * 100;  // Initialize elements
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    // IMPORTANT: Deallocate memory when done to prevent memory leaks
    delete[] dynamicArray;
    dynamicArray = nullptr;  // Good practice to set pointer to nullptr after deletion
    std::cout << "3.1.1 C-style Dynamic Array memory deallocated." << std::endl;
}

// Example 3.1.2: Dynamic 2D Array (using pointers to pointers)
void cStyleDynamic2DArrayExample(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
    {
        std::cout << "3.1.2 Invalid dimensions for dynamic 2D array." << std::endl;
        return;
    }

    // Allocate array of pointers (each pointer will point to a row)
    int** dynamicMatrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        dynamicMatrix[i] = new int[cols];  // Allocate each row
    }

    std::cout << "3.1.2 Dynamic 2D Array elements (initialized):" << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            dynamicMatrix[i][j] = (i + 1) * 10 + (j + 1);
            std::cout << dynamicMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // IMPORTANT: Deallocate memory in reverse order of allocation
    for (int i = 0; i < rows; ++i)
    {
        delete[] dynamicMatrix[i];  // Delete each row
    }
    delete[] dynamicMatrix;  // Delete the array of pointers
    dynamicMatrix = nullptr;
    std::cout << "3.1.2 Dynamic 2D Array memory deallocated." << std::endl;
}

/**
 * **3.2. Modern C++ Dynamic Arrays (`std::vector`)**
 * -   `std::vector` is part of the C++ Standard Library and is the **preferred way**
 * to handle dynamic arrays in modern C++.
 * -   It's a template class that manages its own memory automatically, growing or shrinking
 * as needed.
 * -   It handles memory allocation, deallocation, and resizing internally, eliminating
 * the risk of memory leaks and manual memory management errors.
 * -   Provides bounds checking (with `.at()`), iterators, and a rich set of member functions.
 */

/**
 * **3.2.1. Characteristics of `std::vector`:**
 * -   **Dynamic Size:** Can grow or shrink at runtime.
 * -   **Heap Allocation:** Memory for elements is on the heap, managed by `std::vector`.
 * -   **Automatic Memory Management:** No `new`/`delete` needed. Resource Acquisition Is
 * Initialization (RAII) principle.
 * -   **Bounds Checking:** `.at()` provides bounds checking (throws `std::out_of_range`). `[]`
 * operator does not.
 * -   **Rich API:** `push_back()`, `pop_back()`, `insert()`, `erase()`, `resize()`, `clear()`,
 * `size()`, `capacity()`, etc.
 * -   **Contiguous Storage:** Elements are still stored contiguously in memory, allowing efficient
 * random access.
 */

// Example 3.2.1: std::vector usage
void stdVectorExample()
{
    std::vector<int> numbers;  // Creates an empty vector of integers
    std::cout << "3.2.1 Initial vector size: " << numbers.size()
              << ", capacity: " << numbers.capacity() << std::endl;

    numbers.push_back(10);  // Add elements
    numbers.push_back(20);
    numbers.push_back(30);
    std::cout << "3.2.1 After push_back, size: " << numbers.size()
              << ", capacity: " << numbers.capacity() << std::endl;

    std::cout << "3.2.1 Vector elements: ";
    for (int n : numbers)
    {  // Range-based for loop works seamlessly
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "3.2.1 Element at index 1: " << numbers[1] << std::endl;
    std::cout << "3.2.1 Element at index 0 (with .at()): " << numbers.at(0) << std::endl;

    // numbers.at(3); // This would throw std::out_of_range exception

    numbers.pop_back();  // Remove last element
    std::cout << "3.2.1 After pop_back, size: " << numbers.size()
              << ", capacity: " << numbers.capacity() << std::endl;

    numbers.clear();  // Remove all elements
    std::cout << "3.2.1 After clear, size: " << numbers.size()
              << ", capacity: " << numbers.capacity() << std::endl;
}

// Example 3.2.2: std::vector of vectors (for 2D dynamic arrays)
void stdVector2DExample()
{
    // Create a 3x4 2D vector, initialized with zeros
    std::vector<std::vector<int>> matrix(3, std::vector<int>(4, 0));

    // Access and modify
    matrix[0][0] = 1;
    matrix[1][2] = 5;
    matrix[2][3] = 9;

    std::cout << "3.2.2 std::vector 2D elements:" << std::endl;
    for (const auto& row : matrix)
    {
        for (int val : row)
        {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    }

    // You can resize rows or add new rows dynamically
    matrix.push_back(std::vector<int>(2, 100));  // Add a new row of size 2
    std::cout << "3.2.2 After adding a row, new matrix:" << std::endl;
    for (const auto& row : matrix)
    {
        for (int val : row)
        {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    }
}

/**
 * **3.3. When to Use Dynamic Arrays (`std::vector`):**
 * -   When the size of the collection is not known at compile time or needs to change during
 * runtime.
 * -   For almost all general-purpose array-like needs in modern C++.
 * -   When you want automatic memory management and a rich set of utility functions.
 * -   When you need to pass arrays to functions without explicit size arguments (as `std::vector`
 * carries its size).
 *
 * **When to Use C-style Dynamic Arrays (`new`/`delete`):**
 * -   Rarely in modern C++ applications, unless:
 * -   You are working with legacy C code or APIs that require raw pointers.
 * -   You are implementing custom memory allocators or low-level data structures.
 * -   You are writing performance-critical code where very fine-grained memory control is
 * absolutely necessary (though `std::vector` is highly optimized).
 * -   You are learning about manual memory management for educational purposes.
 */

// =========================================================================
// 4. `std::array` (Fixed-Size Array Wrapper)
// =========================================================================

/**
 * **4. `std::array` (Fixed-Size Array Wrapper - C++11 onwards)**
 * -   `std::array` is a fixed-size container that provides a thin wrapper around a C-style array.
 * -   It combines the benefits of C-style arrays (stack allocation, no heap overhead) with the
 * safety and features of standard library containers.
 * -   Its size is fixed at compile time, just like a C-style array.
 */

/**
 * **4.1. Characteristics of `std::array`:**
 * -   **Fixed Size:** Size must be a compile-time constant. Cannot be changed at runtime.
 * -   **Stack Allocation:** Memory is typically on the stack.
 * -   **Automatic Memory Management:** No `new`/`delete` needed.
 * -   **Bounds Checking:** Provides `.at()` for bounds-checked access (throws `std::out_of_range`).
 * `[]` operator does not.
 * -   **Container Features:** Supports iterators, `size()`, `empty()`, `fill()`, etc.
 * -   **Can be copied and assigned:** Unlike raw C-style arrays.
 */

// Example 4.1.1: std::array usage
void stdArrayFixedExample()
{
    std::array<int, 4> values = {10, 20, 30, 40};  // Fixed size 4
    std::cout << "4.1.1 std::array elements: ";
    for (int val : values)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "4.1.1 Size: " << values.size() << std::endl;
    std::cout << "4.1.1 Element at index 2: " << values.at(2) << std::endl;  // Accesses 30

    std::array<int, 4> otherValues;
    otherValues = values;  // std::array can be copied directly
    std::cout << "4.1.1 Copied std::array elements: ";
    for (int val : otherValues)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

/**
 * **4.2. When to Use `std::array`:**
 * -   When you need a fixed-size array and want the safety, convenience, and features of a standard
 * library container.
 * -   When you want to avoid manual memory management for fixed-size collections.
 * -   As a safer and more feature-rich replacement for C-style fixed-size arrays.
 * -   When performance is critical and stack allocation is preferred over heap.
 */

// =========================================================================
// Main Function (Entry Point of the Program)
// =========================================================================

int main()
{
    std::cout << "--- Section 2: Static Arrays ---" << std::endl;
    staticArrayExample();
    static2DArrayExample();

    std::cout << "\n--- Section 3.1: C-style Dynamic Arrays (`new`/`delete`) ---" << std::endl;
    cStyleDynamicArrayExample(3);
    cStyleDynamicArrayExample(0);  // Test invalid size
    cStyleDynamicArrayExample(7);

    std::cout << "\n--- Section 3.1.2: C-style Dynamic 2D Arrays ---" << std::endl;
    cStyleDynamic2DArrayExample(2, 4);
    cStyleDynamic2DArrayExample(0, 0);  // Test invalid dimensions

    std::cout << "\n--- Section 3.2: Modern C++ Dynamic Arrays (`std::vector`) ---" << std::endl;
    stdVectorExample();
    stdVector2DExample();

    std::cout << "\n--- Section 4: `std::array` (Fixed-Size Array Wrapper) ---" << std::endl;
    stdArrayFixedExample();

    return 0;
}
