#include <iostream>
using namespace std;

/*
 * Recursive function to compute factorial of n
 * Base Case: factorial(0) = 1
 * Recursive Case: n * factorial(n-1)
 */
int factorial(int n)
{
    if (n == 0) return 1;  // fix: factorial(0) = 1 by definition
    return n * factorial(n - 1);
}

/*
 * Recursive function to compute sum of digits
 * Example: 123 => 1 + 2 + 3 = 6
 */
int sumOfDigits(int n)
{
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

/*
 * Prints numbers from 1 to n in order using recursion
 */
void print1ToN(int n)
{
    if (n == 0) return;  // base case
    print1ToN(n - 1);
    cout << n << " ";
}

/*
 * Prints numbers from n to 1 in reverse order using recursion
 */
void printNTo1(int n)
{
    if (n == 0) return;  // base case
    cout << n << " ";
    printNTo1(n - 1);
}

/*
 * Recursive function to get nth Fibonacci number
 * Base Cases: F(0) = 0, F(1) = 1
 * Recursive Case: F(n) = F(n-1) + F(n-2)
 */
int nthFibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

/*
 * Computes a^p recursively
 * Base Case: a^0 = 1
 */
int powerOfNumber(int a, int p)
{
    if (p == 0) return 1;
    return a * powerOfNumber(a, p - 1);
}

int main()
{
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Sum of digits in 123: " << sumOfDigits(123) << endl;

    cout << "Printing 1 to 5: ";
    print1ToN(5);
    cout << endl;

    cout << "Printing 5 to 1: ";
    printNTo1(5);
    cout << endl;

    cout << "10th Fibonacci number: " << nthFibonacci(10) << endl;
    cout << "10^3: " << powerOfNumber(10, 3) << endl;

    return 0;
}
