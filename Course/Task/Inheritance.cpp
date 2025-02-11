#include <iostream>

class Car
{
public:
    Car(const std::string& b, const int s)  : brand(b), speed(s) {}
    void displayInfo() const
    {
        std::cout << "Brand: " << brand << " Speed " << speed << "km/h" << std::endl;
    }
private:
    std::string brand;
    int speed = 0;
};

class BMW : public Car
{
public:
    BMW() : Car("BMW", 120) {}
};

class MB : public Car
{
public:
    MB() : Car("MB", 140){}
};

int main()
{
    const BMW carBmw;
    carBmw.displayInfo();
    const MB carMb;
    carMb.displayInfo();
}