/**
 * File: 01-cpp-arrays.cpp
 * Description: A detailed tutorial on arrays in C++, covering static arrays,
 * initialization, accessing elements, multidimensional arrays, passing arrays
 * to functions, and introducing modern C++ alternatives like std::array and std::vector.
 * Author: AI Assistant
 * Date: 2025-05-23
 */

#include <iostream>  // For std::cout, std::endl
#include <string>    // For std::string (for string arrays)
#include <array>     // For std::array (C++11 fixed-size array wrapper)
#include <vector>    // For std::vector (C++ dynamic array)
#include <numeric>   // For std::accumulate (useful with arrays/vectors)

// =========================================================================
// 1. Introduction: What are Arrays?
// =========================================================================

/**
 * **1. Introduction: What are Arrays?**
 * -   An array is a **fixed-size sequential collection of elements of the same data type**.
 * -   Elements in an array are stored in contiguous (adjacent) memory locations.
 * -   This contiguous storage allows for very fast access to elements using their index.
 * -   Arrays are fundamental data structures in C++ and many other programming languages.
 * -   **Key Characteristics:**
 * -   **Homogeneous:** All elements must be of the same type (e.g., all `int`, all `double`, all
 * `std::string`).
 * -   **Fixed Size:** Once an array is declared with a certain size, that size cannot be changed
 * during runtime.
 * -   **Zero-Indexed:** The first element is at index 0, the second at index 1, and so on.
 */

// =========================================================================
// 2. Declaring and Initializing Arrays
// =========================================================================

/**
 * **2. Declaring and Initializing Arrays**
 *
 * **2.1. Basic Declaration:**
 * -   Syntax: `dataType arrayName[arraySize];`
 * -   `arraySize` must be a constant integer expression (known at compile time).
 * -   Elements are uninitialized (contain garbage values) if not explicitly initialized.
 */

// Example 2.1.1: Basic array declaration
int scores[5];  // Declares an array named 'scores' that can hold 5 integers.
                // Elements are uninitialized.

/**
 * **2.2. Initialization during Declaration:**
 * -   You can initialize an array when you declare it using an initializer list `{}`.
 * -   If you provide fewer elements than the array size, the remaining elements are
 * zero-initialized.
 * -   If you omit the size, the compiler automatically determines the size based on the number of
 * elements provided.
 */

// Example 2.2.1: Initializing with specific values
int primeNumbers[5] = {2, 3, 5, 7, 11};  // Array of 5 integers, fully initialized.

// Example 2.2.2: Partial initialization (remaining elements are zero-initialized)
int partialScores[10] = {10, 20, 30};  // partialScores[0]=10, [1]=20, [2]=30, [3-9]=0.

// Example 2.2.3: Omitting size (compiler deduces size)
int inferredArray[] = {100, 200, 300, 400};  // Size is 4.

// Example 2.2.4: Zero-initialization (all elements to 0)
int zeroArray[5] = {};          // All 5 elements are initialized to 0.
int anotherZeroArray[5] = {0};  // Also initializes all to 0.

/**
 * **2.3. Character Arrays (C-style Strings):**
 * -   Character arrays are used to store C-style strings. They are null-terminated.
 * -   The null character `\0` automatically marks the end of the string.
 */

// Example 2.3.1: Character array initialization
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};  // Explicit null termination.
char name[] = "World";  // Compiler adds '\0' automatically, size is 6 (W,o,r,l,d,\0).

// =========================================================================
// 3. Accessing Array Elements
// =========================================================================

/**
 * **3. Accessing Array Elements**
 * -   Array elements are accessed using the **subscript operator `[]`** and their index.
 * -   Remember that arrays are zero-indexed.
 * -   **Caution: Array Bounds Checking:** C++ does NOT perform automatic bounds checking at
 * runtime. Accessing an index outside the valid range (e.g., `array[size]`) leads to **undefined
 * behavior**, which can cause crashes, corrupted data, or security vulnerabilities.
 */

// Example 3.1: Accessing and modifying elements
int myNumbers[4] = {10, 20, 30, 40};

// Accessing
// int firstElement = myNumbers[0]; // 10
// int thirdElement = myNumbers[2]; // 30

// Modifying
// myNumbers[1] = 25; // myNumbers is now {10, 25, 30, 40}

// Example 3.2: Iterating through an array
void iterateArray(int arr[], int size)
{
    std::cout << "3.2 Array elements (traditional for loop): ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Example 3.3: Range-based for loop (C++11 onwards)
// This is generally preferred for iterating over entire arrays/containers.
void iterateArrayRangeBased(int arr[], int size)
{  // Note: for raw arrays, size is still needed
    std::cout << "3.3 Array elements (range-based for loop): ";
    // This syntax works directly on fixed-size arrays or std::array/std::vector
    // For raw arrays passed as pointers, you might need to know the size or use std::begin/std::end
    // For this example, we'll assume it's used on a known-size array in the calling scope
    // or a std::array/std::vector.
    // Example usage in main will show it on a fixed-size array.
}

// =========================================================================
// 4. Multidimensional Arrays
// =========================================================================

/**
 * **4. Multidimensional Arrays:**
 * -   Arrays of arrays. The most common is a 2D array (matrix).
 * -   Syntax: `dataType arrayName[rows][columns];`
 * -   Accessed using multiple subscript operators: `arrayName[rowIndex][columnIndex]`.
 * -   Stored in **row-major order** in memory (all elements of the first row, then all elements of
 * the second row, etc.).
 */

// Example 4.1: Declaring and initializing a 2D array
int matrix[2][3] = {
    {1, 2, 3},  // Row 0
    {4, 5, 6}   // Row 1
};

// Example 4.2: Accessing elements in a 2D array
// int element = matrix[0][1]; // Accesses 2 (row 0, column 1)

// Example 4.3: Iterating through a 2D array
void printMatrix(int mat[][3], int rows)
{  // Note: column size must be specified for 2D arrays in parameters
    std::cout << "4.3 Matrix elements:" << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// =========================================================================
// 5. Arrays and Functions
// =========================================================================

/**
 * **5. Arrays and Functions:**
 * -   When an array is passed to a function, it **decays into a pointer** to its first element.
 * -   This means the function receives only the memory address of the first element, not the entire
 * array.
 * -   Consequently, the function loses information about the array's size.
 * -   Therefore, it's crucial to **pass the array's size as a separate argument**.
 * -   Changes made to elements inside the function will affect the original array (pass by
 * reference behavior).
 */

// Example 5.1: Passing a 1D array to a function
void modifyArray(int arr[], int size)
{  // 'arr' is actually 'int*'
    std::cout << "5.1 Inside modifyArray (before change): ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    if (size > 0)
    {
        arr[0] = 99;  // Modifies the original array
    }
    std::cout << "5.1 Inside modifyArray (after change): ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Example 5.2: Passing a 2D array to a function
// For 2D arrays, all dimensions except the first must be specified in the parameter.
void process2DArray(int arr[][3], int rows)
{  // 'arr' is actually 'int (*)[3]'
    std::cout << "5.2 Processing 2D array..." << std::endl;
    // You can iterate and access elements as usual
}

// =========================================================================
// 6. Modern C++ Array Alternatives (`std::array` and `std::vector`)
// =========================================================================

/**
 * **6. Modern C++ Array Alternatives:**
 * -   While C-style arrays are fundamental, modern C++ provides safer and more flexible
 * container classes from the Standard Library.
 *
 * **6.1. `std::array` (C++11 onwards):**
 * -   A fixed-size container that wraps a C-style array.
 * -   Provides bounds checking (with `.at()`), iterators, and other container features.
 * -   Size is fixed at compile time, just like C-style arrays.
 * -   Stored on the stack (like C-style arrays), so no heap allocation overhead.
 * -   Syntax: `std::array<dataType, arraySize> arrayName;`
 */

// Example 6.1.1: std::array declaration and usage
void useStdArray()
{
    std::array<int, 5> data = {1, 2, 3, 4, 5};  // Fixed size 5
    std::cout << "6.1.1 std::array elements: ";
    for (int x : data)
    {  // Range-based for loop works perfectly
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "6.1.1 Element at index 2: " << data[2] << std::endl;  // No bounds check
    std::cout << "6.1.1 Element at index 4 (with .at()): " << data.at(4)
              << std::endl;  // Bounds check
    // data.at(5); // This would throw std::out_of_range exception at runtime

    std::cout << "6.1.1 Size of std::array: " << data.size() << std::endl;  // Get size
}

/**
 * **6.2. `std::vector` (Dynamic Arrays):**
 * -   A dynamic-size array that can grow or shrink during runtime.
 * -   Manages its own memory allocation on the heap.
 * -   Provides automatic memory management (no manual `new`/`delete`).
 * -   Offers rich functionality: `push_back()`, `pop_back()`, `insert()`, `erase()`, `resize()`,
 * etc.
 * -   Generally the preferred choice for most array-like needs in modern C++ due to its flexibility
 * and safety.
 * -   Syntax: `std::vector<dataType> vectorName;`
 */

// Example 6.2.1: std::vector declaration and usage
void useStdVector()
{
    std::vector<double> temperatures;  // Empty vector
    temperatures.push_back(25.5);      // Add elements
    temperatures.push_back(28.0);
    temperatures.push_back(22.3);

    std::cout << "6.2.1 std::vector elements: ";
    for (double temp : temperatures)
    {
        std::cout << temp << " ";
    }
    std::cout << std::endl;

    std::cout << "6.2.1 Current size of std::vector: " << temperatures.size()
              << std::endl;  // Get current size

    temperatures.pop_back();  // Remove last element
    std::cout << "6.2.1 After pop_back, size: " << temperatures.size() << std::endl;

    // Accessing elements (similar to arrays, .at() for bounds checking)
    std::cout << "6.2.1 First element: " << temperatures[0] << std::endl;
    std::cout << "6.2.1 Second element (with .at()): " << temperatures.at(1) << std::endl;
}

// =========================================================================
// 7. Common Pitfalls with C-style Arrays
// =========================================================================

/**
 * **7. Common Pitfalls with C-style Arrays:**
 *
 * 7.1. **No Bounds Checking:**
 * -   As mentioned, accessing `array[invalid_index]` leads to undefined behavior.
 * This is a major source of bugs and security vulnerabilities.
 *
 * 7.2. **Array Decay to Pointer:**
 * -   When passed to functions, arrays lose their size information. Always pass size explicitly.
 * -   `sizeof(arr)` inside a function receiving `arr[]` will give the size of the pointer, not the
 * array.
 *
 * 7.3. **Fixed Size:**
 * -   Cannot dynamically resize. If you need more space, you must create a new, larger array
 * and copy elements over (or use `std::vector`).
 *
 * 7.4. **Copying Arrays:**
 * -   You cannot directly assign one C-style array to another (`array1 = array2;`).
 * You must copy elements one by one (e.g., using a loop or `std::copy`).
 * -   `std::array` and `std::vector` handle copying correctly.
 */

// Example 7.1: Array Decay
void demonstrateArrayDecay(int arr[])
{  // arr is actually int*
   // std::cout << sizeof(arr) << std::endl; // This would print size of int* (e.g., 4 or 8 bytes),
   // NOT array size
}

// =========================================================================
// Main Function (Entry Point of the Program)
// =========================================================================

int main()
{
    std::cout << "--- Section 2: Declaring and Initializing Arrays ---" << std::endl;
    int scores[5];  // Uninitialized
    std::cout << "2.1 Uninitialized scores (may show garbage): ";
    for (int i = 0; i < 5; ++i) std::cout << scores[i] << " ";
    std::cout << std::endl;

    int primeNumbers[5] = {2, 3, 5, 7, 11};
    std::cout << "2.2.1 Prime Numbers: ";
    for (int i = 0; i < 5; ++i) std::cout << primeNumbers[i] << " ";
    std::cout << std::endl;

    int partialScores[10] = {10, 20, 30};
    std::cout << "2.2.2 Partial Scores: ";
    for (int i = 0; i < 10; ++i) std::cout << partialScores[i] << " ";
    std::cout << std::endl;

    int inferredArray[] = {100, 200, 300, 400};
    std::cout << "2.2.3 Inferred Array size: " << sizeof(inferredArray) / sizeof(inferredArray[0])
              << std::endl;

    char name[] = "C++";
    std::cout << "2.3.1 C-style string: " << name << std::endl;

    std::cout << "\n--- Section 3: Accessing Array Elements ---" << std::endl;
    int myNumbers[4] = {10, 20, 30, 40};
    std::cout << "3.1 Original myNumbers: ";
    iterateArray(myNumbers, 4);
    myNumbers[1] = 25;  // Modify an element
    std::cout << "3.1 Modified myNumbers: ";
    iterateArray(myNumbers, 4);

    // Range-based for loop example (directly on fixed-size array in same scope)
    std::cout << "3.3 Range-based for loop on myNumbers: ";
    for (int val : myNumbers)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "\n--- Section 4: Multidimensional Arrays ---" << std::endl;
    int matrix[2][3] = {{10, 20, 30}, {40, 50, 60}};
    printMatrix(matrix, 2);
    std::cout << "4.2 Element matrix[1][2]: " << matrix[1][2] << std::endl;  // Accesses 60

    std::cout << "\n--- Section 5: Arrays and Functions ---" << std::endl;
    int dataArray[] = {1, 2, 3, 4};
    std::cout << "5.1 Before modifyArray: ";
    for (int x : dataArray) std::cout << x << " ";
    std::cout << std::endl;
    modifyArray(dataArray, 4);
    std::cout << "5.1 After modifyArray: ";
    for (int x : dataArray) std::cout << x << " ";  // Shows 99 2 3 4
    std::cout << std::endl;

    int anotherMatrix[2][3] = {{1, 2, 3}, {7, 8, 9}};
    process2DArray(anotherMatrix, 2);  // Pass 2D array

    std::cout << "\n--- Section 6: Modern C++ Array Alternatives ---" << std::endl;
    useStdArray();
    useStdVector();

    std::cout << "\n--- Section 7: Common Pitfalls with C-style Arrays ---" << std::endl;
    int decayTestArray[5] = {1, 2, 3, 4, 5};
    demonstrateArrayDecay(decayTestArray);  // No direct output, just to show the concept

    // Attempting to copy C-style arrays directly (will not compile)
    // int arrA[3] = {1,2,3};
    // int arrB[3];
    // arrB = arrA; // ERROR: array type 'int [3]' is not assignable

    return 0;
}
