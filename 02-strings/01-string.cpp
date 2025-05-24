/**
 * File: 03-cpp-strings.cpp
 * Description: A comprehensive tutorial on strings in C++, covering both C-style
 * character arrays and the modern C++ std::string class, including their
 * characteristics, common operations, and best practices.
 */

#include <iostream>  // For std::cout, std::endl, std::cin
#include <string>    // For std::string class
#include <cstring>   // For C-style string functions (strlen, strcpy, etc.)
#include <limits>    // For std::numeric_limits (used with std::cin.ignore)

// =========================================================================
// 1. Introduction: What are Strings in C++?
// =========================================================================

/**
 * **1. Introduction: What are Strings in C++?**
 * -   A string is a sequence of characters. In C++, there are two primary ways
 * to represent and work with strings:
 * -   **C-style Strings (Character Arrays):** Inherited from the C language. These are
 * null-terminated arrays of characters (`char[]`). They require manual management
 * and are prone to errors.
 * -   **`std::string` (C++ Standard Library Class):** Introduced in the C++ Standard Library.
 * This is a powerful, flexible, and safer class for handling strings. It's the
 * **preferred way** to work with strings in modern C++.
 * -   Understanding both is important, as C-style strings are still encountered
 * (e.g., when interacting with C APIs), but `std::string` should be your default.
 */

// =========================================================================
// 2. C-style Strings (Character Arrays)
// =========================================================================

/**
 * **2. C-style Strings (Character Arrays)**
 * -   A C-style string is a `char` array that is terminated by a null character (`\0`).
 * -   The null character is crucial; it signals the end of the string to C-style string functions.
 */

/**
 * **2.1. Declaration and Initialization:**
 * -   Can be declared like any other array of `char`.
 * -   When initialized with a string literal, the compiler automatically adds the `\0`.
 */

// Example 2.1.1: C-style string declaration and initialization
char c_str1[] = "Hello";    // Size will be 6 (H,e,l,l,o,\0)
char c_str2[10] = "World";  // Size 10, initialized with "World\0", remaining 4 chars are \0
char c_str3[5] = {'C', '+', '+', '\0'};  // Explicit null termination, size 5
// char c_str4[3] = "TooLong"; // ERROR: Initializer string is too long for array size

/**
 * **2.2. Common C-style String Functions (from `<cstring>`):**
 * -   These functions operate on null-terminated `char` arrays.
 * -   **Caution:** Most of these functions do not perform bounds checking, making
 * them susceptible to **buffer overflows** if the destination buffer is too small.
 * Prefer `_s` versions (e.g., `strcpy_s`) if available and supported by your compiler,
 * or use `std::string` to avoid these issues entirely.
 */

// Example 2.2.1: strlen (string length)
// size_t strlen(const char* str); // Returns the number of characters before '\0'
void demonstrate_strlen()
{
    char text[] = "Programming";
    std::cout << "2.2.1 Length of '" << text << "': " << std::strlen(text)
              << std::endl;  // Output: 11
}

// Example 2.2.2: strcpy (string copy)
// char* strcpy(char* destination, const char* source); // Copies source to destination
void demonstrate_strcpy()
{
    char source[] = "Source String";
    char destination[20];  // Ensure destination is large enough!
    std::strcpy(destination, source);
    std::cout << "2.2.2 Copied string: " << destination << std::endl;

    // Potential buffer overflow if destination is too small:
    // char smallDest[5];
    // std::strcpy(smallDest, source); // DANGER! Undefined behavior.
}

// Example 2.2.3: strcat (string concatenate)
// char* strcat(char* destination, const char* source); // Appends source to destination
void demonstrate_strcat()
{
    char str_part1[20] = "Hello";  // Must have enough space for concatenation
    char str_part2[] = " World!";
    std::strcat(str_part1, str_part2);
    std::cout << "2.2.3 Concatenated string: " << str_part1 << std::endl;  // Output: Hello World!
}

// Example 2.2.4: strcmp (string compare)
// int strcmp(const char* str1, const char* str2); // Compares two strings lexicographically
// Returns: 0 if equal, <0 if str1 < str2, >0 if str1 > str2
void demonstrate_strcmp()
{
    char s1[] = "apple";
    char s2[] = "banana";
    char s3[] = "apple";

    std::cout << "2.2.4 Comparing 'apple' and 'banana': " << std::strcmp(s1, s2)
              << std::endl;  // Negative
    std::cout << "2.2.4 Comparing 'banana' and 'apple': " << std::strcmp(s2, s1)
              << std::endl;  // Positive
    std::cout << "2.2.4 Comparing 'apple' and 'apple': " << std::strcmp(s1, s3) << std::endl;  // 0
}

/**
 * **2.3. Input/Output with C-style Strings:**
 * -   `std::cin >> char_array;` reads a single word (until whitespace).
 * -   `std::cin.getline(char_array, size);` reads an entire line (until newline or size limit).
 */

// Example 2.3.1: Input with C-style strings
void input_c_style_string()
{
    char name_c_style[50];
    std::cout << "2.3.1 Enter your first name (C-style): ";
    std::cin >> name_c_style;  // Reads until whitespace
    std::cout << "Hello, " << name_c_style << "!" << std::endl;

    // Clear input buffer for subsequent std::cin.getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    char full_name_c_style[100];
    std::cout << "2.3.1 Enter your full name (C-style, with spaces): ";
    std::cin.getline(full_name_c_style, 100);  // Reads entire line
    std::cout << "Welcome, " << full_name_c_style << "!" << std::endl;
}

// =========================================================================
// 3. `std::string` (C++ Standard Library Class)
// =========================================================================

/**
 * **3. `std::string` (C++ Standard Library Class)**
 * -   The `std::string` class is part of the `<string>` header and is the modern,
 * safe, and efficient way to handle strings in C++.
 * -   It automatically manages its own memory (dynamic resizing), eliminating
 * the need for manual `new`/`delete` and preventing buffer overflows.
 * -   Provides a rich set of member functions for common string operations.
 */

/**
 * **3.1. Declaration and Initialization:**
 * -   Can be initialized from string literals, other `std::string` objects, or C-style strings.
 */

// Example 3.1.1: std::string declaration and initialization
std::string s1 = "Hello, C++";   // Direct initialization
std::string s2("World");         // Constructor initialization
std::string s3;                  // Default-constructed (empty string)
std::string s4(s1);              // Copy constructor
std::string s5(5, 'X');          // s5 will be "XXXXX"
std::string s6 = s1 + " " + s2;  // Concatenation using + operator

/**
 * **3.2. Common `std::string` Methods:**
 * -   `length()` or `size()`: Returns the number of characters in the string.
 * -   `empty()`: Checks if the string is empty.
 * -   `append()` or `+=`: Appends characters or another string.
 * -   `+` operator: Concatenates strings.
 * -   `at(index)`: Accesses character at index with bounds checking (throws `std::out_of_range`).
 * -   `[] operator`: Accesses character at index without bounds checking.
 * -   `find()`: Searches for a substring.
 * -   `substr(pos, len)`: Extracts a substring.
 * -   `compare()`: Compares two strings.
 * -   `clear()`: Clears the string content.
 * -   `c_str()`: Returns a null-terminated C-style string representation (const char*).
 */

// Example 3.2.1: Basic std::string operations
void demonstrate_std_string_basics()
{
    std::string message = "Hello";
    std::string name = "Alice";

    std::cout << "3.2.1 Initial message: " << message << ", length: " << message.length()
              << std::endl;

    message += ", " + name + "!";  // Concatenation
    std::cout << "3.2.1 Concatenated message: " << message << ", length: " << message.size()
              << std::endl;

    std::cout << "3.2.1 Character at index 0: " << message[0] << std::endl;                  // H
    std::cout << "3.2.1 Character at index 7 (with .at()): " << message.at(7) << std::endl;  // A

    // message.at(100); // This would throw std::out_of_range exception

    if (message.empty())
    {
        std::cout << "3.2.1 Message is empty." << std::endl;
    }
    else
    {
        std::cout << "3.2.1 Message is not empty." << std::endl;
    }
}

// Example 3.2.2: Searching and Substring
void demonstrate_std_string_search_substr()
{
    std::string sentence = "The quick brown fox jumps over the lazy dog.";

    // Find a substring
    size_t pos = sentence.find("fox");
    if (pos != std::string::npos)
    {  // std::string::npos indicates not found
        std::cout << "3.2.2 'fox' found at position: " << pos << std::endl;  // Output: 16
    }
    else
    {
        std::cout << "3.2.2 'fox' not found." << std::endl;
    }

    // Extract a substring
    std::string sub = sentence.substr(4, 5);  // Start at index 4, length 5 => "quick"
    std::cout << "3.2.2 Substring (quick): " << sub << std::endl;

    std::string lastWord = sentence.substr(sentence.find_last_of(' ') + 1);  // Extract "dog."
    std::cout << "3.2.2 Last word: " << lastWord << std::endl;
}

// Example 3.2.3: Comparison
void demonstrate_std_string_comparison()
{
    std::string strA = "apple";
    std::string strB = "banana";
    std::string strC = "apple";

    if (strA == strC)
    {  // Direct comparison using == operator
        std::cout << "3.2.3 'apple' == 'apple'" << std::endl;
    }
    if (strA != strB)
    {
        std::cout << "3.2.3 'apple' != 'banana'" << std::endl;
    }
    if (strA < strB)
    {  // Lexicographical comparison using < operator
        std::cout << "3.2.3 'apple' < 'banana'" << std::endl;
    }

    // Using compare() method (returns 0 if equal, <0 if str1 < str2, >0 if str1 > str2)
    std::cout << "3.2.3 strA.compare(strB): " << strA.compare(strB) << std::endl;  // Negative
    std::cout << "3.2.3 strA.compare(strC): " << strA.compare(strC) << std::endl;  // 0
}

/**
 * **3.3. Input/Output with `std::string`:**
 * -   `std::cin >> std_string_var;` reads a single word (until whitespace).
 * -   `std::getline(std::cin, std_string_var);` reads an entire line (until newline).
 * -   These are generally safer and easier to use than their C-style counterparts.
 */

// Example 3.3.1: Input with std::string
void input_std_string()
{
    std::string firstName;
    std::cout << "3.3.1 Enter your first name (std::string): ";
    std::cin >> firstName;  // Reads until whitespace
    std::cout << "Hello, " << firstName << "!" << std::endl;

    // Clear input buffer for subsequent std::getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string fullName;
    std::cout << "3.3.1 Enter your full name (std::string, with spaces): ";
    std::getline(std::cin, fullName);  // Reads entire line
    std::cout << "Welcome, " << fullName << "!" << std::endl;
}

/**
 * **3.4. Conversion between `std::string` and C-style Strings:**
 * -   `std::string::c_str()`: Returns a `const char*` (C-style string) representation.
 * The returned pointer is valid only as long as the `std::string` object exists and is not
 * modified.
 * -   `std::string::data()`: (C++11 onwards) Similar to `c_str()`, but returns `char*` for
 * non-const strings (C++17 onwards).
 * -   C-style string to `std::string`: Direct assignment or constructor.
 */

// Example 3.4.1: Conversions
void demonstrate_string_conversions()
{
    std::string cpp_str = "Modern C++";
    const char* c_str_from_cpp = cpp_str.c_str();  // Get C-style string from std::string
    std::cout << "3.4.1 std::string to C-style: " << c_str_from_cpp << std::endl;

    char old_c_str[] = "Legacy C";
    std::string cpp_str_from_c = old_c_str;  // C-style string to std::string
    std::cout << "3.4.1 C-style to std::string: " << cpp_str_from_c << std::endl;
}

// =========================================================================
// 4. String Literals
// =========================================================================

/**
 * **4. String Literals:**
 * -   A sequence of characters enclosed in double quotes (e.g., `"Hello"`).
 * -   String literals are C-style strings (`const char[]`) and are null-terminated.
 * -   They are stored in read-only memory.
 */

// Example 4.1: String literals
const char* literal_ptr = "This is a string literal.";
// literal_ptr[0] = 'X'; // ERROR: Attempting to modify read-only memory

// =========================================================================
// 5. Raw String Literals (C++11 onwards)
// =========================================================================

/**
 * **5. Raw String Literals (C++11 onwards):**
 * -   Allow you to define strings that ignore escape sequences (like `\n`, `\t`, `\\`).
 * -   Useful for regular expressions, file paths on Windows, or XML/JSON strings where
 * backslashes are common.
 * -   Syntax: `R"(string content)"` or `R"delimiter(string content)delimiter"`
 */

// Example 5.1: Raw string literals
void demonstrate_raw_string_literals()
{
    std::cout << "5.1 Normal string with newline: " << "Line 1\nLine 2" << std::endl;
    std::cout << "5.1 Raw string with newline: " << R"(Line 1\nLine 2)" << std::endl;

    std::string windowsPath = R"(C:\Program Files\MyApp\config.ini)";
    std::cout << "5.1 Windows path: " << windowsPath << std::endl;

    std::string regexPattern = R"(\d{3}-\d{2}-\d{4})";  // No need to escape backslashes
    std::cout << "5.1 Regex pattern: " << regexPattern << std::endl;

    // With custom delimiter
    std::string xmlContent = R"xml(
        <data>
            <item id="1">Value1</item>
        </data>
    )xml";
    std::cout << "5.1 XML content:\n" << xmlContent << std::endl;
}

// =========================================================================
// 6. Best Practices for Strings
// =========================================================================

/**
 * **6. Best Practices for Strings:**
 *
 * 6.1. **Prefer `std::string`:**
 * -   Always use `std::string` for general string manipulation in modern C++.
 * -   It handles memory management automatically, provides a rich API, and is much safer.
 *
 * 6.2. **Avoid C-style String Functions (unless necessary):**
 * -   Only use functions from `<cstring>` when interacting with legacy C APIs or for very
 * specific low-level performance optimizations (and even then, use with extreme caution).
 * -   If you must use them, ensure destination buffers are sufficiently large.
 *
 * 6.3. **Use `std::getline` for Line Input:**
 * -   When reading entire lines from input (including spaces), always use `std::getline(std::cin,
 * myString)`.
 * -   Be mindful of leftover newlines in the input buffer after `std::cin >> var;` and use
 * `std::cin.ignore()` if needed.
 *
 * 6.4. **Use `const std::string&` for Function Parameters:**
 * -   When passing `std::string` objects to functions, pass them by `const reference` (`const
 * std::string&`).
 * -   This avoids unnecessary copying (improves performance) and ensures the original string is not
 * modified.
 *
 * 6.5. **Consider String Views (`std::string_view` - C++17):**
 * -   For read-only access to string data (e.g., substrings) without making a copy,
 * `std::string_view` is a lightweight, non-owning type that can improve performance.
 *
 * 6.6. **Understand Null Termination:**
 * -   Always remember that C-style strings are null-terminated. `std::string` handles this
 * internally.
 */

// =========================================================================
// Main Function (Entry Point of the Program)
// =========================================================================

int main()
{
    std::cout << "--- Section 2: C-style Strings ---" << std::endl;
    demonstrate_strlen();
    demonstrate_strcpy();
    demonstrate_strcat();
    demonstrate_strcmp();
    // input_c_style_string(); // Uncomment to test user input for C-style strings

    std::cout << "\n--- Section 3: std::string ---" << std::endl;
    demonstrate_std_string_basics();
    demonstrate_std_string_search_substr();
    demonstrate_std_string_comparison();
    // input_std_string(); // Uncomment to test user input for std::string

    std::cout << "\n--- Section 3.4: String Conversions ---" << std::endl;
    demonstrate_string_conversions();

    std::cout << "\n--- Section 5: Raw String Literals ---" << std::endl;
    demonstrate_raw_string_literals();

    std::cout << "\n--- End of Tutorial ---" << std::endl;

    return 0;
}
