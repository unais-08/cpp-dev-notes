#include <iostream>

class Animal
{
   public:
    std::string name;
    Animal(std::string name) { this->name = name; }
    void eat() { std::cout << name << " can eat" << std::endl; }
    void leg() { std::cout << "Has four legs" << std::endl; }
};
class Tiger : public Animal
{
   public:
    Tiger(std::string name) : Animal(name) {}
    void sound() { std::cout << "BARK BARK..."; }
    void eat()
    {
        std::cout << "Tiger eat non-veg" << std::endl;
        int i;
    }
};
int main()
{
    std::cout << "execution start" << std::endl;
    Animal Dog("Dog");
    Tiger t("Tiger");
    Dog.eat();
    t.eat();
    t.leg();
    return 0;
}
