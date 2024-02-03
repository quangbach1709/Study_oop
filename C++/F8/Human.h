#include<iostream>
#include<string>

using namespace std;

class Human
{
    private:
        int age;
        string name;
    public:
        Human(int tuoi,string ten)
        {
            this->age=tuoi;
            this->name=ten;
        }
        ~Human()
        {
            cout<<"Da huy humna"<<endl;
        }
        void setAge(int tuoi)
        {
            this->age=tuoi;
        }
        int getAge()
        {
            return age;
        }
        void setName(string ten)
        {
            this->name=ten;
        }
        string getName()
        {
            return name;
        }
        void input()
        {
            cout<<"Nhap ten: ";
            getline(cin,name);
            cout<<"Nhap tuoi: ";
            cin>>age;
            cin.ignore();
        }
        void output()
        {
            cout<<"Ten: "<<getName()<<endl;
            cout<<"Tuoi: "<<getAge()<<endl;
        }
};