#include <iostream>
#include <ostream>
#include <string>

void MinArr(const int *element, const int *s)
{
  int min = element[0];
  for(int i=0; i < *s ; i++)
    if(min>element[i])
      min = element[i];
  std::cout<<min<<std::endl;
}
void MaxArr(const int *element, const int *s)
{
  int max = element[0];
  for(int i=0; i < *s ; i++)
    if(max<element[i])
      max = element[i];
  std::cout<<max<<std::endl;
}

int main()
{
  int size = 0;
  std::cout<<"Size! "<<std::endl;
  std::cin>>size;
  int *arr = new int[size];

  std::cout<<"Enter "<<size<<" array elements!"<<std::endl;
  for (size_t i = 0; i < size; i++)
    std::cin>>arr[i];

  MinArr(arr, &size);
  MaxArr(arr, &size);

  delete[] arr;
  return 0;
}