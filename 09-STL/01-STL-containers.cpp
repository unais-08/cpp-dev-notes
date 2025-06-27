// 01-stl.cpp
//
// Professional and detailed documentation for C++ Standard Template Library (STL) Containers.
// This file aims to provide a comprehensive, easy-to-read reference with extensive comments
// to help in understanding and revising core STL container concepts.
//
// Key Features:
// - Overview of common container types: Sequence, Associative, and Unordered Associative.
// - Demonstrations of essential operations for each container.
// - Clear, concise, and professional commenting on purpose, complexity, and usage.
// - Focus on practical usage, common pitfalls, and C++11 features.
//
// Special Note on printContainer:
// overloads for each specific STL container type used (e.g., std::vector<int>),
// rather than using a single generic template that works for all containers.
// This approach is more verbose but explicitly shows the function for each type.
//
// Compatibility:
// This code is primarily written using C++11 features (e.g., range-based for loops,
// initializer lists, shrink_to_fit). It will compile and run correctly with C++11
// compatible compilers and newer standards (C++14, C++17, C++20).

#include <iostream>       // For input/output operations (e.g., std::cout, std::cerr)
#include <vector>         // For std::vector
#include <list>           // For std::list
#include <deque>          // For std::deque
#include <set>            // For std::set
#include <map>            // For std::map
#include <unordered_set>  // For std::unordered_set
#include <unordered_map>  // For std::unordered_map
#include <string>         // For std::string
#include <algorithm>      // For std::sort, std::find, std::distance
#include <iterator>       // For std::ostream_iterator, std::distance
#include <stdexcept>      // For std::out_of_range exception
#include <functional>     // For std::greater

// --- Helper Functions to Print Containers (Specific Overloads) ---
void printContainer(const std::string& name, const std::vector<int>& container);
void printContainer(const std::string& name, const std::list<std::string>& container);
void printContainer(const std::string& name, const std::deque<double>& container);
void printContainer(const std::string& name, const std::set<int>& container);
void printContainer(const std::string& name, const std::set<int, std::greater<int>>& container);
void printContainer(const std::string& name, const std::multiset<int>& container);
void printContainer(const std::string& name, const std::map<int, std::string>& container);
void printContainer(const std::string& name, const std::multimap<std::string, int>& container);
void printContainer(const std::string& name, const std::unordered_set<std::string>& container);
void printContainer(const std::string& name, const std::unordered_map<std::string, int>& container);

// --- Main Function to Demonstrate Containers ---
int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "  C++ STL Containers: Detailed Reference" << std::endl;
    std::cout << "========================================" << std::endl;

    // =======================================================================
    // 1. SEQUENCE CONTAINERS
    //    - Store elements in a linear fashion.
    //    - Elements are ordered by their position in the container.
    //    - Provide access to elements by their index (except for list).
    //    - Manage element memory automatically.
    // =======================================================================

    std::cout << "\n\n--- SECTION: SEQUENCE CONTAINERS ---" << std::endl;

    // --- 1.1 std::vector ---
    // Purpose: A dynamic array that can grow or shrink in size. It is the most commonly
    //          used sequence container due to its excellent performance characteristics
    //          for many use cases.
    // Structure: Elements are stored contiguously in memory.
    // Strengths:
    //   - Fast random access (O(1)) using `operator[]` or `at()`.
    //   - Efficient insertion/deletion at the end (amortized O(1)).
    // Weaknesses:
    //   - Slow insertion/deletion in the middle or beginning (O(N) - linear time)
    //     because it requires shifting all subsequent elements.
    //   - Reallocations can occur when capacity is exceeded, leading to temporary
    //     performance spikes and invalidation of all iterators, pointers, and references.
    std::vector<int> myVector;
    std::cout << "\n--- std::vector ---" << std::endl;

    // Basic Operations:
    myVector.push_back(10);  // Adds element to the end. Amortized O(1).
    myVector.push_back(20);
    myVector.push_back(30);
    printContainer("myVector (after push_back)", myVector);

    myVector.pop_back();  // Removes the last element. O(1).
    printContainer("myVector (after pop_back)", myVector);

    // Accessing elements:
    std::cout << "  First element: " << myVector.front() << std::endl;  // O(1)
    std::cout << "  Last element: " << myVector.back() << std::endl;    // O(1)

    // operator[] vs. .at():
    // operator[]: Provides direct access, no bounds checking. Faster but unsafe if index is out of
    // range.
    std::cout << "  Element at index 0 (using operator[]): " << myVector[0] << std::endl;
    // std::cout << "  Element at index 5 (unsafe): " << myVector[5] << std::endl;  // Undefined
    // behavior!

    // .at(): Provides bounds checking. Throws std::out_of_range if index is invalid. Safer but
    // slightly slower.
    try
    {
        std::cout << "  Element at index 1 (using .at() safe): " << myVector.at(1) << std::endl;
        // The following line would throw an exception:
        std::cout << "  Element at index 5 (using .at() safe): " << myVector.at(5) << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "  Error accessing vector element: " << e.what() << std::endl;
    }

    // Capacity vs. Size:
    // Size: The number of actual elements currently stored in the vector.
    // Capacity: The total number of elements the vector can hold without reallocating
    //           its internal storage. When size == capacity, the next `push_back`
    //           will likely trigger a reallocation (typically doubling capacity).
    std::cout << "  Vector size: " << myVector.size() << std::endl;
    std::cout << "  Vector capacity: " << myVector.capacity() << std::endl;

    // reserve(): Requests that the vector capacity be at least n. Can prevent multiple
    // reallocations.
    myVector.reserve(100);
    std::cout << "  Vector capacity after reserve(100): " << myVector.capacity() << std::endl;

    // shrink_to_fit(): C++11. Reduces capacity to fit its current size.
    //                  This is a non-binding request, the implementation might ignore it.
    myVector.shrink_to_fit();
    std::cout << "  Vector capacity after shrink_to_fit(): " << myVector.capacity() << std::endl;

    // Iterators:
    // `insert`: Inserts elements at a specified position. O(N) due to shifting.
    myVector.insert(myVector.begin() + 1, 15);  // Inserts 15 at index 1.
    printContainer("myVector (after insert 15 at index 1)", myVector);

    // `erase`: Removes elements at a specified position or range. O(N) due to shifting.
    myVector.erase(myVector.begin());  // Erases element at the beginning.
    printContainer("myVector (after erase at beginning)", myVector);

    // Initializing with values:
    std::vector<int> anotherVector(5, 7);  // 5 elements, all initialized to 7.
    printContainer("anotherVector (initialized with 5, 7)", anotherVector);

    std::vector<int> copiedVector = myVector;  // Copy constructor. Deep copy.
    printContainer("copiedVector (from myVector)", copiedVector);

    myVector.clear();  // Removes all elements from the vector. Size becomes 0, capacity might
                       // remain. O(N).
    printContainer("myVector (after clear)", myVector);
    std::cout << "myVector capacity (after clear) " << myVector.capacity() << std::endl;
    std::cout << " myVector is empty: " << (myVector.empty() ? "true" : "false") << std::endl;

    // --- 1.2 std::list (Doubly Linked List) ---
    // Purpose: Designed for efficient insertion and deletion of elements anywhere
    //          in the sequence.
    // Structure: A doubly linked list. Each element stores its value and pointers
    //            to the next and previous elements. Elements are NOT stored contiguously.
    // Strengths:
    //   - Efficient insertion and deletion at any position (O(1)) once an iterator
    //     to that position is found.
    //   - Iterators are not invalidated by insertions or deletions elsewhere in the list,
    //     only by the removal of the element they point to.
    // Weaknesses:
    //   - Slow random access (O(N) - linear time) as it requires traversal from
    //     the beginning or end. No `operator[]` or `at()`.
    //   - Greater memory overhead compared to vector due to pointers for each element.
    std::list<std::string> myList;
    std::cout << "\n--- std::list ---" << std::endl;

    myList.push_back("Apple");    // Add to end. O(1).
    myList.push_front("Banana");  // Add to front. O(1).
    myList.push_back("Cherry");
    printContainer("myList (initial)", myList);

    myList.pop_front();  // Remove from front. O(1).
    myList.pop_back();   // Remove from back. O(1).
    printContainer("myList (after pop_front/back)", myList);

    // Iterators are crucial for list as there's no random access:
    auto it = myList.begin();   // Get iterator to the first element
    it++;                       // Move iterator to the next element. O(1).
    myList.insert(it, "Date");  // Insert "Date" before the element 'it' points to. O(1).
    printContainer("myList (after insert 'Date')", myList);

    auto it_date = std::find(myList.begin(), myList.end(), "Date");
    if (it_date != myList.end())
    {
        myList.erase(it_date);  // Erase the element "Date". O(1).
    }
    printContainer("myList (after erase 'Date')", myList);

    myList.remove("Apple");  // Removes ALL occurrences of "Apple" from the list. O(N).
    printContainer("myList (after remove 'Apple')", myList);

    // Splicing lists: Efficiently moves elements from one list to another without copying. O(1).
    std::list<std::string> otherList = {"Fig", "Grape"};  // C++11: Initializer list
    // Move all elements from otherList to the end of myList.
    myList.splice(myList.end(), otherList);
    printContainer("myList (after splice)", myList);
    printContainer("otherList (after splice)", otherList);  // otherList is now empty

    myList.sort();  // Sorts elements in place. O(N log N).
    printContainer("myList (after sort)", myList);

    // unique(): Removes consecutive duplicate elements. Requires the list to be sorted. O(N).
    myList.push_back("Fig");  // Add a duplicate to demonstrate unique()
    myList.sort();            // Sort again to ensure duplicates are consecutive
    printContainer("myList (before unique, after sort and add Fig)", myList);
    myList.unique();  // Removes consecutive duplicates.
    printContainer("myList (after unique)", myList);

    // --- 1.3 std::deque (Double-Ended Queue) ---
    // Purpose: A double-ended queue, providing efficient insertion/deletion at both ends.
    // Structure: Elements are not stored contiguously in memory but in multiple fixed-size
    //            blocks, managed by an internal map of pointers to these blocks.
    // Strengths:
    //   - Efficient insertion/deletion at both front and back (O(1)).
    //   - Efficient random access (O(1)) using `operator[]` or `at()`.
    // Weaknesses:
    //   - Insertion/deletion in the middle is slow (O(N)).
    //   - Memory overhead is higher than vector due to the block management.
    //   - Iterators are invalidated by insertions/deletions at the ends, and by
    //     insertions/deletions in the middle.
    std::deque<double> myDeque;
    std::cout << "\n--- std::deque ---" << std::endl;

    myDeque.push_back(1.1);   // O(1)
    myDeque.push_front(2.2);  // O(1)
    myDeque.push_back(3.3);
    myDeque.push_front(4.4);
    printContainer("myDeque (initial)", myDeque);

    myDeque.pop_back();   // O(1)
    myDeque.pop_front();  // O(1)
    printContainer("myDeque (after pop_back/front)", myDeque);

    // Access elements by index, similar to vector:
    std::cout << "  Element at index 0: " << myDeque[0] << std::endl;  // O(1)
    try
    {
        std::cout << "  Element at index 1 (safe): " << myDeque.at(1) << std::endl;  // O(1)
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "  Error accessing deque element: " << e.what() << std::endl;
    }

    myDeque.insert(myDeque.begin() + 1, 5.5);  // Insert in the middle. O(N).
    printContainer("myDeque (after insert 5.5)", myDeque);

    myDeque.erase(myDeque.begin());  // Erase from beginning. O(N).
    printContainer("myDeque (after erase at beginning)", myDeque);

    // =======================================================================
    // 2. ASSOCIATIVE CONTAINERS (Ordered)
    //    - Store elements in a sorted order based on their keys.
    //    - Keys must be unique (for set/map) or can be duplicated (for multiset/multimap).
    //    - Provide efficient lookup, insertion, and deletion (logarithmic time).
    //    - Implemented using self-balancing binary search trees (e.g., Red-Black Tree).
    //    - Iterators traverse elements in sorted order.
    // =======================================================================

    std::cout << "\n\n--- SECTION: ASSOCIATIVE CONTAINERS (Ordered) ---" << std::endl;

    // --- 2.1 std::set ---
    // Purpose: Stores unique elements in a sorted order. Elements themselves serve as keys.
    // Structure: Typically implemented as a Red-Black Tree.
    // Strengths:
    //   - Elements are always kept in sorted order.
    //   - Efficient search, insertion, and deletion (O(log N)).
    //   - Keys are unique.
    // Weaknesses:
    //   - Slower than `unordered_set` on average.
    //   - Elements cannot be modified once in the set (as modification might change their sort
    //   order).
    //     You must remove and re-insert.
    //   - Memory overhead due to tree nodes.
    std::set<int> mySet;
    std::cout << "\n--- std::set ---" << std::endl;

    mySet.insert(30);  // O(log N)
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10);  // Duplicate, will NOT be inserted. `insert` returns
                       // `std::pair<iterator,bool>`/**/ The bool indicates if insertion took place.
    printContainer("mySet (initial)", mySet);  // Output will be sorted: [10, 20, 30]

    // Searching:
    // `count()`: Returns 1 if element is found, 0 otherwise (since keys are unique). O(log N).
    if (mySet.count(20))
    {
        std::cout << "  20 is in the set." << std::endl;
    }
    // `find()`: Returns an iterator to the element if found, or `set::end()` otherwise. O(log N).
    if (mySet.find(40) == mySet.end())
    {
        std::cout << "  40 is NOT in the set." << std::endl;
    }

    // Deletion:
    mySet.erase(10);  // Erase by value. O(log N).
    printContainer("mySet (after erase 10)", mySet);

    // Iterating: Elements are traversed in sorted order.
    std::cout << "  Iterating through mySet: ";
    for (auto n : mySet)  // C++11: Range-based for loop
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // --- 2.2 std::multiset ---
    // Purpose: Similar to `std::set`, but allows duplicate elements.
    // Structure: Typically implemented as a Red-Black Tree.
    // Strengths:
    //   - Allows multiple elements with the same value.
    //   - Elements are always kept in sorted order.
    //   - Efficient search, insertion, and deletion (O(log N)).
    // Weaknesses:
    //   - Slower than `unordered_multiset` on average.
    //   - Elements cannot be modified once in the multiset.
    std::multiset<int> myMultiSet;
    std::cout << "\n--- std::multiset ---" << std::endl;

    myMultiSet.insert(30);  // O(log N)
    myMultiSet.insert(10);
    myMultiSet.insert(20);
    myMultiSet.insert(10);                               // Duplicate, will be inserted.
    printContainer("myMultiSet (initial)", myMultiSet);  // Output will be sorted: [10, 10, 20, 30]

    // `count()`: Returns the number of occurrences of a given value. O(log N + M) where M is count.
    std::cout << "  Count of 10 in multiset: " << myMultiSet.count(10) << std::endl;

    // `erase()` by value: Erases ALL occurrences of the specified value. O(log N + M) where M is
    // count.
    myMultiSet.erase(10);
    printContainer("myMultiSet (after erase 10)", myMultiSet);

    // --- 2.3 std::map ---
    // Purpose: Stores key-value pairs (std::pair) in a sorted order based on keys.
    //          Keys are unique.
    // Structure: Typically implemented as a Red-Black Tree.
    // Strengths:
    //   - Efficient lookup by key (O(log N)).
    //   - Elements are always kept in sorted order by key.
    //   - `operator[]` provides convenient access and insertion.
    // Weaknesses:
    //   - Slower than `unordered_map` on average.
    //   - Memory overhead due to tree nodes.
    std::map<int, std::string> myMap;
    std::cout << "\n--- std::map ---" << std::endl;

    myMap[1] = "One";  // Insert or update if key exists. O(log N).
    myMap[3] = "Three";
    myMap.insert({2, "Two"});                  // C++11: Insert using initializer list. O(log N).
    myMap[1] = "Uno";                          // Updates the value for key 1. O(log N).
    printContainer("myMap (initial)", myMap);  // Output sorted by key: {1: Uno, 2: Two, 3: Three}

    // Accessing values:
    // `operator[]`: If key exists, returns reference to value. If key doesn't exist,
    //               inserts a new element with that key and default-constructs value, then returns
    //               reference.
    std::cout << "  Value for key 2 (using operator[]): " << myMap[2] << std::endl;

    // `at()`: If key exists, returns reference to value. If key doesn't exist, throws
    // `std::out_of_range`.
    try
    {
        std::cout << "  Value for key 3 (using .at() safe): " << myMap.at(3) << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "  Error accessing map element: " << e.what() << std::endl;
    }

    // Searching:
    auto mapIt = myMap.find(2);  // O(log N)
    if (mapIt != myMap.end())
    {
        std::cout << "  Found key 2 with value: " << mapIt->second << std::endl;
    }
    else
    {
        std::cout << "  Key 2 not found." << std::endl;
    }

    // Deletion:
    myMap.erase(1);  // Erase by key. O(log N).
    printContainer("myMap (after erase key 1)", myMap);

    // Iterating: Iterators provide `std::pair<const Key, Value>`. The key is `const` because
    // changing it would violate the sorted property of the map.
    std::cout << "  Iterating through myMap: ";
    for (const auto& pair : myMap)  // C++11: Range-based for loop
    {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;

    // --- 2.4 std::multimap ---
    // Purpose: Similar to `std::map`, but allows duplicate keys.
    // Structure: Typically implemented as a Red-Black Tree.
    // Strengths:
    //   - Allows multiple key-value pairs with the same key.
    //   - Elements are always kept in sorted order by key.
    //   - Efficient search, insertion, and deletion (O(log N)).
    // Weaknesses:
    //   - Slower than `unordered_multimap` on average.
    //   - No `operator[]` or `at()` as keys are not unique.
    std::multimap<std::string, int> myMultiMap;
    std::cout << "\n--- std::multimap ---" << std::endl;

    myMultiMap.insert({"Apple", 1});  // C++11: Initializer list
    myMultiMap.insert({"Banana", 2});
    myMultiMap.insert({"Apple", 3});  // Duplicate key, will be inserted.
    printContainer("myMultiMap (initial)",
                   myMultiMap);  // Sorted by key: {Apple:1, Apple:3, Banana:2}

    // `count()`: Returns the number of occurrences of a given key. O(log N + M) where M is count.
    std::cout << "  Count of key 'Apple': " << myMultiMap.count("Apple") << std::endl;

    // Finding all elements for a duplicate key:
    // `equal_range()`: Returns a pair of iterators defining the range of elements
    //                  with the specified key. The first iterator points to the first element
    //                  with the key, and the second iterator points one past the last element.
    auto range = myMultiMap.equal_range("Apple");  // O(log N + M) where M is count.
    std::cout << "  Values for 'Apple': ";
    for (auto it_range = range.first; it_range != range.second; ++it_range)
    {
        std::cout << it_range->second << " ";
    }
    std::cout << std::endl;

    myMultiMap.erase("Apple");  // Erases ALL pairs with key "Apple". O(log N + M) where M is count.
    printContainer("myMultiMap (after erase key 'Apple')", myMultiMap);

    // =======================================================================
    // 3. UNORDERED ASSOCIATIVE CONTAINERS (Hash-based)
    //    - Store elements in an unordered fashion (no specific order guarantees).
    //    - Provide average constant time for lookup, insertion, and deletion.
    //    - Use hash tables for implementation.
    //    - Require a hash function for the key type (provided by default for
    //      fundamental types and std::string, but needs custom for user-defined types).
    //    - Worst-case performance can be linear (O(N)) due to hash collisions,
    //      especially with a poorly chosen hash function or specific data patterns.
    // =======================================================================

    std::cout << "\n\n--- SECTION: UNORDERED ASSOCIATIVE CONTAINERS ---" << std::endl;

    // --- 3.1 std::unordered_set ---
    // Purpose: Stores unique elements in an unordered fashion.
    // Structure: Implemented as a hash table.
    // Strengths:
    //   - Average constant time performance (O(1)) for search, insertion, and deletion.
    //   - No ordering overhead.
    // Weaknesses:
    //   - Worst-case performance is O(N) if many hash collisions occur (e.g., all elements
    //     map to the same bucket).
    //   - Elements are not stored in any particular order.
    //   - Requires a hash function and equality operator for the element type.
    std::unordered_set<std::string> myUnorderedSet;
    std::cout << "\n--- std::unordered_set ---" << std::endl;

    myUnorderedSet.insert("Red");  // Average O(1), Worst O(N)
    myUnorderedSet.insert("Green");
    myUnorderedSet.insert("Blue");
    myUnorderedSet.insert("Red");                                // Duplicate, will not be inserted.
    printContainer("myUnorderedSet (initial)", myUnorderedSet);  // Order will vary

    // Searching:
    // `count()`: Returns 1 if element found, 0 otherwise. Average O(1), Worst O(N).
    if (myUnorderedSet.count("Green"))
    {
        std::cout << "  'Green' is in the unordered set." << std::endl;
    }
    // `find()`: Returns iterator to element if found, or `end()` otherwise. Average O(1), Worst
    // O(N).
    if (myUnorderedSet.find("Yellow") == myUnorderedSet.end())
    {
        std::cout << "  'Yellow' is NOT in the unordered set." << std::endl;
    }

    myUnorderedSet.erase("Red");  // Average O(1), Worst O(N).
    printContainer("myUnorderedSet (after erase 'Red')", myUnorderedSet);

    // --- 3.2 std::unordered_map ---
    // Purpose: Stores key-value pairs in an unordered fashion. Keys must be unique.
    // Structure: Implemented as a hash table.
    // Strengths:
    //   - Average constant time performance (O(1)) for search, insertion, and deletion.
    //   - No ordering overhead.
    // Weaknesses:
    //   - Worst-case performance is O(N) if many hash collisions occur.
    //   - Elements are not stored in any particular order.
    //   - Requires a hash function and equality operator for the key type.
    std::unordered_map<std::string, int> myUnorderedMap;
    std::cout << "\n--- std::unordered_map ---" << std::endl;

    myUnorderedMap["Apple"] = 10;  // Average O(1), Worst O(N)
    myUnorderedMap["Banana"] = 20;
    myUnorderedMap.insert({"Cherry", 30});  // C++11: Initializer list
    myUnorderedMap["Apple"] = 15;           // Updates value for "Apple". Average O(1), Worst O(N).
    printContainer("myUnorderedMap (initial)", myUnorderedMap);  // Order will vary

    // Accessing values:
    // `operator[]`: Average O(1), Worst O(N).
    std::cout << "  Value for key 'Banana': " << myUnorderedMap["Banana"] << std::endl;
    // `at()`: Average O(1), Worst O(N). Throws `std::out_of_range`.
    try
    {
        std::cout << "  Value for key 'Cherry' (safe): " << myUnorderedMap.at("Cherry")
                  << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "  Error accessing unordered_map element: " << e.what() << std::endl;
    }

    // Searching:
    auto unorderedMapIt = myUnorderedMap.find("Banana");  // Average O(1), Worst O(N).
    if (unorderedMapIt != myUnorderedMap.end())
    {
        std::cout << "  Found key 'Banana' with value: " << unorderedMapIt->second << std::endl;
    }

    myUnorderedMap.erase("Apple");  // Average O(1), Worst O(N).
    printContainer("myUnorderedMap (after erase 'Apple')", myUnorderedMap);

    // --- 3.3 std::unordered_multiset / std::unordered_multimap ---
    // Similar to their ordered counterparts (`multiset`, `multimap`) but use hash tables.
    // They allow duplicate elements/keys and provide average O(1) performance.
    // Not explicitly demonstrated here, but they follow the same principles as `unordered_set`
    // and `unordered_map` regarding hashing and unordered storage.

    // =======================================================================
    // 4. CONTAINER ADAPTORS
    //    - Provide a restricted interface to an underlying container.
    //    - Do not support iterators directly.
    //    - Include std::stack, std::queue, std::priority_queue.
    // =======================================================================

    std::cout << "\n\n--- SECTION: CONTAINER ADAPTORS ---" << std::endl;

    // Container adaptors are not full-fledged containers themselves, but rather
    // provide a specific interface on top of existing containers (the "underlying container").

    // --- 4.1 std::stack (LIFO - Last In, First Out) ---
    // By default uses std::deque as its underlying container. Can also use std::vector or
    // std::list. Operations: push(), pop(), top(), empty(), size(). E.g., `std::stack<int>
    // myStack;`
    std::cout << "\n--- std::stack (LIFO) ---" << std::endl;
    std::cout << "  Provides: push, pop, top, empty, size." << std::endl;
    std::cout << "  Default underlying container: std::deque." << std::endl;

    // --- 4.2 std::queue (FIFO - First In, First Out) ---
    // By default uses std::deque as its underlying container. Can also use std::list.
    // Operations: push(), pop(), front(), back(), empty(), size().
    // E.g., `std::queue<std::string> myQueue;`
    std::cout << "\n--- std::queue (FIFO) ---" << std::endl;
    std::cout << "  Provides: push, pop, front, back, empty, size." << std::endl;
    std::cout << "  Default underlying container: std::deque." << std::endl;

    // --- 4.3 std::priority_queue ---
    // A queue where elements are ordered by their "priority" (typically largest element at top).
    // By default uses std::vector as its underlying container. Implemented as a max-heap.
    // Operations: push(), pop(), top(), empty(), size().
    // E.g., `std::priority_queue<int> myPriorityQueue;`
    std::cout << "\n--- std::priority_queue ---" << std::endl;
    std::cout << "  Provides: push, pop, top, empty, size." << std::endl;
    std::cout << "  Default underlying container: std::vector." << std::endl;
    std::cout << "  Elements are ordered by value (max-heap by default)." << std::endl;

    // =======================================================================
    // 5. ADDITIONAL NOTES AND BEST PRACTICES
    // =======================================================================

    std::cout << "\n\n--- SECTION: ADDITIONAL NOTES & BEST PRACTICES ---" << std::endl;

    // Choosing the Right Container:
    // - std::vector: The default choice for most general-purpose sequential storage.
    //                Use when you need fast random access and primarily append/remove from the end.
    //                Predictable memory growth and cache efficiency due to contiguity.
    // - std::list: Use when frequent insertions/deletions in the middle are required,
    //              and random access is not critical. Avoid if random access is frequent.
    //              Best when pointers/iterators to elements must remain valid across modifications.
    // - std::deque: Good for operations at both ends (push_front/pop_front) and still
    //               provides random access. A good alternative to vector if you need
    //               efficient front insertion/deletion often.
    // - std::set/std::map: Use when you need unique elements/keys and sorted order is
    //                      important (e.g., for range queries, ordered iteration).
    //                      Logarithmic time complexity.
    // - std::unordered_set/std::unordered_map: Use when average constant time lookup/insertion is
    //                                         paramount and order is irrelevant. Requires hashable
    //                                         keys. Generally faster than ordered counterparts for
    //                                         single element operations.

    // Common Container Methods (applicable to many containers):
    // - .size(): Returns the number of elements.
    // - .empty(): Returns true if the container is empty, false otherwise.
    // - .clear(): Removes all elements from the container.
    // - .begin() / .end(): Returns iterators to the beginning and one past the last element.
    // - .cbegin() / .cend(): Returns `const` iterators (C++11+), useful when you only need to read.
    // - .rbegin() / .rend(): Returns reverse iterators (C++11+), for reverse traversal.

    // Iterators and Invalidation:
    // - Essential for traversing and manipulating elements in STL containers.
    // - Different containers support different iterator categories (e.g., random access,
    //   bidirectional, forward), which dictate what operations are allowed (e.g., `+ N`, `--`).
    // - **Iterator Invalidation**: A critical concept. When the underlying container's
    //   structure changes, existing iterators (and pointers/references) might become invalid.
    //   - `std::vector`: All iterators, pointers, and references are invalidated by `insert`,
    //     `erase` (after the point of modification), and any operation that causes reallocation
    //     (e.g., `push_back` when `capacity` is reached).
    //   - `std::list`: Iterators are only invalidated when the element they point to is erased.
    //     Insertions and deletions elsewhere do not invalidate other iterators.
    //   - `std::deque`: Iterators are invalidated by `insert` and `erase` operations in the middle,
    //     and by `push_front`/`push_back`/`pop_front`/`pop_back` if they cause reallocation or
    //     affect the specific block the iterator points to.
    //   - Associative/Unordered Associative Containers: Iterators are generally not invalidated by
    //     insertions unless a rehash occurs (for unordered), or by deletions other than the element
    //     they point to. `erase()` on a single element invalidates only iterators to that element.

    // Algorithms (from <algorithm>):
    // - STL algorithms work with iterators, making them generic and usable with various containers.
    //   They typically operate on ranges defined by a pair of iterators (`begin`, `end`).
    std::vector<int> numbers = {5, 2, 8, 1, 9};  // C++11: Initializer list
    std::cout << "\n--- STL Algorithms Example ---" << std::endl;
    printContainer("numbers (before sort)", numbers);
    std::sort(numbers.begin(),
              numbers.end());  // Sorts the vector. O(N log N) for random access iterators.
    printContainer("numbers (after sort)", numbers);

    // `std::find`: Finds the first occurrence of a value in a range. Returns an iterator.
    auto it_find = std::find(numbers.begin(), numbers.end(), 8);
    if (it_find != numbers.end())
    {
        // `std::distance`: Calculates the number of elements between two iterators.
        // O(1) for random access iterators (like vector/deque), O(N) for others (like list).
        std::cout << "  Found 8 at position: " << std::distance(numbers.begin(), it_find)
                  << std::endl;
    }
    else
    {
        std::cout << "  8 not found in numbers." << std::endl;
    }

    // Custom Comparators (for ordered containers like set/map):
    // You can provide a custom comparison function/functor/lambda to control sorting order.
    // For `std::set` and `std::map`, the third template parameter is the comparator (defaults to
    // `std::less<Key>`).
    std::set<int, std::greater<int>>
        descendingSet;  // `std::greater` makes it sort in descending order.
    descendingSet.insert(30);
    descendingSet.insert(10);
    descendingSet.insert(20);
    printContainer("descendingSet (std::greater)", descendingSet);

    // Custom Hash Functions and Equality Operators (for unordered containers):
    // For user-defined types, you need to provide a custom hash function and an
    // equality operator (`operator==`) for `std::unordered_set` and `std::unordered_map`.
    // The default `std::hash` is defined for fundamental types and `std::string`.

    // Example of a user-defined type and its hasher/equality (commented out for brevity, as it's a
    // structural detail)
    /*
    struct MyClass {
        int id;
        std::string name;

        // Required for `std::unordered_set` and `std::unordered_map` to compare elements
        bool operator==(const MyClass& other) const {
            return id == other.id && name == other.name;
        }
    };

    // Custom hash function for MyClass
    struct MyClassHasher {
        std::size_t operator()(const MyClass& mc) const {
            // Combine hashes of member fields. Bit shifting or XORing is common.
            // Using standard hash for int and string.
            return std::hash<int>()(mc.id) ^ (std::hash<std::string>()(mc.name) << 1);
        }
    };

    // Declaration using custom hasher (and default equality, or custom as member `operator==`)
    // std::unordered_set<MyClass, MyClassHasher> myCustomUnorderedSet;
    // std::unordered_map<MyClass, std::string, MyClassHasher> myCustomUnorderedMap;
    */

    std::cout << "\n========================================" << std::endl;
    std::cout << "  STL Container Reference End" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

// Overload for std::vector<int>
void printContainer(const std::string& name, const std::vector<int>& container)
{
    std::cout << "\n--- " << name << " ---" << std::endl;
    if (container.empty())
    {
        std::cout << "  (Container is empty)" << std::endl;
        return;
    }
    std::cout << "  Elements: [";
    bool first = true;
    for (const auto& elem : container)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << elem;
        first = false;
    }
    std::cout << "]" << std::endl;
    std::cout << "  Size: " << container.size() << std::endl;
    std::cout << "  Capacity: " << container.capacity() << std::endl;  // Specific to vector
}

// Overload for std::vector<std::string> - example for other vector types if needed
// void printContainer(const std::string& name, const std::vector<std::string>& container) { /* ...
// */ }

// Overload for std::list<std::string>
void printContainer(const std::string& name, const std::list<std::string>& container)
{
    std::cout << "\n--- " << name << " ---" << std::endl;
    if (container.empty())
    {
        std::cout << "  (Container is empty)" << std::endl;
        return;
    }
    std::cout << "  Elements: [";
    bool first = true;
    for (const auto& elem : container)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << elem;
        first = false;
    }
    std::cout << "]" << std::endl;
    std::cout << "  Size: " << container.size() << std::endl;
}

// Overload for std::deque<double>
void printContainer(const std::string& name, const std::deque<double>& container)
{
    std::cout << "\n--- " << name << " ---" << std::endl;
    if (container.empty())
    {
        std::cout << "  (Container is empty)" << std::endl;
        return;
    }
    std::cout << "  Elements: [";
    bool first = true;
    for (const auto& elem : container)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << elem;
        first = false;
    }
    std::cout << "]" << std::endl;
    std::cout << "  Size: " << container.size() << std::endl;
}

// Overload for std::set<int>
void printContainer(const std::string& name, const std::set<int>& container)
{
    std::cout << "\n--- " << name << " ---" << std::endl;
    if (container.empty())
    {
        std::cout << "  (Container is empty)" << std::endl;
        return;
    }
    std::cout << "  Elements: [";
    bool first = true;
    for (const auto& elem : container)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << elem;
        first = false;
    }
    std::cout << "]" << std::endl;
    std::cout << "  Size: " << container.size() << std::endl;
}

// Overload for std::set<int, std::greater<int>> (for the descendingSet example)
void printContainer(const std::string& name, const std::set<int, std::greater<int>>& container)
{
    std::cout << "\n--- " << name << " ---" << std::endl;
    if (container.empty())
    {
        std::cout << "  (Container is empty)" << std::endl;
        return;
    }
    std::cout << "  Elements: [";
    bool first = true;
    for (const auto& elem : container)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << elem;
        first = false;
    }
    std::cout << "]" << std::endl;
    std::cout << "  Size: " << container.size() << std::endl;
}

// Overload for std::multiset<int>
void printContainer(const std::string& name, const std::multiset<int>& container)
{
    std::cout << "\n--- " << name << " ---" << std::endl;
    if (container.empty())
    {
        std::cout << "  (Container is empty)" << std::endl;
        return;
    }
    std::cout << "  Elements: [";
    bool first = true;
    for (const auto& elem : container)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << elem;
        first = false;
    }
    std::cout << "]" << std::endl;
    std::cout << "  Size: " << container.size() << std::endl;
}

// Overload for std::map<int, std::string>
void printContainer(const std::string& name, const std::map<int, std::string>& container)
{
    std::cout << "\n--- " << name << " ---" << std::endl;
    if (container.empty())
    {
        std::cout << "  (Container is empty)" << std::endl;
        return;
    }
    std::cout << "  Elements: {";
    bool first = true;
    for (const auto& pair : container)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << "{" << pair.first << ": " << pair.second << "}";
        first = false;
    }
    std::cout << "}" << std::endl;
    std::cout << "  Size: " << container.size() << std::endl;
}

// Overload for std::multimap<std::string, int>
void printContainer(const std::string& name, const std::multimap<std::string, int>& container)
{
    std::cout << "\n--- " << name << " ---" << std::endl;
    if (container.empty())
    {
        std::cout << "  (Container is empty)" << std::endl;
        return;
    }
    std::cout << "  Elements: {";
    bool first = true;
    for (const auto& pair : container)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << "{" << pair.first << ": " << pair.second << "}";
        first = false;
    }
    std::cout << "}" << std::endl;
    std::cout << "  Size: " << container.size() << std::endl;
}

// Overload for std::unordered_set<std::string>
void printContainer(const std::string& name, const std::unordered_set<std::string>& container)
{
    std::cout << "\n--- " << name << " ---" << std::endl;
    if (container.empty())
    {
        std::cout << "  (Container is empty)" << std::endl;
        return;
    }
    std::cout << "  Elements: {";
    bool first = true;
    for (const auto& elem : container)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << elem;
        first = false;
    }
    std::cout << "}" << std::endl;
    std::cout << "  Size: " << container.size() << std::endl;
    std::cout << "  Bucket count: " << container.bucket_count() << std::endl;
    std::cout << "  Load factor: " << container.load_factor() << std::endl;
}

// Overload for std::unordered_map<std::string, int>
void printContainer(const std::string& name, const std::unordered_map<std::string, int>& container)
{
    std::cout << "\n--- " << name << " ---" << std::endl;
    if (container.empty())
    {
        std::cout << "  (Container is empty)" << std::endl;
        return;
    }
    std::cout << "  Elements: {";
    bool first = true;
    for (const auto& pair : container)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << "{" << pair.first << ": " << pair.second << "}";
        first = false;
    }
    std::cout << "}" << std::endl;
    std::cout << "  Size: " << container.size() << std::endl;
    std::cout << "  Bucket count: " << container.bucket_count() << std::endl;
    std::cout << "  Load factor: " << container.load_factor() << std::endl;
}
