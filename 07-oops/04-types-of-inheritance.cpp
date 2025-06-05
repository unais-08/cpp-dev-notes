/**
 * InheritanceTypes.cpp
 *
 * This file documents various types of inheritance in C++ Object-Oriented Programming (OOP).
 * It provides definitions, real-world analogies, and code examples for:
 * 1. Single Inheritance
 * 2. Multiple Inheritance
 * 3. Multilevel Inheritance
 * 4. Hierarchical Inheritance
 * 5. Hybrid Inheritance
 *
 * Inheritance allows code reusability and establishes an "is-a" relationship between classes.
 *
 * Author: Gemini
 * Date: May 31, 2025
 */

#include <iostream>  // For input/output operations (e.g., std::cout)
#include <string>    // For std::string

// --- Base Class for all examples (where applicable) ---
/**
 * @class Vehicle
 * @brief A generic base class representing a vehicle.
 *
 * This class serves as a base for demonstrating inheritance. It contains
 * common attributes and behaviors shared by different types of vehicles.
 */
class Vehicle
{
   protected:  // Protected members are accessible by derived classes
    std::string brand;
    int year;

   public:
    /**
     * @brief Constructor for the Vehicle class.
     * @param brandName The brand of the vehicle.
     * @param manufactureYear The manufacturing year of the vehicle.
     */
    Vehicle(const std::string& brandName, int manufactureYear)
        : brand(brandName), year(manufactureYear)
    {
        std::cout << "Vehicle constructor called for " << brand << std::endl;
    }

    /**
     * @brief Displays basic vehicle information.
     */
    void displayVehicleInfo() const
    {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }

    /**
     * @brief Simulates starting the vehicle engine.
     */
    void startEngine() const { std::cout << brand << " engine started." << std::endl; }

    // Virtual destructor for proper polymorphic deletion
    virtual ~Vehicle() { std::cout << "Vehicle destructor called for " << brand << std::endl; }
};

// --- 1. Single Inheritance ---
/**
 * @section Single Inheritance
 * @brief A derived class inherits from only one base class.
 *
 * Real-world Scenario: A 'Car' is a specific type of 'Vehicle'.
 * A Car inherits properties like brand and year, and adds its own specific
 * attributes like number of doors.
 */
class Car : public Vehicle
{  // Car inherits publicly from Vehicle
   private:
    int numberOfDoors;

   public:
    /**
     * @brief Constructor for the Car class.
     * @param brandName The brand of the car.
     * @param manufactureYear The manufacturing year.
     * @param doors The number of doors.
     */
    Car(const std::string& brandName, int manufactureYear, int doors)
        : Vehicle(brandName, manufactureYear), numberOfDoors(doors)
    {  // Call base class constructor
        std::cout << "Car constructor called." << std::endl;
    }

    /**
     * @brief Displays car specific information along with vehicle info.
     */
    void displayCarInfo() const
    {
        std::cout << "--- Car Info (Single Inheritance) ---" << std::endl;
        displayVehicleInfo();  // Accessing base class public method
        std::cout << "Number of Doors: " << numberOfDoors << std::endl;
    }

    /**
     * @brief Simulates opening car doors.
     */
    void openDoors() const { std::cout << brand << " doors opened." << std::endl; }

    ~Car() override
    {  // Override destructor if base is virtual
        std::cout << "Car destructor called." << std::endl;
    }
};

// --- 2. Multiple Inheritance ---
/**
 * @section Multiple Inheritance
 * @brief A derived class inherits from multiple base classes.
 *
 * Real-world Scenario: A 'AmphibiousVehicle' is both a 'LandVehicle' and a 'WaterVehicle'.
 * It combines capabilities from distinct base classes.
 *
 * Note: Multiple inheritance can lead to complexities like the "Diamond Problem"
 * (ambiguity when a class inherits from two classes that have a common base class).
 * Virtual inheritance can resolve this.
 */
class LandVehicle
{
   public:
    void drive() const { std::cout << "Driving on land." << std::endl; }
    virtual ~LandVehicle() = default;  // Ensure proper destruction
};

class WaterVehicle
{
   public:
    void floatOnWater() const { std::cout << "Floating on water." << std::endl; }
    virtual ~WaterVehicle() = default;  // Ensure proper destruction
};

class AmphibiousVehicle : public LandVehicle, public WaterVehicle
{
   public:
    /**
     * @brief Displays capabilities of an amphibious vehicle.
     */
    void displayAmphibiousCapabilities() const
    {
        std::cout << "--- Amphibious Vehicle Info (Multiple Inheritance) ---" << std::endl;
        drive();         // Inherited from LandVehicle
        floatOnWater();  // Inherited from WaterVehicle
        std::cout << "This vehicle can operate on both land and water." << std::endl;
    }
};

// --- 3. Multilevel Inheritance ---
/**
 * @section Multilevel Inheritance
 * @brief A derived class becomes the base class for another derived class.
 * A -> B -> C (A is base, B is intermediate, C is derived from B)
 *
 * Real-world Scenario: A 'SportsCar' is a type of 'Car', which in turn
 * is a type of 'Vehicle'.
 */
class SportsCar : public Car
{  // SportsCar inherits publicly from Car
   private:
    double topSpeedKmH;

   public:
    /**
     * @brief Constructor for the SportsCar class.
     * @param brandName The brand.
     * @param manufactureYear The year.
     * @param doors The number of doors.
     * @param speed The top speed.
     */
    SportsCar(const std::string& brandName, int manufactureYear, int doors, double speed)
        : Car(brandName, manufactureYear, doors), topSpeedKmH(speed)
    {  // Call base class (Car) constructor
        std::cout << "SportsCar constructor called." << std::endl;
    }

    /**
     * @brief Displays sports car specific information.
     */
    void displaySportsCarInfo() const
    {
        std::cout << "--- Sports Car Info (Multilevel Inheritance) ---" << std::endl;
        displayCarInfo();  // Accessing method from immediate base class (Car)
        std::cout << "Top Speed: " << topSpeedKmH << " km/h" << std::endl;
    }

    /**
     * @brief Simulates engaging turbo.
     */
    void engageTurbo() const { std::cout << "Turbo engaged! Speed boost activated." << std::endl; }

    ~SportsCar() override { std::cout << "SportsCar destructor called." << std::endl; }
};

// --- 4. Hierarchical Inheritance ---
/**
 * @section Hierarchical Inheritance
 * @brief Multiple derived classes inherit from a single base class.
 *
 * Real-world Scenario: A 'Vehicle' can be a 'Car', a 'Motorcycle', or a 'Truck'.
 * All these classes share common 'Vehicle' attributes but have their own unique ones.
 */
class Motorcycle : public Vehicle
{
   private:
    bool hasSideCar;

   public:
    /**
     * @brief Constructor for the Motorcycle class.
     * @param brandName The brand.
     * @param manufactureYear The year.
     * @param sideCar Flag indicating if it has a sidecar.
     */
    Motorcycle(const std::string& brandName, int manufactureYear, bool sideCar)
        : Vehicle(brandName, manufactureYear), hasSideCar(sideCar)
    {
        std::cout << "Motorcycle constructor called." << std::endl;
    }

    /**
     * @brief Displays motorcycle specific information.
     */
    void displayMotorcycleInfo() const
    {
        std::cout << "--- Motorcycle Info (Hierarchical Inheritance) ---" << std::endl;
        displayVehicleInfo();
        std::cout << "Has Side Car: " << (hasSideCar ? "Yes" : "No") << std::endl;
    }

    ~Motorcycle() override { std::cout << "Motorcycle destructor called." << std::endl; }
};

class Truck : public Vehicle
{
   private:
    double cargoCapacityTons;

   public:
    /**
     * @brief Constructor for the Truck class.
     * @param brandName The brand.
     * @param manufactureYear The year.
     * @param capacity The cargo capacity in tons.
     */
    Truck(const std::string& brandName, int manufactureYear, double capacity)
        : Vehicle(brandName, manufactureYear), cargoCapacityTons(capacity)
    {
        std::cout << "Truck constructor called." << std::endl;
    }

    /**
     * @brief Displays truck specific information.
     */
    void displayTruckInfo() const
    {
        std::cout << "--- Truck Info (Hierarchical Inheritance) ---" << std::endl;
        displayVehicleInfo();
        std::cout << "Cargo Capacity: " << cargoCapacityTons << " tons" << std::endl;
    }

    ~Truck() override { std::cout << "Truck destructor called." << std::endl; }
};

// --- 5. Hybrid Inheritance ---
/**
 * @section Hybrid Inheritance
 * @brief A combination of two or more types of inheritance.
 * Often a combination of Multiple and Hierarchical inheritance.
 *
 * Real-world Scenario: A 'FlyingCar' is a type of 'Car' (hierarchical)
 * and also inherits capabilities from an 'Aircraft' (multiple inheritance with Car).
 *
 * This scenario can lead to the "Diamond Problem" if `Car` and `Aircraft`
 * both derive from a common base (e.g., `MotorizedObject`). To solve this,
 * virtual inheritance would be used for the common base.
 */
class Aircraft
{
   public:
    void fly() const { std::cout << "Flying in the air." << std::endl; }
    virtual ~Aircraft() = default;
};

// Assuming Car is already defined above from Single/Multilevel inheritance
// For a clean Hybrid example, we might re-define Car or adapt.
// Here, we'll make a new 'FlyingCar' that inherits from both a basic 'Car' (for simplicity)
// and 'Aircraft'. This showcases combination of single (Car is a Vehicle) and multiple.

class FlyingCar : public Car, public Aircraft
{
   private:
    double maxAltitude;

   public:
    /**
     * @brief Constructor for the FlyingCar class.
     * @param brandName The brand.
     * @param manufactureYear The year.
     * @param doors The number of doors.
     * @param altitude The maximum altitude.
     */
    FlyingCar(const std::string& brandName, int manufactureYear, int doors, double altitude)
        : Car(brandName, manufactureYear, doors), maxAltitude(altitude)
    {  // Call base class (Car) constructor
        std::cout << "FlyingCar constructor called." << std::endl;
    }

    /**
     * @brief Displays flying car specific information.
     */
    void displayFlyingCarInfo() const
    {
        std::cout << "--- Flying Car Info (Hybrid Inheritance) ---" << std::endl;
        displayCarInfo();  // From Car base class
        std::cout << "Max Altitude: " << maxAltitude << " meters" << std::endl;
        // drive();  // Removed: Car/Vehicle do not have drive()
        fly();  // From Aircraft
        std::cout << "This vehicle can drive and fly!" << std::endl;
    }

    ~FlyingCar() override { std::cout << "FlyingCar destructor called." << std::endl; }
};

/**
 * @brief Main function to demonstrate different types of inheritance.
 */
int main()
{
    std::cout << "*****************************************************\n";
    std::cout << "          C++ Inheritance Demonstration              \n";
    std::cout << "*****************************************************\n\n";

    // --- Single Inheritance Example ---
    std::cout << "--- Single Inheritance: Car is a Vehicle ---\n";
    Car myCar("Toyota", 2023, 4);
    myCar.displayCarInfo();
    myCar.startEngine();  // Inherited from Vehicle
    myCar.openDoors();
    std::cout << "\n";

    // --- Multiple Inheritance Example ---
    std::cout
        << "--- Multiple Inheritance: AmphibiousVehicle is a LandVehicle and WaterVehicle ---\n";
    AmphibiousVehicle myAmphibiousVehicle;
    myAmphibiousVehicle.displayAmphibiousCapabilities();
    std::cout << "\n";

    // --- Multilevel Inheritance Example ---
    std::cout << "--- Multilevel Inheritance: SportsCar is a Car, Car is a Vehicle ---\n";
    SportsCar mySportsCar("Ferrari", 2024, 2, 320.0);
    mySportsCar.displaySportsCarInfo();
    mySportsCar.startEngine();  // Inherited from Vehicle via Car
    mySportsCar.engageTurbo();
    std::cout << "\n";

    // --- Hierarchical Inheritance Example ---
    std::cout << "--- Hierarchical Inheritance: Motorcycle & Truck are Vehicles ---\n";
    Motorcycle myMotorcycle("Harley", 2022, false);
    myMotorcycle.displayMotorcycleInfo();
    myMotorcycle.startEngine();
    std::cout << "\n";

    Truck myTruck("Volvo", 2021, 15.0);
    myTruck.displayTruckInfo();
    myTruck.startEngine();
    std::cout << "\n";

    // --- Hybrid Inheritance Example ---
    std::cout << "--- Hybrid Inheritance: FlyingCar is a Car and an Aircraft ---\n";
    FlyingCar myFlyingCar("TeslaSky", 2025, 4, 3000.0);
    myFlyingCar.displayFlyingCarInfo();
    myFlyingCar.startEngine();  // From Vehicle -> Car
    // No explicit call to drive() or fly() needed as they are called in displayFlyingCarInfo
    std::cout << "\n";

    std::cout << "*****************************************************\n";
    std::cout << "           Inheritance Demonstration End             \n";
    std::cout << "*****************************************************\n";

    return 0;  // Indicate successful execution
}
