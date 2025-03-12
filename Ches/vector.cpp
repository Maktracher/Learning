
#include <iostream>
#include <vector>

class MyClass
{
public:
    void chislo2(int i, int j)
    {
        for (int k = 0; k<10; k++)
        {
            for (int l = 0; l<10; l++)
            {
                if (i == k || k == 8)
                    std::cout << "2 ";
                else if (k == 0 && l == 0)
                    std::cout << "1 ";
                else
                    std::cout << "0 ";
            }
            std::cout << std::endl;
        }
    }
    void print(int a) {
        std::cout << a << std::endl;
    }
};

int main()
{
    int a;

    std::cin >> a;

    MyClass obj;
    obj.chislo2(1,2);
    obj.print(a);

}
