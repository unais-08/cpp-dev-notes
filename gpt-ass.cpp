
//  Q1: Output Prediction (Loops)
// What will this code print?

// cpp
// Copy
// Edit
// for (int i = 1; i <= 5; i++) {
//     if (i % 2 == 0)
//         cout << i << " ";
// }
// A) 1 2 3 4 5
// B) 2 4
// C) 1 3 5
// D) 1 2 3 4 5

// ans: B

//  Q2: Array Declaration
// Which of the following correctly declares an integer array of size 10 in C++?

// A) int arr[10];
// B) array int[10];
// C) int[10] arr;
// D) arr int[10];

// ANS : A

#include <iostream>
#include <climits>
using namespace std;
// Q3: Find Sum of Array Elements (Code)
// Write C++ code to input 5 integers into an array and print their sum.
void sum_of_array(int* arr, size_t n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "sum of array: " << sum << endl;
}

int* take_array_input(size_t n)
{
    int* arr = new int[n];
    cout << "enter the array elements ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

// 🔹 Q4: Reverse Array
// What logic will you use to reverse an array arr of size n?

// A) Use nested loops
// B) Swap arr[i] with arr[n-i]
// C) Swap arr[i] with arr[n-1-i] for i = 0 to n/2
// D) Reverse doesn’t require code; just print it backwards
void reverse_array(int* arr, size_t n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;
        left++;
        right--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//  Q5: Count Even Numbers (Code)
// Write code to count how many even numbers are present in a given array of 6 integers.
void count_even(int* arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cnt++;
        }
    }
    cout << "Even no: " << cnt;
    cout << endl;
}
//
// 🔹 Q6: Index-based Logic
// What is the output?

// int arr[] = {10, 20, 30, 40};
// cout << arr[2];
// A) 10
// B) 20
// C) 30
// D) Error
// ans -C

// // 🔹 Q7: Find Maximum in Array (Code)
// Write code to find the maximum element in an array of size 7.
void maximum_in_array(int* arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    cout << "Max element :" << maxi << endl;
}
// 🔹 Q8: Frequency Count (MCQ)
// What is the purpose of a frequency array or hash map?

// A) To store sorted data
// B) To count how many times each value appears
// C) To find the length of array
// D) To reverse the array
// ans B

//  Q9: Dry Run (Logic Building)
// Dry run this:

// cpp
// Copy
// Edit
// int sum = 0;
// int arr[] = {1, 3, 5, 2};
// for(int i = 0; i < 4; i++) {
//     sum += arr[i];
// }
// cout << sum;
// ans 11

// 🔹 Q10: Identify Error
// What’s wrong with this code?

// cpp
// Copy
// Edit
// int arr[5];
// arr[5] = 10;
// A) Nothing
// B) Index 5 is out of bounds
// C) Value should be char, not int
// D) Array is not declared properly
// ANS B
int main()
{
    cout << "Enter the size of array: ";
    size_t n;
    cin >> n;
    int* arr = take_array_input(n);

    // cout << n;
    sum_of_array(arr, n);
    reverse_array(arr, n);
    count_even(arr, n);
    maximum_in_array(arr, n);
}