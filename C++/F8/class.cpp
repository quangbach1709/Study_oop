#include <iostream>
#include<string>

using namespace std;

class person
{
    public:
        string name;
        int age;
        string address;

};

int main()
{
    person person1;
    
    person1.name="Tong Quang Bach";
    person1.age=19;
    person1.address="Ha noi";

    cout<<"Ten: "<<person1.name<<"\n"<<"Tuoi: "<<person1.age<<"\n"<<"Dia chi: "<<person1.address;
    return 0;
}