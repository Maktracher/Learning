#include <iostream>
#include <ostream>
#include <string>

class Student
{
    private:
    std::string name;
    int age;
    int grade;
    public:
    Student(const std::string n,const int a,const int g)
    {
        name=n;
        age=a;
        grade=g;
    }
    void print()
    {
        std::cout<<name<<". Age: "<<age<<" Grade: "<<grade<<"\n";
    }
};

int main()
{
    std::string nameYou;
    int ageYou;
    int gradeYou;
    std::cout<<"Please input your name:";
    std::cin>>nameYou;
    std::cout<<"Please input your age:";
    std::cin>>ageYou;
    std::cout<<"Please input your grade:";
    std::cin>>gradeYou;

    Student You(nameYou,ageYou,gradeYou);
    You.print();

    return 0;
}