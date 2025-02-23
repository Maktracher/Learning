#include <iostream>
#include <ostream>

int* findMaxElement(int *arr, int size)
{
    int *maxElement = arr;
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > *maxElement)
        {
            maxElement = &arr[i];
        }
    }
    std::cout<<*maxElement<<std::endl;
    return maxElement;
}

void changeValue(int *num)
{
    *num = 100;
}

void suma(int *arr, int size)
{

    for(int i = 1; i < size; i++)
    {
        *arr += arr[i];
    }
    std::cout<<std::endl;
    std::cout<<"suma"<<std::endl;
    std::cout<<*arr<<std::endl;
}


int main()
{

    int size = 0;
    std::cout<<"Enter the size of the array: ";
    std::cin >> size;

    int arr[size] = {};
    for(int i = 0; i < size; i++)
    {
        std::cout << "Enter number: " << " ";
        std::cin >> arr[i];
    }

    int *max = findMaxElement(arr, size);
    changeValue(max);

    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    suma(arr, size);

    return 0;
}