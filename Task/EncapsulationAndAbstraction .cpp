#include <iostream>
#include <string>

class SmartDevice
{
public:
    void turnOn(bool turn)
    {
        power = true;
    }

    void turnOff(bool turn)
    {
        power = false;
    }

    void setBrightness(int get_brightness)
    {
        if (get_brightness >= 0 && get_brightness <= 100)
        {
            brightness = get_brightness;
        }
        else
            std::cout << "Brightness out of range" << std::endl;
    }

    int getBrightness() const
    {
        return brightness;
    }

    bool getPower() const
    {
        return power;
    }

private:
    bool power = false;
    int brightness = 0;
};

int main()
{
    bool power = false;
    int brightness = 0;
    std::string button = "OFF";
    std::string menu;

    SmartDevice mySmartDevice;

    std::cout << "device is off. Enter 'ON' the power of the device: ";

    while (power == false)
    {
        std::cin >> button;

        if (button == "ON")
        {
            mySmartDevice.turnOn(true);
            power = true;
        }
        else
            std::cout << "Enter 'ON' the power of the device: ";
    }

    while (power == true)
    {
        std::cout << "Device is on. Enter 'brightness' or 'OFF': ";
        std::cin >> menu;

        if (menu == "brightness")
        {
            std::cout << "Brightness: " << mySmartDevice.getBrightness() << std::endl;
            std::cout << "Enter 'Brightness' from 0 to 100: ";
            std::cin >> brightness;

            if (brightness >= 0 && brightness <= 100)
            {
                mySmartDevice.setBrightness(brightness);
                std::cout << "Brightness " << mySmartDevice.getBrightness() << std::endl;
            }
            else
                std::cout << "Brightness out of range"<< std::endl;
        }
        else if (menu == "OFF")
        {
            std::cout << "OFF by";
            power = false;
        }
        else
            std::cout << "Enter 'brightness' or 'OFF': ";
    }
}