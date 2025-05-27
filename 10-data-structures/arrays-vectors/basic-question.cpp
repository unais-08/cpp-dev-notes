#include <iostream>   // For input/output operations (std::cout, std::cin)
#include <vector>     // For dynamic arrays (std::vector)
#include <numeric>    // For std::accumulate (summing elements)
#include <algorithm>  // For std::sort, std::min_element, std::max_element, std::reverse, std::find
#include <map>        // For frequency counting (if needed, though can be done with sort+loop)

// --- Problem 1: Find the largest and smallest elements in an array/vector ---
// Question: Given an array/vector of integers, find its maximum and minimum elements.
// Example: Input: [3, 1, 4, 1, 5, 9, 2, 6] Output: Max: 9, Min: 1
void findMinMax()
{
    std::cout << "\n--- Problem 1: Find Min/Max ---" << std::endl;

    // Using std::vector
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};
    if (vec.empty())
    {
        std::cout << "Vector is empty." << std::endl;
    }
    else
    {
        int max_val_vec = vec[0];
        int min_val_vec = vec[0];
        for (int x : vec)
        {
            if (x > max_val_vec)
            {
                max_val_vec = x;
            }
            if (x < min_val_vec)
            {
                min_val_vec = x;
            }
        }
        std::cout << "Vector: ";
        for (int x : vec) std::cout << x << " ";
        std::cout << "\nMax (vector, manual): " << max_val_vec
                  << ", Min (vector, manual): " << min_val_vec << std::endl;

        // Using std::min_element and std::max_element from <algorithm>
        auto it_min = std::min_element(vec.begin(), vec.end());
        auto it_max = std::max_element(vec.begin(), vec.end());
        std::cout << "Max (vector, std::alg): " << *it_max
                  << ", Min (vector, std::alg): " << *it_min << std::endl;
    }

    // Using C-style array
    int arr[] = {10, 5, 8, 20, 2, 15};
    int n_arr = sizeof(arr) / sizeof(arr[0]);
    if (n_arr == 0)
    {
        std::cout << "Array is empty." << std::endl;
    }
    else
    {
        int max_val_arr = arr[0];
        int min_val_arr = arr[0];
        for (int i = 0; i < n_arr; ++i)
        {
            if (arr[i] > max_val_arr)
            {
                max_val_arr = arr[i];
            }
            if (arr[i] < min_val_arr)
            {
                min_val_arr = arr[i];
            }
        }
        std::cout << "Array: ";
        for (int i = 0; i < n_arr; ++i) std::cout << arr[i] << " ";
        std::cout << "\nMax (array): " << max_val_arr << ", Min (array): " << min_val_arr
                  << std::endl;
    }
}

// --- Problem 2: Reverse an array/vector ---
// Question: Given an array/vector, reverse its elements in-place.
// Example: Input: [1, 2, 3, 4, 5] Output: [5, 4, 3, 2, 1]
void reverseArrayVector()
{
    std::cout << "\n--- Problem 2: Reverse Array/Vector ---" << std::endl;

    // Using std::vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Original vector: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;

    std::reverse(vec.begin(), vec.end());  // Using std::reverse from <algorithm>
    std::cout << "Reversed vector (std::alg): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;

    // Manual reversal for a vector (resetting for demonstration)
    vec = {1, 2, 3, 4, 5};  // Reset to original
    int left = 0;
    int right = vec.size() - 1;
    while (left < right)
    {
        std::swap(vec[left], vec[right]);  // Swap elements
        left++;
        right--;
    }
    std::cout << "Reversed vector (manual): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;

    // Using C-style array
    int arr[] = {10, 20, 30, 40};
    int n_arr = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original array: ";
    for (int i = 0; i < n_arr; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;

    left = 0;
    right = n_arr - 1;
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    std::cout << "Reversed array: ";
    for (int i = 0; i < n_arr; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// --- Problem 3: Check if an array/vector is sorted ---
// Question: Given an array/vector, determine if it is sorted in non-decreasing order.
// Example: Input: [1, 2, 3, 4] Output: True. Input: [1, 3, 2] Output: False.
void checkIfSorted()
{
    std::cout << "\n--- Problem 3: Check if Sorted ---" << std::endl;

    // Using std::vector
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 3, 2, 4};

    // Manual check for vector
    bool is_sorted_vec1 = true;
    if (vec1.size() > 1)
    {
        for (size_t i = 0; i < vec1.size() - 1; ++i)
        {
            if (vec1[i] > vec1[i + 1])
            {
                is_sorted_vec1 = false;
                break;
            }
        }
    }
    std::cout << "Vector 1: ";
    for (int x : vec1) std::cout << x << " ";
    std::cout << (is_sorted_vec1 ? " is sorted." : " is NOT sorted.") << std::endl;

    // Using std::is_sorted from <algorithm>
    std::cout << "Vector 2: ";
    for (int x : vec2) std::cout << x << " ";
    std::cout << (std::is_sorted(vec2.begin(), vec2.end()) ? " is sorted." : " is NOT sorted.")
              << std::endl;

    // Using C-style array
    int arr1[] = {7, 8, 9, 9, 10};
    int n_arr1 = sizeof(arr1) / sizeof(arr1[0]);
    bool is_sorted_arr1 = true;
    if (n_arr1 > 1)
    {
        for (int i = 0; i < n_arr1 - 1; ++i)
        {
            if (arr1[i] > arr1[i + 1])
            {
                is_sorted_arr1 = false;
                break;
            }
        }
    }
    std::cout << "Array 1: ";
    for (int i = 0; i < n_arr1; ++i) std::cout << arr1[i] << " ";
    std::cout << (is_sorted_arr1 ? " is sorted." : " is NOT sorted.") << std::endl;
}

// --- Problem 4: Calculate the sum of elements in an array/vector ---
// Question: Given an array/vector of integers, calculate the sum of all its elements.
// Example: Input: [1, 2, 3] Output: 6
void sumElements()
{
    std::cout << "\n--- Problem 4: Sum Elements ---" << std::endl;

    // Using std::vector
    std::vector<int> vec = {10, 20, 30, 40};
    long long sum_vec_manual = 0;  // Use long long for potentially large sums
    for (int x : vec)
    {
        sum_vec_manual += x;
    }
    std::cout << "Vector: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\nSum (vector, manual): " << sum_vec_manual << std::endl;

    // Using std::accumulate from <numeric>
    long long sum_vec_accumulate =
        std::accumulate(vec.begin(), vec.end(), 0LL);  // 0LL ensures accumulation as long long
    std::cout << "Sum (vector, std::accumulate): " << sum_vec_accumulate << std::endl;

    // Using C-style array
    int arr[] = {1, 2, 3, 4, 5};
    int n_arr = sizeof(arr) / sizeof(arr[0]);
    long long sum_arr = 0;
    for (int i = 0; i < n_arr; ++i)
    {
        sum_arr += arr[i];
    }
    std::cout << "Array: ";
    for (int i = 0; i < n_arr; ++i) std::cout << arr[i] << " ";
    std::cout << "\nSum (array): " << sum_arr << std::endl;
}

// --- Problem 5: Find duplicates in an array/vector ---
// Question: Given an array/vector with elements, find if there are any duplicate elements.
// (Bonus: find all duplicate elements)
// Example: Input: [1, 2, 3, 2, 1] Output: Duplicates found: 1, 2
void findDuplicates()
{
    std::cout << "\n--- Problem 5: Find Duplicates ---" << std::endl;

    // Using std::vector and sorting (modifies original vector)
    std::vector<int> vec = {1, 5, 2, 8, 5, 1, 3, 9, 2};
    std::cout << "Original vector: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end());  // Sorts the vector
    std::vector<int> duplicates_vec;
    for (size_t i = 0; i < vec.size() - 1; ++i)
    {
        if (vec[i] == vec[i + 1])
        {
            // Add to duplicates_vec only if it's not already added (to avoid multiple same
            // duplicates)
            if (duplicates_vec.empty() || duplicates_vec.back() != vec[i])
            {
                duplicates_vec.push_back(vec[i]);
            }
        }
    }

    if (duplicates_vec.empty())
    {
        std::cout << "No duplicates found in vector." << std::endl;
    }
    else
    {
        std::cout << "Duplicates in vector: ";
        for (int x : duplicates_vec) std::cout << x << " ";
        std::cout << std::endl;
    }

    // Using C-style array and a frequency map (or sorting + checking)
    int arr[] = {4, 1, 3, 4, 2, 1, 5};
    int n_arr = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original array: ";
    for (int i = 0; i < n_arr; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::map<int, int> frequency_map;
    for (int i = 0; i < n_arr; ++i)
    {
        frequency_map[arr[i]]++;
    }

    std::vector<int> duplicates_arr;
    for (auto const& [key, val] : frequency_map)
    {
        if (val > 1)
        {
            duplicates_arr.push_back(key);
        }
    }

    if (duplicates_arr.empty())
    {
        std::cout << "No duplicates found in array." << std::endl;
    }
    else
    {
        std::cout << "Duplicates in array: ";
        for (int x : duplicates_arr) std::cout << x << " ";
        std::cout << std::endl;
    }
}

// --- Problem 6: Rotate an array/vector by k positions ---
// Question: Rotate the given array/vector to the right by k steps.
// Example: Input: [1, 2, 3, 4, 5], k = 2 Output: [4, 5, 1, 2, 3]
void rotateArrayVector()
{
    std::cout << "\n--- Problem 6: Rotate Array/Vector by K ---" << std::endl;

    // Using std::vector (using a temporary vector)
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int k = 2;
    int n = vec.size();

    if (n == 0 || k == 0)
    {
        std::cout << "Vector: ";
        for (int x : vec) std::cout << x << " ";
        std::cout << ", k = " << k << " -> No rotation needed." << std::endl;
        return;
    }

    k = k % n;  // Handle cases where k is greater than vector size

    std::vector<int> rotated_vec(n);
    for (int i = 0; i < n; ++i)
    {
        rotated_vec[(i + k) % n] = vec[i];  // Place element at new position
    }

    std::cout << "Original vector: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << ", k = " << k << std::endl;
    std::cout << "Rotated vector (temp vector): ";
    for (int x : rotated_vec) std::cout << x << " ";
    std::cout << std::endl;

    // Using std::vector (in-place using std::reverse - more efficient)
    vec = {1, 2, 3, 4, 5};  // Reset for demonstration
    k = 2;                  // Reset k
    k = k % n;

    // Step 1: Reverse the whole array
    std::reverse(vec.begin(), vec.end());  // [5, 4, 3, 2, 1]
    // Step 2: Reverse the first k elements
    std::reverse(vec.begin(), vec.begin() + k);  // [4, 5, 3, 2, 1] (for k=2)
    // Step 3: Reverse the remaining n-k elements
    std::reverse(vec.begin() + k, vec.end());  // [4, 5, 1, 2, 3] (for k=2)

    std::cout << "Rotated vector (std::reverse in-place): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;

    // Using C-style array (manual rotation by k steps, less efficient for large k)
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n_arr = sizeof(arr) / sizeof(arr[0]);
    int k_arr = 3;
    k_arr = k_arr % n_arr;

    std::cout << "Original array: ";
    for (int i = 0; i < n_arr; ++i) std::cout << arr[i] << " ";
    std::cout << ", k = " << k_arr << std::endl;

    // Create a temp array to store rotated elements
    int* temp_arr = new int[n_arr];
    for (int i = 0; i < n_arr; ++i)
    {
        temp_arr[(i + k_arr) % n_arr] = arr[i];
    }
    // Copy back to original array
    for (int i = 0; i < n_arr; ++i)
    {
        arr[i] = temp_arr[i];
    }
    delete[] temp_arr;  // Free dynamically allocated memory

    std::cout << "Rotated array (temp array): ";
    for (int i = 0; i < n_arr; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// --- Problem 7: Remove duplicates from a sorted array/vector (in-place) ---
// Question: Given a sorted array/vector, remove the duplicate elements in-place such that each
// unique element appears only once. The relative order of the elements should be kept the same.
// Return the new length. Example: Input: [1, 1, 2, 2, 3, 4] Output: 4, array becomes [1, 2, 3, 4,
// _, _]
void removeDuplicatesSorted()
{
    std::cout << "\n--- Problem 7: Remove Duplicates from Sorted Array/Vector (in-place) ---"
              << std::endl;

    // Using std::vector
    std::vector<int> vec = {1, 1, 2, 2, 3, 4, 4, 5};
    std::cout << "Original vector: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;

    if (vec.empty())
    {
        std::cout << "New length (vector): 0" << std::endl;
        return;
    }

    int write_idx = 1;  // Index where the next unique element will be written
    for (size_t i = 1; i < vec.size(); ++i)
    {
        if (vec[i] != vec[i - 1])
        {                             // If current element is different from previous
            vec[write_idx] = vec[i];  // Write it to the current write_idx
            write_idx++;              // Increment write_idx
        }
    }
    vec.resize(write_idx);  // Resize the vector to the new length

    std::cout << "Vector after removing duplicates: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\nNew length (vector): " << write_idx << std::endl;

    // Using C-style array
    int arr[] = {10, 10, 20, 30, 30, 30, 40};
    int n_arr = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original array: ";
    for (int i = 0; i < n_arr; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;

    if (n_arr == 0)
    {
        std::cout << "New length (array): 0" << std::endl;
        return;
    }

    write_idx = 1;
    for (int i = 1; i < n_arr; ++i)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[write_idx] = arr[i];
            write_idx++;
        }
    }
    // The array now contains unique elements up to write_idx - 1
    // The elements beyond write_idx are not considered part of the "new" array.

    std::cout << "Array after removing duplicates (first " << write_idx << " elements): ";
    for (int i = 0; i < write_idx; ++i) std::cout << arr[i] << " ";
    std::cout << "\nNew length (array): " << write_idx << std::endl;
}

int main()
{
    findMinMax();
    reverseArrayVector();
    checkIfSorted();
    sumElements();
    findDuplicates();
    rotateArrayVector();
    removeDuplicatesSorted();

    return 0;
}