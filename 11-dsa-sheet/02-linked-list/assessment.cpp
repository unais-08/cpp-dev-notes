#include <iostream>
#include <cstring>

// Q1: Reference variable usage
void q1()
{
    int x = 10;
    int& ref = x;                                  // ref is a reference to x
    ref = 20;                                      // modifies x via reference
    std::cout << "Q1 Output: " << x << std::endl;  // Output: 20
}

// Q2: Difference between Pointer and Reference
void q2()
{
    /*
    - Pointers can be reassigned, references cannot.
    - Pointers need dereferencing (*ptr) to access value, references act as alias.
    - Pointers can be NULL, references must be initialized.
    - Use pointers when reassignment or dynamic memory is involved.
    */
}

// Q3: Pointer arithmetic in strings
void q3()
{
    char str[] = "Hello";
    std::cout << "Q3 Output: " << *(str + 1) << std::endl;  // Output: e
}

// Q4: Use of 'new' for dynamic array allocation
void q4()
{
    /*
    new int[10] dynamically allocates memory for an array of 10 integers on the heap.
    You must use delete[] to free it later.
    */
}

// Q5: Sum elements using pointer arithmetic
int q5(int* arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);  // Proper pointer usage
    }
    return sum;
}

// Q6: Count vowels in a string
int q6()
{
    char str[100];
    std::cout << "Enter string for Q6: ";
    std::cin.getline(str, 100);
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        char ch = tolower(str[i]);  // Convert to lowercase to handle uppercase vowels
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            count++;
        }
    }
    return count;
}

// Q7: Reverse string using pointers
char* q7(char* str, int len)
{
    char* start = str;
    char* end = str + len - 1;

    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    return str;
}

// Q8: Create and print a dynamic 2D array
void q8()
{
    int rows = 3, cols = 3;
    int** arr = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    // Fill array
    int value = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) arr[i][j] = value++;

    std::cout << "Q8 Output:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Free memory
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

// Q9: Swap using pointers
void q9(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Q10: Concatenate two C-style strings using dynamic memory
char* q10(const char* source, const char* dest)
{
    int len1 = strlen(source);
    int len2 = strlen(dest);
    char* newArray = new char[len1 + len2 + 1];  // +1 for '\0'

    int i = 0;
    while (*source) newArray[i++] = *source++;
    while (*dest) newArray[i++] = *dest++;
    newArray[i] = '\0';

    return newArray;
}

int main()
{
    q1();  // Reference test

    q3();  // Pointer arithmetic

    int arr[] = {1, 2, 3, 4, 5};
    int sum = q5(arr, 5);
    std::cout << "Q5 Output (Sum): " << sum << std::endl;

    int vowelCount = q6();
    std::cout << "Q6 Output (Vowel Count): " << vowelCount << std::endl;

    char str7[] = "hello";
    std::cout << "Q7 Output (Reversed): " << q7(str7, strlen(str7)) << std::endl;

    q8();  // Dynamic 2D array

    int x = 10, y = 20;
    q9(&x, &y);
    std::cout << "Q9 Output (After Swap): x = " << x << ", y = " << y << std::endl;

    char* result = q10("Hello", "World");
    std::cout << "Q10 Output (Concatenated): " << result << std::endl;
    delete[] result;  // free memory

    return 0;
}
