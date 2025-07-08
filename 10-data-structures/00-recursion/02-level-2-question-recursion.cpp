// 🌿 Level 2 – Classic Variants
// ✅ 7. Check Palindrome String
// Check if a string is a palindrome using recursion.

// ✅ 8. Reverse a String
// Recursively reverse a string.

// ✅ 9. Count number of zeros in a number
// Example: 2040 → 2 zeros.

// ✅ 10. Sum of array elements
// Recursively sum elements of an array.

// ✅ 11. Find maximum in array
// Find the maximum element in an array recursively.

// ✅ 12. Product of array elements
// Find the product of all elements recursively.
#include <iostream>
#include <algorithm>
using namespace std;

bool checkPalindrome(string str)
{
    int left = 0;
    int right = str.length() - 1;
    while (left < right)
    {
        if (tolower(str[left]) != tolower(str[right])) return false;
        left++;
        right--;
    }
    return true;
}

string reverseString(string str)
{
    if (str.empty()) return "";
    return reverseString(str.substr(1)) + str[0];
}

int main()
{
    checkPalindrome("radar") ? cout << "true" : cout << "false";
    cout << endl;
    cout<<reverseString("reverse");
    cout << endl;
    return 0;
}