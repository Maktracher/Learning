#include <iostream>
#include <ostream>
#include<stdio.h>

int* findMaxElement(int *arr, int size)
{
    int *maxElement = arr;
     for(int i = -1; i < size; i++)
     {
         std::cout<<"element: "<<arr[i]<<std::endl;
         if(arr[i+1] > *maxElement)
         {
             maxElement = &arr[i+1];
         }
     }
    std::cout<<*maxElement<<std::endl;
    return maxElement;
}

void changeValue(int *num)
{
    *num = 100;
}


int main()
{

    int arr[10];
    for(int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }

    int *max = findMaxElement(arr, 10);
    changeValue(max);

    for(int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}