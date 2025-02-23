#include <iostream>

class Vehicle
{
    public:
    virtual ~Vehicle() = default;

    virtual void move()
    {
        std::cout << "The vehicle is moving: " << std::endl;
    }
};
class Car final : public Vehicle
{
    public:
    void move() override
    {
        std::cout << "The car drives on the road " << std::endl;
    }
};
class Boat final : public Vehicle
{
public:
    void move() override
    {
        std::cout << "The boat sails on water " << std::endl;
    }
};
class Plane final : public Vehicle
{
    public:
    void move() override
    {
        std::cout << "The plane flies in the sky " << std::endl;
    }
};
int main()
{
    Vehicle *car = new Car;
    Vehicle *boat = new Boat;
    Vehicle *plane = new Plane;

    car->move();
    boat->move();
    plane->move();

    delete car;
    delete boat;
    delete plane;
}