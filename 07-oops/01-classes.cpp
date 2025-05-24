/**
 * File: 01-cpp-classes-beginner.cpp
 * Description: A professional and beginner-friendly tutorial on C++ Classes,
 * covering fundamental concepts like class definition, member variables, member functions,
 * access specifiers, objects, constructors, destructors, the 'this' pointer,
 * and basic inheritance.
 * Date: 2025-05-23
 */

#include <iostream>  // For std::cout, std::endl
#include <string>    // For std::string

// =========================================================================
// 1. Introduction: What are Classes? (The Blueprint Analogy)
// =========================================================================

/**
 * **1. Introduction: What are Classes?**
 * -   In C++, a **class** is a fundamental concept in Object-Oriented Programming (OOP).
 * -   Think of a class as a **blueprint** or a **template** for creating objects.
 * -   Just like an architectural blueprint defines the structure (rooms, windows) and
 * functionality (plumbing, electrical) of a house, a C++ class defines:
 * -   **Attributes (Member Variables):** The data or properties that objects of this class will
 * possess.
 * -   **Behaviors (Member Functions):** The actions or operations that objects of this class can
 * perform.
 * -   A class itself is not an object; it's a definition. You create **objects** (also called
 * instances) from a class. Many objects can be created from the same blueprint.
 */

// =========================================================================
// 2. Class Declaration and Definition
// =========================================================================

/**
 * **2. Class Declaration and Definition**
 * -   A class is declared using the `class` keyword.
 * -   The declaration typically includes its member variables and member functions.
 * -   It ends with a semicolon `;`.
 */

// Example 2.1: Basic Class Declaration
class Dog
{
    // Member variables (attributes)
    std::string name;
    std::string breed;
    int age;

   public:  // Access specifier (explained in Section 4)
    // Member functions (behaviors)
    void bark() { std::cout << "2.1 " << name << " says Woof!" << std::endl; }

    void setDetails(std::string n, std::string b, int a)
    {
        name = n;
        breed = b;
        age = a;
    }

    void displayDetails()
    {
        std::cout << "2.1 Name: " << name << ", Breed: " << breed << ", Age: " << age << std::endl;
    }
};  // Don't forget the semicolon!

// =========================================================================
// 3. Objects (Instances)
// =========================================================================

/**
 * **3. Objects (Instances)**
 * -   An object is a concrete realization of a class. It's a variable of the class type.
 * -   Creating an object from a class is called **instantiation**.
 * -   Each object has its own set of member variables, but they share the same member functions
 * (methods).
 */

// Example 3.1: Creating Objects and Calling Member Functions
void demonstrateObjects()
{
    std::cout << "\n--- 3. Objects Example ---" << std::endl;

    Dog myDog;  // Declares an object 'myDog' of the 'Dog' class

    // Call member functions using the dot operator '.'
    myDog.setDetails("Buddy", "Golden Retriever", 3);
    myDog.displayDetails();  // Output: Name: Buddy, Breed: Golden Retriever, Age: 3
    myDog.bark();            // Output: Buddy says Woof!

    Dog anotherDog;  // Create another object
    anotherDog.setDetails("Max", "German Shepherd", 5);
    anotherDog.displayDetails();  // Output: Name: Max, Breed: German Shepherd, Age: 5
    anotherDog.bark();            // Output: Max says Woof!
}

// =========================================================================
// 4. Access Specifiers (`public`, `private`, `protected`)
// =========================================================================

/**
 * **4. Access Specifiers**
 * -   Access specifiers control the visibility and accessibility of class members (variables and
 * functions).
 * -   They enforce **encapsulation**, a core OOP principle that bundles data with the methods that
 * operate on that data, and restricts direct access to some of the object's components.
 * -   **`private`:** Members declared `private` are accessible only from within the class itself
 * (by its own member functions). They cannot be accessed directly from outside the class. This is
 * the default access level if not specified.
 * -   **`public`:** Members declared `public` are accessible from anywhere, both inside and outside
 * the class. These are typically the interface through which users interact with the object.
 * -   **`protected`:** (Will be covered in inheritance tutorials) Members declared `protected` are
 * accessible from within the class itself and by derived classes (classes that inherit from it).
 */

// Example 4.1: Using Access Specifiers
class BankAccount
{
   private:  // Private members (data encapsulation)
    std::string accountNumber;
    double balance;

   public:  // Public interface
    // Public constructor (explained in Section 5)
    BankAccount(std::string accNum, double initialBalance)
    {
        accountNumber = accNum;
        balance = initialBalance;
        std::cout << "4.1 Account " << accountNumber << " created with balance $" << balance
                  << std::endl;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << "4.1 Deposited $" << amount << ". New balance: $" << balance << std::endl;
        }
        else
        {
            std::cout << "4.1 Deposit amount must be positive." << std::endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            std::cout << "4.1 Withdrew $" << amount << ". New balance: $" << balance << std::endl;
        }
        else
        {
            std::cout << "4.1 Insufficient funds or invalid amount." << std::endl;
        }
    }

    double getBalance() const
    {  // 'const' means this function won't modify the object's state
        return balance;
    }

    std::string getAccountNumber() const { return accountNumber; }
};

void demonstrateAccessSpecifiers()
{
    std::cout << "\n--- 4. Access Specifiers Example ---" << std::endl;
    BankAccount myAccount("123456789", 1000.0);

    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    std::cout << "Current balance for " << myAccount.getAccountNumber() << ": $"
              << myAccount.getBalance() << std::endl;

    // myAccount.balance = 5000.0; // ERROR: 'balance' is private, cannot be accessed directly
    // std::cout << myAccount.accountNumber << std::endl; // ERROR: 'accountNumber' is private
}

// =========================================================================
// 5. Constructors
// =========================================================================

/**
 * **5. Constructors**
 * -   A constructor is a special member function that is automatically called when an object
 * of the class is created (instantiated).
 * -   Its primary purpose is to **initialize the object's member variables**.
 * -   **Characteristics:**
 * -   Has the **same name as the class**.
 * -   Has **no return type** (not even `void`).
 * -   Can be overloaded (multiple constructors with different parameters).
 */

/**
 * **5.1. Default Constructor:**
 * -   A constructor that takes no arguments.
 * -   If you don't define any constructors, the compiler provides a default public one.
 * -   If you define *any* other constructor, the compiler will *not* provide a default constructor.
 */

// Example 5.1.1: Default Constructor
class Point
{
    int x;
    int y;

   public:
    Point()
    {           // Default Constructor
        x = 0;  // Initialize with default values
        y = 0;
        std::cout << "5.1.1 Default Point created: (" << x << ", " << y << ")" << std::endl;
    }
    void display() const { std::cout << "5.1.1 Point: (" << x << ", " << y << ")" << std::endl; }
};

/**
 * **5.2. Parameterized Constructor:**
 * -   A constructor that takes one or more arguments.
 * -   Used to initialize member variables with values provided during object creation.
 */

// Example 5.2.1: Parameterized Constructor
class Rectangle
{
    double length;
    double width;

   public:
    Rectangle(double l, double w)
    {  // Parameterized Constructor
        length = l;
        width = w;
        std::cout << "5.2.1 Rectangle created: Length=" << length << ", Width=" << width
                  << std::endl;
    }
    double getArea() const { return length * width; }
};

/**
 * **5.3. Constructor Overloading:**
 * -   A class can have multiple constructors, as long as they have different parameter lists.
 */

// Example 5.3.1: Constructor Overloading
class Circle
{
    double radius;
    std::string color;

   public:
    Circle() : radius(1.0), color("blue")
    {  // Default constructor, using initializer list (preferred)
        std::cout << "5.3.1 Default Circle created (radius 1.0, blue)." << std::endl;
    }
    Circle(double r) : radius(r), color("red")
    {  // Constructor with radius
        std::cout << "5.3.1 Circle created with radius " << radius << ", color red." << std::endl;
    }
    Circle(double r, std::string c) : radius(r), color(c)
    {  // Constructor with radius and color
        std::cout << "5.3.1 Circle created with radius " << radius << ", color " << color << "."
                  << std::endl;
    }
    void display() const
    {
        std::cout << "5.3.1 Circle: Radius=" << radius << ", Color=" << color << std::endl;
    }
};

// =========================================================================
// 6. Destructors
// =========================================================================

/**
 * **6. Destructors**
 * -   A destructor is a special member function that is automatically called when an object
 * is about to be destroyed (goes out of scope, or `delete` is called on a dynamically allocated
 * object).
 * -   Its primary purpose is to **perform cleanup operations**, such as:
 * -   Releasing dynamically allocated memory.
 * -   Closing file handles or network connections.
 * -   Releasing other resources acquired by the object.
 * -   **Characteristics:**
 * -   Has the same name as the class, prefixed with a tilde `~`.
 * -   Has **no return type** and takes **no arguments**.
 * -   A class can have **only one destructor**.
 */

// Example 6.1: Destructor for resource cleanup
class ResourceHandler
{
    int* data;  // Pointer to dynamically allocated memory
   public:
    ResourceHandler(int size)
    {
        data = new int[size];  // Allocate memory in constructor
        std::cout << "6.1 ResourceHandler created, allocated " << size << " integers." << std::endl;
    }

    ~ResourceHandler()
    {                   // Destructor
        delete[] data;  // Release allocated memory in destructor
        data = nullptr;
        std::cout << "6.1 ResourceHandler destroyed, memory released." << std::endl;
    }

    void useResource() const
    {
        if (data)
        {
            std::cout << "6.1 Using resource (data[0]): " << data[0] << std::endl;
        }
    }
};

// =========================================================================
// 7. The `this` Pointer
// =========================================================================

/**
 * **7. The `this` Pointer**
 * -   `this` is a special keyword in C++ that represents a **pointer** to the
 * **current object** (the object on which a member function is being called).
 * -   It is implicitly available inside all non-static member functions.
 * -   **Key Uses:**
 * -   **Distinguishing between member variables and function parameters** when they have the same
 * name.
 * -   **Returning the current object** from a member function (e.g., for method chaining).
 * -   Accessing other member functions or variables of the current object.
 */

// Example 7.1: Using the 'this' pointer
class Point3D
{
    int x, y, z;

   public:
    Point3D(int x, int y, int z)
    {                 // Parameter names are same as member variables
        this->x = x;  // 'this->x' refers to the member variable 'x'
        this->y = y;  // 'this->y' refers to the member variable 'y'
        this->z = z;  // 'this->z' refers to the member variable 'z'
    }

    void display() const
    {
        std::cout << "7.1 Point3D: (" << x << ", " << y << ", " << z << ")" << std::endl;
    }

    // Returning *this by reference for chaining
    Point3D& setX(int x)
    {
        this->x = x;
        return *this;  // Return the current object by reference
    }
    Point3D& setY(int y)
    {
        this->y = y;
        return *this;
    }
    Point3D& setZ(int z)
    {
        this->z = z;
        return *this;
    }
};

// =========================================================================
// 8. Basic Inheritance (A Glimpse)
// =========================================================================

/**
 * **8. Basic Inheritance (A Glimpse)**
 * -   Inheritance is an OOP mechanism that allows a new class (derived class or child class)
 * to inherit properties and behaviors from an existing class (base class or parent class).
 * -   It represents an "is-a" relationship (e.g., a `Car` IS-A `Vehicle`).
 * -   Promotes code reusability and establishes a hierarchy.
 * -   Syntax: `class DerivedClass : accessSpecifier BaseClass { ... };`
 * -   `accessSpecifier` (e.g., `public`) determines how base class members are inherited.
 */

// Example 8.1: Simple Inheritance
class Vehicle
{  // Base class
   public:
    std::string brand;
    Vehicle(std::string b) : brand(b)
    {
        std::cout << "8.1 Vehicle constructor called for brand: " << brand << std::endl;
    }
    void honk() const { std::cout << "8.1 " << brand << " goes Honk!" << std::endl; }
};

class Car : public Vehicle
{  // Derived class, public inheritance
   public:
    std::string model;
    Car(std::string b, std::string m) : Vehicle(b), model(m)
    {  // Call base class constructor
        std::cout << "8.1 Car constructor called for model: " << model << std::endl;
    }
    void drive() const
    {
        std::cout << "8.1 " << brand << " " << model << " is driving." << std::endl;
    }
};

// =========================================================================
// 9. Best Practices for Classes
// =========================================================================

/**
 * **9. Best Practices for Classes:**
 *
 * 9.1. **Encapsulation:** Make member variables `private` and provide `public`
 * getter/setter methods (if needed) to control access.
 *
 * 9.2. **Single Responsibility Principle (SRP):** Design classes to have one
 * primary reason to change. Each class should do one thing well.
 *
 * 9.3. **Use Constructors for Initialization:** Always initialize all member variables
 * in a constructor. Use initializer lists for efficiency (e.g., `MyClass() : var(value) {}`).
 *
 * 9.4. **Destructors for Resource Management:** If your class manages dynamic memory
 * or other resources, ensure the destructor correctly releases them. Follow the
 * **Rule of Three/Five/Zero** (an advanced topic, but important concept).
 *
 * 9.5. **`const` Correctness:** Mark member functions that do not modify the object's
 * state as `const`. Use `const` references for input parameters to avoid copying.
 *
 * 9.6. **Meaningful Names:** Use clear and descriptive names for classes, variables, and functions.
 *
 * 9.7. **Minimize Public Interface:** Only expose what's necessary in the `public` section.
 *
 * 9.8. **Prefer `std::string` and `std::vector`:** For strings and dynamic arrays,
 * use standard library classes instead of raw C-style arrays/pointers.
 */

// =========================================================================
// Main Function (Entry Point of the Program)
// =========================================================================

int main()
{
    std::cout << "--- 2. Class Declaration & Definition ---" << std::endl;
    Dog myFirstDog;
    myFirstDog.setDetails("Sparky", "Poodle", 2);
    myFirstDog.displayDetails();
    myFirstDog.bark();

    demonstrateObjects();

    demonstrateAccessSpecifiers();

    std::cout << "\n--- 5. Constructors ---" << std::endl;
    Point p1;  // Calls default constructor
    p1.display();

    Rectangle rect1(10.0, 5.0);  // Calls parameterized constructor
    std::cout << "Rectangle Area: " << rect1.getArea() << std::endl;

    Circle c1;                // Default constructor
    Circle c2(2.5);           // Constructor with radius
    Circle c3(3.0, "green");  // Constructor with radius and color
    c1.display();
    c2.display();
    c3.display();

    std::cout << "\n--- 6. Destructors ---" << std::endl;
    {                                // Create a block to control object lifetime
        ResourceHandler handler(5);  // Constructor called
        handler.useResource();
    }  // Destructor called automatically when handler goes out of scope

    std::cout << "\n--- 7. The 'this' Pointer ---" << std::endl;
    Point3D p3d(1, 2, 3);
    p3d.display();
    p3d.setX(10).setY(20).setZ(30);  // Method chaining using 'this'
    p3d.display();

    std::cout << "\n--- 8. Basic Inheritance ---" << std::endl;
    Car myCar("Ford", "Mustang");  // Calls Vehicle then Car constructor
    myCar.honk();                  // Inherited from Vehicle
    myCar.drive();                 // Own method

    std::cout << "\n--- End of Tutorial ---" << std::endl;

    return 0;
}
