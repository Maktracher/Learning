#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>

bool IsOperator(const char sign)
{
    return sign != '+' && sign != '-' && sign != '*' && sign != '/' && sign != '^' && sign != '=';
}

bool IsNumber(const char number)
{
    return number >= '0' && number <= '9';
}

double ToDouble(const char sign)
{
    return std::stod(std::string(1, sign));
}

double Calculate(const std::string input)
{
    double result = ToDouble(input[0]);

    for (size_t i = 0; i < input.length(); i++)
    {
        switch (input[i]) {
            case '+':
                result += ToDouble(input[i + 1]);
                break;
            case '-':
                result -= ToDouble(input[i + 1]);
                break;
            case '*':
                result *= ToDouble(input[i + 1]);
                break;

            case '/':
                if(input[i + 1] == '0')
                {
                    std::cout << "Division by 0" << std::endl;
                    return -555.555;
                }
                result /= ToDouble(input[i + 1]);
                break;

            case '^':
                if((i - 1) == 0)
                {
                    result = pow(ToDouble(input[i - 1]), ToDouble(input[i + 1])) ;
                }else
                {
                    switch (input[i - 2])
                    {
                        case '+':
                            result -= ToDouble(input[i - 1]);
                            result += pow(ToDouble(input[i - 1]), ToDouble(input[i + 1])) ;
                            break;
                        case '-':
                            result += ToDouble(input[i - 1]);
                            result -= pow(ToDouble(input[i - 1]), ToDouble(input[i + 1])) ;
                            break;
                        case '*':
                            result /= ToDouble(input[i - 1]);
                            result *= pow(ToDouble(input[i - 1]), ToDouble(input[i + 1])) ;
                            break;
                        case '/':
                            result *= ToDouble(input[i - 1]);
                            result /= pow(ToDouble(input[i - 1]), ToDouble(input[i + 1])) ;
                            break;
                    }
                }
                break;
        }
    }
    return result;
}

int main()
{
    std::string input;
    char inputSign;
    bool isNum = true;

    while (true)
    {
        if(isNum)
        {
            while (true)
            {
                std::cout << "Enter a number: ";
                std::cin >> inputSign;

                if(IsNumber(inputSign))
                {
                    break;
                }
            }
            isNum = false;
        }
        else
        {
            while (true)
            {
                std::cout << "Enter an operator: ";
                std::cin >> inputSign;

                if(!IsOperator(inputSign))
                {
                    break;
                }
            }
            isNum = true;
        }
        if (inputSign == '=')
        {
            auto start = std::chrono::system_clock::now();

            double result = Calculate(input);

            std::time_t start_time = std::chrono::system_clock::to_time_t(start);


            std::cout << "Result: " << result << std::endl;
            std::cout << "time: " << std::put_time(std::localtime(&start_time), "%Y-%m-%d %H:%M:%S") << std::endl;
            break;
        }
        input.append(1, inputSign);
    }

    return 0;
}
