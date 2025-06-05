/**
 * PolymorphismDocumentation.cpp
 *
 * This file provides comprehensive documentation and examples for the
 * concept of Polymorphism in C++ Object-Oriented Programming (OOP).
 *
 * Polymorphism means "many forms". In C++, it allows objects of different classes
 * to be treated as objects of a common base class. This enables a single interface
 * to represent different underlying forms (types), enhancing code flexibility,
 * extensibility, and reusability.
 *
 * There are two main types of polymorphism in C++:
 * 1.  Compile-time Polymorphism (Static Binding / Early Binding):
 * Achieved through Function Overloading and Operator Overloading. The compiler
 * decides which function or operator to call at compile time based on the
 * function signature (name, number, and type of arguments).
 * 2.  Run-time Polymorphism (Dynamic Binding / Late Binding):
 * Achieved through Virtual Functions and Abstract Classes. The decision
 * of which function to call is made at run time, based on the actual
 * type of the object pointed to by a base class pointer or reference.
 *
 * Author: Gemini
 * Date: May 31, 2025
 */

#include <iostream> // For input/output operations (e.g., std::cout)
#include <string>   // For std::string
#include <vector>   // For std::vector (useful for collections of polymorphic objects)

// Use the standard namespace to avoid prefixing std::
using namespace std;

// --- 1. Compile-time Polymorphism (Function Overloading) ---
/**
 * @section Function Overloading
 * @brief Defining multiple functions with the same name but different parameters.
 *
 * Real-world Scenario: A 'Logger' service that can log messages in various ways:
 * -   Log a simple string message.
 * -   Log an integer value.
 * -   Log a message with a severity level.
 *
 * The compiler determines which 'log' function to call based on the arguments provided.
 */
class Logger {
public:
    /**
     * @brief Logs a simple message.
     * @param message The string message to log.
     */
    void log(const string& message) const {
        cout << "[INFO]: " << message << endl;
    }

    /**
     * @brief Logs an integer value.
     * @param value The integer value to log.
     */
    void log(int value) const {
        cout << "[INFO]: Numeric value: " << value << endl;
    }

    /**
     * @brief Logs a message with a specified severity.
     * @param severity The severity level (e.g., "WARNING", "ERROR").
     * @param message The string message to log.
     */
    void log(const string& severity, const string& message) const {
        cout << "[" << severity << "]: " << message << endl;
    }
};

// --- 2. Compile-time Polymorphism (Operator Overloading) ---
/**
 * @section Operator Overloading
 * @brief Giving special meaning to C++ operators when applied to user-defined data types.
 *
 * Real-world Scenario: Defining vector addition for 2D vectors.
 * The '+' operator, when applied to two `Vector2D` objects, performs vector addition.
 */
class Vector2D {
private:
    double x;
    double y;

public:
    /**
     * @brief Constructor for Vector2D.
     * @param valX The x-component.
     * @param valY The y-component.
     */
    Vector2D(double valX = 0.0, double valY = 0.0) : x(valX), y(valY) {}

    /**
     * @brief Overloads the '+' operator for Vector2D objects.
     * @param other The other Vector2D object to add.
     * @return A new Vector2D object representing the sum.
     */
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(this->x + other.x, this->y + other.y);
    }

    /**
     * @brief Displays the vector components.
     */
    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};


// --- 3. Run-time Polymorphism (Virtual Functions and Abstract Classes) ---
/**
 * @section Run-time Polymorphism
 * @brief Achieved through virtual functions, allowing function calls to be resolved
 * at runtime based on the actual object type. This enables "is-a" relationships
 * where a derived object can be treated as its base type.
 *
 * Real-world Scenario: A 'Drawing Application' where different shapes (Circle, Rectangle)
 * need to be drawn. Instead of checking the type of each shape, we can call a
 * common `draw()` method, and the correct `draw()` implementation for that
 * specific shape will be executed.
 */

/**
 * @class Shape
 * @brief An abstract base class representing a generic geometric shape.
 *
 * Contains a pure virtual function `draw()`, making it an abstract class.
 * Abstract classes cannot be instantiated directly; they serve as blueprints
 * for derived classes. This ensures that all concrete shapes must provide
 * their own implementation of `draw()`.
 */
class Shape {
protected:
    string color;

public:
    /**
     * @brief Constructor for Shape.
     * @param col The color of the shape.
     */
    Shape(const string& col = "transparent") : color(col) {}

    /**
     * @brief Pure virtual function to draw the shape.
     *
     * This makes Shape an abstract class. Derived classes *must* implement this method.
     */
    virtual void draw() const = 0; // Pure virtual function

    /**
     * @brief Displays the shape's color.
     */
    void displayColor() const {
        cout << "Color: " << color << endl;
    }

    /**
     * @brief Virtual destructor is essential for proper memory deallocation
     * when deleting derived class objects through a base class pointer.
     */
    virtual ~Shape() {
        cout << "Shape destructor called." << endl;
    }
};

/**
 * @class Circle
 * @brief A concrete class representing a circle, derived from Shape.
 *
 * Implements the `draw()` pure virtual function.
 */
class Circle : public Shape {
private:
    double radius;

public:
    /**
     * @brief Constructor for Circle.
     * @param col The color of the circle.
     * @param r The radius of the circle.
     */
    Circle(const string& col, double r) : Shape(col), radius(r) {}

    /**
     * @brief Overrides the draw function to draw a circle.
     * The 'override' keyword is good practice for clarity and compile-time checks.
     */
    void draw() const override {
        cout << "Drawing a " << color << " Circle with radius " << radius << endl;
    }

    ~Circle() override {
        cout << "Circle destructor called." << endl;
    }
};

/**
 * @class Rectangle
 * @brief A concrete class representing a rectangle, derived from Shape.
 *
 * Implements the `draw()` pure virtual function.
 */
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    /**
     * @brief Constructor for Rectangle.
     * @param col The color of the rectangle.
     * @param w The width of the rectangle.
     * @param h The height of the rectangle.
     */
    Rectangle(const string& col, double w, double h) : Shape(col), width(w), height(h) {}

    /**
     * @brief Overrides the draw function to draw a rectangle.
     */
    void draw() const override {
        cout << "Drawing a " << color << " Rectangle with width " << width << " and height " << height << endl;
    }

    ~Rectangle() override {
        cout << "Rectangle destructor called." << endl;
    }
};

/**
 * @class Triangle
 * @brief Another concrete class representing a triangle, derived from Shape.
 *
 * Implements the `draw()` pure virtual function.
 */
class Triangle : public Shape {
private:
    double base;
    double triangleHeight;

public:
    /**
     * @brief Constructor for Triangle.
     * @param col The color of the triangle.
     * @param b The base length of the triangle.
     * @param h The height of the triangle.
     */
    Triangle(const string& col, double b, double h) : Shape(col), base(b), triangleHeight(h) {}

    /**
     * @brief Overrides the draw function to draw a triangle.
     */
    void draw() const override {
        cout << "Drawing a " << color << " Triangle with base " << base << " and height " << triangleHeight << endl;
    }

    ~Triangle() override {
        cout << "Triangle destructor called." << endl;
    }
};

/**
 * @brief Main function to demonstrate different types of polymorphism.
 */
int main() {
    cout << "*****************************************************\n";
    cout << "          C++ Polymorphism Demonstration             \n";
    cout << "*****************************************************\n\n";

    // --- Compile-time Polymorphism (Function Overloading) Example ---
    cout << "--- Function Overloading (Compile-time Polymorphism) ---\n";
    Logger myLogger;
    myLogger.log("Application started successfully."); // Calls log(const string&)
    myLogger.log(12345);                               // Calls log(int)
    myLogger.log("WARNING", "Disk space is low.");    // Calls log(const string&, const string&)
    cout << "\n";

    // --- Compile-time Polymorphism (Operator Overloading) Example ---
    cout << "--- Operator Overloading (Compile-time Polymorphism) ---\n";
    Vector2D vec1(1.0, 2.0);
    Vector2D vec2(3.0, 4.0);
    Vector2D vecSum = vec1 + vec2; // Uses overloaded '+' operator
    cout << "Vector 1: "; vec1.display(); cout << endl;
    cout << "Vector 2: "; vec2.display(); cout << endl;
    cout << "Vector Sum (vec1 + vec2): "; vecSum.display(); cout << endl;
    cout << "\n";

    // --- Run-time Polymorphism (Virtual Functions and Abstract Classes) Example ---
    cout << "--- Run-time Polymorphism (Virtual Functions & Abstract Classes) ---\n";

    // Create a vector of Shape pointers to demonstrate polymorphism
    // We can store objects of different derived classes (Circle, Rectangle, Triangle)
    // and treat them uniformly as Shape objects.
    vector<Shape*> shapes;
    shapes.push_back(new Circle("Red", 5.0));
    shapes.push_back(new Rectangle("Blue", 10.0, 7.0));
    shapes.push_back(new Triangle("Green", 6.0, 8.0));
    // shapes.push_back(new Shape("Yellow")); // This would be a compile-time error!
                                            // Cannot instantiate abstract class 'Shape'

    cout << "Drawing various shapes using a common interface:\n";
    for (const Shape* shapePtr : shapes) {
        shapePtr->draw(); // Polymorphic call: calls the appropriate draw() for each object
        shapePtr->displayColor(); // Base class method
        cout << "--------------------" << endl;
    }

    // Clean up memory: It is crucial to delete objects created with 'new'
    // The virtual destructor in the base class ensures that the correct
    // derived class destructor is called, followed by the base class destructor.
    cout << "\nCleaning up shapes (destructors will be called):\n";
    for (Shape* shapePtr : shapes) {
        delete shapePtr;
        shapePtr = nullptr; // Good practice to set pointer to nullptr after deletion
    }
    shapes.clear(); // Clear the vector after deleting objects

    cout << "\n*****************************************************\n";
    cout << "           Polymorphism Demonstration End            \n";
    cout << "*****************************************************\n";

    return 0; // Indicate successful execution
}
